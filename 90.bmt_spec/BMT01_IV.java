
import java.sql.*;
import java.util.*;
import com.cubeone.*;


/**

암호문의 유추 해석 방지를 위해 데이타 암호화 시 IV 사용이 가능 할 것 ..

CREATE TABLE BMT01_IV
(
    COL_PLN VARCHAR(13) FIXED,
    COL_ENC VARCHAR(50) FIXED
)

 */
public class BMT01_IV {
    
//  String url = "jdbc:Altibase://192.168.1.11:20300/MYDB";  // Linux 
//  String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP

    String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP; 
    String driver = "Altibase.jdbc.driver.AltibaseDriver";
    String id = "xserver";
    String pass = "xserver";

    Connection conn = null;
    
    String col1, col2, col3, col4, col5;

    static String type, item;
    
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

        System.out.print("[1] Input Item : ");
        item = scan.nextLine();            
        
        System.out.print("[2] I(Insert), S(Select) : ");
        type = scan.nextLine();            
        
        scan.close();
        
        System.out.println("\n");

        // IV test
        BMT01_IV bmtFunction = new BMT01_IV();

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
        
        String sqlIns = "INSERT INTO BMT01_IV VALUES(?,?)"  ;

        System.out.println("<<< CubeLog :: sqlIns = [" + sqlIns + "]\n");

        try{
            
            Class.forName(driver);
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            psIns = conn.prepareStatement(sqlIns);
            
            for(int i=1; i<11; i++){ 
                loop++;
                
                psIns.setString(1, plain);
                psIns.setString(2, CubeOneAPI.coencchar(plain,item,11,null,null,errbyte));
                psIns.execute();

            }

            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptInsert) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - item : " + item);
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

        String sql = "SELECT COL_PLN, COL_ENC FROM BMT01_IV"  ;
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
                col2 = rs.getString(2);

                decrypt = CubeOneAPI.codecchar(rs.getString(2),item, 11,null,null,errbyte);

                System.out.println(col1 + "||" + col2 + "||" + decrypt);
            }

            
            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptSelect) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - item : " + item);
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

