import java.io.*;
import java.text.*;
import java.util.*;

import com.cubeone.*;

public class co_file2 {
    static String plain = "1234567890123";
    static String encrypt = "" ;
    static String decrypt = "" ;
    static String item = "AES256" ;
    static String sid ;

    static byte[] errbyte = new byte[5];

    static String plnFile = "";
    static String encFile = "";
    static String decFile = "";

    static String os = "";

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  CubeOneAPI-JAVA Self Test Program ###########");
        System.out.println("########################################################\n");

        plnFile = args[0] ; 
        sid = args[1] ;
        os = args[2] ;

        encFile = plnFile + "." + os + ".API.enc";
        decFile = plnFile + "." + os + ".API.dec";

        System.out.println("\n[1] File Infor  ");
        System.out.println("<<< CubeLog :: ITEM = [" + item + "]");
        System.out.println("<<< CubeLog :: System.getProperty(file.encoding) = [" + System.getProperty("file.encoding") + "]");
        System.out.println("<<< CubeLog :: plnFile = [" + plnFile + "]");
        System.out.println("<<< CubeLog :: encFile = [" + encFile + "]");
        System.out.println("<<< CubeLog :: decFile = [" + decFile + "]");

        encFile();
        decFile();
    }

    static void encFile() {

        int ret;

        System.out.println("\n[2] Enc-File Test ");

        ret = CubeOneAPI.coencfile(plnFile, encFile, sid, item);
        if(ret == 0) 
            System.out.println("<<< CubeLog :: coencfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: coencfile = [ Fail ] = [" + ret +"]");

    }

    static void decFile() {
        int ret;
        System.out.println("\n[3] Dec-File Test ");
        ret = CubeOneAPI.codecfile(encFile, decFile, sid, item);

        if(ret == 0) 
            System.out.println("<<< CubeLog :: codecfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: codecfile = [ Fail ] = [" + ret +"]");

        System.out.println("\n#### DEC-File :: Success..... !!!\n\n" );
    }


    static void fileUTF() {

        System.out.println("####################################" );
        System.out.println("#### UTF-File :: start ..... !!!" );
        System.out.println("####################################" );

        int ret;

        String plnFile = "zUTF-8.txt";
        String encFile = "NT.zUTF-8.txt.enc";
        String decFile = "NT.zUTF-8.txt.dec";

        System.out.println("\n[1] File Infor  ");
        System.out.println("<<< CubeLog :: ITEM = [" + item + "]");
        System.out.println("<<< CubeLog :: System.getProperty(file.encoding) = [" + System.getProperty("file.encoding") + "]");
        System.out.println("<<< CubeLog :: plnFile = [" + plnFile + "]");
        System.out.println("<<< CubeLog :: encFile = [" + encFile + "]");
        System.out.println("<<< CubeLog :: decFile = [" + decFile + "]");

        System.out.println("\n[2] UTF-File Test ");

/*
        ret = CubeOneAPI.coencfile(plnFile, encFile, sid, item);
        if(ret == 0) 
            System.out.println("<<< CubeLog :: coencfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: coencfile = [ Fail ]");

*/
        /********************************************************************************/
        /********************************************************************************/

        System.out.println("\n[3] UTF-File Test ");
        ret = CubeOneAPI.codecfile(encFile, decFile, sid, item);

        if(ret == 0) 
            System.out.println("<<< CubeLog :: codecfile = [ Success ]");
        else 
            System.out.println("<<< CubeLog :: codecfile = [ Fail ]");

        System.out.println("\n#### UTF-File :: Success..... !!!\n\n" );

    }
}

