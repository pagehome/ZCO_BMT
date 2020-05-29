
import java.sql.*;
import java.util.*;
import com.cubeone.*;


/**

컬럼단위로 암호화 설정 가능하며 암호화 데이터 검증
컬럼 별 AES/ARIA/SEED/SHA 알고리즘 적용 가능 ...

CREATE TABLE BMT02_COL
(
    COL_PLN VARCHAR(13) ,
    COL_AES VARCHAR(50) , 
    COL_ARIA VARCHAR(50) , 
    COL_SEED VARCHAR(50) , 
    COL_SHA VARCHAR(128)  
)


 */
public class BMT02_COL {
    
//  String url = "jdbc:Altibase://192.168.1.11:20300/MYDB";  // Linux 
//  String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP

    String url = "jdbc:Altibase://192.168.1.220:20300/MYDB"; // HP; 
    String driver = "Altibase.jdbc.driver.AltibaseDriver";
    String id = "xserver";
    String pass = "xserver";

    Connection conn = null;
    
    String col1, col2, col3, col4, col5;

    static String type, item;
    
    String itemAES = "AES256";
    String itemARIA = "ARIA256";
    String itemSEED = "SEED";
    String itemSHA = "SHA256";
    
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
        BMT02_COL bmtFunction = new BMT02_COL();

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
        
        String sqlIns = "INSERT INTO BMT02_COL VALUES(?,?,?,?,?)"  ;

        System.out.println("<<< CubeLog :: sqlIns = [" + sqlIns + "]\n");

        try{
            
            Class.forName(driver);
            conn = DriverManager.getConnection(url, id, pass); // Connect DB

            psIns = conn.prepareStatement(sqlIns);
            
            for(int i=1; i<10; i++){ 
                loop++;

                plain = i + "00000000";
/*
                System.out.println("<<< CubeLog :: plain = [" + plain + "]\n");
                System.out.println("<<< CubeLog :: itemAES = [" + CubeOneAPI.coencchar(plain,itemAES,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemARIA = [" + CubeOneAPI.coencchar(plain,itemARIA,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemSEED = [" + CubeOneAPI.coencchar(plain,itemSEED,11,null,null,errbyte) + "]\n");
                System.out.println("<<< CubeLog :: itemSHA = [" + CubeOneAPI.coencchar(plain,itemSHA,11,null,null,errbyte) + "]\n");
*/                
                psIns.setString(1, plain);
                psIns.setString(2, CubeOneAPI.coencchar(plain,itemAES,11,null,null,errbyte));
                psIns.setString(3, CubeOneAPI.coencchar(plain,itemARIA,11,null,null,errbyte));
                psIns.setString(4, CubeOneAPI.coencchar(plain,itemSEED,11,null,null,errbyte));
                psIns.setString(5, CubeOneAPI.coencchar(plain,itemSHA,11,null,null,errbyte));
                
                psIns.execute();

            }

            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptInsert) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - itemAES : " + itemAES);
            System.out.println(" - itemARIA : " + itemARIA);
            System.out.println(" - itemSEED : " + itemSEED);
            System.out.println(" - itemSHA : " + itemSHA);
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

        String sql = "SELECT COL_PLN,COL_AES,COL_ARIA,COL_SEED,COL_SHA FROM BMT02_COL"  ;
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

                col2 = CubeOneAPI.codecchar(rs.getString(2),itemAES, 11,null,null,errbyte);
                col3 = CubeOneAPI.codecchar(rs.getString(3),itemARIA, 11,null,null,errbyte);
                col4 = CubeOneAPI.codecchar(rs.getString(4),itemSEED, 11,null,null,errbyte);

                System.out.println(col1 + "||" + rs.getString(2) + "||" + col2 + "||" + "||" + rs.getString(3) + col3 + "||" + "||" + rs.getString(4) + col4 + "||" );
            }

            
            System.out.println("----------------------------------------");
            System.out.println("-------- RESULT(encryptSelect) ---------");
            System.out.println("----------------------------------------");
            System.out.println(" - itemAES : " + itemAES);
            System.out.println(" - itemARIA : " + itemARIA);
            System.out.println(" - itemSEED : " + itemSEED);

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

