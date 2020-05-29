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

int nDecLen, nEncLen, nRtn;

/* for salt */
unsigned char sEncSaltOut[2000];
int nEncSaltLen;

/* 
char sPlain[100] = "한글테스트K"; 
char sPlain[100] = "1234567890123";
*/
char sPlain[100] = "1234567890123";
//char sItem[100] = "AES256"; 
char sItem[100] = "SHA512"; 
char sItemSalt[100] = "SHA256_SALT"; 

int get_envdata();
int basic();
int basic_salt();
int order();
int basic_getbyte();

int main (int argc, char* argv[])
{
    printf("########################################################\n");
    printf("#########  CubeOneAPI-C Self Test Program ##############\n");
    printf("########################################################\n\n");

    memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));
 
/*   
    get_envdata();
    order();
*/
    basic();

    basic_salt();
    basic_getbyte();
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

int basic_getbyte()
{
    printf ("#########################################\n" );
    printf ("#### basic_getbyte() :: start ..... !!!\n" );
    printf ("#########################################\n" );

    printf("\n<<< CubeLog :: ITEM = [%s]\n",sItem);

    int nReadSize = strlen(sPlain);

    printf("<<< CubeLog :: strlen(sPlain) = %d \n" , nReadSize);
    

    /*******************************************************/
    printf ("\n[2] Enc Test\n");
    nRtn = CO_enc_byte(sPlain, nReadSize, sItem, 10, "TBL", "COL", sEncOut, &nEncLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: CO_enc_byte = [%s]\n" , sEncOut);
        printf ("<<< CubeLog :: strlen(CO_enc_byte) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );
    }
    else {
        printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
        return 0;
    }


    /********************************************************/
    printf ("\n[3] Dec Test\n");

    nRtn = CO_dec_byte((char *)sEncOut, nEncLen, sItem, 10, "TBL", "COL", (unsigned char *)sDecOut, &nDecLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: CO_dec_byte = [%s]\n" , sDecOut);
        printf ("<<< CubeLog :: strlen(CO_dec_byte) = %ld \n" , strlen(sDecOut) );
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
    }


    printf("\n#### basic_getbyte() :: Success..... !!!\n\n" );

    return 0;	
}

int basic_salt() 
{
    printf ("####################################\n" );
    printf ("#### Basic(SALT)-Test :: start ..... !!!\n" );
    printf ("####################################\n" );

    char salt[21];
    memset(salt, 0x00, sizeof(salt));
    printf("\n<<< CubeLog :: ITEM(SALT) = [%s]\n",sItemSalt);

    printf ("\n[1] Plain Test\n");

    printf ("<<< CubeLog :: sPlain = [%s]\n" , sPlain);
    printf ("<<< CubeLog :: strlen(sPlain) = %ld \n" , strlen(sPlain));
    
    /******************************************************/
    printf ("\n[2] Enc Test\n");
    nRtn = CO_enc_char(sPlain, sItemSalt,10,"TBL","COL",sEncOut,&nEncLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: coencchar = [%s]\n" , sEncOut);
        printf ("<<< CubeLog :: strlen(encrypt) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );
        strncpy(salt, (char *)sEncOut, 20);
        printf ("<<< CubeLog :: salt = [%s]\n" , salt);
        printf ("<<< CubeLog :: strlen(salt) = %ld\n" , strlen(salt));
    }
    else {
        printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
        return 0;
    }

    printf ("-----------------------------------------------------------------\n");
/*

CO_salt_sel  & CO_hash_salt : use same parameter But return value is different  ..
   char   *inval,  -- plain text
   char   *sSalt,  -- salt text 
   int    nType,   -- 256 (when sha256)
   BYTE   *encOut, -- result string
   int    *encLen  -- result length(CO_salt_sel : 84 , CO_hash_salt : 64 )
) 
*/ 
    nRtn = CO_hash_salt(sPlain, salt, 256, sEncSaltOut, &nEncSaltLen); 
    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: CO_hash_salt = [%s]\n" , sEncSaltOut);
        printf ("<<< CubeLog :: strlen(CO_hash_salt) = %ld,%d \n" , strlen((char *)sEncSaltOut),nEncSaltLen );
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
    }


    printf ("-----------------------------------------------------------------\n");
    nRtn = CO_salt_sel(sPlain, salt, 256, sEncSaltOut, &nEncSaltLen); 
    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: CO_salt_sel = [%s]\n" , sEncSaltOut);
        printf ("<<< CubeLog :: strlen(CO_salt_sel) = %ld, %d \n" , strlen((char *)sEncSaltOut), nEncSaltLen );
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
    }

    if(strcmp((char *)sEncSaltOut,(char *)sEncOut) == CTR_SUCCESS) {
        printf ("<<< CubeLog :: CO_salt_sel Result :: True  \n" );
    } 
    else {
        printf ("<<< CubeLog :: CO_salt_sel Result :: False  \n" );
    }

    /******************************************************/
    printf ("\n[3] Dec Test\n");

    nRtn = CO_dec_char(sEncOut,nEncLen,sItemSalt,10,"TBL","COL", sDecOut);

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

int order() 
{
    int nIdxCharLen, nIdxCharSelLen;
    char sIdxChar[2000], sIdxCharSel[2000];

    printf ("####################################\n" );
    printf ("#### Order-Test :: start ..... !!!\n" );
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
    printf ("\n[3] coindexchar Test : XX1.ENC_INDEX_VARCHAR2(enc_column,'ITEM') \n");
    nRtn = CO_index_char(sEncOut, nEncLen, sItem, "TBL", "COL", sIdxChar, &nIdxCharLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: sIdxChar = [%s]\n" , sIdxChar);
        printf ("<<< CubeLog :: strlen(sIdxChar) = %ld,%d \n" , strlen(sIdxChar), nIdxCharLen );
    }
    else {
        printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
        return 0;
    }
    /******************************************************/

    printf ("\n[4] coindexcharsel Test : XX1.ENC_INDEX_VARCHAR2_SEL('plain-constant','ITEM')\n");

    nRtn = CO_index_char_sel(sPlain, sItem, "TBL", "COL", sIdxCharSel, &nIdxCharSelLen);

    if (nRtn == CTR_SUCCESS) {
        printf ("<<< CubeLog :: sIdxCharSel = [%s]\n" , sIdxCharSel);
        printf ("<<< CubeLog :: strlen(sIdxCharSel) = %ld,%d \n\n" , strlen(sIdxCharSel), nIdxCharSelLen);
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
    }

    if(strcmp(sIdxChar, sIdxCharSel) == 0) {
        printf("<<< CubeLog :: idxcharsel & idxchar same !!\n" );
    } else {
        printf("<<< CubeLog :: idxcharsel & idxchar not same CHECK CHECK !! \n" );
    }

    printf("\n#### Order-Test :: Success..... !!!\n\n" );
    return 0;
}

int get_envdata()
{
    printf ("####################################\n" );
    printf ("#### Get CubeOne Env :: start .. !!!\n" );
    printf ("####################################\n" );

    printf("<<< CubeLog :: $DBNAME = [%s]\n", getenv("DBNAME"));
    printf("<<< CubeLog :: $CO_HOME = [%s]\n", getenv("CO_HOME"));
    
    FILE *pFile = NULL;
    char path[100];
    char *sub1 = "/.cube/";
    char *sub2 = "/env.dat";

    memset(path, 0x00, sizeof(path));

    strcat(path, getenv("CO_HOME"));
    strcat(path, sub1);
    strcat(path, getenv("DBNAME"));
    strcat(path, sub2);

    printf("<<< CubeLog :: Env Path = [%s]\n", path);

    pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        char strTemp[255];
        char *pStr;

        while(!feof(pFile)) 
        {
            pStr = fgets(strTemp, sizeof(strTemp), pFile);
            printf("%s", strTemp);
        }
    } 
    else 
    {
        printf("<<< CubeLog :: file open error\n");
    }

    printf("\n#### Get CubeOne Env :: enc ........ !!!\n\n" );

    return 0;
}




