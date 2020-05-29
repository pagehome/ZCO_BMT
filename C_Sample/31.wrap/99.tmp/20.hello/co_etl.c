#include <stdio.h>
#include <stdlib.h>
#include <coapi_user.h>

int  decLen = 0;
int  encLen = 0;

int  bFirst=1;
int  nRtn;
long nSessionId = 0;

char item1[20] = "SSN"; 
char sTblName[20] = "TBL";
char sColName[20] = "COL";
char sNull[10] = "";
char sUser[10] = "API_USER";
char sSid[10]  = "API_SID";

char encOut[2000];
char decOut[2000];

char *enc(char *in_plain) 
{

	// Initialize Key
    nRtn = CO_init (bFirst, sSid, sUser, sNull, sNull, sNull, sNull, sNull, sNull, sNull, nSessionId);

    if (nRtn != CTR_SUCCESS) {
    	printf("CO_init failed. returned %d\n", nRtn);
    	exit(1);
    }

	nRtn = CO_enc_char(in_plain, item1,10,sTblName,sColName,encOut,&encLen);

	if (nRtn == CTR_SUCCESS) {
		//printf("<<<<< CubeLog[enc] :: Encrypted[%d] is [%s]\n",encLen,encOut);
	}
	else {
		printf("\n<<<<< CubeLog[enc] :: Failed Encryption data with return [%d].\n",nRtn);
		return 0;
	}

	return encOut;

}

char *dec(char *in_cipher) 
{
	// Initialize Key
    nRtn = CO_init (bFirst, sSid, sUser, sNull, sNull, sNull, sNull, sNull, sNull, sNull, nSessionId);

    if (nRtn != CTR_SUCCESS) {
    	printf("CO_init failed. returned %d\n", nRtn);
    	exit(1);
    }

    nRtn = CO_dec_char(in_cipher,encLen,item1,10,sTblName,sColName, decOut);

	if (nRtn == CTR_SUCCESS) {
		//printf("<<<<< CubeLog[dec] :: Decrypted[%d] is [%s]\n\n", sizeof(in_cipher),decOut);
	}
	else {
		printf("\n<<<<< CubeLog[dec] :: Failed Decryption data with return [%d].\n",nRtn);
	}

	return decOut;
}

