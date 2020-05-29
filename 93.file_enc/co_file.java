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

public class co_file {
    static String plain = "1234567890123";
    static String encrypt = "" ;
    static String decrypt = "" ;

    static String type, item, file  ;
    static int nBuf;

    static byte[] byteErr = new byte[5];

    public static void main(String[] args) throws Exception {

        System.out.println("########################################################");
        System.out.println("#########  CubeOneAPI-JAVA :: File Enc/Dec  ###########");
        System.out.println("########################################################\n");

        if(args.length !=4)
        {
            System.out.println("Input buf type item file");
            return;
        } else 
        {
            nBuf = Integer.parseInt(args[0]);
            type = args[1];
            item = args[2];
            file = args[3];
        }

        if(nBuf == 0 && "E".equals(type))
        {
            encFileOneShot();
        } 
        else if(nBuf == 0 && "D".equals(type))
        {
            decFileOneShot();
        }
        else if(nBuf != 0 && "E".equals(type))
        {
            encFileBuf();
        }
        else if(nBuf != 0 && "D".equals(type))
        {
            // decFileBuf();
        }

        //basic();
    }

    static void encFileBuf() throws Exception {

        System.out.println("-------------------------------------------------------" );
        System.out.println("---- encFileBuf() :: start ..... !!!" );
        System.out.println("-------------------------------------------------------" );

        File filePln = new File(file);
        File fileEnc = new File(file + "." + nBuf + ".enc");

        FileInputStream fisPln; 
        FileOutputStream fosEnc;

        fisPln = new FileInputStream(filePln);

        byte[] bytePln = new byte[nBuf];
        byte[] byteEnc;

        fosEnc = new FileOutputStream(fileEnc);

        int nRead;
        while(true)
        {

            nRead = fisPln.read(bytePln, 0, nBuf);
            if(nRead == -1) break;

            // Enc !! 
            // byteEnc = CubeOneAPI.coencbyteb(bytePln, bytePln.length, item, 11, null, null, byteErr); // in last line , space will be encrypted !! .. be Careful !!
            byteEnc = CubeOneAPI.coencbyteb(bytePln, nRead, item, 11, null, null, byteErr);
            fosEnc.write(byteEnc,0, byteEnc.length);
        }

        System.out.println("<<< CubeLog :: byteErr = [" + new String(byteErr) + "]");

        // Close 
        fisPln.close();
        fosEnc.close();

        System.out.println("---- encFileBuf() :: end ..... !!!" );
    }
    
    static void decFileOneShot() throws Exception {

        System.out.println("-------------------------------------------------------" );
        System.out.println("---- decFileOneShot() :: start ..... !!!" );
        System.out.println("-------------------------------------------------------" );

        File fileEnc = new File(file + ".enc");
        File fileDec = new File(file + ".dec");

        FileInputStream fisEnc; 
        FileOutputStream fosDec;

        fisEnc = new FileInputStream(fileEnc);
        int nEnc = (int)fileEnc.length();

        byte[] byteEnc = new byte[nEnc];
        int nRead = fisEnc.read(byteEnc);

        System.out.println("<<< CubeLog :: nEnc = [" + nEnc + "]");

        byte[] byteDec = CubeOneAPI.codecbyteb(byteEnc, byteEnc.length, item, 11, null, null, byteErr);
        System.out.println("<<< CubeLog :: byteEnc.length = [" + byteEnc.length + "]");

        System.out.println("<<< CubeLog :: byteErr = [" + new String(byteErr) + "]");

        /// Dec !! 
        fosDec = new FileOutputStream(fileDec);
        fosDec.write(byteDec);

        /// Close 
        fisEnc.close();
        fosDec.close();

        System.out.println("---- decFileOneShot() :: end ..... !!!" );
    }


    static void encFileOneShot() throws Exception {

        System.out.println("-------------------------------------------------------" );
        System.out.println("---- encFileOneShot() :: start ..... !!!" );
        System.out.println("-------------------------------------------------------" );

        File filePln = new File(file);
        File fileEnc = new File(file + ".enc");

        FileInputStream fisPln; 
        FileOutputStream fosEnc;

        fisPln = new FileInputStream(filePln);
        int nPln = (int)filePln.length();

        byte[] bytePln = new byte[nPln];
        int nRead = fisPln.read(bytePln);

        System.out.println("<<< CubeLog :: nPln = [" + nPln + "]");

        byte[] byteEnc = CubeOneAPI.coencbyteb(bytePln, bytePln.length, item, 11, null, null, byteErr);
        System.out.println("<<< CubeLog :: byteEnc.length = [" + byteEnc.length + "]");

        System.out.println("<<< CubeLog :: byteErr = [" + new String(byteErr) + "]");

        /// Enc !! 
        fosEnc = new FileOutputStream(fileEnc);
        fosEnc.write(byteEnc);

        /// Close 
        fisPln.close();
        fosEnc.close();

        System.out.println("---- encFileOneShot() :: end ..... !!!" );
    }
}
