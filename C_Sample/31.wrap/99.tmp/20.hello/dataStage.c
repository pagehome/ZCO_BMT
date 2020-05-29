#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // if not exist ,, Error ...
//#include <sys/timeb.h>

char *enc(char *);
char *dec(char *);


              //1234567890123
char *sPlain = "7645311566787";
char *sEncry; 	
char *sDecry; 	

char sDate[8+1];
char sTime[6+1];

int  ggbFirst=0;
int  ggnRtn;
long ggnSessionId = 0;

char ggitem1[20] = "SSN"; 
char ggsTblName[20] = "TBL";
char ggsColName[20] = "COL";
char ggsNull[10] = "";
char ggsUser[10] = "API_USER";
char ggsSid[10]  = "API_SID";


main (int argc, char *argv[])
{
	
		// Initialize Key
//    ggnRtn = CO_init (ggbFirst, ggsSid, ggsUser, ggsNull, ggsNull, ggsNull, ggsNull, ggsNull, ggsNull, ggsNull, ggnSessionId);

	 
	basic();
	speed();
}


int basic() 
{

	printf ("####################################\n" );
	printf ("#### Basic-Test :: start ..... !!!\n" );
	printf ("####################################\n" );

	printf ("\n[1] Plain Test\n");

	printf ("<<< CubeLog :: sPlain : [%s]\n" , sPlain);
	printf ("<<< CubeLog :: strlen(sPlain) : %d \n" , strlen(sPlain));
	
	/////////////////////////////////////////////////
	printf ("\n[2] Enc Test\n");

	sEncry = enc(sPlain);

	printf ("<<< CubeLog :: sEncry : [%s]\n" , sEncry);
	printf ("<<< CubeLog :: strlen(sEncry) : %d \n" , strlen(sEncry) );

	/////////////////////////////////////////////////
	printf ("\n[3] Dec Test\n");

	sDecry = dec(sEncry);

	printf ("<<< CubeLog :: sDecry : [%s]\n" , sDecry);
	printf ("<<< CubeLog :: strlen(sDecry) : %d \n" , strlen(sDecry) );


	printf("\n#### Basic-Test :: Success..... !!!\n\n" );
}


int speed() 
{

	printf ("####################################\n" );
	printf ("#### Speed-Test :: start ..... !!!\n" );
	printf ("####################################\n" );


	long start_time;
	long end_time;
	int  elap_time;
	int total = 20000000; // 10 thousand ..
	int i = 0;

	// Test Encrypting  
	printf("<<< CubeLog :: total : [%d] \n",total);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);
	start_time = clock();

	for(i=0; i<total; i++)
	{
		enc(sPlain);
	}
	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime);

	printf("<<< CubeLog :: Speed-Test : encrypted .......................\n");

	end_time = clock();
	elap_time = (end_time - start_time) / 1000000; //1,000,000

	printf("<<< CubeLog :: end_time - start_time : [%d] \n", end_time - start_time);
	printf("<<< CubeLog :: (end_time - start_time)/1000000 : [%.1f] \n", (end_time - start_time)/1000000);

	printf("<<< CubeLog :: EncPerSec[%d cnt]\n",total/elap_time);


	// Test Decrypting 
	printf("\n\n\n\n<<< CubeLog :: Speed-Test : decrypting .......................\n");

	Get_Time(sDate, sTime); 
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);

	start_time = clock();
	for(i=0; i<total; i++)
	{
		sDecry = dec(sEncry);
	}

	end_time = clock();

	Get_Time(sDate, sTime); 
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime); 
	printf("<<< CubeLog :: end_time - start_time : [%d] \n", end_time - start_time);

	printf("<<< CubeLog :: Speed-Test : decrypted .......................\n");
	elap_time = (end_time - start_time) / 1000000; //1,000,000
	printf("<<< CubeLog :: DecPerSec[%d cnt]\n",total/elap_time);


	printf("\n#### Speed-Test :: Success..... !!!\n\n" );

}





int Get_Time(char *Strdate, char *Strtime)
{
    struct tm *gtime;
    time_t clock;
    char sdate[9];
    char stime[7];

    time(&clock);
    gtime = localtime(&clock);

    sprintf(sdate, "%04d%02d%02d",
            gtime->tm_year + 1900, gtime->tm_mon + 1, gtime->tm_mday);

    sprintf(stime, "%02d%02d%02d",
            gtime->tm_hour, gtime->tm_min, gtime->tm_sec);
    memcpy(Strdate, sdate, sizeof(sdate));
    memcpy(Strtime, stime, sizeof(stime));
    return 0;
}

