#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "coapi_user.h"

int main (argc, argv)
    int     argc;
    char    *argv[];
{
    int     nRtn;
    char    *inval;
    char    *sTblName, *sColName;
    unsigned char   encOut[2000];
    char    decOut[2000];
    int     decLen;
    int     encLen;
    int     i;
    int        total = 3000000; 

    time_t start,end;
    double dif;

    printf ("Initialing...\n");
    memset (encOut, 0x00, sizeof (encOut));
    memset (decOut, 0x00, sizeof (decOut));

    /* Test CO_init() 
    nRtn = CO_init (1, "API", "SA", "","","","","","","",100);
    if (nRtn != CTR_SUCCESS) {
        printf ("CO_init failed. returned %d\n", nRtn);
        exit(1);
    }
    */


    /* Test CO_enc_char() */
    inval = "5086-8545-3474-1780";
    sTblName = "TBL";
    sColName = "COL";

    /* from YB */
    char *item[]= {
        "3DES",
        "AES128","AES192","AES256",
        "AES256_LE", "AES256_LN", "AES256_PART", "AES256_RE","AES256_RN",
        "ARIA128","ARIA192","ARIA256",
        "ARIA256_LE", "ARIA256_LN", "ARIA256_RE","ARIA256_RN",
        "DES","SEED",
        "SHA256", "SHA384", "SHA512"
    };

    printf ("\nEncrypting [%s] Tbl=[%s], Col=[%s]...\n",inval, sTblName, sColName);
    for (i=0; i<sizeof(item)/sizeof(*item); i++) {
        nRtn = CO_enc_char(inval, item[i],1,sTblName,sColName,encOut,&encLen); 
        printf ("[%s] Encrypted data is [%s]  errcode=[%d]\n",item[i],encOut,nRtn);
        if (!strstr(item[i],"SHA") ) { /* if item is "SHA",run */
            nRtn = CO_dec_char(encOut,encLen,item[i],0,sTblName,sColName, decOut); 
            printf ("[%s] Decrypted data is [%s]  errcode=[%d]\n\n",item[i],decOut,nRtn);
        }else {
            printf("\n");
        }
    }

    /* Part Pad Test */
    char *PartIn = "abcde6";
    nRtn = CO_enc_char(PartIn, item[6],1,sTblName,sColName,encOut,&encLen); 
    printf ("[%s] Part Pad Test Input =[%s]  Encrypted data is [%s]  errcode=[%d]\n\n",item[6],PartIn,encOut,nRtn);

    /* Check Sum Test */
    nRtn = CO_enc_char(inval, item[3],1,sTblName,sColName,encOut,&encLen); 
    printf ("[%s] Check Sum Encrypted data is [%s]  errcode=[%d]\n",item[3],encOut,nRtn);
    nRtn = CO_enc_char((char *)encOut, item[3],1,sTblName,sColName,encOut,&encLen); 
    if (nRtn == 20018 )
        printf ("[%s] Check Sum Test is Ok errcode = [%d]\n\n",item[3],nRtn);
    else 
        printf ("[%s] Check Sum Test is not Ok errcode = [%d]\n\n",item[3],nRtn);

    /* Enc Repeat Test */
/*
    printf ("\nStart ENC %d test...\n",total);
    time (&start);
    for (i=0; i<total; i++) {
        nRtn = CO_enc_char(inval, item[3],1,sTblName,sColName,encOut,&encLen); 
    }
    time (&end);
    dif = difftime (end,start);
    printf ("total time =[%.2lf]  The number of processed per second =[%d]\n", dif, total/(int)dif );
*/

}
