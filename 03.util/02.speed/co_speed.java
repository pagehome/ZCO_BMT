


import java.io.*;
import java.text.*;
import java.util.*;

import com.cubeone.CubeOneAPI;

public class co_speed {


    public static  void main(String args[]) {

        String encrypt = "", decrypt = "", plain = "";
        String menu = "", item = "AES256";
        byte[] errbyte = new byte[5];

        long startTime, endTime, elapTime;
        DecimalFormat dfComma = new DecimalFormat("#,##0");
        int loop = 5000000;

        System.out.println( "********************************");
        System.out.println( "**  CubeOne Test List     ******");
        System.out.println( "********************************");
        System.out.println( "**  1. Input Item         ******");
        System.out.println( "**  2. Loop Count         ******");
        System.out.println( "**  3. Encrypt Speed      ******");
        System.out.println( "**  4. Decrypt Speed      ******");
        System.out.println( "**  9. Exit               ******");
        System.out.println( "********************************");

        try {
            while(true)
            {

                BufferedReader brMenu = new BufferedReader(new InputStreamReader(System.in));
                BufferedReader brStr = new BufferedReader(new InputStreamReader(System.in));
                System.out.print(" Select Test List[1-9] : "); 
                menu = brMenu.readLine();

                if (menu.equals("9"))  {
                    System.out.println("  - Terminiate this test progrom !!! \n");
                    System.exit(0);
                } 

                // Item 
                else if (menu.equals("1"))  {
                    System.out.print("  - Input Item  : ");
                    item = brStr.readLine();
                    System.out.println("");
                } 

                // Loop Cnt 
                else if (menu.equals("2"))  {
                    System.out.print("  - Loop Count  : ");
                    loop = Integer.parseInt(brStr.readLine());
                    System.out.println("");
                } 

                // Encrypt
                else if (menu.equals("3"))  {

                    if(loop < 10000) {
                        System.out.print("  - Loop Count [ " + loop + " ] is too small \n\n");
                        continue;
                    }

                    System.out.print("  - Input Plain [ ITEM = " + item + " ]  : ");
                    plain = brStr.readLine();

                    System.out.print("  - Loop Count [ " + dfComma.format(loop) + " ] : starting !! \n");
                    startTime = System.currentTimeMillis();
                    for(int i=0; i<loop; i++) {
                        encrypt = CubeOneAPI.coencchar(plain,item,11,null,null,errbyte);

                        /*
                        if(!"00000".equals(new String(errbyte))) {
                            System.out.println(new String(errbyte));
                        } else {
                            System.out.println("<<< CubeLog  :: encrypt[" + dfComma.format(i) + "] = [" + encrypt + "]");
                        }
                        */
                    }
                    endTime = System.currentTimeMillis();
                    elapTime = (endTime - startTime) / 1000; //
            
                    System.out.println("  - elapTime = [" + String.valueOf(elapTime) + " sec]");
                    System.out.println("  - EncPerSec = [" + dfComma.format(loop/elapTime) + " cnt/sec]");

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                       System.out.println("  - encrypt = ["+encrypt+"]");
                       System.out.println("  - strlen(encrypt) = "+encrypt.length());
                    }else {
                       System.out.println("  ** Encryption Failed.. ["+new String(errbyte)+"]");
                    }
                    
                    System.out.println("");
                 } 
                 
                // Decrypt
                else if (menu.equals("4"))  {
                    System.out.print("  - Input Encrypt [ ITEM = " + item + " ]  : ");
                    encrypt = brStr.readLine();

                    System.out.print("  - Loop Count [ " + dfComma.format(loop) + " ] : starting !! \n");
                    startTime = System.currentTimeMillis();
                    for(int i=0; i<loop; i++) {
                        decrypt = CubeOneAPI.codecchar(encrypt,item,11,null,null,errbyte);
                        /*
                        if(!"00000".equals(new String(errbyte))) {
                            System.out.println(new String(errbyte));
                        } else {
                            System.out.println("<<< CubeLog  :: decrypt[" + dfComma.format(i) + "] = [" + decrypt + "]");
                        }
                        */
                    }
                    endTime = System.currentTimeMillis();
                    elapTime = (endTime - startTime) / 1000; //
            
                    System.out.println("  - elapTime = [" + String.valueOf(elapTime) + " sec]");
                    System.out.println("  - DecPerSec = [" + dfComma.format(loop/elapTime) + " cnt/sec]");

                    if (errbyte[0] == 48 && errbyte[1] == 48 && errbyte[2] == 48 && errbyte[3] == 48 && errbyte[4] == 48 ){
                       System.out.println("  - decrypt = ["+decrypt+"]");
                       System.out.println("  - strlen(decrypt) = "+decrypt.length());
                    }else {
                       System.out.println("  ** Decryption Failed.. ["+new String(errbyte)+"]");
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
