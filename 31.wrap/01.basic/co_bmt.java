
/*
20007	No Privileges to access encrypted column    COER_NOTALLOWEDS
20008	Item is not specified                       COER_NOITEM_ENTEREDS
20009	Fail to get OCI Environment                 COER_FAIL_GET_OCIENVS
20010	Fail to Enabling Lob Buffering              COER_FAIL_ENABLE_BUFFERINGS
20011	Fail to treat Lob data                      COER_FAIL_LOBS
20012	Fail to Decrypt Lob data                    COER_FAIL_DEC_LOBS
20013	Fail to Encrypt Lob data                    COER_FAIL_ENC_LOBS
20014	Fail to Encryption data                     COER_FAIL_ENCRYPTIONS
20015	Fail to Encryption self testing             COER_FAIL_SELFTESTS
20016	Fatal error so should exception             COER_FATAL_ERROR
20017	error when check Initialize.                COER_FAIL_INIT
20018	error when check double enc.                COER_DOUBLE_CHECK

20021	error when SHMOpen file open.  				COER_SHMFILEOPEN
20022	error when SHMOpen ftok.                    COER_SHMFTOK
20023	error when SHMOpen shmget.                  COER_SHMGETNORMAL
20024	error when SHMOpen shmget ENPSPC.           COER_SHMGETNOSPC
20025	error when SHMOpen shmget ENOMEM.           COER_SHMGETNOMEM
20031	error when shmat EMFILE.                    COER_SHMATEMFILE
20032	error when shmat ENOMEM.                    COER_SHMATENOMEM
20033	error when shmat EINVAL.                    COER_SHMATEINVAL
20034	error for Admin Act.: Ver 2.5-9021-C        COER_ADMINACTION
*/


import java.io.*;
import java.text.*;
import com.cubeone.*;
import com.site.*;

public class co_bmt {

	static String plain = "1234567890123";
	static String encrypt = "" ;
	static String decrypt = "" ;

	static String item = "AES256" ;

	static byte[] errbyte = new byte[5];

	static long start_time;
	static long end_time;
	static long elap_time;
	//static int total = 10000000 ; 
	static int total = 5000000 ; 
	static DecimalFormat df = new DecimalFormat("#,##0");

	public static void main(String[] args) throws Exception{

		System.out.println("###############################################################");
		System.out.println("#########  CubeOneAPI for Wrap!!  Self Test Program ###########");
		System.out.println("###############################################################\n");

		/**************************************************************
		** !!!!!! Very Important !!!!!
		** 0) do not use coinit  ..if coinit is called many times then performance is bad ..
		** 1) Call this Function only once for performance ..
		** 2) CubeOneAPI.jcoinit ("API"); for Access Control ..
		**	    - user : OS telnet account
		**	    - ip/mac : Terminal PC  		
		** 3) CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100); is for Old-Version ..    
		***************************************************************/
		//CubeOneAPI.jcoinit (1, "API", "SA", "","","","","","","",100);
		//CubeOneAPI.jcoinit ("API");
     
		basic();
		speed();

	}

	static void basic() throws Exception{

		System.out.println("####################################" );
		System.out.println("#### Basic-Test :: start ..... !!!" );
		System.out.println("####################################" );

		System.out.println("\n[1] Plain Test  ");

		System.out.println("<<< CubeLog :: plain = [" + plain + "]");
		System.out.println("<<< CubeLog :: plain.length() = [" + plain.length()+ "]");


		System.out.println("\n[2] Enc Test ");

		//encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);
		CubeWrap4Site instWrap = CubeWrap4Site.getInstance();
		encrypt = instWrap.encryptAES(plain);

		System.out.println("<<< CubeLog :: encrypt = [" + encrypt + "]");
		System.out.println("<<< CubeLog :: encrypt.length() = [" + encrypt.length()+ "]");
		//System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");

		/********************************************************************************/
		/********************************************************************************/
		System.out.println("\n[3] Dec Test ");

		decrypt = instWrap.decryptAES(encrypt);

		System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
		System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");
		System.out.println("<<< CubeLog :: errbyte = [" + new String(errbyte) + "]");

		System.out.println("\n#### Basic-Test :: Success..... !!!\n\n" );

	}

	static void speed() throws Exception{

		System.out.println("####################################" );
		System.out.println("#### Speed-Test :: start ..... !!!" );
		System.out.println("####################################" );

		System.out.println("\n[1] Enc Speed ");
		start_time = System.currentTimeMillis();

        CubeWrap4Site instWrap = CubeWrap4Site.getInstance();
		for(int i=0; i<total;i++) {
			//encrypt = CubeOneAPI.coencchar(plain,item,11,"TBL","COL",errbyte);
        	encrypt = instWrap.encryptAES(plain);
		}
		end_time = System.currentTimeMillis();
		elap_time = (end_time - start_time) / 1000; //

		System.out.println("<<< CubeLog  :: elap_time = [" + String.valueOf(elap_time) + " sec]");
		System.out.println("<<< CubeLog  :: EncPerSec = [" + df.format(total/elap_time) + " cnt/sec]");

		System.out.println("<<< CubeLog  :: encrypt = [" + encrypt + "]");
		System.out.println("<<< CubeLog  :: encrypt.length() = [" + encrypt.length() + "]");

		/********************************************************************************/
		/********************************************************************************/

		System.out.println("\n[2] Dec Speed ");

		start_time = System.currentTimeMillis();
		for(int i=0; i<total;i++) {
			//decrypt = CubeOneAPI.codecchar(encrypt,item,11,"TBL","COL",errbyte);
			decrypt = instWrap.decryptAES(encrypt);
		}
		end_time = System.currentTimeMillis();
		elap_time = (end_time - start_time) / 1000; //

		System.out.println("<<< CubeLog :: elap_time = [" + String.valueOf(elap_time) + " sec]");
		System.out.println("<<< CubeLog :: DecPerSec = [" + df.format(total/elap_time) + " cnt/sec]");

		System.out.println("<<< CubeLog :: decrypt = [" + decrypt + "]");
		System.out.println("<<< CubeLog :: decrypt.length() = [" +decrypt.length() + "]");

		System.out.println("\n#### Speed-Test :: Success..... !!!\n\n" );
	}
}

