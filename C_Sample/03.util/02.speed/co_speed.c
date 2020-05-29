#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* CubeOne : nclude CubeOneAPI Header */
#include <coapi_user.h>

int main (int argc, char* argv[])
{
    char sDecOut[2000];
    unsigned char sEncOut[2000];
    char sPlain[2000] = "1234567890123";
    char sItem[100] = "AES256";

    int nRtn, nMenu;
    int nDecLen, nEncLen;

    int nTotal=10000000;
    time_t startTime, endTime;
    float elapTime;

    memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));

    printf( "********************************\n");
    printf( "**  CubeOne Test List     ******\n");
    printf( "********************************\n");
    printf( "**  1. Input Item         ******\n");
    printf( "**  2. Loop Count         ******\n");
    printf( "**  3. Encrypt Test       ******\n");
    printf( "**  4. Decrypt Test       ******\n");
    printf( "**  9. Exit               ******\n");
    printf( "********************************\n");

    while(1)
    {
        printf( "\nSelect Test List[1-9] : ");
        scanf("%d",&nMenu);
        if (nMenu == 9)
        {
            printf ("  - Terminiate this test progrom !!! \n\n");
            exit(0);
        }

        /* ITEM */
        else if (nMenu == 1)
        {
            printf( "  - Input Item  : " ); scanf ( "%s", sItem );
        }
        
	/* Loop Count */
        else if (nMenu == 2)
        {
            printf( "  - Loop Count  : " ); scanf ( "%d", &nTotal );
        }

        /* Encrypt */
        else if (nMenu == 3)
        {
            printf( "  - Input Plain [ ITEM = %s ] : ", sItem ); scanf ( "%s", sPlain );
            printf( "  - Loop Count [ %d ] : starting !! \n", nTotal );

            startTime = clock();

            int i=0;
            for(i=0; i<nTotal; i++)
	    {
                nRtn = CO_enc_char(sPlain, sItem,10,"TBL","COL",sEncOut,&nEncLen);
                /*
                if (nRtn == 0) {
                    printf ("  - encrypt = [%s]\n" , sEncOut);
                    printf ("  - strlen(encrypt) = %ld\n" , strlen((char *)sEncOut));
                } else {
                    printf ("  ** Encryption Failed.. [%d]\n" , nRtn);
                }
                */
            }
            endTime = clock();
            elapTime = (float)(endTime - startTime)/CLOCKS_PER_SEC;

            printf("  - elapTime : [%.2f sec]\n", elapTime);
            printf("  - EncPerSec[%.0f cnt/sec]\n",(float)nTotal/elapTime);
            printf("  - encrypt = [%s]\n" , sEncOut);
            printf("  - strlen(encrypt) = %ld,%d \n" , strlen((char *)sEncOut), nEncLen );
        }

        /* Decrypt */
        else if (nMenu == 4)
        {
            printf( "  - Input Encrypt [ ITEM = %s ] : ", sItem ); scanf ( "%s", sEncOut );
            printf( "  - Loop Count [ %d ] : starting !! \n", nTotal );

            startTime = clock();

            int i=0;
            for(i=0; i<nTotal; i++)
            {
                nRtn = CO_dec_char(sEncOut,nEncLen,sItem,10,"TBL","COL", sDecOut);

		/*
                if (nRtn == 0) {
                    printf ("  - decrypt = [%s]\n" , sDecOut);
                    printf ("  - strlen(decrypt) = %ld\n" , strlen(sDecOut));
                } else {
                    printf ("  ** Decryption Failed.. [%d]\n" , nRtn);
                }
		*/
            }
            endTime = clock();
            elapTime = (float)(endTime - startTime)/CLOCKS_PER_SEC;

            printf("  - elapTime : [%.2f sec]\n", elapTime);
            printf("  - DecPerSec[%.0f cnt/sec]\n",(float)nTotal/elapTime);
            printf("  - decrypt = [%s]\n" , sDecOut);
            printf("  - strlen(derypt) = %ld \n" , strlen((char *)sDecOut));
        }
    }
}

