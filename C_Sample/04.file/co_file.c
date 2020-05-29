/*
20007    No Privileges to access encrypted column    COER_NOTALLOWEDS
20008    Item is not specified                       COER_NOITEM_ENTEREDS
20009    Fail to get OCI Environment                 COER_FAIL_GET_OCIENVS
20010    Fail to Enabling Lob Buffering              COER_FAIL_ENABLE_BUFFERINGS
20011    Fail to treat Lob data                      COER_FAIL_LOBS
20012    Fail to Decrypt Lob data                    COER_FAIL_DEC_LOBS
20013    Fail to Encrypt Lob data                    COER_FAIL_ENC_LOBS
20014    Fail to Encryption data                     COER_FAIL_ENCRYPTIONS
20015    Fail to Encryption self testing             COER_FAIL_SELFTESTS
20016    Fatal error so should exception             COER_FATAL_ERROR
20017    error when check Initialize.                COER_FAIL_INIT
20018    error when check double enc.                COER_DOUBLE_CHECK

20021    error when SHMOpen file open.               COER_SHMFILEOPEN
20022    error when SHMOpen ftok.                    COER_SHMFTOK
20023    error when SHMOpen shmget.                  COER_SHMGETNORMAL
20024    error when SHMOpen shmget ENPSPC.           COER_SHMGETNOSPC
20025    error when SHMOpen shmget ENOMEM.           COER_SHMGETNOMEM
20031    error when shmat EMFILE.                    COER_SHMATEMFILE
20032    error when shmat ENOMEM.                    COER_SHMATENOMEM
20033    error when shmat EINVAL.                    COER_SHMATEINVAL
20034    error for Admin Act.: Ver 2.5-9021-C        COER_ADMINACTION
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* CubeOne : Include CubeOneAPI Header */
#include <coapi_user.h>

char sDecOut[2000];
unsigned char sEncOut[2000];

/*
char sPlain[] = "한글"; 
char sItem[] = "SHA256"; 
*/

char sPlain[100] = "한글테스트"; 
char sItem[100] = "AES_PI"; 

int nDecLen, nEncLen, nRtn;

int basic();
int fileEUC();
int fileUTF();

int main (int argc, char* argv[])
{
    printf("########################################################\n");
    printf("#########  CubeOneAPI-C Self Test Program ##############\n");
    printf("########################################################\n\n");

    /*memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));*/

    basic();

    fileEUC();
    fileUTF();

}

int fileEUC()
{
    return 0;

}

int fileUTF()
{
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


