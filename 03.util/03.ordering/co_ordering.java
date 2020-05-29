/*
20007    No Privileges to access encrypted column    COER_NOTALLOWEDS
20008    Item is not specified                       COER_NOITEM_ENTEREDS
20009    Fail to get OCI Environment                 COER_FAIL_GET_OCIENVS
20010    Fail to Enabling Lob Buffering              COER_FAIL_ENABLE_BUFFERINGS
20011    Fail to treat Lob data                      COER_FAIL_LOBS
20012    Fail to Decrypt Lob data                    COER_FAIL_DEC_LOBS
20013    Fail to Encrypt Lob data                    COER_FAIL_ENC_LOBS
20014    Fail to Encryption data                     COER_FAIL_ENCRYPTIONS
20015    Fail to Encryption self testing             COER_FAIL_SELFTESTS
20016    Fatal error so should exception             COER_FATAL_ERROR
20017    error when check Initialize.                COER_FAIL_INIT
20018    error when check double enc.                COER_DOUBLE_CHECK

20021    error when SHMOpen file open.               COER_SHMFILEOPEN
20022    error when SHMOpen ftok.                    COER_SHMFTOK
20023    error when SHMOpen shmget.                  COER_SHMGETNORMAL
20024    error when SHMOpen shmget ENPSPC.           COER_SHMGETNOSPC
20025    error when SHMOpen shmget ENOMEM.           COER_SHMGETNOMEM
20031    error when shmat EMFILE.                    COER_SHMATEMFILE
20032    error when shmat ENOMEM.                    COER_SHMATENOMEM
20033    error when shmat EINVAL.                    COER_SHMATEINVAL
20034    error for Admin Act.: Ver 2.5-9021-C        COER_ADMINACTION
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import com.cubeone.CubeOneAPI;

public class co_ordering {
    public static  void main(String args[]) {
        String sEncOut = "";
        String sDecOut = "";
        String sPlain = "", encrypt = "";
        String nMenu = "";
        String item = "";

        byte[] errbyte = new byte[5];

        System.out.println( "********************************");
        System.out.println( "**  CubeOne Test List     ******");
        System.out.println( "********************************");
        System.out.println( "**  1. Input Item         ******");
        System.out.println( "**  2. Encrypt(coencchar)  *****");
        System.out.println( "**  3. coindexchar Test    *****");
        System.out.println( "**  4. coindexcharsel Test *****");
        System.out.println( "**  9. Exit               ******");
        System.out.println( "********************************");

        try {
            while(true)
            {

                BufferedReader brMenu = new BufferedReader(new InputStreamReader(System.in));
                BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                System.out.print(" Select Test List[1-9] : "); 
                nMenu = brMenu.readLine();

                if (nMenu.equals("9"))  {
                    System.out.println("  - Terminiate this test progrom !!! \n");
                    System.exit(0);
                } 

                // Item 
                else if (nMenu.equals("1"))  {
                    System.out.print("  - Input Item  : ");
                    item = brStr.readLine();
                    System.out.println("");
                } 
                
                // Encrypt
                else if (nMenu.equals("2"))  {
                    System.out.print("  - Input Plain [ ITEM = " + item + " ]  : ");
                    sPlain = brStr.readLine();
                    sEncOut = CubeOneAPI.coencchar(sPlain, item, 11, null, null, errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                       System.out.println("  - encrypt = ["+sEncOut+"]");
                       System.out.println("  - strlen(encrypt) = "+sEncOut.length());
                    }else {
                       System.out.println("  ** Encryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                 } 
                 
                // coindexchar
                else if (nMenu.equals("3"))  {
                    System.out.print("  - Input Encrypt [ ITEM = " + item + " ]  : ");
                    encrypt = brStr.readLine();
                    sDecOut = CubeOneAPI.coindexchar(encrypt, item, null, null, errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                        System.out.println("  - result = ["+sDecOut+"]");
                        System.out.println("  - strlen(coindexchar) = "+sDecOut.length());
                    }else {
                        System.out.println("  ** coindexchar Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                }

                // coindexcharsel
                else if (nMenu.equals("4"))  {
                    System.out.print("  - Input Plain [ ITEM = " + item + " ]  : ");
                    sPlain = brStr.readLine();
                    sDecOut = CubeOneAPI.coindexcharsel(sPlain, item, null, null, errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                        System.out.println("  - result = ["+sDecOut+"]");
                        System.out.println("  - strlen(decrypt) = "+sDecOut.length());
                    }else {
                        System.out.println("  ** coindexchar Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                }


                else {
                    System.out.println("  ** Choose 1,2,3,9 \n");
                }
            }
        }
            catch (Exception e) {
            e.printStackTrace();
        }
    }
}
