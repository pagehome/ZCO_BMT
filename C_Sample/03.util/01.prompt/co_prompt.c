#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CubeOne : nclude CubeOneAPI Header */
#include <coapi_user.h>


int main (int argc, char* argv[])
{
    char sDecOut[2000];
    unsigned char sEncOut[2000];
    char sPlain[2000];
    char sItem[100] = "AES256" ;

    int nRtn, nMenu;
    int nDecLen, nEncLen;

    memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));


    CO_init_api("API");

    printf( "********************************\n");
    printf( "**  CubeOne Test List     ******\n");
    printf( "********************************\n");
    printf( "**  1. Input Item         ******\n");
    printf( "**  2. Encrypt Test       ******\n");
    printf( "**  3. Decrypt Test       ******\n");
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
            printf( "  - Input Item  : " ); 
            scanf ( "%s", sItem );
        }

        /* Encrypt */
        else if (nMenu == 2)
        {
            printf( "  - Input Plain [ ITEM = %s ] : ", sItem ); 
            scanf ( "%s", sPlain );

            nRtn = CO_enc_char(sPlain, sItem,10,"TBL","COL",sEncOut,&nEncLen);

            if (nRtn == 0) {
                printf ("  - encrypt = [%s]\n" , sEncOut);
                printf ("  - strlen(encrypt) = %ld\n" , strlen((char *)sEncOut));
            } else {
                printf ("  ** Encryption Failed.. [%d]\n" , nRtn);
            }
        }

        /* Decrypt */
        else if (nMenu == 3)
        {
            printf( "  - Input Encrypt [ ITEM = %s ] : ", sItem ); 
            scanf ( "%s", sEncOut );

            nRtn = CO_dec_char(sEncOut,strlen((char *)sEncOut),sItem,10,"TBL","COL", sDecOut);

            if (nRtn == 0) {
                printf ("  - decrypt = [%s]\n" , sDecOut);
                printf ("  - strlen(decrypt) = %ld\n" , strlen(sDecOut));
            } else {
                printf ("  ** Decryption Failed.. [%d]\n" , nRtn);
            }
        }
    }
}

