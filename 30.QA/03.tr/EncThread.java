import java.io.*;
import com.cubeone.*;

public class EncThread extends Thread{
    public void run() {
        byte[] errbyte = new byte[5];
        String strEncrypt = "" ;
        String strEncrypt2 = "" ;
        String strDecrypt = "" ;
        String strDecrypt2 = "" ;
        String strErrbyte = "";
        String item = "SSN";
        String item2 = "AES256CBC_LN";
        int iSuccEnc = 0;
        int iSuccDec = 0;
        int total = 1000;

        String plain = "1234567890123";

        CubeOneAPI.coinit ("OBCS");
        //CubeOneAPI.coinit (1, "API", "SA", "","","","","","","",100L);
        //CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100L);
        String strEncTest = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);
                strErrbyte = new String(errbyte);
        if(!"00000".equals(strErrbyte)) {
             System.out.println("<<< CubeLog :: EncThread.run() : init Fail Encrypt["+ strErrbyte +"]");
		strEncTest = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);
        } else {
	}
        String strEncTest2 = CubeOneAPI.coencchar(plain,item2,11,"TBL","COL",errbyte);
                strErrbyte = new String(errbyte);
        if(!"00000".equals(strErrbyte)) {
             System.out.println("<<< CubeLog :: EncThread.run() : init Fail Encrypt["+ strErrbyte +"]");
		strEncTest2 = CubeOneAPI.coencchar(plain,item2,11,"TBL","COL",errbyte);
        } else {
	}
	
        //String strEncTest="";
        try{
            for(int i=0;i<total;i++) {
        	CubeOneAPI.coinit ("OBCS");
        	//CubeOneAPI.coinit(1, "API", "SA", "","","","","","","",100L);
		strEncrypt ="";
		strEncrypt2 ="";
                strEncrypt = CubeOneAPI.coencchar(plain, item, 11,"TBL", "COL", errbyte);
                strErrbyte = new String(errbyte);

                if(!"00000".equals(strErrbyte)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt["+ strErrbyte +"]");
		break;
                } else {
    //              System.out.println("<<< CubeLog :: EncThread.run() : strErrbyte = ["+ strEncrypt +"]");
                }
                strEncrypt2 = CubeOneAPI.coencchar(plain, item2, 11,"TBL", "COL", errbyte);
                if(!"00000".equals(strErrbyte)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt["+ strErrbyte +"]");
		break;
                } else {
    //              System.out.println("<<< CubeLog :: EncThread.run() : strErrbyte = ["+ strEncrypt +"]");
                }
		
		if (strEncrypt.equals(null)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt null check : strErrbyte = ["+ strErrbyte +"]["+strEncrypt+"]");
		}

                if(strEncTest.equals(strEncrypt)) {
                    iSuccEnc++;
                } else {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt : strErrbyte = ["+ strErrbyte +"]["+strEncrypt+"]["+strEncTest+"]");
			break;
		
                }
                if(strEncTest2.equals(strEncrypt2)) {
                    iSuccEnc++;
                } else {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Encrypt : strErrbyte = ["+ strErrbyte +"]["+strEncrypt2+"]["+strEncTest2+"]");
			break;
		
                }
            }
            //System.out.println("<<< CubeLog :: EncThread.run() : iSuccEnc = ["+ iSuccEnc +"]");

            for(int i=0;i<total;i++) {
        	CubeOneAPI.coinit ("OBCS");
        	//CubeOneAPI.coinit(1, "API", "SA", "","","","","","","",100L);
		strDecrypt ="";
                strDecrypt = CubeOneAPI.codecchar(strEncrypt,item,11,"TBL","COL",errbyte);
                strErrbyte = new String(errbyte);

                if(!"00000".equals(strErrbyte)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Decrypt["+ strErrbyte +"]");
		break;
                } else {
    //              System.out.println("<<< CubeLog :: EncThread.run() : strDecrypt = ["+ strDecrypt +"]");
                }
		if (strDecrypt.equals(null)) {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Decrypt null check : strErrbyte = ["+ strErrbyte +"]["+strDecrypt+"]["+strEncrypt+"]");
		}


                if((plain).equals(strDecrypt)) {
                    iSuccDec++;
                } else {
                    System.out.println("<<< CubeLog :: EncThread.run() : Fail Decrypt : strErrbyte = ["+ strErrbyte +"]["+strEncrypt+"]");
			break;
                }
            }

            //System.out.println("<<< CubeLog :: EncThread.run() : iSuccDec = ["+ iSuccDec +"]");

        } catch(Exception e) {
		e.printStackTrace();
	        System.out.println("<<< CubeLog :: EncThread.run() : Fail  null check : strErrbyte = ["+ strErrbyte +"]["+strDecrypt+"]["+strEncrypt+"]["+strEncTest+"]");

        }
    }
}

