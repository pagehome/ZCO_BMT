import java.io.*;
import com.cubeone.*;

public class EncThread extends Thread{

    public void run() {
        // CubeOneAPI.coinit (1, "API", "cubeapi", "","","","","","","",100L);

        byte[] errbyte = new byte[5];
        String strEncrypt = "" ;
        String strDecrypt = "" ;
        String strErrbyte = "";

        String item = "AES256";

        int iSuccEnc = 0;
        int iSuccDec = 0;

        //int total = 1000;
        //int total = 100;
        int total = 100000;

        String plain = "1234567890123";

        String strEncTest  = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);

        CubeOneAPI.coencchar(plain,"ARIA128",11,"TBL","COL",errbyte);
        CubeOneAPI.coencchar(plain,"ARIA192",11,"TBL","COL",errbyte);
        CubeOneAPI.coencchar(plain,"ARIA256",11,"TBL","COL",errbyte);
        //CubeOneAPI.coencchar(plain,"ARIA256_LE",11,"TBL","COL",errbyte);
        //CubeOneAPI.coencchar(plain,"ARIA256_LN",11,"TBL","COL",errbyte);
        //CubeOneAPI.coencchar(plain,"ARIA256_RE",11,"TBL","COL",errbyte);
        //CubeOneAPI.coencchar(plain,"ARIA256_RN",11,"TBL","COL",errbyte);

        try{

            for(int i=0;i<total;i++) {

            ////////////////////////////////////////////////////////////////////////
                CubeOneAPI.coencchar(plain,"ARIA128",   11,"TBL","COL",errbyte);
                CubeOneAPI.coencchar(plain,"ARIA192",   11,"TBL","COL",errbyte);
                CubeOneAPI.coencchar(plain,"ARIA256",   11,"TBL","COL",errbyte);
                //CubeOneAPI.coencchar(plain,"ARIA256_LE",11,"TBL","COL",errbyte);
                //CubeOneAPI.coencchar(plain,"ARIA256_LN",11,"TBL","COL",errbyte);
                //CubeOneAPI.coencchar(plain,"ARIA256_RE",11,"TBL","COL",errbyte);
                //CubeOneAPI.coencchar(plain,"ARIA256_RN",11,"TBL","COL",errbyte);
            ////////////////////////////////////////////////////////////////////////

                strEncrypt = CubeOneAPI.coencchar(plain, item, 11,"TBL", "COL", errbyte);
                strErrbyte = new String(errbyte);

                if(!"00000".equals(strErrbyte)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt : strErrbyte = ["+ strErrbyte +"]");
                } else {
    //              System.out.println("<<< CubeLog :: EncThread.run() : strEncrypt = ["+ strEncrypt +"]");
                }


	        // synchronized(this){
                if(strEncTest.equals(strEncrypt)) {
                    if(++iSuccEnc % 100000 == 0) {
                        System.out.println("<<< CubeLog :: EncThread.run() : iSuccEnc => " + iSuccEnc );
		    }
                } else {
                    System.out.println("<<< CubeLog :: EncThread.run() : strEncTest [ " + strEncTest + " <> strEncrypt ["+ strEncrypt +"]");
                }
	        // }

            }
            System.out.println("<<< CubeLog :: EncThread.run() : iSuccEnc = ["+ iSuccEnc +"]");

            for(int i=0;i<total;i++) {
            ////////////////////////////////////////////////////////////////////////
                CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA128",   11,"TBL","COL",errbyte),"ARIA128",      11,"TBL","COL",errbyte);
                CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA192",   11,"TBL","COL",errbyte),"ARIA192",      11,"TBL","COL",errbyte);
                CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA256",   11,"TBL","COL",errbyte),"ARIA256",      11,"TBL","COL",errbyte);
                //CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA256_LE",11,"TBL","COL",errbyte),"ARIA256_LE",   11,"TBL","COL",errbyte);
                //CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA256_LN",11,"TBL","COL",errbyte),"ARIA256_LN",   11,"TBL","COL",errbyte);
                //CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA256_RE",11,"TBL","COL",errbyte),"ARIA256_RE",   11,"TBL","COL",errbyte);
                //CubeOneAPI.codecchar(CubeOneAPI.coencchar(plain,"ARIA256_RN",11,"TBL","COL",errbyte),"ARIA256_RN",   11,"TBL","COL",errbyte);
            ////////////////////////////////////////////////////////////////////////
                strDecrypt = CubeOneAPI.codecchar(strEncrypt,item,11,"TBL","COL",errbyte);
                strErrbyte = new String(errbyte);

                if(!"00000".equals(strErrbyte)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt["+ strErrbyte +"]");
                } else {
    //              System.out.println("<<< CubeLog :: EncThread.run() : strErrbyte = ["+ strEncrypt +"]");
                }

                if((plain).equals(strDecrypt)) {
                    if(++iSuccDec % 100000 == 0) {
                        System.out.println("<<< CubeLog :: EncThread.run() : iSuccDec => " + iSuccDec );
		    }
                } else {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Decrypt["+ strErrbyte +"]");
                }
            }

            System.out.println("<<< CubeLog :: EncThread.run() : iSuccDec = ["+ iSuccDec +"]");


        } catch(Exception e) {

        }
    }
}
