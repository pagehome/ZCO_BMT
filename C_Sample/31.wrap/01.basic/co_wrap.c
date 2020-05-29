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
                // Error 처리 ..
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
                // Error 처리 ..
                printf ("  ** Decryption Failed.. [%d]\n" , nRtn);
            }

				}
    } 
}



int encJumin(char *pPlain, char *pEnc)
{
    /**********************************************************
    * - nCubeRtn : cubeOne 의 에러코드이고 
    * - nCommRtn : 적용 할 고객사의 Application 의 에러 코드입니다 ..
    * - 보면 일단  에러 발생하는 경우 nCommRtn = -1; 로만 되어 있는데 고객사에 맞게 바꾸는 것이 안전합니다 ..
    **********************************************************/				

    int nEncLen, nCubeRtn;
    int nCommRtn = 0;

    /**********************************************************
    * 암호화 하고자 하는 문자열이 NULL 인경우     * 
    **********************************************************/
    if (pPlain == NULL) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * 암호화 하고자 하는 문자열이 득정 길이 이상이거나 
    * DB의 커럼 사이즈가 64 byte라면 평문은  최대 47byte만 요청되야 합니다
    **********************************************************/
    else if (strlen(pPlain) > 48) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * 암호화 하고자 하는 문자열이 득정 길이 이하인 경우 
    * 주민번호라면 13 byte 이하인 경우는 문제가 있는상황임.
    **********************************************************/
    else if (strlen(pPlain) < 13) {
        nCommRtn = -1;
    } 
    /**********************************************************
    * 처리하고자 하는 문자열이  정상 경우
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
        * 권한이 없는 경우 : 20007
        * ip/mac, Application, User(OS account)
        **********************************************************/
        else if(nCubeRtn == 20007) {
            printf("<<< CubeLog :: [%d] Privileges to access encrypted column.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 등록되지 않은 ITEM 으로 암복화 시도 하는 경우
        **********************************************************/
        else if(nCubeRtn == 20008) {
            printf("<<< CubeLog :: [%d] item is not specified.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 암호화 시 오류 발생하는 경우
        **********************************************************/
        else if(nCubeRtn == 20014) {
            printf("<<< CubeLog :: [%d] Fail to Encryption data.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 환경변수가 맞지 않는 경우 
        **********************************************************/
        else if(nCubeRtn == 20016) {
            printf("<<< CubeLog :: [%d] Fatal error so should exception.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * Shared Memory 에 Key가 적재 되어 있지 않은 경우
        **********************************************************/
        else if(nCubeRtn == 20023) {
            printf("<<< CubeLog :: [%d] error when SHMOpen shmget.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 기타 에러 ..
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
    * 복호화  하고자 하는 암호문장이 NULL 인 경우 * 
    **********************************************************/
    if (pEncIn == NULL) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * 복호화 하고자 하는 암호문장이 득정 길이 이상이거나 
    * 
    **********************************************************/
    else if (strlen(pEncIn) > 50) {
        nCommRtn = -1;
    } 

    /**********************************************************
    * 복호화 하고자 하는 암호문장이 득정 길이 이하인 경우 
    * 
    **********************************************************/
    else if (strlen(pEncIn) < 23) {
        nCommRtn = -1;
    } 
    /**********************************************************
    * 처리하고자 하는 문자열이  정상 경우
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
        * 권한이 없는 경우 : 20007
        * ip/mac, Application, User(OS account)
        **********************************************************/
        else if(nCubeRtn == 20007) {
            printf("<<< CubeLog :: [%d] Privileges to access encrypted column.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 등록되지 않은 ITEM 으로 암복화 시도 하는 경우
        **********************************************************/
        else if(nCubeRtn == 20008) {
            printf("<<< CubeLog :: [%d] item is not specified.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 복호화 시 오류 발생하는 경우
        **********************************************************/
        else if(nCubeRtn == 20014) {
            printf("<<< CubeLog :: [%d] Fail to Encryption data.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 환경변수가 맞지 않는 경우 
        **********************************************************/
        else if(nCubeRtn == 20016) {
            printf("<<< CubeLog :: [%d] Fatal error so should exception.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * Shared Memory 에 Key가 적재 되어 있지 않은 경우
        **********************************************************/
        else if(nCubeRtn == 20023) {
            printf("<<< CubeLog :: [%d] error when SHMOpen shmget.\n",nCubeRtn);
            nCommRtn = -1;
        }

        /**********************************************************
        * 기타 에러 ..
        **********************************************************/
        else {
            printf("<<< CubeLog :: [%d] Fatal error other reason.\n",nCubeRtn);
            nCommRtn = -1;
        }
    }

    return nCommRtn;    
}
