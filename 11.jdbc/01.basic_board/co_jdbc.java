import java.sql.*;
import com.cubeone.CubeOneAPI;

public class co_jdbc
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
    /**************************************************************************************/

    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static String seq, writer, regno, subject, cnt, wrdate, format;
    static String decRegno;

    static String item = "AES256" ;
    static byte[] byteErr = new byte[5];

    static String plainTable = "ZCUBE_BOARD8";
    static String encTable = "ZCUBE_BOARD#";

    static int random;

    public static void main(String[] args) {

        System.out.println("################################################");
        System.out.println("###### CubeOne API SelfTest : JDBC TEST ########");
        System.out.println("################################################\n");

        System.out.println("<<< CubeLog :: [url][id/pass] = [" + url + "][" + id + "/" + pass + "]"); 

        try{
            Class.forName(driver); // Load Jdbc Driver
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            random = (int) (Math.random()*100);
            insertPlain();
            insertEncTable();

            selectPlain();
            selectEncTable();

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
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
    }

    static void selectPlain() throws Exception {

        System.out.println("<<< [1] Select Plain  ");

        String sql = "SELECT SEQ, WRITER, REGNO, SUBJECT, CNT, CONTENTS, WRDATE FROM " + plainTable + " ORDER BY SEQ DESC";
            
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("----------------------------------------------------------------------------------------");
        format = String.format("|%-3s|%-10s|%-30s|%-10s|%-30s|", "Seq", "Writer", "Regno", "Subject", "Wrdate");
        System.out.println(format);
        System.out.println("----------------------------------------------------------------------------------------");

        int rownum = 0;                    
        while(rs.next()){ 
            seq = rs.getString("seq");  
            writer = rs.getString("writer");  
            regno = rs.getString("regno");  
            subject = rs.getString("subject");  
            cnt = rs.getString("cnt");  
            wrdate = rs.getString("wrdate");  

            format = String.format("|%-3s|%-10s|%-30s|%-10s|%-30s|", seq, writer, regno, subject, wrdate);
            System.out.println(format);
            
            if(++rownum > 10 ) break;

        }
        System.out.println("----------------------------------------------------------------------------------------\n\n");
    }

    static void selectEncTable() throws Exception {

        System.out.println("<<< [2] Select Enc Table  ");

        String sql = "SELECT SEQ, WRITER, REGNO, SUBJECT, CNT, CONTENTS, WRDATE FROM " + encTable + " ORDER BY SEQ DESC";
        
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("--------------------------------------------------------------------------------------------------------------");
        format = String.format("|%-3s|%-10s|%-30s|%-20s|%-10s|%-30s|", "Seq", "Writer", "Regno(Enc)","Regno(Dec)", "Subject", "Wrdate");
        System.out.println(format);
        System.out.println("--------------------------------------------------------------------------------------------------------------");
                
        int rownum = 0;                    
        while(rs.next()){ 
            seq = rs.getString("seq");  
            writer = rs.getString("writer");  
            regno = rs.getString("regno");  
            subject = rs.getString("subject");  
            cnt = rs.getString("cnt");  
            wrdate = rs.getString("wrdate");  

            decRegno = CubeOneAPI.codecchar(regno, item, 11, null, null, byteErr);
 
            format = String.format("|%-3s|%-10s|%-30s|%-20s|%-10s|%-30s|", seq, writer, regno,decRegno, subject, wrdate);
            System.out.println(format);

            if(++rownum > 10 ) break;
        }
        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n");
    }

    static void insertPlain() throws Exception {

        System.out.println("<<< [3] Insert Plain Table  ");

        String sql = "INSERT INTO " + plainTable + " VALUES((SELECT NVL(MAX(SEQ),0)+1 FROM " + plainTable + " ) , ?, ?, ?, 1, ?,SYSDATE)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, "wri000" + random);
        pstmt.setString(2, "reg000" + random);
        pstmt.setString(3, "sbj000" + random);
        pstmt.setString(4, "cnt000" + random);

        System.out.println(" - [wri000" + random + "],[reg000" + random + "],[sbj000" + random + "],[cnt000" + random + "]");

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n");
    }


    static void insertEncTable() throws Exception {

        System.out.println("<<< [4] Insert Enc Table  ");

        String sql = "INSERT INTO " + encTable + " VALUES((SELECT NVL(MAX(SEQ),0)+1 FROM " + encTable + " ) , ?, ?, ?, 1, ?,SYSDATE)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);

        pstmt.setString(1, "wri000" + random);
        pstmt.setString(2, CubeOneAPI.coencchar("reg000" + random,item,10, null, null, byteErr));
        pstmt.setString(3, "sbj000" + random);
        pstmt.setString(4, "cnt000" + random);

        System.out.println(" - [wri000" + random + "],[reg000" + random + "],[sbj000" + random + "],[cnt000" + random + "]");

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n");
    }
}


