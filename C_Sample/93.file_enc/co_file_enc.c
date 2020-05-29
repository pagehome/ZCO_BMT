#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "coapi_user.h"

#define FBUFSIZE 1024  /* 적절한 블럭으로 암호호하는 것이 효율적임 .. */


int main(argc, argv)
int    argc;
char    *argv[];
{
    char sSID[31];
    char sUser[31];
    char sItemName[31];

    char sInFile[81];
    char sOutFile[81];

    struct stat    bufStat;

    off_t nInFileSize; 
    off_t nBufSize ; 

    int    nReadSize;
    int    fdInFile, fdOutFile;
    char *pInBuff, *pOutBuff;

    int    nEncLen = 0;
    int    i;

    int    nRtn, ret;
    ssize_t    nOutLen;

    /* Check Usage */
    if (argc != 2) {
        printf ("Usage: %s <in file> \n", argv[0]);
        exit(-1);
    }

    strcpy (sInFile, argv[1]);

    strcpy (sOutFile, argv[1]);
    strcat (sOutFile, ".enc");

    strcpy (sSID, "API");
    strcpy (sUser, "SA");
    strcpy (sItemName, "AES256");

    /* Check Input file */
    nRtn = stat (sInFile, &bufStat);    
    if (nRtn != 0) {
        printf ("Error: %s has error with errno=%d.\n", sInFile, errno);
        exit(-1);
        
    }
    nInFileSize = bufStat.st_size;
    printf ("size of %s is %lld\n", sInFile, nInFileSize);


    /***********************************************************/
    fdInFile = open(sInFile, O_RDONLY);
    if (fdInFile == -1) {
        printf ("Error: Failed to open %s with errno=%d\n", sInFile, errno);
        exit(-1);
    }

    /***********************************************************/
    fdOutFile = open (sOutFile, O_CREAT|O_RDWR, 0666);
    if (fdOutFile == -1) {
        printf ("Error: Failed to open %s with errno=%d\n", sOutFile, errno);
        close(fdInFile);
        exit(-1);
    }

    /* Initialize Cubeone. */
    /* nRtn = CO_init (0, sSID, sUser,"","","","","","","",0); */

    if (nRtn != 0) {
        printf ("Failed to initialize Encryption. ret=%d\n", nRtn);
        exit (-1);
    }

    /* read file into memory */
    nBufSize = nInFileSize;

    pInBuff = malloc (FBUFSIZE) ;
    pOutBuff = malloc (FBUFSIZE * 2) ;
    if (pInBuff == NULL || pOutBuff == NULL) {
        printf ("Fail to malloc(%d) for string Buffer. errno=%d.\n", FBUFSIZE+1, errno);
        exit(1);
    }

    /* Now read input file and Treat it */
    printf ("Inform: Encrypt File ...\n"); 

    i = 0 ;
    while (nBufSize)
    {
        nReadSize = read (fdInFile, pInBuff, FBUFSIZE);
        if (nReadSize < 0) {
            printf ("Fail to read data from inputfile. errno=%d.\n", errno);
            exit(1);
        }

        ret = CO_enc_byte (pInBuff, nReadSize, sItemName, 10, "BATCH", "BATCH", pOutBuff, &nEncLen);
        if (ret != CTR_SUCCESS) {
            printf ("Error: Encryption Error for ITEM is [%s].ret=[%d]\n", sItemName, ret); 
            exit(-1);
        }
        else {
            nOutLen = write (fdOutFile, pOutBuff, nEncLen);
            if (nOutLen == -1) {
                printf ("Error: Failed to write with errno [%d].\n", errno);
                exit(-1);
            }
        }
        nBufSize -= (off_t) nReadSize ;

        printf ("Read/Write Size = [%d]/[%d]..... [%ld]\n", nReadSize, nEncLen, nBufSize) ;
 
    }    
        
    close (fdInFile);
    close (fdOutFile);

    printf ("\nEncryption done successfully.\n");
    free (pInBuff);
    free (pOutBuff);

    printf ("\n") ;
    exit(0);

}

