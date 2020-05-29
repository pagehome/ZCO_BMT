import java.sql.*;
import com.cubeone.CubeOneAPI;

public class co_han
{

    static String url = "jdbc:oracle:thin:@192.168.1.59:1535:ORCL"; // URL 10g GA1
    // static String url = "jdbc:oracle:thin:@192.168.1.45:1535:ORCL";  // URL 11g GA2
    static String driver = "oracle.jdbc.driver.OracleDriver";
    static String id = "scott";
    static String pass = "tiger";

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

    //static String item = "AES_PART" ;
    static String item = "AES256" ;
    static byte[] bytErr = new byte[5];

    static String strPlainTable = "zcube_hangul";
    static String strEncTable   = "zcube_hangul#";

    static int intRandom;

    public static void main(String[] args) {

        System.out.println("################################################");
        System.out.println("###### CubeOne API SelfTest : JDBC TEST ########");
        System.out.println("################################################\n");
    
        System.out.println("<<< CubeLog :: [url][id/pass] = [" + url + "][" + id + "/" + pass + "]"); 
    
        try{
            Class.forName(driver); // Load Jdbc Driver
            conn = DriverManager.getConnection(url, id, pass); // Connect DB
    
            intRandom = (int) (Math.random()*100);
    
            //selEnc();
            insEnc();
    
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
    
    static void selEnc() throws Exception {

        System.out.println("<<< [2] Select Enc Table  ");

        // String sql = "SELECT col_pk, col_varchar2,UTL_RAW.CAST_TO_RAW(col_hangul) as  col_hangul, col_date FROM " + strEncTable + " where col_pk = 2 order by col_pk asc";
        String sql = "SELECT col_pk, col_varchar2,UTL_RAW.CAST_TO_RAW(col_hangul) as  col_hangul, col_date FROM zcube_hangul# WHERE col_pk = 2 order by col_pk asc";
        // String sql = "SELECT col_pk, col_varchar2,RAWTOHEX(col_hangul) as  col_hangul, col_date FROM zcube_hangul# WHERE col_pk < 20 order by col_pk asc";
        // String sql = "SELECT col_pk, col_varchar2,col_hangul, col_date FROM zcube_blob_han WHERE col_pk < 20 order by col_pk asc";
            
        pstmt = conn.prepareStatement(sql);        
        rs = pstmt.executeQuery();

        System.out.println(" - sql = [" + sql + "]");
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        strFormat = String.format("|%-6s|%-25s|%-30s|%-44s|%-30s|", "col_pk", "col_date", "col_varchar2", "col_hangul", "col_hangul[dec]");
        System.out.println(strFormat);
        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

        int intRownum = 0;                    

        byte[] byteEnc ;


        Blob encBlob;

        while(rs.next()){ 
            strCol_pk = rs.getString("col_pk");  
            strCol_varchar2 = rs.getString("col_varchar2");  

            strCol_hangul = rs.getString("col_hangul");  
            byteEnc = strCol_hangul.getBytes(); 

/*
            encBlob = rs.getBlob("col_hangul"); 
            byteEnc = encBlob.getBytes(1,(int)encBlob.length());
*/

//            byteEnc = rs.getBytes("col_hangul");

   for ( int i =0; i < byteEnc.length ; i++){
           System.out.print(byteEnc[i]+",");
   }


        System.out.println("<<< CubeLog :: byteEnc.length = [" + byteEnc.length+ "]");
        System.out.println("<<< CubeLog :: new String(byteEnc) = [" + new String(byteEnc) + "]");




            byte[] byteDec = CubeOneAPI.codecbyteb(byteEnc, byteEnc.length, item, 10, null, null, bytErr);  
            decCol_hangul = new String(byteDec,"EUC-KR");

     
            strCol_date = rs.getString("col_date");  

            strFormat = String.format("|%-6s|%-25s|%-30s|%-44s|%-30s|", strCol_pk, strCol_date, strCol_varchar2, strCol_hangul, decCol_hangul);
            System.out.println(strFormat);
                
            if(++intRownum > 10 ) break;
        }

        System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    }


    static void insEnc() throws Exception {

        System.out.println("<<< [4] Insert Enc Table  ");
//  
       String hangul = "일이삼사오육칠팔구";
//        String hangul = "1234567890123";
//      byte[] bytehan = hangul.getBytes("KSC5601");
//        byte[] bytehan = hangul.getBytes("EUC-KR");
        byte[] bytehan = hangul.getBytes();

        System.out.println("<<< CubeLog :: hangul.length() = [" + hangul.length()+ "]");
        System.out.println("<<< CubeLog :: hangul.getBytes(\"EUC-KR\") = [" + hangul.getBytes("EUC-KR").length+ "]");
        System.out.println("<<< CubeLog :: hangul.getBytes(\"UTF-8\") = [" + hangul.getBytes("UTF-8").length+ "]");
        System.out.println("<<< CubeLog :: hangul.getBytes() = [" + hangul.getBytes().length+ "]");

        String sql = "INSERT INTO " + strEncTable + " (col_pk, col_varchar2, col_hangul, col_date)  VALUES( ?, ?, ?, sysdate)";
        System.out.println(" - sql = [" + sql + "]");

        pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, Integer.toString(intRandom));

        pstmt.setString(2, hangul);
        // hangul ========    
        //pstmt.setString(3,CubeOneAPI.coencchar(hangul,item,11,null,null,bytErr));
        pstmt.setString(3, CubeOneAPI.coencbytes(bytehan,bytehan.length,item,11,null,null,bytErr));

        pstmt.executeUpdate();

        System.out.println("--------------------------------------------------------------------------------------------------------------\n\n\n");
    }
}



