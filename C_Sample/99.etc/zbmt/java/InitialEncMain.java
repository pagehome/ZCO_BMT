
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.*;
import java.util.*;
import java.text.*;

import com.cubeone.*;


public class InitialEncMain {

    /**
     * CubeOne setting ...
     */
    String plain = "1234567890123";
    String encrypt = "" ;
    String decrypt = "" ;
    byte[] errbyte = new byte[5];
    int total = 5000000 ; 
    DecimalFormat df = new DecimalFormat("#,##0");

    String item = "AES256" ;
    int fetchSize, insertSize;
    double startTime, endTime, elapTime;
    
    public static void main(String[] args) {

        System.out.println("##########################################################################");
        System.out.println("########## BMT(TTA) CubeOne-API JDBC Testing-MultiThread(2015.06.17) #####");
        System.out.println("##########################################################################\n\n\n");

        //CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100);
        CubeOneAPI.jcoinit ("API");

        InitialEncMain encMain = new InitialEncMain();
        
        encMain.getParam();
        
        //encMain.basic();
        //encMain.speed();
        encMain.makeThread();
    }

    
    
    
    void makeThread() {

        Thread t1 = new InitialEncThread(item, fetchSize, insertSize,"      1 AND 1000000");
        t1.start();

/*
        Thread t1 = new InitialEncThread(item, fetchSize, insertSize,"      1 AND  500000");
        Thread t2 = new InitialEncThread(item, fetchSize, insertSize," 500001 AND 1000000");

        t1.start();
        t2.start();

/*        
        Thread t1 = new InitialEncThread(item, fetchSize, insertSize,"      1 AND  250000");
        Thread t2 = new InitialEncThread(item, fetchSize, insertSize," 250001 AND  500000");
        Thread t3 = new InitialEncThread(item, fetchSize, insertSize," 500001 AND  750000");
        Thread t4 = new InitialEncThread(item, fetchSize, insertSize," 750001 AND 1000000");

        t1.start();
        t2.start();
        t3.start();
        t4.start();
 */       
    
    }
    
    
    void getParam() {

        System.out.println("################################################");
        System.out.println("###### Param Setting  ##########################");
        System.out.println("################################################\n");

        
        Scanner scan = new Scanner(System.in);    

        System.out.print("[1] Input Item : ");
        item = scan.nextLine();            

        System.out.print("[2] Input FetchSize : ");
        fetchSize = scan.nextInt();            
        
        System.out.print("[3] Input insert Array Size : ");
        insertSize = scan.nextInt();           
        
        System.out.println("\n");
    }
 
    
    void basic() {

        System.out.println("####################################" );
        System.out.println("#### Basic-Test :: start ..... !!!" );
        System.out.println("####################################" );

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

        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

    }
    
    void speed() {

        System.out.println("####################################" );
        System.out.println("#### Speed-Test :: start ..... !!!" );
        System.out.println("####################################" );

        System.out.println("\n[1] Enc Speed ");
        startTime = System.currentTimeMillis();

        for(int i=0; i<total;i++) {
            encrypt = CubeOneAPI.coencchar(plain,item,11,null,null,errbyte);
        }
        endTime = System.currentTimeMillis();
        elapTime = (endTime - startTime) / 1000; //

        System.out.println("<<< CubeLog  :: elap_time = [" + String.valueOf(elapTime) + " sec]");
        System.out.println("<<< CubeLog  :: EncPerSec = [" + df.format(total/elapTime) + " cnt/sec]");

        System.out.println("<<< CubeLog  :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog  :: encrypt.length() = [" + encrypt.length() + "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[2] Dec Speed ");

        startTime = System.currentTimeMillis();
        for(int i=0; i<total;i++) {
            decrypt = CubeOneAPI.codecchar(encrypt,item,11,null,null,errbyte);
        }
        endTime = System.currentTimeMillis();
        elapTime = (endTime - startTime) / 1000; //

        System.out.println("<<< CubeLog :: elap_time = [" + String.valueOf(elapTime) + " sec]");
        System.out.println("<<< CubeLog :: DecPerSec = [" + df.format(total/elapTime) + " cnt/sec]");

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

        System.out.println("\n#### Speed-Test :: Success..... !!!\n\n" );
        
    }
    

}

