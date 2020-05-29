import java.sql.*;
import com.cubeone.CubeOneAPI;

public class co_han
{

    static String strUrl = "jdbc:oracle:thin:@192.168.1.11:1521:ORCL"; // URL 10g GA1
//    static String strUrl = "jdbc:oracle:thin:@192.168.1.9:1521:ORCL";  // URL 11g GA2

    static String strId = "scott";
    static String strPass = "one123";
    static Connection conn = null;
    static PreparedStatement pstmt = null;
    static ResultSet rs = null;

    static String strCol_pk;

    static String strCol_varchar2; 
    static String decCol_varchar2; 

    static String strCol_hangul; 
    static String decCol_hangul; 


    static long lngCol_number; 
    static String strCol_number; 
    static String decCol_number; 

    static String strCol_date; 
    static String decCol_date; 

    static String strFormat;

    static String strItem = "AES256" ;
    static byte[] bytErr = new byte[5];

    static String strPlainTable = "zcube_hangul";
    static String strEncTable   = "zcube_hangul#";

    static int intRandom;

    public static void main(String[] args) {

        System.out.println("################################################");
        System.out.println("###### CubeOne API SelfTest : JDBC TEST ########");
        System.out.println("################################################\n");
    
        System.out.println("<<< CubeLog :: [strUrl][id/pass] = [" + strUrl + "][" + strId + "/" + strPass + "]"); 
    
        CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100);
    
        try{
            Class.forName("oracle.jdbc.driver.OracleDriver"); // Load Jdbc Driver
            conn = DriverManager.getConnection(strUrl, strId, strPass); // Connect DB
    
            intRandom = (int) (Math.random()*100);
    
            selectEncTable();
            insertEncTable();
    
        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ############################################################");
            System.out.println(e.getMessage());
    
            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
                conn.close();
            } catch (Exception e) {
                // ignored ..       
                System.out.println("<<< CubeLog :: Finally ############################################################");
                System.out.println(e.getMessage());
            }
        }
    }
    
    static void selectEncTable() throws Exception {

        System.out.println("<<< [2] Select Enc Table  ");

        String sql = "SELECT col_pk, col_varchar2, col_hangul, col_date FROM " + strEncTable + " order by col_pk desc";
            
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        strFormat = String.format("|%-6s|%-25s|%-30s|%-44s|%-30s|", "col_pk", "col_date", "col_varchar2", "col_hangul", "col_hangul[dec]");
        System.out.println(strFormat);
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

        int intRownum = 0;                    
        while(rs.next()){ 
            strCol_pk = rs.getString("col_pk");  
            strCol_varchar2 = rs.getString("col_varchar2");  
            strCol_hangul = rs.getString("col_hangul");  

//            decCol_hangul = CubeOneAPI.codecchar(rs.getString("col_hangul"), strItem, 10, null, null, bytErr);  

            byte[] ret = CubeOneAPI.codecbyte(rs.getString("col_hangul"), strItem, 10, null, null, bytErr);  
            decCol_hangul = new String(ret,"EUC-KR");

            strCol_date = rs.getString("col_date");  

            strFormat = String.format("|%-6s|%-25s|%-30s|%-44s|%-30s|", strCol_pk, strCol_date, strCol_varchar2, strCol_hangul, decCol_hangul);
            System.out.println(strFormat);
                
            if(++intRownum > 10 ) break;
        }

        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    }


    static void insertEncTable() throws Exception {

        System.out.println("<<< [4] Insert Enc Table  ");
// ÇѱÛ 
        String hangul = "1234567890123abcdÇѱÛÇѱÛ";
//        byte[] bytehan = hangul.getBytes("KSC5601");
        byte[] bytehan = hangul.getBytes("EUC-KR");

        String sql = "INSERT INTO " + strEncTable + " (col_pk, col_varchar2, col_hangul, col_date)  VALUES( ?, ?, ?, sysdate)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, Integer.toString(intRandom));

        pstmt.setString(2, hangul);
        // hangul ========    
        //pstmt.setString(3,CubeOneAPI.coencchar(hangul,"AES256",11,null,null,bytErr));
        pstmt.setString(3, CubeOneAPI.coencbytes(bytehan,bytehan.length,"AES256",11,null,null,bytErr));

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n\n");
    }
}



