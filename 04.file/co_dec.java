import java.io.*;
import java.text.*;
import java.util.*;

import com.cubeone.*;

public class co_dec {
    static String plain = "1234567890123";
    static String encrypt = "" ;
    static String decrypt = "" ;
    static String item = "AES256" ;
    static String sid ;

    static byte[] errbyte = new byte[5];

    static String encFile = "";
    static String decFile = "";
    static String os = "";

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  co_dec.java :: codecfile() ###########");
        System.out.println("########################################################\n");

        //property();

        encFile = args[0] ; 
        sid = args[1] ;
        os = args[2] ; 

        decFile = encFile + ".dec";

        decFile();
    }

    static void decFile() {

        System.out.println("####################################" );
        System.out.println("#### Dec-File :: start ..... !!!" );
        System.out.println("####################################" );

        int ret;

        System.out.println("\n[1] File Infor  ");
        System.out.println("<<< CubeLog :: ITEM = [" + item + "]");
        System.out.println("<<< CubeLog :: System.getProperty(file.encoding) = [" + System.getProperty("file.encoding") + "]");
        System.out.println("<<< CubeLog :: encFile = [" + encFile + "]");
        System.out.println("<<< CubeLog :: decFile = [" + decFile + "]");

        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] Dec-File Test ");
        ret = CubeOneAPI.codecfile(encFile, decFile, sid, item);

        if(ret == 0) 
            System.out.println("<<< CubeLog :: codecfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: codecfile = [ Fail ]");

        System.out.println("\n#### ENC-File :: Success..... !!!\n\n" );

    }
}

