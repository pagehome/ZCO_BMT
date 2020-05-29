/*
20007   No Privileges to access encrypted column    COER_NOTALLOWEDS
20008   Item is not specified                       COER_NOITEM_ENTEREDS
20009   Fail to get OCI Environment                 COER_FAIL_GET_OCIENVS
20010   Fail to Enabling Lob Buffering              COER_FAIL_ENABLE_BUFFERINGS
20011   Fail to treat Lob data                      COER_FAIL_LOBS
20012   Fail to Decrypt Lob data                    COER_FAIL_DEC_LOBS
20013   Fail to Encrypt Lob data                    COER_FAIL_ENC_LOBS
20014   Fail to Encryption data                     COER_FAIL_ENCRYPTIONS
20015   Fail to Encryption self testing             COER_FAIL_SELFTESTS
20016   Fatal error so should exception             COER_FATAL_ERROR
20017   error when check Initialize.                COER_FAIL_INIT
20018   error when check double enc.                COER_DOUBLE_CHECK

20021   error when SHMOpen file open.               COER_SHMFILEOPEN
20022   error when SHMOpen ftok.                    COER_SHMFTOK
20023   error when SHMOpen shmget.                  COER_SHMGETNORMAL
20024   error when SHMOpen shmget ENPSPC.           COER_SHMGETNOSPC
20025   error when SHMOpen shmget ENOMEM.           COER_SHMGETNOMEM
20031   error when shmat EMFILE.                    COER_SHMATEMFILE
20032   error when shmat ENOMEM.                    COER_SHMATENOMEM
20033   error when shmat EINVAL.                    COER_SHMATEINVAL
20034   error for Admin Act.: Ver 2.5-9021-C        COER_ADMINACTION
*/

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/***************************************/
/* CubeOne : Include CubeOneAPI Header */
/* cpp can use c-function by use extern "C" */
//#include <coapi_user.h>
#ifndef BYTE
#define BYTE    unsigned char
#endif

#ifndef CTR_SUCCESS
#define CTR_SUCCESS     0
#endif

extern "C" int CO_init (short int, char *, char *, char *, char *, char *, char *, char *, char *, char *, long);
extern "C" int CO_enc_char      (char *, char *, short int, char *, char *, BYTE *, int *);
extern "C" int CO_dec_char      (BYTE *, int, char *, short int, char *, char *, char *);

char sDecOut[2000];
unsigned char sEncOut[2000];

char sIdxChar[2000];
char sIdxCharSel[2000];

char *sPlain = "1234567890123";
char *sItem = "SSN";
char *sItemSalt = "SHA256_SALT";

int nDecLen, nEncLen, nRtn;
int nIdxCharLen, nIdxCharSelLen;

int nTotal=10000000;

int basic();
int speed();

int main(){

    cout << "########################################################\n";
    cout << "#########  CubeOneAPI-C++ Self Test Program ############\n";
    cout << "########################################################\n\n";

    /*memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));*/

    /*********************************/
    /* Initializing Key  *************/ 
    /*********************************/
    /**************************************************************
    ** !!!!!! Very Important !!!!!
    ** 0) do not use coinit  ..if coinit is called many times then performance is bad ..
    ** 1) Call this Function only once for performance ..
    ** 2) CO_init_api ("API"); for Access Controll ..
    **      - user : OS telnet account
    **      - ip/mac : Terminal PC          
    ** 3) CO_init (0, "API", "SA", "","","","","","","",100); is for Old-Version ..    
    ***************************************************************/
    /*  nRtn = CO_init (bFirst, sSid, sUser, sNull, sNull, sNull, sNull, sNull, sNull, sNull, nSessionId);
                                            ip Machine OsUser Program Module Terminal Psswd SeesionId */
    /* nRtn = CO_init (0, "API", "SA", "","",     "",    "",     "",    "",      "",   0); */
    /*nRtn = CO_init_api ("API");*/

 /*   nRtn = CO_init (0, "API", "SA", "","",     "",    "",     "",    "",      "",   0);  */

    if (nRtn != CTR_SUCCESS) {
        printf("<<< CubeLog :: CO_init failed. returned %d\n", nRtn);
        exit(1);
    } 

    basic();
    speed();

    return 0;
} 


int basic()
{
    printf ("####################################\n" );
    printf ("#### Basic-Test :: start ..... !!!\n" );
    printf ("####################################\n" );
    printf("\n<<< CubeLog :: ITEM = [%s]\n",sItem);

    printf ("\n[1] Plain Test\n");

    printf ("<<< CubeLog :: sPlain = [%s]\n" , sPlain);
    printf ("<<< CubeLog :: strlen(sPlain) = %ld \n" , strlen(sPlain));

    /******************************************************/
    printf ("\n[2] Enc Test\n");
    nRtn = CO_enc_char(sPlain, sItem,10,"TBL","COL",sEncOut,&nEncLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: encrypt = [%s]\n" , sEncOut);
        printf ("<<< CubeLog :: strlen(encrypt) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );
    }
    else {
        printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
        return 0;
    }

    /******************************************************/
    printf ("\n[3] Dec Test\n");

    nRtn = CO_dec_char(sEncOut,nEncLen,sItem,10,"TBL","COL", sDecOut);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: decrypt = [%s]\n" , sDecOut);
        printf ("<<< CubeLog :: strlen(decrypt) = %ld \n" , strlen(sDecOut) );
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
    }

    printf("\n#### Basic-Test :: Success..... !!!\n\n" );
    return 0;
}



int speed()
{
    printf ("####################################\n" );
    printf ("#### Speed-Test(Data) :: start ..... !!!\n" );
    printf ("####################################\n\n" );

    printf("<<< CubeLog :: nTotal : %d\n", nTotal);

    time_t startTime, endTime;
    float elapTime;
    int i = 0;

    printf("[1] Enc Speed .......................\n");

    startTime = clock();
    for(i=0; i<nTotal; i++)
    {
        nRtn = CO_enc_char(sPlain, sItem,11,"TBL","COL",sEncOut,&nEncLen);

        if (nRtn == CTR_SUCCESS) {
            /*printf ("<<< CubeLog :: encrypt = [%s]\n" , sEncOut);
            printf ("<<< CubeLog :: strlen(encrypt) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );*/
        }
        else {
            printf("<<< CubeLog : Failed Encryption data with return [%d].\n",nRtn);
            return 0;
        }
    }
    endTime = clock();

    printf ("<<< CubeLog :: encrypt = [%s]\n" , sEncOut);
    printf ("<<< CubeLog :: strlen(encrypt) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );

    elapTime = (float)(endTime - startTime)/CLOCKS_PER_SEC;
    /*printf("<<< CubeLog :: (endTime - startTime)/CLOCKS_PER_SEC : [%.2f] \n\n", elapTime); */
    printf("<<< CubeLog :: EncPerSec[%.0f cnt]\n",(float)nTotal/elapTime);

    /********************************************************************************/
    /********************************************************************************/
    printf("\n\n");
    printf("[2] Dec Speed .......................\n");

    startTime = clock();
    for(i=0; i<nTotal; i++)
    {
        nRtn = CO_dec_char(sEncOut,nEncLen,sItem,10,"TBL","COL", sDecOut);

        if (nRtn == CTR_SUCCESS) {
            /*printf ("<<< CubeLog :: decrypt = [%s]\n" , sDecOut);
            printf ("<<< CubeLog :: strlen(decrypt) = %ld \n" , strlen(sDecOut) );*/
        }
        else {
            printf("\n<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
            return 0;
        }
    }
    endTime = clock();

    printf ("<<< CubeLog :: decrypt = [%s]\n" , sDecOut);
    printf ("<<< CubeLog :: strlen(decrypt) = %ld \n" , strlen(sDecOut) );

    elapTime = (float)(endTime - startTime)/CLOCKS_PER_SEC;
    /*printf("<<< CubeLog :: (endTime - startTime)/CLOCKS_PER_SEC : [%.2f] \n\n", elapTime); */
    printf("<<< CubeLog :: EncPerSec[%.0f cnt]\n",(float)nTotal/elapTime);

    printf("\n#### Speed-Test(Data) :: Success..... !!!\n\n" );
    return 0;
}

