using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;


public class COencAPI
{
    [DllImport("C:\\Program Files\\eGlobal Systems\\CubeOne Server\\coapi\\lib\\COencAPI.dll")]
    public static extern int CO_enc_byte(String inVal, int length, String item, int dml, String tbl, String col, byte[] encOut, ref int encLen);
    [DllImport("C:\\Program Files\\eGlobal Systems\\CubeOne Server\\coapi\\lib\\COencAPI.dll")]
    public static extern int CO_dec_byte(byte[] encOut, int encLen, String item, int dml, String tbl, String col, byte[] decOut, ref int decLen);


    [DllImport("C:\\Program Files\\eGlobal Systems\\CubeOne Server\\coapi\\lib\\COencAPI.dll")]
    public static extern int CO_enc_char(String inVal, String item, int dml, String tbl, String col, byte[] encOut, ref int encLen);
    [DllImport("C:\\Program Files\\eGlobal Systems\\CubeOne Server\\coapi\\lib\\COencAPI.dll")]
    public static extern int CO_dec_char(byte[] encOut, int encLen, String item, int dml, String tbl, String col, byte[] decOut);



}

namespace cubetest
{
    class Program
    {

        public static int GetEncLen(int len)
        {
            int multi, remainder = 0;
            int enclen = 0;
            multi = len / 16;
            remainder = len % 16;

            if (remainder == 0)
            {
                enclen = len + 16;
            }
            else
            {
                enclen = 16 * (multi + 1);
            }

            return enclen * 2;
        }



        static void Main(string[] args)
        {


            int nRtn; // 암복호화 수행 성공 여부 
            int encLen = 0; // 암호화 값의 길이 받을 변수
            String text = "1234567890123"; //암호화할 데이타
            int getLen = GetEncLen(text.Length);

            byte[] encbyte = new byte[getLen];

            System.Console.WriteLine("Input Length = [{0}]  Get Length :[{1}]  ", text.Length, getLen);

            System.Console.WriteLine("Initialing...");
            System.Console.WriteLine("P:[{0}]", text);


            //==================================ENC==============================
            nRtn = COencAPI.CO_enc_char(text, "AES256", 11, "sTblName", "sColName", encbyte, ref encLen);

            String encryptedText = Encoding.Default.GetString(encbyte);
            System.Console.WriteLine("encryptedText:[{0}]", encryptedText);
            System.Console.WriteLine("encryptedText.Length:[{0}]", encryptedText.Length);
            System.Console.WriteLine("encLen:[{0}]", encLen);

            //==================================DEC============================== 
            byte[] decbyte = new byte[encryptedText.Length];

            nRtn = COencAPI.CO_dec_char(encbyte, encLen, "AES256", 10, "sTblName", "sColName", decbyte);

            String decryptedText = Encoding.Default.GetString(decbyte);
            decryptedText = decryptedText.TrimEnd('\0');


            System.Console.WriteLine("D:[{0}]", decryptedText);



            //            System.Console.WriteLine("D:[{0}]", Encoding.Default.GetString(decbyte));


            /*

                        try
                        {

                            System.Console.WriteLine("############ C# Test Start ############\n");
                            String plainText = "1234567890123";




                            String encstr = encrypt_byte(plainText);                
                            System.Console.WriteLine("###### encrypt Test Start ######");
                            System.Console.WriteLine("plainText : [{0}]", plainText);
                            System.Console.WriteLine("encryptText : [{0}]", encstr);
                            System.Console.WriteLine("#### encrypt Test End..... !!!\n\n");

                            String decstr = decrypt_byte(encstr);
                            System.Console.WriteLine("###### decrypt Test Start ######");
                            System.Console.WriteLine("encryptText : [{0}]", encstr);
                            System.Console.WriteLine("decryptText : [{0}]", decstr);
                            System.Console.WriteLine("#### decrypt TEST End..... !!!\n\n");



                            String encstr_char = encrypt_char(plainText);
                            System.Console.WriteLine("###### encrypt Test Start ######");
                            System.Console.WriteLine("plainText : [{0}]", plainText);
                            System.Console.WriteLine("encryptText : [{0}]", encstr_char);
                            System.Console.WriteLine("#### encrypt Test End..... !!!\n\n");

                            String decstr_char = decrypt_char(encstr_char);
                            System.Console.WriteLine("###### decrypt Test Start ######");
                            System.Console.WriteLine("encryptText : [{0}]", encstr_char);
                            System.Console.WriteLine("decryptText : [{0}]", decstr_char);
                            System.Console.WriteLine("#### decrypt TEST End..... !!!\n\n");

                        }
                        catch (Exception e)
                        {
                            System.Console.WriteLine(e.Message);
                        }

            */



            Console.ReadKey();
        }


        static String encrypt_char(String plainText)
        {

            System.Console.WriteLine("<<< encrypt_char() : start");

            String encryptedText = null;
            int nRtn;       // 암복호화 수행 성공 여부
            int encLen = 0; // 암호화 값의 길이 받을 변수
            byte[] encbyte = new byte[1000];
            nRtn = COencAPI.CO_enc_char(plainText, "AES256", 11, null, null, encbyte, ref encLen);

            if (nRtn == 0)  // CTR_SUCCESS
            {
                encryptedText = Encoding.Default.GetString(encbyte);
                encryptedText = encryptedText.Substring(0, encLen);
            }
            else
            {
                throw new Exception("encryptPI Error: " + nRtn);
            }

            System.Console.WriteLine("<<< encrypt_char() : end");

            return encryptedText;
        }


        static String decrypt_char(String encryptedText)
        {
            System.Console.WriteLine("<<< decrypt_char() : start");

            String decryptedText = null;
            byte[] encbyte = Encoding.Default.GetBytes(encryptedText);
            int nRtn;       // 암복호화 수행 성공 여부
            byte[] decbyte = new byte[encbyte.Length];
            nRtn = COencAPI.CO_dec_char(encbyte, encbyte.Length, "AES256", 11, null, null, decbyte);

            if (nRtn == 0)  // CTR_SUCCESS
            {
                decryptedText = Encoding.Default.GetString(decbyte);
                decryptedText = decryptedText.Trim('\0');
            }
            else
            {
                throw new Exception("decryptPI Error: " + nRtn);
            }

            System.Console.WriteLine("<<< decrypt_char() : end");

            return decryptedText;
        }



        static String encrypt_byte(String plainText)
        {
            String encryptedText = null;
            int nRtn;       // 암복호화 수행 성공 여부
            int encLen = 0; // 암호화 값의 길이 받을 변수
            byte[] encbyte = new byte[1000];
            nRtn = COencAPI.CO_enc_byte(plainText, Encoding.Default.GetByteCount(plainText), "AES256", 11, null, null, encbyte, ref encLen);

            if (nRtn == 0)  // CTR_SUCCESS
            {
                encryptedText = Encoding.Default.GetString(encbyte);
                encryptedText = encryptedText.Substring(0, encLen);
            }
            else
            {
                throw new Exception("encryptPI Error: " + nRtn);
            }
            return encryptedText;
        }


        static String decrypt_byte(String encryptedText)
        {
            String decryptedText = null;
            byte[] encbyte = Encoding.Default.GetBytes(encryptedText);
            int nRtn;       // 암복호화 수행 성공 여부
            int decLen = 0; // 복호화 값의 길이 받을 변수
            byte[] decbyte = new byte[1000];
            nRtn = COencAPI.CO_dec_byte(encbyte, encbyte.Length, "AES256", 11, null, null, decbyte, ref decLen);

            if (nRtn == 0)  // CTR_SUCCESS
            {
                decryptedText = Encoding.Default.GetString(decbyte);
                decryptedText = decryptedText.Trim('\0');
                //decryptedText = decryptedText.Substring(0, decLen).Trim('\0');
            }
            else
            {
                throw new Exception("decryptPI Error: " + nRtn);
            }
            return decryptedText;
        }
    }
}