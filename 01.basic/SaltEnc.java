import com.cubeone.*;

public class SaltEnc {

    public static void main(String[] args) throws Exception {

        System.out.println("\n########################################################");
        System.out.println("#########  CubeOneAPI-java Test : SaltEnc    ###########");
        System.out.println("########################################################\n");

        String item = "SHA256_SALT" ;
        byte[] bytErr = new byte[5];

        String passwd = "1234qwer";
        String coencchar = "" ;
        String cosaltsel = "" ;

        System.out.println("[1] Basic Check  ");
        System.out.println(" - item   = [" + item + "]");
        System.out.println(" - passwd = [" + passwd + "]");
        System.out.println(" - passwd.length() = [" + passwd.length()+ "]\n");

        ///////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////        
        System.out.println("[2] Enc Test ");

        coencchar = CubeOneAPI.coencchar(passwd,item,10,null,null,bytErr);
        
        // success
        if("00000".equals(new String(bytErr))) {
            System.out.println(" - coencchar = [" + coencchar + "]");
            System.out.println(" - coencchar.length() = [" + coencchar.length()+ "]\n");
        }
        // fail
        else {
            throw new Exception("Enc Fail_CubeOne_ErrCode = [" +  new String(bytErr) + "]\n");
        }

        ///////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////        
        System.out.println("[3] Passwd Compare Test ");

        cosaltsel = CubeOneAPI.cosaltsel(passwd,coencchar,256,bytErr);

        // success
        if("00000".equals(new String(bytErr))) {
            System.out.println(" - cosaltsel = [" + cosaltsel + "]");
            System.out.println(" - cosaltsel.length() = [" + cosaltsel.length()+ "]\n");
            
            // compare ok
            if(coencchar.equals(cosaltsel)) {
                System.out.println("*** salt passwd verify ok !! ***");
            } 
            // compare fail
            else {
                System.out.println(" - salt passwd verify fail !!");
                throw new Exception("Enc Fail_CubeOne_ErrCode = [salt passwd verify fail]");
            }
        }
        // fail
        else {
            throw new Exception("Enc Fail_CubeOne_ErrCode = [" +  new String(bytErr) + "]");
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

