import java.io.BufferedReader;
import java.io.InputStreamReader;
import com.cubeone.CubeOneAPI;

public class co_prompt {
    public static  void main(String args[]) {
        String encOut = "";
        String decOut = "";
        String plain = "", encrypt = "";
        String menu = "";
        String item = "AES256";

        byte[] errbyte = new byte[5];

        System.out.println( "**********************************");
        System.out.println( "**  CubeOne Test List       ******");
        System.out.println( "**********************************");
        System.out.println( "**  1. Input Item           ******");
        System.out.println( "**  2. Encrypt Test         ******");
        System.out.println( "**  3. Decrypt Test         ******");
        System.out.println( "**  4. Encrypt(EUC_KR) Test ******");
        System.out.println( "**  5. Decrypt(EUC_KR) Test ******");
        System.out.println( "**  9. Exit                 ******");
        System.out.println( "**********************************");

        try {
            while(true)
            {

                BufferedReader brMenu = new BufferedReader(new InputStreamReader(System.in));
                System.out.print(" Select Test List[1-9] : "); 
                menu = brMenu.readLine();

                if (menu.equals("9"))  {
                    System.out.println("  - Terminiate this test progrom !!! \n");
                    System.exit(0);
                } 

                // Item 
                else if (menu.equals("1"))  {
                    BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                    System.out.print("  - Input Item  : ");
                    item = brStr.readLine();
                    System.out.println("");
                } 
                
                // Encrypt
                else if (menu.equals("2"))  {
                    BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                    System.out.print("  - Input Plain [ ITEM = " + item + " ]  : ");
                    plain = brStr.readLine();
                    System.out.println("  - strlen(plain) = " + plain.length());

                    encOut = CubeOneAPI.coencchar(plain, item, 11, null, null, errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                       System.out.println("  - encrypt = ["+encOut+"]");
                       System.out.println("  - strlen(encrypt) = "+encOut.length());
                    }else {
                       System.out.println("  ** Encryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                } 
                 
                // Decrypt
                else if (menu.equals("3"))  {
                    BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                    System.out.print("  - Input Encrypt [ ITEM = " + item + " ]  : ");
                    encrypt = brStr.readLine();
                    decOut = CubeOneAPI.codecchar(encrypt, item, 10, null, null, errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                        System.out.println("  - decrypt = ["+decOut+"]");
                        System.out.println("  - strlen(decrypt) = "+decOut.length());
                    }else {
                        System.out.println("  ** Decryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                }

/*******************************/

                // Encrypt Byte : for Hangul
                else if (menu.equals("4"))  {
                    BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in,"EUC-KR"));
                    System.out.print("  - Input Plain [ ITEM = " + item + " ]  : ");
                    plain = brStr.readLine();
                    System.out.println("  - strlen(plain) = " + plain.length());

                    byte[] bytehan = plain.getBytes("EUC-KR");
                    encOut = CubeOneAPI.coencbytes(bytehan,bytehan.length,item,11,"TBL","COL",errbyte);

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                       System.out.println("  - encrypt = ["+encOut+"]");
                       System.out.println("  - strlen(encrypt) = "+encOut.length());
                    }else {
                       System.out.println("  ** Encryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                } 
                 
                // Decrypt Byte :  for Hangul
                else if (menu.equals("5"))  {
                    BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                    System.out.print("  - Input Encrypt [ ITEM = " + item + " ]  : ");
                    encrypt = brStr.readLine();

                    byte[] ret = CubeOneAPI.codecbyte(encrypt,item,11,null,null,errbyte);
                    decOut = new String(ret,"EUC-KR");

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                        System.out.println("  - decrypt = ["+decOut+"]");
                        System.out.println("  - strlen(decrypt) = "+decOut.length());
                    }else {
                        System.out.println("  ** Decryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                }
/*******************************/
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
