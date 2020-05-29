import java.io.*;
import java.text.*;
import java.util.*;

import com.cubeone.*;

public class co_enc {
    static String plain = "1234567890123";
    static String encrypt = "" ;
    static String decrypt = "" ;
    static String item = "AES256" ;
    static String sid ;

    static byte[] errbyte = new byte[5];

    static String encFile = "";
    static String plnFile = "";
    static String os = "";

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  co_enc.java :: coencfile() ##################");
        System.out.println("########################################################\n");

        plnFile = args[0] ; 
        sid = args[1] ;
        os = args[2] ; 

        encFile = plnFile + ".enc";

        encFile();
    }

    static void encFile() {

        int ret;

        System.out.println("[1] File Infor  ");
        System.out.println("<<< CubeLog :: ITEM = [" + item + "]");
        System.out.println("<<< CubeLog :: System.getProperty(file.encoding) = [" + System.getProperty("file.encoding") + "]");
        // System.out.println("<<< CubeLog :: encFile = [" + encFile + "]");
        // System.out.println("<<< CubeLog :: decFile = [" + decFile + "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[2] Enc-File Test ");
        ret = CubeOneAPI.coencfile(plnFile, encFile, sid, item);

        if(ret == 0) 
            System.out.println("<<< CubeLog :: codecfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: codecfile = [ Fail ]");
    }
}

