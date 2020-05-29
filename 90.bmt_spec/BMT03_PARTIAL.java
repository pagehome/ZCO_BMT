
import java.sql.*;
import java.util.*;
import com.cubeone.*;


/**

부분 암호화 지원

CREATE TABLE BMT03_PARTIAL
(
    COL_PLN VARCHAR(13) ,
    COL_FRONT VARCHAR(50) , 
    COL_BACK VARCHAR(50)  
)


 */
public class BMT03_PARTIAL {
    
//  String url = "jdbc:Altibase://192.168.1.11:20300/MYDB";  // Linux 
//  String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP

    String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP; 
    String driver = "Altibase.jdbc.driver.AltibaseDriver";
    String id = "xserver";
    String pass = "xserver";

    Connection conn = null;
    
    String col1, col2, col3, col4, col5;

    static String type, item;
    
    String itemFront = "ARIA256_LN";
    String itemBack = "ARIA256_RN";
    
    /**
     * CubeOne setting ...
     */
    String plain = "1234567890123";
    String encrypt = "" ;
    String decrypt = "" ;
    byte[] errbyte = new byte[5];
    
    public static void main(String[] args) {

        System.out.println("##############################################################");
        System.out.println("########## BMT(TTA) IV Insert / Select  ######################");
        System.out.println("##############################################################\n\n\n");
        
        // get CubeOne Policy ..
        CubeOneAPI.jcoinit ("API");
//      bmtFunction.basic();

        // get Parameter
        Scanner scan = new Scanner(System.in);    
        
        System.out.print("[1] I(Insert), S(Select) : ");
        type = scan.nextLine();            
        
        scan.close();
        
        System.out.println("\n");

        // IV test
        BMT03_PARTIAL bmtFunction = new BMT03_PARTIAL();

        if("I".equals(type)) bmtFunction.encryptInsert();
        else bmtFunction.encryptSelect();            
    }

    void encryptInsert() {

        System.out.println("************************************************");
        System.out.println("*** CubeOneAPI Encrypt Insert Test *************");
        System.out.println("************************************************\n");

        System.out.println("<<< CubeLog :: Connection = [" + url + "][" + id + "/" + pass + "]"); 
        
        PreparedStatement psIns = null;
        int loop = 0;
        
        String sqlIns = "INSERT INTO BMT03_PARTIAL VALUES(?,?,?)"  ;

        System.out.println("<<< CubeLog :: sqlIns = [" + sqlIns + "]\n");

        try{
            
            Class.forName(driver);
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            psIns = conn.prepareStatement(sqlIns);
            
            for(int i=1; i<10; i++){ 
                loop++;

                plain = i + "00000000000" + i;
/*
                System.out.println("<<< CubeLog :: plain = [" + plain + "]\n");
                System.out.println("<<< CubeLog :: itemAES = [" + CubeOneAPI.coencchar(plain,itemAES,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemARIA = [" + CubeOneAPI.coencchar(plain,itemARIA,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemSEED = [" + CubeOneAPI.coencchar(plain,itemSEED,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemSHA = [" + CubeOneAPI.coencchar(plain,itemSHA,11,null,null,errbyte) + "]\n");
*/                
                psIns.setString(1, plain);
                psIns.setString(2, CubeOneAPI.coencchar(plain,itemFront,11,null,null,errbyte));
                psIns.setString(3, CubeOneAPI.coencchar(plain,itemBack,11,null,null,errbyte));
                
                psIns.execute();

            }

            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptInsert) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - itemFront : " + itemFront);
            System.out.println(" - itemBack : " + itemBack);
            System.out.println(" - Success Count : " + loop);
            
        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");
            e.printStackTrace();
        } finally {
            try {
                psIns.close();
                conn.close();
            } catch (Exception e) {
                // ignored ..       
                System.out.println("<<< CubeLog :: Finally ************************************************************");
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
    }
    
    void encryptSelect() {
        
        System.out.println("************************************************");
        System.out.println("****** CubeOneAPI Encrypt Select Test   ********");
        System.out.println("************************************************\n");
        
        System.out.println("<<< CubeLog :: Connection = [" + url + "][" + id + "/" + pass + "]"); 

        PreparedStatement pstmt = null;
        ResultSet rs = null;

        String sql = "SELECT COL_PLN,COL_FRONT,COL_BACK FROM BMT03_PARTIAL"  ;
        System.out.println("<<< CubeLog :: sql = [" + sql + "]");

        try{

            Class.forName(driver);
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            pstmt = conn.prepareStatement(sql);        
            rs = pstmt.executeQuery();

            System.out.println("--------------------------------------------------------------------------------------------------------------");

            int loop = 0;
            
            while(rs.next()){ 
                loop++;
                col1 = rs.getString(1);  

                col2 = CubeOneAPI.codecchar(rs.getString(2),itemFront, 11,null,null,errbyte);
                col3 = CubeOneAPI.codecchar(rs.getString(3),itemBack, 11,null,null,errbyte);

                System.out.println(col1 + "||" + rs.getString(2) + "||" + col2 + "||"  + rs.getString(3) + "||" + col3  );
            }

            
            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptSelect) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - itemFront : " + itemFront);
            System.out.println(" - itemBack : " + itemBack);
            System.out.println(" - Total Count : " + loop);

            
        } catch (Exception e) {
            System.out.println("<<< CubeLog :: Exception ************************************************************");
            System.out.println("msg = [" + e.getMessage() + "]");

            e.printStackTrace();
        } finally {
            try {
                rs.close();
                pstmt.close();
            } catch (Exception e) {
                // ignored ..       
                System.out.println("<<< CubeLog :: Finally ************************************************************");
                System.out.println("msg = [" + e.getMessage() + "]");
                e.printStackTrace();
            }
        }
        
    }
        
    void basic() {

        System.out.println("************************************" );
        System.out.println("**** Basic-Test :: start ..... !!!" );
        System.out.println("************************************" );

        System.out.println("\n<<< CubeLog :: ITEM = [" + item + "]");

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");

        System.out.println("\n[2] Enc Test ");

        encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        if(!"00000".equals(new String(errbyte))) {
            System.exit(1);
        }
        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(encrypt,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

        
        if(!"00000".equals(new String(errbyte))) {
            System.exit(1);
        }

        System.out.println("\n**** Basic-Test :: Success..... !!!\n\n" );

    }
}

