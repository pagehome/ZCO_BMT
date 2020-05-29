
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "co_batch.pc"
};


static unsigned int sqlctx = 150731;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

 static char *sq0005 = 
"select AUTONUM ,JUMIN ,EMAIL ,PASSWORD ,ADDRESS  from BMT_MEMBER            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4138,1,0,0,
5,0,0,1,0,0,32,59,0,0,0,0,0,1,0,
20,0,0,0,0,0,60,71,0,0,0,0,0,1,0,
35,0,0,0,0,0,27,80,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
66,0,0,3,0,0,32,87,0,0,0,0,0,1,0,
81,0,0,4,0,0,30,121,0,0,0,0,0,1,0,
96,0,0,5,76,0,9,162,0,0,0,0,0,1,0,
111,0,0,5,0,0,13,172,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
146,0,0,5,0,0,15,182,0,0,0,0,0,1,0,
161,0,0,6,56,0,3,203,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
196,0,0,5,0,0,15,207,0,0,0,0,0,1,0,
211,0,0,7,0,0,29,210,0,0,0,0,0,1,0,
226,0,0,5,0,0,15,215,0,0,0,0,0,1,0,
241,0,0,5,0,0,15,224,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <string.h>
#include <pthread.h>


#include "coapi_user.h" 
/*EXEC SQL INCLUDE coapi_user;*/

#define ARRAY_LENGTH 20000
#define THREADS 3



/* EXEC SQL INCLUDE SQLCA;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


char sDecOut[2000];
unsigned char sEncOut[2000];

int nDecLen, nEncLen, nRtn;

char sIdxChar[2000];
char sIdxCharSel[2000];

char *sPlain = "1234567890123";
char *sItem = "AES256";

int nDecLen, nEncLen, nRtn;
int nIdxCharLen, nIdxCharSelLen;

int nTotal=10000000;

int get_envdata();
int basic();
int basic_salt();
int order();
int speed();

void thread();
void encryptInsert();

void sql_error(char *routine)
{
    char message_buffer[512];
    size_t buffer_size;
    size_t message_length;

    /* Turn off the call to sql_error() to avoid a possible infinite loop */
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    printf("\nOracle error while executing %s!\n", routine);

    /* Use sqlglm() to get the full text of the error message. */
    buffer_size = sizeof(message_buffer);
    sqlglm(message_buffer, &buffer_size, &message_length);
    printf("%.*s\n", message_length, message_buffer);

    /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    exit(1);
}

int main(int argc, char *argv[])
{
    printf("##########################################################################\n");
    printf("########## BMT(TTA) CubeOne-API JDBC Testing-MultiThread(2015.06.17) #####\n");
    printf("##########################################################################\n\n\n");

	sql_context ctx[THREADS];
	/* EXEC SQL ENABLE THREADS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )20;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

	

    /* Connect to DB */
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char userid[40]= "scott/one123@ORCL";
    /* EXEC SQL END DECLARE SECTION; */ 


    printf("<<< CubeLog :: id/pass = [%s]\n\n", userid);

    /* EXEC SQL CONNECT :userid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )35;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)userid;
    sqlstm.sqhstl[0] = (unsigned long )40;
    sqlstm.sqhsts[0] = (         int  )40;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	printf("<<< CubeLog :: step1 \n");

    if (sqlca.sqlcode < 0)
    {
        printf("<<< CubeLog :: %s\n", sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )66;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        exit(0);
    }

	printf("<<< CubeLog :: step2 \n");
    /*memset(sEncOut, 0x00, sizeof(sEncOut));
    memset(sDecOut, 0x00, sizeof(sDecOut)); */
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
    //nRtn = CO_init (0, "ORCL", "SCOTT", "","",     "",    "",     "",    "",      "",   0);
    nRtn = CO_init_api ("API"); 

    if (nRtn != CTR_SUCCESS) {
        printf("<<< CubeLog :: CO_init failed. returned %d\n", nRtn);
        exit(1);
    }
	
	printf("<<< CubeLog :: step3 \n");
    encryptInsert();
	//thread();

	
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    return 0;
}


void encryptInsert() {

	printf("<<< CubeLog :: step4 \n");

	sql_context ctx;


    time_t startTime, endTime;
    float elapTime;

    int nRownum = 0;

	printf("************************************************\n");
	printf("****** CubeOneAPI Encrypt Insert Test   ********\n");
	printf("************************************************\n\n");

	startTime = clock();

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => encryptInsert"); */ 

	/* EXEC SQL CONTEXT USE :ctx; */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long col1[ARRAY_LENGTH];
        /* VARCHAR col2[ARRAY_LENGTH][13+1]; */ 
struct { unsigned short len; unsigned char arr[14]; } col2[20000];

        /* VARCHAR col2_enc[ARRAY_LENGTH][24+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } col2_enc[20000];

        /* VARCHAR col3[ARRAY_LENGTH][50+1]; */ 
struct { unsigned short len; unsigned char arr[54]; } col3[20000];

        /* VARCHAR col4[ARRAY_LENGTH][20+1]; */ 
struct { unsigned short len; unsigned char arr[22]; } col4[20000];

        /* VARCHAR col5[ARRAY_LENGTH][100+1]; */ 
struct { unsigned short len; unsigned char arr[102]; } col5[20000];

    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE C_ARRAY CURSOR FOR
        SELECT AUTONUM, JUMIN, EMAIL, PASSWORD, ADDRESS 
        FROM BMT_MEMBER; */ 

        //FROM BMT_MEMBER  where rownum < 1000000000;

    /* EXEC SQL OPEN C_ARRAY; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )96;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}


    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 


    while(1)
    {
/*
        memset(&writer, 0x00, sizeof(writer));
        memset(&regno, 0x00, sizeof(regno));
        memset(&subject, 0x00, sizeof(subject));
*/
        /* EXEC SQL FETCH C_ARRAY INTO
            :col1,
            :col2,
            :col3,
            :col4,
            :col5; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )20000;
        sqlstm.offset = (unsigned int  )111;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)col1;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)col2;
        sqlstm.sqhstl[1] = (unsigned long )16;
        sqlstm.sqhsts[1] = (         int  )16;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)col3;
        sqlstm.sqhstl[2] = (unsigned long )53;
        sqlstm.sqhsts[2] = (         int  )56;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)col4;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )24;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)col5;
        sqlstm.sqhstl[4] = (unsigned long )103;
        sqlstm.sqhsts[4] = (         int  )104;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C_ARRAY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )146;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}


            exit(-1);
        }

        if(++nRownum%1000 == 10) break;    

        printf ("sqlca.sqlerrd[2] = [%d]\n" , sqlca.sqlerrd[2]);

		int i;
		for(i=0;i<ARRAY_LENGTH;i++) {
			//CO_enc_char(col2[i].arr, sItem,10,NULL,NULL,col2_enc[i].arr,col2_enc[i].len);
			CO_enc_char(col2[i].arr, sItem,10,NULL,NULL,col2_enc[i].arr,&nEncLen);
			col2_enc[i].len = nEncLen;
        	if (nRtn == CTR_SUCCESS) {
            	//printf ("<<< CubeLog :: strlen(encrypt) = %s, %d,%d \n" , regno_enc[i].arr, strlen(regno_enc[i].arr), nEncLen ); 
        	}
        	else {
            	printf("<<< CubeLog :: insertEncTable() : Failed Encryption data with return [%d].\n",nRtn);
        	}
		}

        /* EXEC SQL INSERT INTO BMT_MEMBER_CUB VALUES(:col1, :col2_enc, :col3, :col4, :col5); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "insert into BMT_MEMBER_CUB  values (:b0,:b1,:b2,:b3,:\
b4)";
        sqlstm.iters = (unsigned int  )20000;
        sqlstm.offset = (unsigned int  )161;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)col1;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)col2_enc;
        sqlstm.sqhstl[1] = (unsigned long )27;
        sqlstm.sqhsts[1] = (         int  )28;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)col3;
        sqlstm.sqhstl[2] = (unsigned long )53;
        sqlstm.sqhsts[2] = (         int  )56;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)col4;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )24;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)col5;
        sqlstm.sqhstl[4] = (unsigned long )103;
        sqlstm.sqhsts[4] = (         int  )104;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}


        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C_ARRAY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )196;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}


            exit(-1);
        }
        /* EXEC SQL COMMIT WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )211;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C_ARRAY; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )226;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => encryptInsert");
}


            exit(-1);
        }
    }


    printf ("--------------------------------------------------------------------------------------------\n\n\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C_ARRAY; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )241;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
}




	endTime = clock();
	elapTime = (float)(endTime - startTime)/CLOCKS_PER_SEC;

	printf(" ----------------------------------------\n");
	printf(" -------- RESULT(encryptInsert) ---------\n");
	printf(" ----------------------------------------\n");
	printf("  - item : %s\n" , sItem);
//	printf("  - Total Count : %d\n" , );
//	printf("  - Success Count : %d\n" , df.format(loop));
	printf("  - Fail Cout : 0\n");
	printf("  - Elapse Time : %.2f sec\n" , elapTime);
	printf("<<< CubeLog :: (endTime - startTime)/CLOCKS_PER_SEC : [%.2f] \n\n", elapTime);

	printf("sqlca.sqlerrd[2] = [%d]\n" , sqlca.sqlerrd[2]);
}
