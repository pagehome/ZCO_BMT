import java.sql.*;
import com.cubeone.CubeOneAPI;
import java.text.*;
import java.util.*;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.IOException;

public class co_clob {
    static String strUrl = "jdbc:oracle:thin:@192.168.1.213:1521:ORA11"; // URL
    static String strDriver = "oracle.jdbc.driver.OracleDriver";
    static String strId = "scott";
    static String strPass = "tiger";

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static byte[] errbyte = new byte[5];
    static String item = "AES256";

    public static void main(String[] args) {
        System.out.println("################################################");
        System.out.println("###### CubeOne API SelfTest : JDBC TEST ########");
        System.out.println("################################################\n");

        System.out.println("<<< CubeLog :: [strUrl][id/pass] = [" + strUrl + "][" + strId + "/" + strPass + "]");
        System.out.println("<<< CubeLog :: DB connection waiting ....");

        try {
            Class.forName(strDriver); // Load Jdbc Driver
            conn = DriverManager.getConnection(strUrl, strId, strPass); // Connect
                                                                        // DB
            System.out.println("<<< CubeLog :: DB connection completed .... \n");

            insertClob();
            //selectClob();

        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ############################################################");
            System.out.println("msg = [" + e.getMessage() + "]");
            e.printStackTrace();
        } finally {
            try {
                conn.close();
            } catch (Exception e) {
                System.out.println("<<< CubeLog :: Finally ############################################################");
                e.printStackTrace();
            }
        }
    }

    static void selectClob() throws Exception {
        InputStream in = null;
        byte[] buffer;
        int count = 0;
        byte[] encblob;
        String clobstr;

        System.out.println("\n<<< [2] Select CLOB Table :: ================== ");
        String sql = "SELECT ENC_CLOB FROM ZCUBE_CLOB1 ";
        //String sql = "SELECT COL_BLOB FROM test03_01_01# ";

        pstmt = conn.prepareStatement(sql);
        rs = pstmt.executeQuery();

        while (rs.next()) {
            clobstr = CubeOneAPI.codecchar(rs.getString(1), item, 10, "", "", errbyte);
            if (errbyte[0] == 50) {
                System.out.println("[" + item + "] [" + new String(errbyte) + "]");
            } else {
                System.out.println("[" + item + "] length=[" + clobstr.length() + "] [" + new String(errbyte) + "]");
            }
        }
    }

    static void insertClob() throws Exception {
        StringBuffer lob = new StringBuffer();
        String plain, encrypt;
        byte[] bytePln, byteEnc;

        // for(int i=0; i<500000; i++) { // ORACLE
        for (int i = 0; i < 1000; i++) {
            lob.append(i);
            lob.append("twinkle twinkle little star, How I wonder what you are, up above the world so high, like a diamond in the sky,twinkle twinkle little star, How I wonder what you are\n");
        }
        plain = lob.toString();
        //System.out.println("<<< CubeLog :: lob.capacity() =  " + lob.capacity());
        //System.out.println("<<< CubeLog :: plain.length() =  " + plain.length());

        encrypt = CubeOneAPI.coencchar(plain, item, 10, null, null, errbyte);
        if (errbyte[0] == 50) {
            System.out.println("[" + item + "] [" + new String(errbyte) + "]\n");
        } else {
            System.out.println("<<< [1] Insert CLOB Table :: ================== ");
            String sql = "INSERT INTO zcube_clob VALUES((SELECT NVL(MAX(pkcol)+1,1) FROM zcube_clob),?,?,?,?,?)";
            System.out.println(" - sql = [" + sql + "]");
            try {
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, "encrypt");
                pstmt.setString(2, plain);
                pstmt.setInt(3, plain.length());
                pstmt.setString(4, encrypt);
                pstmt.setInt(5, encrypt.length());
                pstmt.executeUpdate();
            } catch( SQLException e) {
                e.printStackTrace();
            }
        System.out.println("<<< CubeLog :: encrypt.length() =  " + encrypt.length());
            System.out.println(" insert end. ");
        }
    }
}
