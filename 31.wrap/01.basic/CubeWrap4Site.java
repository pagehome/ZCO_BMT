
// /home/tomcat/apache-tomcat-7.0.37/lib

package com.site;

import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import com.cubeone.*;


public class CubeWrap4Site
{
	
    public static String CUBEONE_SID = "API";
    public static String CUBEONE_USERID = "SA";
    public static String CUBEONE_AES = "AES256";
    public static String CUBEONE_SHA = "SHA256"; 
		public static String CUBEONE_TBL = "CubeWrap4Clone";
    public static final int CUBEONE_SEL = 10;
    public static final int CUBEONE_INS = 11;
    public static HashMap<String,String> CUBEONE_MESSAGE_CODE_MAP;
    public boolean debug;
    private static CubeWrap4Site CubeWrap4CloneInst = new CubeWrap4Site();

    static 
    {
        CUBEONE_MESSAGE_CODE_MAP =  new HashMap();
        CUBEONE_MESSAGE_CODE_MAP.put("20007", "Accessing Encrypted column is not allowd.");
        CUBEONE_MESSAGE_CODE_MAP.put("20008", "Item is not specified correctly.");
        CUBEONE_MESSAGE_CODE_MAP.put("20009", "Fail to get OCI Environment for LOB.");
        CUBEONE_MESSAGE_CODE_MAP.put("20010", "Fail to Enable Lob Buffering.");
        CUBEONE_MESSAGE_CODE_MAP.put("20011", "Fail to treat Lob data.");
        CUBEONE_MESSAGE_CODE_MAP.put("20012", "Fail to Decrypt Lob data.");
        CUBEONE_MESSAGE_CODE_MAP.put("20013", "Fail to Encrypt Lob data.");
        CUBEONE_MESSAGE_CODE_MAP.put("20014", "Fail to Encryption/Decryption data.");
        CUBEONE_MESSAGE_CODE_MAP.put("20015", "Fail to Encryption self testing.");
        CUBEONE_MESSAGE_CODE_MAP.put("20016", "Fatal error so should exception.");
        CUBEONE_MESSAGE_CODE_MAP.put("20017", "error when check Initialize.");
        CUBEONE_MESSAGE_CODE_MAP.put("20018", "error when check double enc");
    }

    public static CubeWrap4Site getInstance()
    {
        if(CubeWrap4CloneInst == null)
            CubeWrap4CloneInst = new CubeWrap4Site();
        return CubeWrap4CloneInst;
    }

    private CubeWrap4Site()
    {
        /**************************************************************
        ** !!!!!! Very Important !!!!!
        ** 0) do not use coinit  ..if coinit is called many times then performance is bad ..
        ** 1) Call this Function only once for performance ..
        ** 2) CubeOneAPI.jcoinit ("API"); for Access Control ..
        **      - user : OS telnet account
        **      - ip/mac : Terminal PC          
        ** 3) CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100); is for Old-Version ..    
        ***************************************************************/
        //CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100);
        //CubeOneAPI.jcoinit ("API");
        debug = false;
        CubeOneAPI.jcoinit(1, CUBEONE_SID, CUBEONE_USERID, "", "", "", "", "", "", "", 100L);
    }

    public String encryptAES(String plainText)
        throws COException
    {
        return encrypt(plainText, CUBEONE_AES);
    }

    public String encryptSHA(String plainText)
        throws COException
    {
        return encrypt(plainText, CUBEONE_SHA);
    }

    public String decryptAES(String encryptedText)
        throws COException
    {
        String decryptedText = null;
        String errString = null;
        byte errbyte[] = new byte[5];
        decryptedText = CubeOneAPI.codecchar(encryptedText, CUBEONE_AES, 11, CUBEONE_TBL, "encryptAES", errbyte);
        errString = new String(errbyte);
        if(debug)
            System.out.println((new StringBuilder("<<< CUBE_LOG >> CubeWrap4Clone.decryptAES() :: errString => ")).append(errString).toString());
        if(!errString.equals("00000"))
        {
            String messageCd = (String)CUBEONE_MESSAGE_CODE_MAP.get(errString);
            if(messageCd != null)
                throw new COException(messageCd, Integer.parseInt(errString));
            else
                throw new COException("Fatal Error. See event_log.", -1);
        } else
        {
            return decryptedText;
        }
    }

    public String encrypt(String plainText, String item)
        throws COException
    {
        String encryptedText = null;
        String errString = null;
        byte errbyte[] = new byte[5];
        encryptedText = CubeOneAPI.coencchar(plainText, item, 11, CUBEONE_TBL, "encryptAES", errbyte);
        errString = new String(errbyte);
        if(debug)
            System.out.println((new StringBuilder("<<< CUBE_LOG >> CubeWrap4Clone.encryptAES() :: errString => ")).append(errString).toString());
        if(!errString.equals("00000"))
        {
            String messageCd = (String)CUBEONE_MESSAGE_CODE_MAP.get(errString);
            if(messageCd != null)
                throw new COException(messageCd, Integer.parseInt(errString));
            else
                throw new COException("Fatal Error. See event_log.", -1);
        } else
        {
            return encryptedText;
        }
    } 

}

