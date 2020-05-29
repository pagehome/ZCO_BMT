import java.io.*;
import java.text.*;
import com.cubeone.*;
import java.util.*;


public class CubeOneWrapSample
{
    
    static String plainText = "한글테스트";
    
    public static void main(String[] args) throws Exception {
    
        System.out.println("#########  CubeOneAPI-JAVA Self Test Program ###########\n\n");
        
        try{
            String encPI = CubeOneWrapSample.encryptPI(plainText);
            System.out.println("###### encryptPI Test Start ######");
            System.out.println("plainText : " +  plainText);
            System.out.println("encryptText : " + encPI);
            System.out.println("#### encryptPI Test End..... !!!\n\n" );    
                
            String decPI = CubeOneWrapSample.decryptPI(encPI);
            System.out.println("###### decryptPI Test Start ######");
            System.out.println("encryptText : " + encPI);
            System.out.println("decryptText : " + decPI);
            System.out.println("#### decryptPI TEST End..... !!!\n\n" );
            
            String encFI = CubeOneWrapSample.encryptFI(plainText);
            System.out.println("###### encryptFI Test Start ######");
            System.out.println("plainText : " +  plainText);
            System.out.println("encryptText : " + encFI);
            System.out.println("#### encryptFI Test End..... !!!\n\n" );
            
            String decFI = CubeOneWrapSample.decryptFI(encFI);
            System.out.println("###### decryptFI Test Start ######");
            System.out.println("encryptText : " + encFI);
            System.out.println("decryptText : " + decFI);
            System.out.println("#### decryptFI Test End..... !!!\n\n" );
            
            String encTI = CubeOneWrapSample.encryptTI(plainText);
            System.out.println("###### encryptTI Test Start ######");
            System.out.println("plainText : " +  plainText);
            System.out.println("encryptText : " + encTI);
            System.out.println("#### encryptTI Test End..... !!!\n\n" );
            
            String decTI = CubeOneWrapSample.decryptTI(encTI);
            System.out.println("###### decryptTI Test Start ######");
            System.out.println("encryptText : " + encTI);
            System.out.println("decryptText : " + decTI);
            System.out.println("#### decryptTI Test End..... !!!\n\n" );
            
            String encSHA = CubeOneWrapSample.encryptSHA(plainText);
            System.out.println("###### encryptSHA Test Start ######");
            System.out.println("plainText : " +  plainText);
            System.out.println("encryptText : " + encSHA);
            System.out.println("#### encryptSHA Test End..... !!!\n\n" );
            
            boolean checkSHA = CubeOneWrapSample.checkSHA(plainText,encSHA);
            System.out.println("###### checkSHA Test Start ######");
            System.out.println("plainText : " +  plainText);
            System.out.println("encryptText : " + encSHA);
            System.out.println("cehck Value: " + checkSHA);
            System.out.println("#### checkSHA Test End..... !!!\n\n" );
            
            boolean checkEncFile = CubeOneWrapSample.encFile("a.txt","a.enc");    
            System.out.println("###### encFile Test Start ######");
            System.out.println("encFile: " + checkEncFile);
            System.out.println("#### encryptFile Test End..... !!!\n\n" );
            
            boolean checkDecFile = CubeOneWrapSample.decFile("a.enc","a.dec");    
            System.out.println("###### decFile Test Start ######");
            System.out.println("decFile: " + checkDecFile);
            System.out.println("#### decryptFile Test End..... !!!\n\n" );
            byte errbyte[] = new byte[5];
            String encPIchr = CubeOneAPI.coencchar(plainText,"AES_PI",11,"TBL","COL",errbyte);
            String encSHAchr = CubeOneAPI.coencchar(plainText,"SHA_KBK",11,"TBL","COL",errbyte);
            boolean cosaltsel = CubeOneAPI.cosaltsel(plainText,encSHAchr,256,errbyte).equals(encSHAchr);
            System.out.println("############");
            System.out.println("plainText : " +  plainText);
            System.out.println("AES_PI encryptText : " + encPIchr);
            System.out.println("SHA_KBK encryptText : " + encSHAchr);
            System.out.println("cehck Value: " + cosaltsel);
            System.out.println("############");

        }catch(Exception e){
            System.out.println(e);
        }    
    }
    
    
    public static String encryptPI(String plainText)
        throws Exception
    {
        String encryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] inbyte ;
        try {
            inbyte = plainText.getBytes(); 
             encryptedText = CubeOneAPI.coencbytes(inbyte, inbyte.length, "AES_PI", 11, null, null, errbyte);
        } catch( Exception e) {
            
           throw new Exception("encryptPI Error: " + e);
        }

        if(errbyte[0] == 50)
        {
           throw new Exception("encryptPI Error: " + new String(errbyte));
        } 
        return encryptedText;
    }
 
    public static String decryptPI(String encryptedText)
        throws Exception
    {
        String decryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] decbyte ;
        decbyte = CubeOneAPI.codecbyte(encryptedText, "AES_PI", 11, null, null, errbyte);
        if( decbyte != null)
            decryptedText = new String(decbyte);
        
        if(errbyte[0] == 50)
        {
           throw new Exception("decryptPI Error: " + new String(errbyte));
        }
        return decryptedText;
    }

 
    public static String encryptFI(String plainText)
        throws Exception
    {
        String encryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] inbyte ;
      
        try {
            inbyte = plainText.getBytes(); //db characterset
            encryptedText = CubeOneAPI.coencbytes(inbyte, inbyte.length, "AES_FI", 11, null, null, errbyte);
        } catch( Exception e) {
            throw new Exception("encryptFI Error: " + e);    
        }

        if(errbyte[0] == 50)
        {
            throw new Exception("encryptFI Error: " + new String(errbyte)); 
        }
 
        return encryptedText;
    }

 
 
    public static String decryptFI(String encryptedText)
        throws Exception
    {
        String decryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] decbyte ;
        decbyte = CubeOneAPI.codecbyte(encryptedText, "AES_FI", 11, null, null, errbyte);
        if( decbyte != null) 
        decryptedText = new String(decbyte);
        
        if(errbyte[0] == 50)
        {
            throw new Exception("decryptFI Error: " + new String(errbyte)); 
        }
        
        return decryptedText;
    } 
 
    public static String encryptTI(String plainText)
        throws Exception
    {
        String encryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] inbyte ;
        try {
           inbyte = plainText.getBytes(); //db characterset
           encryptedText = CubeOneAPI.coencbytes(inbyte, inbyte.length, "AES_TI", 11, null, null, errbyte);
        }catch( Exception e) {
            throw new Exception("encryptTI Error: " + e);        
        }

        if(errbyte[0] == 50)
        {
               throw new Exception("encryptTI Error: " + new String(errbyte)); 
        }
        return encryptedText;
    }
 
    public static String decryptTI(String encryptedText)
        throws Exception
    {
        String decryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] decbyte ;
        decbyte = CubeOneAPI.codecbyte(encryptedText, "AES_TI", 11, null, null, errbyte);

        if( decbyte != null) 
            decryptedText = new String(decbyte);
        
        if(errbyte[0] == 50)
        {
            throw new Exception("decryptTI Error: " + new String(errbyte)); 
        }
        
        return decryptedText;
    }
 
    public static String encryptSHA(String plainText)
        throws Exception
    {
        String encryptedText = null;
        byte errbyte[] = new byte[5];
        byte[] inbyte ;
        try {
            inbyte = plainText.getBytes();
            encryptedText = CubeOneAPI.coencbytes(inbyte, inbyte.length, "SHA_KBK", 11, null, null, errbyte);
        } catch( Exception e) {
           throw new Exception("encryptSHA Error: " + e);    
        }

        if(errbyte[0] == 50)
        {
            throw new Exception("encryptSHA Error: " + new String(errbyte)); 
        }
        return encryptedText;
    }
 
    public static boolean checkSHA(String plainText,String encryptText)
        throws Exception
    {
        String cosaltsel = "";
        byte errbyte[] = new byte[5];
        byte[] inbyte ;
        try {
           inbyte = plainText.getBytes();
             cosaltsel = CubeOneAPI.cosaltsel(plainText,encryptText,256,errbyte);
        } catch( Exception e) {
            throw new Exception("checkSHA Error: " + e);        
        }

        if(errbyte[0] == 50)
        {
            throw new Exception("checkSHA Error: " + new String(errbyte)); 
        }
       return cosaltsel.equals(encryptText);
    }

    public static boolean encFile(String Infile,String outFile)
        throws Exception
    {
        int rtnvalue = CubeOneAPI.coencfile(Infile,outFile,"KBANK","AES_TI");
        return rtnvalue == 0 ? true : false;
    }

    public static boolean decFile(String Infile,String outFile)
        throws Exception
    {
        int rtnvalue = CubeOneAPI.codecfile(Infile,outFile,"KBANK","AES_TI");
        return rtnvalue == 0 ? true : false;
    }
}

