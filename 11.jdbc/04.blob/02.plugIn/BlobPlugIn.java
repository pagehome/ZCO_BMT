
import java.sql.*;
import java.io.*;
import oracle.jdbc.pool.OracleDataSource;


/**
 * Blob 테스트 샘풀
 *

DROP TABLE SCOTT.ZCUBE_BLOB_PLG CASCADE CONSTRAINTS;

CREATE TABLE SCOTT.ZCUBE_BLOB_PLG
(
  PKCOL     NUMBER     NOT NULL,
  ENC_BLOB  BLOB,
  REMARK    VARCHAR2(200 BYTE),
  TR_DATE   DATE       DEFAULT SYSDATE
)

 * 
 */

public class BlobPlugIn {
        
//    static String jdbcUrl = "jdbc:oracle:thin:scott/tiger@192.168.1.212:1527:ORA9I"; // oracle 9i
    static String jdbcUrl = "jdbc:oracle:thin:scott/tiger@192.168.1.59:1535:ORCL"; // oracle 10g

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static OracleDataSource ods;

    static String item, plnFileNm, decFileNm, encFileNm;
    
    public static void main(String[] args) {

        System.out.println("###################################################");
        System.out.println("###### CubeOne PlugIn BLOB-Type : JDBC TEST #######");
        System.out.println("###################################################\n");

        if(args.length != 2) {
            System.out.println("<<< Input item fileName !!!!");
            return;
        } else {
            item = args[0];
            plnFileNm = args[1];
            decFileNm = "DEC." + plnFileNm;
        }
        
        System.out.println("<<< main() :: plnFileNm = [" + plnFileNm + "]");
        System.out.println("<<< main() :: decFileNm = [" + decFileNm + "]");

        System.out.println("<<< main() :: jdbcUrl = [" + jdbcUrl + "]");

        try {

            ods = new OracleDataSource();
            ods.setURL(jdbcUrl);
            conn = ods.getConnection();
            System.out.println("<<< main() :: DB connection completed .... \n");

            DatabaseMetaData meta = conn.getMetaData(); // Create Oracle DatabaseMetaData object

            System.out.println("<<< main() :: java.version = [" + System.getProperty("java.version") + "]"); // getDriverName
            System.out.println("<<< main() :: JDBC getDatabaseProductVersion = [" + meta.getDatabaseProductVersion() + "]"); // getDatabaseProductVersion
            System.out.println("<<< main() :: JDBC getDriverVersion = [" + meta.getDriverVersion() + "]"); // getDriverVersion
            System.out.println("<<< main() :: JDBC getDriverName = [" + meta.getDriverName() + "]\n\n"); // getDriverName


            // 입력 방식 2가지 가능
            Ins_Oracle_BLOB_createTemporary();
            Ins_PreparedStatement_setBinaryStream();

            // 수정 방식 2가지 가능
            //Upd_PreparedStatement_setBinaryStream();
            //Upd_Oracle_BLOB_createTemporary();
            
            // 조회 방식 3가지 가능
            Sel_Oracle_BLOB_getBinaryStream();
            //Sel_Jdbc_Blob_getBinaryStream();
            //Sel_Jdbc_getBinaryStream();
            
            // 기존에 사용하던 select for update 방식은 사용 불가 함
            // _ins_selectForUpdate();
            
            
        } catch (SQLException e) {
            System.out.println("<<< SQLException ############################################################");
            System.out.println("msg = [" + e.getMessage() + "]");
            System.out.println("e.getErrorCode() = [" + e.getErrorCode() + "]");

            System.out.println("e.getSQLState() = [" + e.getSQLState() + "]");

            e.printStackTrace();

        } catch (Exception e) {
            System.out.println("<<< Exception ############################################################");
            System.out.println("msg = [" + e.getMessage() + "]");
            e.printStackTrace();
        } finally {
            try {
                conn.close();
            } catch (Exception e) {
                System.out.println("<<< Finally ############################################################");
                e.printStackTrace();
            }
        }

    }

    
    /*
     * classes12.jar 이상에서 사용가능
     *  
     * 최초 temp 테이블스페이스를 사용하고  
     * pstmt.executeUpdate() 후에 해당 Table의 테이블스페이스를 사용함(Object Type은 LOBSEGMENT)
     * 
     */
    static void Ins_Oracle_BLOB_createTemporary() throws Exception {

        System.out.println("<<< Ins_Oracle_BLOB_createTemporary() :: start !!!!! ");

        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fis = new FileInputStream(file);
        
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Create oracle.sql.BLOB.createTemporary
        /////////////////////////////////////////////////////////////////////////////////////
        oracle.sql.BLOB blobPln = oracle.sql.BLOB.createTemporary(conn, false, oracle.sql.BLOB.DURATION_SESSION);
        
        OutputStream outStream = blobPln.setBinaryStream(1L);

        System.out.println(" - outStream.getClass().getName() = [" + outStream.getClass().getName() + "]");

        // @ Read ..
        byte[] buff = new byte[1024];
        while(fis.read(buff) != -1) {
            outStream.write(buff);
        }
        
        outStream.flush();
        outStream.close();
        fis.close();
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.enc_blob_ins(?,10,'ITEM') DB Function !!!
        // @ Must use PrepareStatement
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "INSERT INTO ZCUBE_BLOB_PLG ( PKCOL, \n"
                   + "                             ENC_BLOB, \n"
                   + "                             REMARK ) \n"
                   + "                     VALUES((SELECT NVL(MAX(PKCOL)+1,1) FROM ZCUBE_BLOB_PLG), \n"
                   + "                             xx1.enc_blob_ins(?,10,?), \n"
                   + "                             ?)";

        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);

        int idx = 1;
        pstmt.setBlob  (idx++, blobPln); 
        pstmt.setString(idx++, item); 
        pstmt.setString(idx++, "Ins_Oracle_BLOB_createTemporary||classes12.jar||oracle9i||jdk1.4 available"); // REMARK

        pstmt.executeUpdate();

        /////////////////////////////////////////////////////////////////////////////////////
        // @ createTemporary 를 사용 후에 freeTemporary 사용하도록 메뉴얼에서 가이드 하고 있음.
        // 
        // ** IMPORTANT !!
        // You can free a temporary LOB by calling the freeTemporary method. Free any
        // temporary LOBs before ending the session or call. Otherwise, the storage used by the
        // temporary LOB will not be reclaimed.
        /////////////////////////////////////////////////////////////////////////////////////
        blobPln.freeTemporary();

        System.out.println("<<< Ins_Oracle_BLOB_createTemporary() :: End !!!!\n\n\n");        

    }

    /*
     * ojdbc6.jar 이상에서만 사용가능
     * 
     * 최초 temp 테이블스페이스를 사용하고  
     * pstmt.executeUpdate() 후에 해당 Table의 테이블스페이스를 사용함(Object Type은 LOBSEGMENT)
     * 
     */
    static void Ins_PreparedStatement_setBinaryStream() throws Exception {
    
        System.out.println("<<< Ins_PreparedStatement_setBinaryStream() :: start !!!!! ");
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fis = new FileInputStream(file);
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.enc_blob_ins(?,10,'ITEM') DB Function !!!
        // @ Must use PrepareStatement
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "INSERT INTO ZCUBE_BLOB_PLG ( PKCOL, \n"
                   + "                             ENC_BLOB, \n"
                   + "                             REMARK ) \n"
                   + "                     VALUES((SELECT NVL(MAX(PKCOL)+1,1) FROM ZCUBE_BLOB_PLG), \n"
                   + "                             xx1.enc_blob_ins(?,10,?), \n"
//                   + "                             ?, \n"
                   + "                             ?)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
        
        //ORA-01461: LONG 값은 LONG 열에 삽입할 때만 바인드할 수 있습니다.
        //pstmt.setBinaryStream(1, fis, file.length()); 
        //pstmt.setBinaryStream(1, fis, (int)file.length()); 

        int idx = 1;
        pstmt.setBinaryStream(idx++, fis);  // ojdbc6.jar 이상에서만 사용가능
        pstmt.setString      (idx++, item);
        pstmt.setString      (idx++, "Ins_PreparedStatement_setBinaryStream||pstmt.setBinaryStream(1,InputStream)||Only ojdbc6.jar Up !!"); // REMARK
    
        pstmt.executeUpdate();
    
        System.out.println("<<< Ins_PreparedStatement_setBinaryStream() :: End !!!!\n\n\n");        
    
    }


    /*
     * 최초 temp 테이블스페이스를 사용하고  
     * pstmt.executeUpdate() 후에 해당 Table의 테이블스페이스를 사용함(Object Type은 LOBSEGMENT)
     * 
     */

    static void Upd_PreparedStatement_setBinaryStream() throws Exception {
    
        System.out.println("<<< Upd_PreparedStatement_setBinaryStream() :: start !!!!! ");
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fis = new FileInputStream(file);
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.enc_blob_ins(?,10,'ITEM') DB Function !!!
        // @ Must use PrepareStatement
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "UPDATE ZCUBE_BLOB_PLG \n"
                   + "   SET ENC_BLOB = xx1.enc_blob_ins(?,10,?), \n"
                   + "       REMARK   = ? \n"
                   + " WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
    
        int idx = 1;
        pstmt.setBinaryStream(idx++, fis); 
        pstmt.setString      (idx++, item);
        pstmt.setString      (idx++, "Upd_PreparedStatement_setBinaryStream||pstmt.setBinaryStream(1,InputStream)||Only ojdbc6.jar Up !!"); // REMARK
    
        pstmt.executeUpdate();
    
        System.out.println("<<< Upd_PreparedStatement_setBinaryStream() :: End !!!!\n\n\n");        
    }


    /*
     * 최초 temp 테이블스페이스를 사용하고  
     * pstmt.executeUpdate() 후에 해당 Table의 테이블스페이스를 사용함(Object Type은 LOBSEGMENT)
     * 
     */

    static void Upd_Oracle_BLOB_createTemporary() throws Exception {
    
        System.out.println("<<< Upd_Oracle_BLOB_createTemporary() :: start !!!!! ");
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fis = new FileInputStream(file);
    
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Create oracle.sql.BLOB.createTemporary
        /////////////////////////////////////////////////////////////////////////////////////
        oracle.sql.BLOB blobPln = oracle.sql.BLOB.createTemporary(conn, false, oracle.sql.BLOB.DURATION_SESSION);
    
        // @ Test Stream creation 
        OutputStream outStream = blobPln.setBinaryStream(1L);
        
        System.out.println(" - outStream.getClass().getName() = [" + outStream.getClass().getName() + "]");
    
        byte[] buff = new byte[1024];
        while(fis.read(buff) != -1) {
            outStream.write(buff);
        }
    
        outStream.flush();
        outStream.close();
        fis.close();
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.enc_blob_ins(?,10,'ITEM') DB Function !!!
        // @ Must use PrepareStatement
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "UPDATE ZCUBE_BLOB_PLG \n"
                   + "   SET ENC_BLOB = xx1.enc_blob_ins(?,10,?), \n"
                   + "       REMARK   = ? \n"
                   + " WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
    
        int idx = 1 ;
        pstmt.setBlob  (idx++, blobPln);
        pstmt.setString(idx++, item);
        pstmt.setString(idx++, "Upd_Oracle_BLOB_createTemporary||ojdbc14.jar||oracle9i||jdk1.4 available"); // REMARK
    
        pstmt.executeUpdate();
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ createTemporary 를 사용 후에 freeTemporary 사용하도록 메뉴얼에서 가이드 하고 있음.
        // 
        // ** IMPORTANT !!
        // You can free a temporary LOB by calling the freeTemporary method. Free any
        // temporary LOBs before ending the session or call. Otherwise, the storage used by the
        // temporary LOB will not be reclaimed.
        /////////////////////////////////////////////////////////////////////////////////////
        blobPln.freeTemporary();
    
    
        System.out.println("<<< Upd_Oracle_BLOB_createTemporary() :: End !!!!\n\n\n");        
    }


    static void Sel_Oracle_BLOB_getBinaryStream() throws Exception {
    
        System.out.println("<<< Sel_Oracle_BLOB_getBinaryStream() :: start !!!!! ");
    
        String pkcol, remark ;
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Write Dec-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(decFileNm);
        FileOutputStream fos = new FileOutputStream(file);
    
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.dec_blob_sel(?,10,'ITEM') DB Function !!!
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "SELECT PKCOL, \n"
                   + "       xx1.dec_blob_sel(ENC_BLOB,10,?) DEC_BLOB, \n"
                   + "       REMARK \n"
                   + "  FROM ZCUBE_BLOB_PLG WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG)";
    
        System.out.println(" - sql = [" + sql + "]\n");
    
        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, item);
        rs = pstmt.executeQuery();
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Use oracle.sql.BLOB
        /////////////////////////////////////////////////////////////////////////////////////
        oracle.sql.BLOB blobDec;         

        if(rs.next())
        {
            pkcol = rs.getString("PKCOL");
            blobDec = (oracle.sql.BLOB)rs.getBlob("DEC_BLOB");
            remark = rs.getString("REMARK");
    
            InputStream inStream =  blobDec.getBinaryStream();
            System.out.println(" - inStream.getClass().getName() = [" + inStream.getClass().getName() + "]");
            
            byte[] buff = new byte[1024];
            
            while(inStream.read(buff) != -1) {
                fos.write(buff);
            }
    
            System.out.println(" - pkcol = [" + pkcol + "]");
            System.out.println(" - remark = [" + remark + "]");
            System.out.println(" - blobDec.length() = [" + blobDec.length() + "]");
    
            inStream.close();
            fos.close();
            
        }
        
        System.out.println("<<< Sel_Oracle_BLOB_getBinaryStream() :: End !!!!\n\n\n");        
    }


    static void Sel_Jdbc_Blob_getBinaryStream() throws Exception {
    
        System.out.println("<<< Sel_Jdbc_Blob_getBinaryStream() :: start !!!!! ");
    
        String pkcol, remark ;
        Blob blobDec;         

        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Write Dec-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(decFileNm);
        FileOutputStream fos = new FileOutputStream(file);

        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.dec_blob_sel(?,10,'ITEM') DB Function !!!
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "SELECT PKCOL, \n"
                   + "       xx1.dec_blob_sel(ENC_BLOB,10,?) DEC_BLOB, \n"
                   + "       REMARK \n"
                   + "  FROM ZCUBE_BLOB_PLG \n"
                   + " WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, item);
        rs = pstmt.executeQuery();
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Use java.sql.Blob
        /////////////////////////////////////////////////////////////////////////////////////
        if(rs.next())
        {
            pkcol = rs.getString("PKCOL");
            blobDec = rs.getBlob("DEC_BLOB");
            remark = rs.getString("REMARK");
                
            InputStream inStream =  blobDec.getBinaryStream();
            System.out.println(" - inStream.getClass().getName() = [" + inStream.getClass().getName() + "]");            
            
            byte[] buff = new byte[1024];
            
            while(inStream.read(buff) != -1) {
                fos.write(buff);
            }

            System.out.println(" - pkcol = [" + pkcol + "]");
            System.out.println(" - remark = [" + remark + "]");
            System.out.println(" - blobDec.length() = [" + blobDec.length() + "]");
    
            inStream.close();
            fos.close();
        }
    
        System.out.println("<<< Sel_Jdbc_Blob_getBinaryStream() :: End !!!!\n\n\n");        
    }


    static void Sel_Jdbc_getBinaryStream() throws Exception {
    
        System.out.println("<<< Sel_Jdbc_getBinaryStream() :: start !!!!! ");
    
        String pkcol, remark ;
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Write Dec-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(decFileNm);
        FileOutputStream fos = new FileOutputStream(file);

        /////////////////////////////////////////////////////////////////////////////////////
        // @ Creating SQL : Must use xx1.dec_blob_sel(?,10,'ITEM') DB Function !!!
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "SELECT PKCOL, \n"
                   + "       xx1.dec_blob_sel(ENC_BLOB,10,?) DEC_BLOB, \n"
                   + "       REMARK \n"
                   + "  FROM ZCUBE_BLOB_PLG \n"
                   + " WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, item);
        rs = pstmt.executeQuery();
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Use ResultSet.getBinaryStream()
        /////////////////////////////////////////////////////////////////////////////////////
        if(rs.next())
        {
            pkcol = rs.getString("PKCOL");
            remark = rs.getString("REMARK");
            InputStream inStream = rs.getBinaryStream("DEC_BLOB");
            
            System.out.println(" - inStream.getClass().getName() = [" + inStream.getClass().getName() + "]");            
            
            byte[] buff = new byte[1024];
            
            while(inStream.read(buff) != -1) {
                fos.write(buff);
            }

            System.out.println(" - pkcol = [" + pkcol + "]");
            System.out.println(" - remark = [" + remark + "]");
    
            inStream.close();
            fos.close();

            
        }
    
        System.out.println("<<< Sel_Jdbc_getBinaryStream() :: End !!!!\n\n\n");        
    }


    /**
     * 
     * USERS와 UNDOTBS1 이 증가 함 !!
     * 
     * 
     */
    
    
    /*
     * temp 테이블스페이스를 사용하지 않고   
     * 자신의 Table의 테이블스페이스를 사용함(Object Type은 LOBSEGMENT)
     * 
     */

    static void _ins_selectForUpdate() throws Exception {
    
        System.out.println("<<< _ins_selectForUpdate() :: start !!!!! ");
    
        String pkcol, remark ;
        Blob blobEnc;
        
        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fis = new FileInputStream(file);

        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ 
        /////////////////////////////////////////////////////////////////////////////////////
        String sql = "INSERT INTO ZCUBE_BLOB_PLG ( PKCOL, \n"
                   + "                              ENC_BLOB, \n"
                   + "                              REMARK ) \n"
                   + "                     VALUES ((SELECT NVL(MAX(PKCOL)+1,1) FROM ZCUBE_BLOB_PLG), \n"
                   + "                             empty_blob(), \n"
                   + "                             ?)";
    
        System.out.println(" - sql = [" + sql + "]");
    
        pstmt = conn.prepareStatement(sql);
    
        pstmt.setString(1, "_ins_selectForUpdate||ojdbc14.jar||oracle9i||jdk1.4 available"); // REMARK
    
        pstmt.executeUpdate();

        
        /////////////////////////////////////////////////////////////////////////////////////
        // @ 
        /////////////////////////////////////////////////////////////////////////////////////
        sql = "SELECT PKCOL, \n"
             + "       ENC_BLOB, \n"
            + "       REMARK \n"
            + "  FROM ZCUBE_BLOB_PLG WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB_PLG) \n"
            + "   FOR UPDATE";

        
        pstmt = conn.prepareStatement(sql);
        rs = pstmt.executeQuery();
    
        /////////////////////////////////////////////////////////////////////////////////////
        // @ 
        /////////////////////////////////////////////////////////////////////////////////////
        if(rs.next())
        {
            pkcol = rs.getString("PKCOL");
            remark = rs.getString("REMARK");
            blobEnc = rs.getBlob("ENC_BLOB");

            OutputStream outStream = blobEnc.setBinaryStream(1);
            System.out.println(" - outStream.getClass().getName() = [" + outStream.getClass().getName() + "]");            

            byte[] buff = new byte[1024];
            while(fis.read(buff) != -1) {
                outStream.write(buff);
            }

            outStream.flush();
            outStream.close();
            fis.close();
            
            System.out.println(" - pkcol = [" + pkcol + "]");
            System.out.println(" - remark = [" + remark + "]");
        }
    
    
        
        
        System.out.println("<<< _ins_selectForUpdate() :: End !!!!\n\n\n");        
    
    }
}
