
package com.cubeone;


public class CubeOneAPI
{

    public CubeOneAPI()
    {
        errCode = new byte[6];
    }


    public static  native int coinit(int i, String s, String s1, String s2, String s3, String s4, String s5, String s6, 
            String s7, String s8, long l);


 //   public static synchronized  native String coencchar(String s, String s1, int i, String s2, String s3, byte abyte0[]);
    public static   native String coencchar(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    
    public static  native String coencbytes(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static  native String coencbyte(byte abyte0[], String s, int i, String s1, String s2, byte abyte1[]);

    public static synchronized native String coencblob(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static  native String codecchar(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static  native byte[] codecbyte(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static  native byte[] codecbytes(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static synchronized native byte[] codecblob(String s, String s1, int i, String s2, String s3, byte abyte0[]);


   

    private static int bFirst = 1;
    private static String stringSID = "CUBEHP10";
    private static String stringITEM = "ICAS";
    private static String stringTBL = "ICASTBL";
    private static String stringCOL = "ICASCOL";
    private static String vIPAddress = "";
    private static String vSessionId = "100";
    private static String vMachine = "";
    private static String vUser = "DEMO";
    private static String vPassword = "";
    private static String vOSUser = "";
    private static String vAPPName = "";
    private static String vModule = "";
    private static String vTerminal = "";
    private static long iSessionId = 100L;
    private byte errCode[];
    private static int staticFirst = 1;

    static 
    {
        System.loadLibrary("COencapi");
    }
}

