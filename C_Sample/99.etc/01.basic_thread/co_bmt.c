
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


#include <stdio.h>
#include <stdlib.h>
#include <coapi_user.h>
#include <time.h>
#include <sys/timeb.h>
#include <string.h>
#include <pthread.h>

char decOut[2000];
char encOut[2000];
int  decLen = 0;
int  encLen = 0;

char sPlain[500] = "1234567890123";
/* char sPlain[500] = ""; */

/* for index test */
char sInval_idx[20] = "1234567890123456789";
char encOut_idx[2000];
int  encLen_idx = 0;

int  nRtn;
char item1[20] = "AES256"; 

char sDate[8+1];
char sTime[6+1];


int total;

int Get_Time(char *Strdate, char *Strtime);

main (argc, argv)
int	argc;
char *argv[];
{
	if(argc != 2) {
		printf("Enter total loop cnt !! \n");
		exit(0);
	}
	total = atoi(argv[1]);

	memset(encOut, 0x00, sizeof (encOut));
	memset(encOut_idx, 0x00, sizeof (encOut_idx));
	memset(decOut, 0x00, sizeof (decOut));
		
	/*********************************/
	/* Initializing Key  *************/ 
	/*********************************/

	/**************************************************************
	** !!!!!! Very Important !!!!!
	** 0) do not use coinit  ..if coinit is called many times then performance is bad ..
	** 1) Call this Function only once for performance ..
	** 2) CO_init_api ("API"); for Access Controll ..
	**	    - user : OS telnet account
	**	    - ip/mac : Terminal PC  		
	** 3) CO_init (1, "API", "SA", "","","","","","","",100); is for Old-Version ..    
	***************************************************************/
	/*	nRtn = CO_init (bFirst, sSid, sUser, sNull, sNull, sNull, sNull, sNull, sNull, sNull, nSessionId);
	                                        ip Machine OsUser Program Module Terminal Psswd SeesionId */
	nRtn = CO_init (0, "API", "SA", "","",     "",    "",     "",    "",      "",   0);
//nRtn = CO_init_api ("API");

	if (nRtn != CTR_SUCCESS) {
		printf("CO_init failed. returned %d\n", nRtn);
		exit(1);
	}

	basic();
	thread();

/*	
	speedIdx(); 
	speed();
*/

}

int basic() 
{
	printf ("####################################\n" );
	printf ("#### Basic-Test :: start ..... !!!\n" );
	printf ("####################################\n" );

	printf ("\n[1] Plain Test\n");

	printf ("<<< CubeLog :: sPlain : [%s]\n" , sPlain);
	printf ("<<< CubeLog :: strlen(sPlain) : %d \n" , strlen(sPlain));
	
	/******************************************************/
	printf ("\n[2] Enc Test\n");
	nRtn = CO_enc_char(sPlain, item1,10,"TBL","COL",encOut,&encLen);

	if (nRtn == CTR_SUCCESS) {
		printf ("<<< CubeLog :: encrypt : [%s]\n" , encOut);
		printf ("<<< CubeLog :: strlen(encrypt) : %d,%d \n" , strlen(encOut), encLen );
	}
	else {
		printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
		return 0;
	}

	/******************************************************/
	printf ("\n[3] Dec Test\n");

	nRtn = CO_dec_char(encOut,1000,item1,10,"TBL","COL", decOut);
	/*nRtn = CO_dec_char(encOut,encLen,item1,10,"TBL","COL", decOut);*/

	if (nRtn == CTR_SUCCESS) {
		printf ("<<< CubeLog :: decrypt : [%s]\n" , decOut);
		printf ("<<< CubeLog :: strlen(decrypt) : %d \n" , strlen(decOut) );
	}
	else {
		printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
	}

	/******************************************************/
	printf ("\n[4] index_scan Test\n");

	nRtn = CO_index_char_sel(sInval_idx,item1,"TBL","COL",encOut_idx,&encLen_idx);

	if (nRtn == CTR_SUCCESS) {
	printf ("<<< CubeLog :: index_scan : [%s]\n" , encOut_idx);
	printf ("<<< CubeLog :: strlen(index_scan) : %d \n" , strlen(encOut_idx) );
	}
	else {
		printf("<<< CubeLog :: Failed index_scan data with return [%d].\n",nRtn);
	}

	printf("\n#### Basic-Test :: Success..... !!!\n\n" );
}


int speed() 
{
	printf ("####################################\n" );
	printf ("#### Speed-Test(Data) :: start ..... !!!\n" );
	printf ("####################################\n\n" );

	long start_time;
	long end_time;
	int  elap_time;
	int i = 0;

	/********************/
	/* Test Encrypting **/
	/********************/

	printf("[1] Enc Speed .......................\n");
	printf("<<< CubeLog :: total : %d\n", total);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);
	start_time = clock();

	for(i=0; i<total; i++)
	{
		nRtn = CO_enc_char(sPlain, item1,1,"TBL","COL",encOut,&encLen);

		if (nRtn == CTR_SUCCESS) {
			/*printf ("<<< CubeLog :: Encrypted[%d] is [%s]\n",encLen,encOut); */
		}
		else {
			printf("\nFailed Encryption data with return [%d].\n",nRtn);
			return 0;
		}
	}
	printf ("<<< CubeLog :: Encrypted[%d] is [%s]\n",encLen,encOut);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime);

	end_time = clock();
	elap_time = (end_time - start_time) / 1000000; /*1,000,000 */

	printf("<<< CubeLog :: end_time - start_time : [%d] \n", end_time - start_time);
/*	printf("<<< CubeLog :: (end_time - start_time)/1000000 : [%.1f] \n\n", (end_time - start_time)/1000000); */

	printf("<<< CubeLog :: EncPerSec[%d cnt]\n",total/elap_time);


	/********************/
	/* Test Decrypting **/
	/********************/
	printf("\n\n");
	printf("[2] Dec Speed .......................\n");
	printf("<<< CubeLog :: total : %d\n", total);

	Get_Time(sDate, sTime); 
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);

	start_time = clock();
	for(i=0; i<total; i++)
	{
    	nRtn = CO_dec_char(encOut,encLen,item1,0,"TBL","COL", decOut);

		if (nRtn == CTR_SUCCESS) {
			/*printf ("<<< CubeLog :: Decrypted[%d] is [%s]\n\n", sizeof(decOut),decOut); */
		}
		else {
			printf("\n<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
			return 0;
		}
	}

	printf ("<<< CubeLog :: Decrypted[%d] is [%s]\n\n", sizeof(decOut),decOut);

	end_time = clock();

	Get_Time(sDate, sTime); 
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime); 
	printf("<<< CubeLog :: end_time - start_time : [%d] \n\n", end_time - start_time);

	elap_time = (end_time - start_time) / 1000000; /* 1,000,000 */
	printf("<<< CubeLog :: DecPerSec[%d cnt]\n",total/elap_time);

	printf("\n#### Speed-Test(Data) :: Success..... !!!\n\n" );
	
}



int speedIdx() 
{
	printf ("####################################\n" );
	printf ("#### Speed-Test(Index_Scan) :: start ..... !!!\n" );
	printf ("####################################\n\n" );

	long start_time;
	long end_time;
	int  elap_time;
	int i = 0;

	/********************/
	/* Test Encrypting **/
	/********************/
	printf("[1] Enc Speed .......................\n");
	printf("<<< CubeLog :: total : %d\n", total);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);
	start_time = clock();

	for(i=0; i<total; i++)
	{
		nRtn = CO_index_char_sel(sInval_idx,item1,"TBL","COL",encOut_idx,&encLen_idx);

		if (nRtn == CTR_SUCCESS) {
			/*printf ("<<< CubeLog :: Encrypted[%d] is [%s]\n",encLen,encOut); */
		}
		else {
			printf("\nFailed Encryption data with return [%d].\n",nRtn);
			return 0;
		}
	}

	printf ("<<< CubeLog :: index_scan : [%s]\n" , encOut_idx);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime);

	end_time = clock();
	elap_time = (end_time - start_time) / 1000000; /*1,000,000 */

	printf("<<< CubeLog :: end_time - start_time : [%d] \n", end_time - start_time);
/*	printf("<<< CubeLog :: (end_time - start_time)/1000000 : [%.1f] \n\n", (end_time - start_time)/1000000); */

	printf("<<< CubeLog :: EncPerSec[%d cnt]\n",total/elap_time);



	printf("\n#### Speed-Test(Index_Scan) :: Success..... !!!\n\n" );
	
}

int thread() 
{
	printf ("####################################\n" );
	printf ("#### thread test :: start ..... !!!\n" );
	printf ("####################################\n" );


	pthread_t thread1;
	int i=0;
	
	for(i=0;i<1000;i++) {
		printf("<<< CubeLog :: thread-cnt[%d cnt]\n",i);
		pthread_create (&thread1, NULL, (void *)&speed, (void *)NULL);
	}

	printf("\nthread test :: Success..... !!!\n\n" );
}


int Get_Time(char *Strdate, char *Strtime)
{
	struct tm *gtime;
	time_t clock;
	char sdate[9];
	char stime[7];
	
	time(&clock);
	gtime = localtime(&clock);
	
	sprintf(sdate, "%04d%02d%02d", gtime->tm_year + 1900, gtime->tm_mon + 1, gtime->tm_mday);
	
	sprintf(stime, "%02d%02d%02d", gtime->tm_hour, gtime->tm_min, gtime->tm_sec);
	memcpy(Strdate, sdate, sizeof(sdate));
	memcpy(Strtime, stime, sizeof(stime));
	return 0;
}



