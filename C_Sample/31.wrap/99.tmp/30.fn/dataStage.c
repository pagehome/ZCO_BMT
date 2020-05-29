#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // if not exist ,, Error ...

void enc(char *);
void enc_m(char *,char *,char *,char *,char *, char *, char * , char *,char *, char *);

char sDate[8+1];
char sTime[6+1];

char *sPlain = "7645311566787";
                
int total    =  9000000; // 10 thousand ..
int fn_total =     1000; // 10 thousand ..


main (int argc, char *argv[])
{
	
	speed();
}

int speed() 
{

	printf ("####################################\n" );
	printf ("#### Speed-Test :: start ..... !!!\n" );
	printf ("####################################\n" );


	long start_time;
	long end_time;
	int  elap_time;
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




	// Test Encrypting  
	printf("<<< CubeLog :: total : [%d] \n",total);

	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: start-Time : [%s] \n", sTime);
	start_time = clock();

	for(i=0; i<total; i++)
	{
		enc_m(sPlain,sPlain,sPlain,sPlain,sPlain,sPlain,sPlain,sPlain,sPlain,sPlain);
	}
	Get_Time(sDate, sTime);
	printf("<<< CubeLog :: end-Time   : [%s] \n", sTime);

	printf("<<< CubeLog :: Speed-Test : encrypted .......................\n");

	end_time = clock();
	elap_time = (end_time - start_time) / 1000000; //1,000,000

	printf("<<< CubeLog :: end_time - start_time : [%d] \n", end_time - start_time);
	printf("<<< CubeLog :: (end_time - start_time)/1000000 : [%.1f] \n", (end_time - start_time)/1000000);

	printf("<<< CubeLog :: EncPerSec[%d cnt]\n",total/elap_time);






	printf("\n#### Speed-Test :: Success..... !!!\n\n" );

}


void enc(char *col1) {

	int i=0;

	for(i=0; i<fn_total; i++)
	{
	}
}

void enc_m(char *col1,char *col2,char *col3,char *col4,char *col5, char *col6, char *col7 , char *col8,char *col9, char *col10) {
	
	int i=0;

	for(i=0; i<fn_total; i++)
	{
	}
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

