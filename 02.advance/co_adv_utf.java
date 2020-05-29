


import java.io.*;
import java.text.*;
import com.cubeone.*;
import java.util.*;

public class co_adv_utf {
    static String plain = "1234567890123";
    // static String plain = "��글�����K";
    static String item = "AES256" ;

    static String itemSalt = "SHA256_SALT" ;
    static int hashSize = 256;

    static byte[] errbyte = new byte[5];

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  CubeOneAPI-JAVA Self Test Program ###########");
        System.out.println("########################################################\n");

        // property();
           
        //Test basic API 
        basic();

        //Test Hangul
        basic_getbyte();

        //Test hash-salt
        basic_salt(); 

        //Test Ordered Index
        order();
    }

    static void basic() throws Exception {

        System.out.println("####################################" );
        System.out.println("#### Basic-Test :: start ..... !!!" );
        System.out.println("####################################" );

        String encrypt = "" ; 
	    String decrypt = "" ;
        System.out.println("\n<<< CubeLog :: ITEM = [" + item + "]");

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length() + "]");
        System.out.println("<<< CubeLog :: plain.getBytes().length = [" + plain.getBytes().length + "]");
        System.out.println("<<< CubeLog :: plain.getBytes(\"UTF8\").length = [" + plain.getBytes("UTF8").length + "]");

        System.out.println("\n[2] Enc Test ");

        encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        decrypt = CubeOneAPI.codecchar(encrypt,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");
        System.out.println("<<< CubeLog :: decrypt.getBytes().length = [" + decrypt.getBytes().length + "]");
        System.out.println("<<< CubeLog :: decrypt.getBytes(\"UTF8\").length = [" + decrypt.getBytes("UTF8").length + "]");

        System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

    }
    
    static void basic_salt() {

        System.out.println("####################################" );
        System.out.println("#### Basic(SALT)-Test :: start ..... !!!" );
        System.out.println("####################################" );

        String decrypt = "" ;

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
        String cosaltsel = CubeOneAPI.cosaltsel(plain, salt, hashSize, errbyte);

        System.out.println("<<< CubeLog :: cosaltsel = [" + cosaltsel + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: cosaltsel(Salt).length() = [" + cosaltsel.length()+ "]");
        /********************************************************************************/
        /********************************************************************************/
        
	if(coencchar.equals(cosaltsel)) 
            System.out.println("\n*** RESULT :: coencchar And cosaltsel :: Same ");
	else
            System.out.println("\n*** RESULT :: coencchar And cosaltsel :: Different ");


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

        String encrypt = "" ;
        String decrypt = "" ;

        System.out.println("\n[1] Plain Test  ");

        System.out.println("<<< CubeLog :: plain = [" + plain + "]");
        System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");

        System.out.println("\n[2] Enc Test ");

        byte[] bytehan = plain.getBytes("EUC-KR");
        //byte[] bytehan = plain.getBytes();  // get Default JVM file.encoding
        encrypt = CubeOneAPI.coencbytes(bytehan,bytehan.length,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec Test ");

        byte[] ret = CubeOneAPI.codecbyte(encrypt,item,11,"TBL","COL",errbyte);
        decrypt = new String(ret,"EUC-KR");
        //decrypt = new String(ret);  // get Default JVM file.encoding

        System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");
        System.out.println("<<< CubeLog :: decrypt.getBytes().length = [" + decrypt.getBytes().length + "]");
        System.out.println("<<< CubeLog :: decrypt.getBytes(\"UTF8\").length = [" + decrypt.getBytes("UTF8").length + "]");


        System.out.println("\n#### Basic-Test(Hangul getBytes) :: Success..... !!!\n\n" );

    }

    static void order() throws Exception {

        System.out.println("####################################" );
        System.out.println("#### Order-Test :: start ..... !!!" );
        System.out.println("####################################" );

        String idxchar = "" ;
        String idxcharsel = "" ;
        String encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);

        System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
        System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");
        System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");

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
            System.out.println("*** RESULT :: idxcharsel & idxchar same !!");
        else 
            System.out.println("*** RESULT :: idxcharsel & idxchar not same CHECK CHECK !!");


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

