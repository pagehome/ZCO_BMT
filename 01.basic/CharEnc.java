import com.cubeone.*;

public class CharEnc {

    public static void main(String[] args) throws Exception {

        System.out.println("\n########################################################");
        System.out.println("#########  CubeOneAPI-java Test : CharEnc    ###########");
        System.out.println("########################################################\n");

        String item   = "AES128" ;
        byte[] bytErr = new byte[5];

        String plain   = "1ab한" ;
        String encrypt = "" ;
        String decrypt = "" ;

        System.out.println("[1] Basic Check  ");
        System.out.println(" - item  = [" + item + "]");
        System.out.println(" - plain = [" + plain + "]");
        System.out.println(" - plain.length() = [" + plain.length()+ "]\n");

        ///////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////
        System.out.println("[2] Enc Test ");

        encrypt = CubeOneAPI.coencchar(plain,item,10,null,null,bytErr);

        // success
        if("00000".equals(new String(bytErr))) {
            System.out.println(" - coencchar = [" + encrypt + "]");
            System.out.println(" - coencchar.length() = [" + encrypt.length()+ "]");
        }
        // fail
        else {
            throw new Exception("Enc Fail_CubeOne_ErrCode = [" +  new String(bytErr) + "]");
        }

        ///////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////
        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(encrypt,item,10,null,null,bytErr);

        // success
        if("00000".equals(new String(bytErr))) {
            System.out.println(" - codecchar = [" + decrypt + "]");
            System.out.println(" - codecchar.length() = [" +decrypt.length() + "]");
        }
        // fail
        else {
            throw new Exception("Dec Fail_CubeOne_ErrCode = [" +  new String(bytErr) + "]");
        }
        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );
    }
}

/*
	20007   No Privileges to access encrypted column    COER_NOTALLOWEDS
	20008   Item is not specified                       COER_NOITEM_ENTEREDS
	20009   Fail to get OCI Environment                 COER_FAIL_GET_OCIENVS
	20010   Fail to Enabling Lob Buffering              COER_FAIL_ENABLE_BUFFERINGS
	20011   Fail to treat Lob data                      COER_FAIL_LOBS
	20012   Fail to Decrypt Lob data                    COER_FAIL_DEC_LOBS
	20013   Fail to Encrypt Lob data                    COER_FAIL_ENC_LOBS
	20014   Fail to Encryption data                     COER_FAIL_ENCRYPTIONS
	20015   Fail to Encryption self testing             COER_FAIL_SELFTESTS
	20016   Fatal error so should exception             COER_FATAL_ERROR
	20017   error when check Initialize.                COER_FAIL_INIT
	20018   error when check double enc.                COER_DOUBLE_CHECK
	
	20021   error when SHMOpen file open.               COER_SHMFILEOPEN
	20022   error when SHMOpen ftok.                    COER_SHMFTOK
	20023   error when SHMOpen shmget.                  COER_SHMGETNORMAL
	20024   error when SHMOpen shmget ENPSPC.           COER_SHMGETNOSPC
	20025   error when SHMOpen shmget ENOMEM.           COER_SHMGETNOMEM
	20031   error when shmat EMFILE.                    COER_SHMATEMFILE
	20032   error when shmat ENOMEM.                    COER_SHMATENOMEM
	20033   error when shmat EINVAL.                    COER_SHMATEINVAL
	20034   error for Admin Act.: Ver 2.5-9021-C        COER_ADMINACTION
*/

