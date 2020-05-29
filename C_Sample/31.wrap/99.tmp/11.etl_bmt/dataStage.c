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



main (int argc, char *argv[])
{ 
	basic();
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

