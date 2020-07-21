
import java.io.*;
import java.text.*;
import com.cubeone.*;
import java.util.*;

public class EnvCheck {

    static String plain = "1234567890123";
    static String encrypt = "" ;
    static String decrypt = "" ;
    static String item = "AES256" ;

    static byte[] errbyte = new byte[5];
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub

        
        System.out.println("########################################################");
        System.out.println("#########  CubeOneAPI-JAVA Self Test Program ###########");
        System.out.println("########################################################\n");
        

        CubeOneAPI.coinit (1, "API", "SA", "","","","","","","",100);

        testEnv();
        basic();
        
    }

    static void testEnv() {
        
        String dirAdm = "/var/adm/.cube/env.dat";
        String dirData="", dirEventlog="";
        
        String line="";
        String[] arrToken;
        String separator = "=";
        
        BufferedReader brAdm = null;
        BufferedWriter bwEventlog = null;
        BufferedReader brDataFile = null;
        
        try {
            brAdm = new BufferedReader(new FileReader(dirAdm));

            while ((line = brAdm.readLine()) != null) {
                arrToken = line.split(separator);
                
                if("COEVENTLOG".equalsIgnoreCase(arrToken[0])) {
                    dirEventlog = arrToken[1];
                    
                } else if("CODATADIR".equalsIgnoreCase(arrToken[0])) {
                    dirData = arrToken[1];
                }
            }
            
            System.out.println(dirData);
            System.out.println(dirEventlog);
            
            // event_log write ..
            bwEventlog = new BufferedWriter(new FileWriter(dirEventlog,true));
            PrintWriter pw = new PrintWriter(bwEventlog,true);
            pw.write("**** Write Log Test ****\n");
            pw.flush();
            pw.close();
            
            // data folder read 
            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_MSG"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }

            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_Q1"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }
            
            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_Q2"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }
            
            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_SEM"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }

            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_SEM_CLIENT"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }

            brDataFile = new BufferedReader(new FileReader(dirData + "/KEYFILE_SHM"));
            while ((line = brDataFile.readLine()) != null) {
            	System.out.println(line);
            }

            
            
            
            
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    
    static void basic() {

        System.out.println("####################################" );
        System.out.println("#### Basic-Test :: start ..... !!!" );
        System.out.println("####################################" );

        System.out.println("\n<<< CubeLog :: ITEM = [" + item + "]");

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");

        System.out.println("\n[2] Enc Test ");

        encrypt = CubeOneAPI.coencchar(plain,item,1,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(encrypt,item,1,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

    }
}
