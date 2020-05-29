import com.cubeone.CubeOneAPI;

import java.sql.*;
import java.text.*;
import java.util.*;
import java.io.*;

public class co_blob
{

    /****************************************************************************************
    // Oracle :: PLUG5
    static String url = "jdbc:oracle:thin:@192.168.1.45:1535:ORCL"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

    // Oracle :: AIX
    static String url = "jdbc:oracle:thin:@192.168.1.213:1522:ORA12"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

    // Tibero
    static String url = "jdbc:tibero:thin:@192.168.1.70:8629:tibero"; // URL
    static String driver = "com.tmax.tibero.jdbc.TbDriver";
    static String id = "test";
    static String pass = "test";
    //
    ****************************************************************************************/

    // Oracle :: PLUG5
    static String url = "jdbc:oracle:thin:@192.168.1.43:1535:ORCL"; // URL
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static byte[] byteErr = new byte[5];
    static String item , fileNm ;

    public static void main(String[] args) {

        System.out.println("*****************************************************");
        System.out.println("****** CubeOne API SelfTest : JDBC-BLOB TEST ********");
        System.out.println("*****************************************************");

        if(args.length == 0) {
            System.out.println("Input fileName and itemName");    
        }

        fileNm = args[0];
        item = args[1]; 

        System.out.println("<<< CubeLog :: file = [" + fileNm + "]");
        System.out.println("<<< CubeLog :: item = [" + item + "]"); 

        System.out.println("<<< CubeLog :: DB URL = [" + url + "][" + id + "/" + pass + "]"); 
        System.out.println("<<< CubeLog :: DB connection waiting ..."); 


        try{
            Class.forName(driver); // Load Jdbc Driver
            conn = DriverManager.getConnection(url, id, pass); // Connect DB
            System.out.println("<<< CubeLog :: DB connection completed !!! \n\n"); 

            insFileToBlob();
            selBlobToFile();

        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ############################################################");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
                conn.close();
            } catch (Exception e) {
                // ignored ..       
                System.out.println("<<< CubeLog :: Finally ############################################################");
                //System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
    }

    static void insFileToBlob() throws Exception 
    {
        String encrypt ;
        byte[] bytePln, byteEnc ; 
        ByteArrayInputStream baisPln, baisEnc ;

        File file = new File(fileNm);
        FileInputStream fis = new FileInputStream(file);

        ////////////////////////////////////////
        bytePln = new byte[(int)file.length()];
        fis.read(bytePln);

        baisPln = new ByteArrayInputStream(bytePln);

        /********************************************************************************************************
         * @ 2009-03-11
         * @ public static native String coencchar(byte[] inval, int inval_l, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * encrypt = CubeOneAPI.coencchar(new String(bytePln), item, 10, null, null, byteErr);
         * byteEnc = encrypt.getBytes();
         ********************************************************************************************************/

        /********************************************************************************************************
         * @ 2010-09-02 : THIS IS CONTAIN BUG !!!!!! DO NOT USE !!!!
         * @ public static native String coencbyte(byte[] inval, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * encrypt = CubeOneAPI.coencbyte(bytePln, item, 10, null, null, byteErr);
         * byteEnc = encrypt.getBytes();
         ********************************************************************************************************/

        /********************************************************************************************************
         * @ 2012-06-26
         * @ public static native String coencbytes(byte[] inval, int inval_l, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * encrypt = CubeOneAPI.coencbytes(bytePln, bytePln.length, item, 10, null, null, byteErr);
         * byteEnc = encrypt.getBytes();
         ********************************************************************************************************/

        /********************************************************************************************************
         * @ 2013-06-12
         * @ public static native byte[] coencbyteb(Byte[] inval, int inval_l, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * byteEnc = CubeOneAPI.coencbyteb(bytePln, bytePln.length, item, 10, null, null, byteErr);
         ********************************************************************************************************/
        byteEnc = CubeOneAPI.coencbyteb(bytePln, bytePln.length, item, 10, null, null, byteErr);

        ////////////////////////////////////////
        baisEnc = new ByteArrayInputStream(byteEnc);

        ////////////////////////////////////////
        System.out.println("<<< Insert File to BLOB Table :: starting ... " );

        String sql = "INSERT INTO ZCUBE_BLOB(PKCOL, PLN_BLOB, PLN_LENGTH, ENC_BLOB, ENC_LENGTH) VALUES((SELECT NVL(MAX(PKCOL)+1,1) FROM ZCUBE_BLOB),?,?,?,?)" ;
        System.out.println(" - sql = [" + sql + "]");
        
        pstmt = conn.prepareStatement(sql);        

        pstmt.setBinaryStream(1, baisPln, bytePln.length);
        pstmt.setInt(2, bytePln.length); 
        pstmt.setBinaryStream(3, baisEnc, byteEnc.length);
        pstmt.setInt(4, byteEnc.length);

        pstmt.executeUpdate();

        System.out.println("<<< Insert File to BLOB Table :: succeeded !!! \n" );
    }

    static void selBlobToFile() throws Exception 
    {
        byte[] bytePln, byteEnc, byteDec ; 
        String pkcol, plnLen, encLen; 
        Blob blobPln, blobEnc; 
        FileOutputStream fosDecFile ;

        System.out.println("<<< Select BLOB Table to File :: starting ... " );

        String sql = "SELECT PKCOL, PLN_BLOB, PLN_LENGTH, ENC_BLOB, ENC_LENGTH FROM ZCUBE_BLOB WHERE PKCOL IN (SELECT MAX (PKCOL) FROM ZCUBE_BLOB)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);
        rs = pstmt.executeQuery();

        /********************************************************************************************************
         * @ public static native byte[] codecbyte(String inval, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * byteDec = CubeOneAPI.codecbyte(new String(byteEnc),item,10,null,null,byteErr);
         ********************************************************************************************************/

        /********************************************************************************************************
         * @ public static native byte[] codecbytes(String inval, String item, int act, String jvTblName, String jvColName, byte[] err)
         * @
         * byteDec = CubeOneAPI.codecbytes(new String(byteEnc),item,10,null,null,byteErr);
         ********************************************************************************************************/

        /********************************************************************************************************
         * @ public static native byte[] codecbyteb(byte[] inval, int inval_l, String item, int act, String jvTblName, String jvColName, byte[] err
         * @
         * byteDec = CubeOneAPI.codecbyteb(byteEnc,byteEnc.length, item,10,null,null,byteErr);
         ********************************************************************************************************/

        while(rs.next())
        {
            pkcol = rs.getString("PKCOL");
            blobPln = rs.getBlob("PLN_BLOB");
            plnLen = rs.getString("PLN_LENGTH");
            blobEnc = rs.getBlob("ENC_BLOB");
            encLen = rs.getString("ENC_LENGTH");

            bytePln = blobPln.getBytes(1,(int)blobPln.length());
            byteEnc = blobEnc.getBytes(1,(int)blobEnc.length());

            byteDec = CubeOneAPI.codecbyteb(byteEnc,byteEnc.length, item,10,null,null,byteErr);

            fosDecFile = new FileOutputStream(new File(fileNm + ".dec"));
            fosDecFile.write(byteDec);
        } 

        System.out.println("<<< Select BLOB Table to File :: succeeded !!! " );
    }
}
