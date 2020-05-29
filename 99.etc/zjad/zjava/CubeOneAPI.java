// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   CubeOneAPI.java

package com.cubeone;

import java.sql.*;

// Referenced classes of package com.cubeone:
//            COException

public class CubeOneAPI
{

    public CubeOneAPI()
    {
        errCode = new byte[6];
    }

    public static native String cogensn(int i, int j, int k);

    public static native int coinit(int i, String s, String s1, String s2, String s3, String s4, String s5, String s6, 
            String s7, String s8, long l);

    public static native int coinit(String s);

    public static native String coencrypt(String s, byte abyte0[]);

    public static native String codecrypt(String s, byte abyte0[]);

    public static native String coencchar(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static native String coencbytes(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static native byte[] coencbyteb(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static native String coencbyte(byte abyte0[], String s, int i, String s1, String s2, byte abyte1[]);

    public static native String coencblob(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static native String codecchar(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static native byte[] codecbyte(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static native byte[] codecbytes(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static native byte[] codecbyteb(byte abyte0[], int i, String s, int j, String s1, String s2, byte abyte1[]);

    public static native byte[] codecblob(String s, String s1, int i, String s2, String s3, byte abyte0[]);

    public static native int coinitf(String s);

    public static native String coenccharf(String s, String s1, byte abyte0[]);

    public static native String coencbytef(byte abyte0[], String s, byte abyte1[]);

    public static native String codeccharf(String s, String s1, byte abyte0[]);

    public static native byte[] codecbytef(String s, String s1, byte abyte0[]);

    public static native String coindexchar(String s, String s1, String s2, String s3, byte abyte0[]);

    public static native String coindexcharsel(String s, String s1, String s2, String s3, byte abyte0[]);

    public static native String cohashsalt(String s, String s1, int i, byte abyte0[]);

    public static native String cosaltsel(String s, String s1, int i, byte abyte0[]);

    private static void throwError(int i, byte abyte0[])
        throws COException
    {
        int j = Integer.parseInt(new String(abyte0));
        if(i == 1)
        {
            if(j == 20007)
            {
                String s = "Accessing Encrypted column is not allowd.";
                throw new COException(s, j);
            }
            if(j == 20014)
            {
                String s1 = "Fail to Encryption data.";
                throw new COException(s1, j);
            }
            if(j == 20016)
            {
                String s2 = "Fail to initialize Cubeone.";
                throw new COException(s2, j);
            }
        } else
        {
            if(j == 20007)
            {
                String s3 = "Accessing Encrypted column is not allowd.";
                throw new COException(s3, j);
            }
            if(j == 20016)
            {
                String s4 = "Fail to initialize Cubeone.";
                throw new COException(s4, j);
            }
            if(j == 20014)
            {
                String s5 = "Fail to Decryption data.";
                throw new COException(s5, j);
            }
        }
        if(j == 20008)
        {
            String s6 = "Item is not specified correctly.";
            throw new COException(s6, j);
        }
        if(j == 20009)
        {
            String s7 = "Fail to get OCI Environment for LOB.";
            throw new COException(s7, j);
        }
        if(j == 20010)
        {
            String s8 = "Fail to Enable Lob Buffering.";
            throw new COException(s8, j);
        }
        if(j == 20011)
        {
            String s9 = "Fail to treat Lob data.";
            throw new COException(s9, j);
        }
        if(j == 20012)
        {
            String s10 = "Fail to Decrypt Lob data.";
            throw new COException(s10, j);
        }
        if(j == 20013)
        {
            String s11 = "Fail to Encrypt Lob data.";
            throw new COException(s11, j);
        }
        if(j == 20015)
        {
            String s12 = "Fail to Encryption self testing.";
            throw new COException(s12, j);
        } else
        {
            String s13 = "Fatal Error. See event_log.";
            throw new COException(s13, j);
        }
    }

    public static String jcogensn(int i, int j, int k)
    {
        String s = cogensn(i, j, k);
        return s;
    }

    public static String jcoencrypt(String s)
        throws COException
    {
        byte abyte0[] = new byte[5];
        if(s == null)
            return null;
        String s1 = coencrypt(s, abyte0);
        if(abyte0[0] != 48)
            throwError(1, abyte0);
        return s1;
    }

    public static String jcodecrypt(String s)
        throws COException
    {
        byte abyte0[] = new byte[5];
        if(s == null)
            return s;
        String s1 = codecrypt(s, abyte0);
        if(abyte0[0] != 48)
            throwError(0, abyte0);
        return s1;
    }

    public static int jcoinit(int i, String s, String s1, String s2, String s3, String s4, String s5, String s6, 
            String s7, String s8, long l)
    {
        int j = 0;
        if(staticFirst == 0)
            return j;
        if(i == 1)
        {
            j = coinit(i, s, s1, s2, s3, s4, s5, s6, s7, s8, l);
            staticFirst = 0;
        }
        return j;
    }

    public static int jcoinit(String s)
    {
        int i = 0;
        if(staticFirst == 0)
        {
            return i;
        } else
        {
            int j = coinit(s);
            staticFirst = 0;
            return j;
        }
    }

    public static int jcoinit(String s, ResultSet resultset, int i)
    {
        int j = 0;
        try
        {
            resultset.setFetchSize(i);
        }
        catch(SQLException sqlexception) { }
        if(staticFirst == 0)
        {
            return j;
        } else
        {
            int k = coinit(s);
            staticFirst = 0;
            return k;
        }
    }

    public static int jcoinit(String s, PreparedStatement preparedstatement, int i)
    {
        int j = 0;
        try
        {
            preparedstatement.setFetchSize(i);
        }
        catch(SQLException sqlexception) { }
        if(staticFirst == 0)
        {
            return j;
        } else
        {
            int k = coinit(s);
            staticFirst = 0;
            return k;
        }
    }

    public static native String[] cogetitems(String s);

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
