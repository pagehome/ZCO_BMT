import com.cubeone.CubeOneAPI;

import java.sql.*;
import java.io.*;
import oracle.jdbc.pool.OracleDataSource;


/*
 * 

CREATE TABLE SCOTT.ZCUBE_BLOB
(
  PKCOL        NUMBER                           NOT NULL,
  PLN_LEN      NUMBER,
  ENC_API      BLOB,
  ENC_API_LEN  NUMBER,
  ENC_PLG      BLOB,
  REMARK       VARCHAR2(100 BYTE),
  TR_DATE      DATE                             DEFAULT SYSDATE
)

 * 
 */

public class BlobApiPlug {

    //static String jdbcUrl = "jdbc:oracle:thin:scott/tiger@192.168.1.212:1527:ORA9I"; // oracle 9i
    static String jdbcUrl = "jdbc:oracle:thin:scott/tiger@192.168.1.59:1535:ORCL"; // oracle 10g

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static OracleDataSource ods;

    static String plnFileNm, decApiFileNm, decPlnFileNm;


    static byte[] byteErr = new byte[5];
    static String item ;

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

            decApiFileNm = "DEC.API." + plnFileNm;
            decPlnFileNm = "DEC.PLG." + plnFileNm;
        }

        System.out.println("<<< main() :: item = [" + item + "]");
        System.out.println("<<< main() :: decApiFileNm = [" + decApiFileNm + "]");
        System.out.println("<<< main() :: decPlnFileNm = [" + decPlnFileNm + "]");

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

            insert();
            select();
            

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

    static void insert() throws Exception {

        System.out.println("<<< insert() :: start !!!!! ");

        /////////////////////////////////////////////////////////////////////////////////////
        // @ Read Plain-Binary File 
        /////////////////////////////////////////////////////////////////////////////////////
        File file = new File(plnFileNm);
        FileInputStream fisPln = new FileInputStream(file);


        byte[] bytePln,byteEnc;
        ByteArrayInputStream baisPln, baisEnc ;


        bytePln = new byte[(int)file.length()];
        fisPln.read(bytePln);

        baisPln = new ByteArrayInputStream(bytePln);


        // API-Enc !!
        byteEnc = CubeOneAPI.coencbyteb(bytePln, bytePln.length, item, 10, null, null, byteErr);

        baisEnc = new ByteArrayInputStream(byteEnc);


        String sql = "INSERT INTO ZCUBE_BLOB(PKCOL\n"
                   + "                       ,PLN_LEN\n"
                   + "                       ,ENC_API\n"
                   + "                       ,ENC_API_LEN\n"
                   + "                       ,ENC_PLG\n"
                   + "                       ,REMARK\n"
                   + "                )\n "
                   + "                VALUES((SELECT NVL(MAX(PKCOL)+1,1) FROM ZCUBE_BLOB)\n"
                   + "                       ,?\n"
                   + "                       ,?\n"
                   + "                       ,?\n"
                   + "                       ,xx1.enc_blob_ins(?,10,?) \n"
                   + "                       ,?\n"
                   + "                )\n";



        System.out.println(" - sql = [" + sql + "]");

        /////////////////////////////////////
        pstmt=conn.prepareStatement(sql);

        int idx=1;

        // Plain Info
        pstmt.setInt         (idx++, (int)file.length()); // PLN_LENGTH

        // Api-Enc
        pstmt.setBinaryStream(idx++, baisEnc);               // ENC_API
        pstmt.setInt         (idx++, byteEnc.length);       // ENC_API_LEN

        // PlugIn-Enc
        pstmt.setBinaryStream(idx++, baisPln);               // ENC_PLG,
        pstmt.setString      (idx++, item);               // Item,

        // Remark for Test !!
        pstmt.setString      (idx++, "Insert Test !!!");  // REMARK

        pstmt.executeUpdate();

        fisPln.close();

        System.out.println("<<< insert() :: End !!!!\n\n");        

    }

    static void select() throws Exception {

        System.out.println("<<< select() :: start !!!!! ");

        String pkcol, pln ;
        int nPln, nEncApi;

        byte[] byteEncApi, byteEncPlg, byteDecApi, byteDecPlg;
        Blob   blobEncApi, blobEncPlg;         

        FileOutputStream fosDecApi, fosDecPlg ;

        /////////////////////////
        String sql = "SELECT PKCOL\n"
                + "         ,PLN_LEN\n"
                + "         ,ENC_API\n"
                + "         ,ENC_API_LEN\n"
                + "         ,ENC_PLG\n"
                + "    FROM ZCUBE_BLOB\n "
                + "    WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB)";

        System.out.println(" - sql = [" + sql + "]\n");

        pstmt = conn.prepareStatement(sql);
        rs = pstmt.executeQuery();

        if(rs.next())
        {
            pkcol      = rs.getString("PKCOL");
            nPln       = rs.getInt   ("PLN_LEN");
            blobEncApi = rs.getBlob  ("ENC_API");
            nEncApi    = rs.getInt   ("ENC_API_LEN");
            blobEncPlg = rs.getBlob  ("ENC_PLG");

            System.out.println(" - pkcol   = [" + pkcol + "]");
            System.out.println(" - nPln    = [" + nPln + "]");
            System.out.println(" - nEncApi = [" + nEncApi + "]\n");

            byteEncApi = blobEncApi.getBytes(1,(int)blobEncApi.length());
            byteEncPlg = blobEncPlg.getBytes(1,(int)blobEncPlg.length());

            // API 로 암호화 된 컬럼을 API로 복호화 시도
            byteDecApi = CubeOneAPI.codecbyteb(byteEncApi,byteEncApi.length, item,10,null,null,byteErr);

            if("00000".equals(new String(byteErr))) {
                fosDecApi = new FileOutputStream(new File(decApiFileNm));
                fosDecApi.write(byteDecApi);
                fosDecApi.close();
                
                System.out.println(" - " + decApiFileNm + "  OK !!!\n");
                
            } else {
                System.out.println(" - byteDecApi_byteErr = [" + new String(byteErr) + "]");
                System.out.println(" - CubeLog :: " + decApiFileNm + "  Fail !!!\n");
            }
            
            // PlugIn 으로 암호화 된 컬럼을 API로 복호화 시도
            byteDecPlg = CubeOneAPI.codecbyteb(byteEncPlg,byteEncPlg.length, item,10,null,null,byteErr);

            if("00000".equals(new String(byteErr))) {
                fosDecPlg = new FileOutputStream(new File(decPlnFileNm));
                fosDecPlg.write(byteDecPlg);
                fosDecPlg.close();

                System.out.println(" - " + decPlnFileNm + "  OK !!!\n");
                
            } else {
                System.out.println(" - byteDecPlg_byteErr = [" + new String(byteErr) + "]");
                System.out.println(" - " + decPlnFileNm + "  Fail !!!\n");
            }        
        }

        System.out.println("<<< select() :: End !!!!\n\n\n");        
    }
}
