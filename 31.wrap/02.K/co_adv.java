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

import java.io.*;
import java.text.*;
import com.cubeone.*;
import java.util.*;

public class co_adv {
    static String plain = "한글테스트";
    static String encrypt = "" ;
    static String decrypt = "" ;
    static String item = "AES_PI" ;

    static String itemSalt = "SHA256_SALT" ;
    static int hashSize = 256;

    static String idxchar;
    static String idxcharsel;

    static byte[] errbyte = new byte[5];

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  CubeOneAPI-JAVA Self Test Program ###########");
        System.out.println("########################################################\n");

        property();

        /**************************************************************
        ** !!!!!! Very Important !!!!!
        ** 0) do not use coinit  ..if coinit is called many times then performance is bad ..
        ** 1) Call this Function only once for performance ..
        ** 2) CubeOneAPI.jcoinit ("API"); for Access Control ..
        **        - user : OS telnet account
        **        - ip/mac : Terminal PC          
        ** 3) CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100); is for Old-Version ..    
        ***************************************************************/
        //nRtn = CO_init (bFirst, sSid, sUser, sNull, sNull, sNull, sNull, sNull, sNull, sNull, nSessionId);
        //                                        ip Machine OsUser Program Module Terminal Psswd SeesionId 
        // CubeOneAPI.coinit (1, "API", "cubeapi", "","","","","","","",100);
        //CubeOneAPI.jcoinit ("API");
           
        //Test basic API 
        basic();
        
        //Test Hangul
        basic_getbyte();
        
        //Test Ordered Index
        //order();

        //Test hash-salt
        //basic_salt(); 

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

        encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        //System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(encrypt,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        //System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

    }
    
    static void basic_salt() {

        System.out.println("####################################" );
        System.out.println("#### Basic(SALT)-Test :: start ..... !!!" );
        System.out.println("####################################" );

        System.out.println("\n<<< CubeLog :: ITEM(SALT) = [" + itemSalt + "]");

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");

        System.out.println("\n[2] Enc Test ");

        String coencchar = CubeOneAPI.coencchar(plain,itemSalt,11,"TBL","COL",errbyte);
        String salt = coencchar.substring(0,20);

        System.out.println("<<< CubeLog :: coencchar = [" + coencchar + "]");
        System.out.println("<<< CubeLog :: coencchar.length() = [" + coencchar.length()+ "]");
        System.out.println("<<< CubeLog :: salt = [" + salt + "]");
        System.out.println("<<< CubeLog :: salt.length() = [" + salt.length()+ "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");

        ///////////////////////////
        System.out.println("-----------------------------------------------------------------");
        String cohashsalt = CubeOneAPI.cohashsalt(plain, salt, hashSize, errbyte);

        System.out.println("<<< CubeLog :: cohashsalt = [" + cohashsalt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: cohashsalt(Salt).length() = [" + cohashsalt.length()+ "]");

        ///////////////////////////
        System.out.println("-----------------------------------------------------------------");
        String cosaltsel = CubeOneAPI.cosaltsel(plain, coencchar, hashSize, errbyte);

        System.out.println("<<< CubeLog :: cosaltsel = [" + cosaltsel + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: cosaltsel(Salt).length() = [" + cosaltsel.length()+ "]");
        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(coencchar,itemSalt,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]"); 
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

    }

    static void basic_getbyte() throws Exception {

        System.out.println("#######################################################" );
        System.out.println("#### Basic-Test(Hangul getBytes) :: start ..... !!!" );
        System.out.println("#######################################################" );

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");

        System.out.println("\n[2] Enc Test ");

        // byte[] bytehan = plain.getBytes("EUC-KR");
        byte[] bytehan = plain.getBytes("");
        encrypt = CubeOneAPI.coencbytes(bytehan,bytehan.length,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        byte[] ret = CubeOneAPI.codecbyte(encrypt,item,11,"TBL","COL",errbyte);
        //decrypt = new String(ret,"EUC-KR");
        decrypt = new String(ret);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");


        System.out.println("\n#### Basic-Test(Hangul getBytes) :: Success..... !!!\n\n" );

    }

    static void order() {

        System.out.println("####################################" );
        System.out.println("#### Order-Test :: start ..... !!!" );
        System.out.println("####################################" );

        System.out.println("\n[1] coindexchar Test : XX1.ENC_INDEX_VARCHAR2(enc_column,'ITEM') ");

        idxchar = CubeOneAPI.coindexchar(encrypt,item,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: idxchar = [" + idxchar + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: idxchar.length() = [" + idxchar.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[2] coindexcharsel Test : XX1.ENC_INDEX_VARCHAR2_SEL('plain-constant','ITEM')  ");

        idxcharsel = CubeOneAPI.coindexcharsel(plain,item,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: idxcharsel = [" + idxcharsel + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: idxcharsel.length() = [" + idxcharsel.length() + "]\n");

        if(idxchar.equals(idxcharsel)) 
            System.out.println("<<< CubeLog :: idxcharsel & idxchar same !!");
        else 
            System.out.println("<<< CubeLog :: idxcharsel & idxchar not same CHECK CHECK !!");


        System.out.println("\n#### Order-Test :: Success..... !!!\n\n" );

    }



    static void property(){

        System.out.println("####################################" );
        System.out.println("#### Get JVM Property ..... !!!" );
        System.out.println("####################################" );

        Properties sysprops = System.getProperties();

        String key, value ;

        for (Enumeration e = sysprops.propertyNames(); e.hasMoreElements();) {
            key = (String) e.nextElement();
            value = sysprops.getProperty(key);
            
            if(key.equals("java.ext.dirs") || 
                key.equals("java.library.path") ||  
                key.equals("java.class.path") ||  
                key.equals("java.home") || 
                key.equals("java.vm.name") || 
                key.equals("java.runtime.version") || 
                key.equals("java.version") || 
                key.equals("sun.boot.library.path") || 
                key.equals("os.name") || 
                key.equals("os.arch") || 
                key.equals("os.version") || 
                key.equals("user.dir") || 
                key.equals("user.name") || 
                key.equals("user.language") || 
                key.equals("file.encoding") || 
                key.equals("")) 
            {
                System.out.println(key + "=" + value);
            }
        }
        System.out.println("\n\n");
    }
/*
System.setProperty("java.library.path","/home/cubeapi/lib64");

java.lang.reflect.Field fieldSysPath = ClassLoader.class.getDeclaredField( "sys_paths" );
fieldSysPath.setAccessible( true );
fieldSysPath.set( null, null );
*/
}

