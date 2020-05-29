#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coapi_user.h"

main (argc, argv)
int	argc;
char	*argv[];
{
	int	nRtn;
	unsigned char	encOut[2000];
	char	decOut[2000];
	int	decLen;
	int	encLen;

	char	inval[10]="abcde12345";
	char	sid[3]="API";
	char    item[3]="SSN";

	printf ("Initialing...\n");
	memset (encOut, 0x00, sizeof (encOut));
	memset (decOut, 0x00, sizeof (decOut));

	nRtn = CO_init_api (sid);

	/* Test CO_enc_char() */
	printf ("\nEncrypting [%s] with item [%s]...\n",inval, item);
	nRtn = CO_enc_char(inval, item,11,"","",encOut,&encLen); 
	printf ("Encrypted data is [%s] errcode[%d]\n",encOut,nRtn);
	nRtn = CO_dec_char(encOut,encLen,item,10,"","", decOut); 
	printf ("Decrypted data is [%s] errcode[%d]\n\n", decOut,nRtn);

	/* Test CO_index_char() */
	nRtn = CO_index_char(encOut,encLen, item,"","",decOut,&decLen);
        printf ("index_char is [%s] errcode[%d]\n",decOut,nRtn);
        nRtn = CO_index_char_sel (inval,item,"","",encOut,&encLen);
        printf ("index_charsel is [%s] errcode[%d]\n\n",encOut,nRtn);
	
COCLOSE:
	nRtn = CO_close(sid); 
	if (nRtn != 0) {
		printf ("CO_close failed. returned %d\n", nRtn);
	}
	else {
		printf ("CO_close has been successed\n");
	}
	printf ("\nExiting %s\n", argv[0]);
	exit(0);
}

