#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CubeOne : nclude CubeOneAPI Header */
#include <coapi_user.h>

#define ITEM    "AES256"

int encJumin(char *pPlain, char *pEnc);
int decJumin(char *pEncIn, char *pDecOut);

int main (int argc, char* argv[])
{
    char sDecOut[2000];
    char sEncOut[2000];
    char sPlain[2000];
    int nRtn, nMenu;

    memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut));

    printf( "********************************\n");
    printf( "**  CubeOne Test List     ******\n");
    printf( "********************************\n");
    printf( "**  0. Exit               ******\n");
    printf( "**  1. Encrypt            ******\n");
    printf( "**  2. Decrypt            ******\n");
    printf( "********************************\n");

    while(1)
    {
        printf( "\nSelect Test List[0-2] : ");
        scanf("%d",&nMenu);
        if (nMenu == 0) 
        {
            printf ("  - Terminiate this test progrom !!! \n");
            exit(0);    
        }
        else if (nMenu == 1) 
        {
            printf( "  - Input Plain String  : " ); scanf ( "%s", sPlain );
            nRtn = encJumin(sPlain, sEncOut);

            if (nRtn == 0) {
                printf ("  - encrypt = [%s]\n" , sEncOut);
                printf ("  - strlen(encrypt) = %ld\n" , strlen((char *)sEncOut));
            } else {
                // Error ó�� ..
                printf ("  ** Encryption Failed.. [%d]\n" , nRtn);
            }
        }
        else if (nMenu == 2) 
        {
            printf( "  - Input Encrypted String  : " ); scanf ( "%s", sEncOut );
            nRtn = decJumin(sEncOut, sDecOut);
            
            if (nRtn == 0) {
                printf ("  - decrypt = [%s]\n" , sDecOut);
                printf ("  - strlen(decrypt) = %ld\n" , strlen((char *)sDecOut));
            } else {
                // Error ó�� ..
                printf ("  ** Decryption Failed.. [%d]\n" , nRtn);
            }

				}
    } 
}



int encJumin(char *pPlain, char *pEnc)
{
    /**********************************************************
    * - nCubeRtn : cubeOne �� �����ڵ��̰� 
    * - nCommRtn : ���� �� ������ Application �� ���� �ڵ��Դϴ� ..
    * - ���� �ϴ�  ���� �߻��ϴ� ��� nCommRtn = -1; �θ� �Ǿ� �ִµ� ���翡 �°� �ٲٴ� ���� �����մϴ� ..
    **********************************************************/				

    int nEncLen, nCubeRtn;
    int nCommRtn = 0;

    /**********************************************************
    * ��ȣȭ �ϰ��� �ϴ� ���ڿ��� NULL �ΰ��     * 
    **********************************************************/
    if (pPlain == NULL) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * ��ȣȭ �ϰ��� �ϴ� ���ڿ��� ���� ���� �̻��̰ų� 
    * DB�� Ŀ�� ����� 64 byte��� ����  �ִ� 47byte�� ��û�Ǿ� �մϴ�
    **********************************************************/
    else if (strlen(pPlain) > 48) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * ��ȣȭ �ϰ��� �ϴ� ���ڿ��� ���� ���� ������ ��� 
    * �ֹι�ȣ��� 13 byte ������ ���� ������ �ִ»�Ȳ��.
    **********************************************************/
    else if (strlen(pPlain) < 13) {
        nCommRtn = -1;
    } 
    /**********************************************************
    * ó���ϰ��� �ϴ� ���ڿ���  ���� ���
    **********************************************************/
    else {

        nCubeRtn = CO_enc_char(pPlain, ITEM, 10, NULL, NULL, (unsigned char *)pEnc, &nEncLen);

        if (nCubeRtn == CTR_SUCCESS) {
            /*
            printf ("<<< CubeLog :: encrypt = [%s]\n" , pEnc);
            printf ("<<< CubeLog :: strlen(encrypt) = %ld,%d \n" , strlen((char *)pEnc), nEncLen );
            */
            nCommRtn = 0;
        }
        /**********************************************************
        * ������ ���� ��� : 20007
        * ip/mac, Application, User(OS account)
        **********************************************************/
        else if(nCubeRtn == 20007) {
            printf("<<< CubeLog :: [%d] Privileges to access encrypted column.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��ϵ��� ���� ITEM ���� �Ϻ�ȭ �õ� �ϴ� ���
        **********************************************************/
        else if(nCubeRtn == 20008) {
            printf("<<< CubeLog :: [%d] item is not specified.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��ȣȭ �� ���� �߻��ϴ� ���
        **********************************************************/
        else if(nCubeRtn == 20014) {
            printf("<<< CubeLog :: [%d] Fail to Encryption data.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ȯ�溯���� ���� �ʴ� ��� 
        **********************************************************/
        else if(nCubeRtn == 20016) {
            printf("<<< CubeLog :: [%d] Fatal error so should exception.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * Shared Memory �� Key�� ���� �Ǿ� ���� ���� ���
        **********************************************************/
        else if(nCubeRtn == 20023) {
            printf("<<< CubeLog :: [%d] error when SHMOpen shmget.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��Ÿ ���� ..
        **********************************************************/
        else {
            printf("<<< CubeLog :: [%d] Fatal error other reason.\n",nCubeRtn);
            nCommRtn = -1;
        }
    }

    return nCommRtn;    
}


int decJumin(char *pEncIn, char *pDecOut)
{
    int nEncLen, nCubeRtn;
    int nCommRtn = 0;

    /**********************************************************
    * ��ȣȭ  �ϰ��� �ϴ� ��ȣ������ NULL �� ��� * 
    **********************************************************/
    if (pEncIn == NULL) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * ��ȣȭ �ϰ��� �ϴ� ��ȣ������ ���� ���� �̻��̰ų� 
    * 
    **********************************************************/
    else if (strlen(pEncIn) > 50) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * ��ȣȭ �ϰ��� �ϴ� ��ȣ������ ���� ���� ������ ��� 
    * 
    **********************************************************/
    else if (strlen(pEncIn) < 23) {
        nCommRtn = -1;
    } 
    /**********************************************************
    * ó���ϰ��� �ϴ� ���ڿ���  ���� ���
    **********************************************************/
    else {

        nCubeRtn = CO_dec_char((unsigned char *)pEncIn, strlen(pEncIn), ITEM, 10, NULL, NULL, pDecOut);

        if (nCubeRtn == CTR_SUCCESS) {
            /**/
            printf ("<<< CubeLog :: decrypt = [%s]\n" , pDecOut);
            printf ("<<< CubeLog :: strlen(encrypt) = %ld \n" , strlen((char *)pDecOut));
            /**/
            nCommRtn = 0;
        }
        /**********************************************************
        * ������ ���� ��� : 20007
        * ip/mac, Application, User(OS account)
        **********************************************************/
        else if(nCubeRtn == 20007) {
            printf("<<< CubeLog :: [%d] Privileges to access encrypted column.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��ϵ��� ���� ITEM ���� �Ϻ�ȭ �õ� �ϴ� ���
        **********************************************************/
        else if(nCubeRtn == 20008) {
            printf("<<< CubeLog :: [%d] item is not specified.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��ȣȭ �� ���� �߻��ϴ� ���
        **********************************************************/
        else if(nCubeRtn == 20014) {
            printf("<<< CubeLog :: [%d] Fail to Encryption data.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ȯ�溯���� ���� �ʴ� ��� 
        **********************************************************/
        else if(nCubeRtn == 20016) {
            printf("<<< CubeLog :: [%d] Fatal error so should exception.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * Shared Memory �� Key�� ���� �Ǿ� ���� ���� ���
        **********************************************************/
        else if(nCubeRtn == 20023) {
            printf("<<< CubeLog :: [%d] error when SHMOpen shmget.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * ��Ÿ ���� ..
        **********************************************************/
        else {
            printf("<<< CubeLog :: [%d] Fatal error other reason.\n",nCubeRtn);
            nCommRtn = -1;
        }
    }

    return nCommRtn;    
}
