
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
"select seq ,writer ,regno ,subject ,to_char(crdate,'YYYY-MM-DD fmHH24fm:MI:\
SS') crdate  from zcube_zsource            ";

 static char *sq0008 = 
"select seq ,writer ,regno ,subject  from zcube_ztarget  order by seq desc  \
           ";

 static char *sq0011 = 
"select seq ,writer ,regno ,subject ,to_char(crdate,'YYYY-MM-DDHH24MISS') cr\
date  from zcube_zsource            ";

 static char *sq0012 = 
"select seq ,writer ,regno ,subject ,crdate  from zcube_ztarget            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,840,0,0,
5,0,0,1,0,0,32,45,0,0,0,0,0,1,0,
20,0,0,0,0,0,27,66,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
51,0,0,3,0,0,32,71,0,0,0,0,0,1,0,
66,0,0,4,0,0,30,86,0,0,0,0,0,1,0,
81,0,0,5,118,0,9,115,0,0,0,0,0,1,0,
96,0,0,5,0,0,13,130,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
131,0,0,6,125,0,3,157,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
166,0,0,7,0,0,29,159,0,0,0,0,0,1,0,
181,0,0,5,0,0,15,174,0,0,0,0,0,1,0,
196,0,0,8,86,0,9,197,0,0,0,0,0,1,0,
211,0,0,8,0,0,13,207,0,0,4,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
242,0,0,8,0,0,15,216,0,0,0,0,0,1,0,
257,0,0,9,77,0,3,233,0,0,4,4,0,1,0,1,3,0,0,1,9,0,0,1,97,0,0,1,9,0,0,
288,0,0,10,0,0,29,234,0,0,0,0,0,1,0,
303,0,0,8,0,0,15,241,0,0,0,0,0,1,0,
318,0,0,11,111,0,9,268,0,0,0,0,0,1,0,
333,0,0,11,0,0,13,278,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
368,0,0,11,0,0,15,288,0,0,0,0,0,1,0,
383,0,0,11,0,0,15,301,0,0,0,0,0,1,0,
398,0,0,12,74,0,9,328,0,0,0,0,0,1,0,
413,0,0,12,0,0,13,338,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
448,0,0,12,0,0,15,348,0,0,0,0,0,1,0,
463,0,0,12,0,0,15,370,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <string.h>

#include "coapi_user.h" 
/*EXEC SQL INCLUDE coapi_user;*/

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
char *sItem = "AES256";

int nDecLen, nEncLen, nRtn;
int totalRec = 88888;

#define ARRAY_LENGTH 20000


//void targetUpdArray();
//void targetDelArray();

void encInsArr();
void encInsOne();
void decSelOne();
void plnSelOne();

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
    printf("%ld.%s\n", message_length, message_buffer);

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

    printf("################################################\n");
    printf("###### CubeOne API SelfTest : PRO*C TEST #######\n");
    printf("################################################\n\n");

    /* Connect to DB */
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char userid[40]= "scott/one123@VM_19";
    /* EXEC SQL END DECLARE SECTION; */ 


    printf("<<< CubeLog :: id/pass = [%s]\n", userid);
    printf("<<< CubeLog :: totalRec = [%d]\n", totalRec);
    printf("<<< CubeLog :: ARRAY_LENGTH = [%d]\n\n", ARRAY_LENGTH);

    /* EXEC SQL CONNECT :userid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
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
        sqlstm.offset = (unsigned int  )51;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        exit(0);
    }

    // nRtn = CO_init_api ("ORCL");

    if (nRtn != CTR_SUCCESS) {
        printf("<<< CubeLog :: CO_init failed. returned %d\n", nRtn);
        exit(1);
    }

    encInsArr();
    //decSelOne();
    //plnSelOne();

    /* EXEC SQL COMMIT WORK RELEASE; */ 

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


    return 0;
}

void encInsArr() {

    int nRownum = 0;
	int i;

	printf("************************************************\n");
	printf("****** CubeOneAPI Encrypt Array Insert  ********\n");
	printf("************************************************\n\n");

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => targetInsLoop"); */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long seq[ARRAY_LENGTH];
        /* VARCHAR writer[ARRAY_LENGTH][20+1]; */ 
struct { unsigned short len; unsigned char arr[22]; } writer[20000];

        /* VARCHAR regno[ARRAY_LENGTH][13+1]; */ 
struct { unsigned short len; unsigned char arr[14]; } regno[20000];

        /* VARCHAR regno_enc[ARRAY_LENGTH][24+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } regno_enc[20000];

        /* VARCHAR subject[ARRAY_LENGTH][20+1]; */ 
struct { unsigned short len; unsigned char arr[22]; } subject[20000];

        //VARCHAR crdate[ARRAY_LENGTH][40+1];
        /* VARCHAR crdate[ARRAY_LENGTH][60+1]; */ 
struct { unsigned short len; unsigned char arr[62]; } crdate[20000];

    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE c_array CURSOR FOR
        SELECT seq, writer, regno, subject, to_char(crdate, 'YYYY-MM-DD fmHH24fm:MI:SS') crdate
        FROM zcube_zsource; */ 


    /* EXEC SQL OPEN c_array; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 


	// Treat Page 
	int rows_to_fetch, rows_before;

	rows_to_fetch = ARRAY_LENGTH; 
	rows_before = 0; 

    while(rows_to_fetch>0)
    {

    	printf ("<<< CubeLog :: =====================================================\n");

        /* EXEC SQL FOR :rows_to_fetch
		FETCH c_array INTO
            :seq,
            :writer,
            :regno,
            :subject,
			:crdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )rows_to_fetch;
        sqlstm.offset = (unsigned int  )96;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )24;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)regno;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )16;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )24;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)crdate;
        sqlstm.sqhstl[4] = (unsigned long )63;
        sqlstm.sqhsts[4] = (         int  )64;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    	printf ("<<< CubeLog :: after select(sqlca.sqlerrd[2]) = [%d] cnt\n" , sqlca.sqlerrd[2]);

		rows_before = sqlca.sqlerrd[2];
    	//printf ("<<< CubeLog :: rows_before = [%d] cnt\n" , rows_before );

		for(i=0; i<rows_to_fetch; i++) {
			//CO_enc_char((char *)regno[i].arr, sItem, 10, NULL, NULL, regno_enc[i].arr, regno_enc[i].len);

			CO_enc_char((char *)regno[i].arr, sItem, 10, NULL, NULL, regno_enc[i].arr, &nEncLen);
			regno_enc[i].len = nEncLen;

        	if (nRtn == CTR_SUCCESS) {
            	//printf ("<<< CubeLog :: strlen(encrypt) = %s, %ld,%d \n" , regno_enc[i].arr, strlen((char *)regno_enc[i].arr), nEncLen ); 
        	}
        	else {
            	printf("<<< CubeLog :: insertEncTable() : Failed Encryption data with return [%d].\n",nRtn);
        	}
		}

        /* EXEC SQL FOR :rows_to_fetch
			INSERT INTO zcube_ztarget(seq, writer, regno, subject, crdate) VALUES(:seq, :writer, :regno_enc, :subject, to_date(:crdate,'YYYY-MM-DD fmHH24fm:MI:SS')); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "insert into zcube_ztarget (seq,writer,regno,subject,\
crdate) values (:b1,:b2,:b3,:b4,to_date(:b5,'YYYY-MM-DD fmHH24fm:MI:SS'))";
        sqlstm.iters = (unsigned int  )rows_to_fetch;
        sqlstm.offset = (unsigned int  )131;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )24;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)regno_enc;
        sqlstm.sqhstl[2] = (unsigned long )27;
        sqlstm.sqhsts[2] = (         int  )28;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )24;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)crdate;
        sqlstm.sqhstl[4] = (unsigned long )63;
        sqlstm.sqhsts[4] = (         int  )64;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}


        /* EXEC SQL COMMIT WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )166;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    	//printf ("<<< CubeLog :: after insert(sqlca.sqlerrd[2])  = [%d] cnt\n" , sqlca.sqlerrd[2]);

		if(totalRec-rows_before < ARRAY_LENGTH) {
			rows_to_fetch = totalRec-rows_before;
    		printf ("<<< CubeLog :: **rows_to_fetch** = [%d] cnt\n" , rows_to_fetch );
		}
    }

   	printf ("<<< CubeLog :: *****************************************************\n");
    printf ("<<< CubeLog :: last(sqlca.sqlerrd[2]) = [%d] cnt\n" , sqlca.sqlerrd[2]);

    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_array; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )181;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

void encInsOne() {

    int nRownum = 0;

    printf ("<<< [3] targetInsLoop \n" );
    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => targetInsLoop"); */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR writer[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } writer;

        /* VARCHAR regno[13+1]; */ 
struct { unsigned short len; unsigned char arr[14]; } regno;

        /* VARCHAR subject[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } subject;

        long seq;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE C1 CURSOR FOR
        SELECT seq, writer, regno, subject  
        FROM zcube_ztarget
        ORDER BY seq DESC ; */ 


    /* EXEC SQL OPEN C1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0008;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )196;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    printf ("---------------------------------------------------------------------------------------------\n");
    printf ("|%10s|%-15s|%-15s|%-15s|\n" , "Seq", "Writer", "Regno", "Subject" );
    printf ("---------------------------------------------------------------------------------------------\n");

    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    while(1)
    {

        /* EXEC SQL FETCH C1 INTO
            :seq,
            :writer,
            :regno,
            :subject; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )211;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&regno;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )242;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}


            exit(-1);
        }

        if(++nRownum%1000 == 10) break;    


        CO_enc_char((char *)regno.arr, sItem,10,NULL,NULL,sEncOut,&nEncLen);
        if (nRtn == CTR_SUCCESS) {
            // printf ("<<< CubeLog :: strlen(encrypt) = %d,%d \n" , strlen(sEncOut), nEncLen ); 
        }
        else {
            printf("<<< CubeLog :: insertEncTable() : Failed Encryption data with return [%d].\n",nRtn);
        }

        printf ("|%ld||%s|%s|%s|\n" , seq, writer.arr, regno.arr, subject.arr);

        /* EXEC SQL INSERT INTO zcube_ztarget(seq, writer, regno, subject) VALUES(:seq, :writer, :sEncOut, :subject); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "insert into zcube_ztarget (seq,writer,regno,subject)\
 values (:b0,:b1,:b2,:b3)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )257;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)sEncOut;
        sqlstm.sqhstl[2] = (unsigned long )2000;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}


        /* EXEC SQL COMMIT WORK; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )288;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    }

    printf ("--------------------------------------------------------------------------------------------\n\n\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )303;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



}


void plnSelOne() {

    printf("************************************************\n");
    printf("****** CubeOneAPI Plain One Select  ************\n");
    printf("************************************************\n\n");

    int nRownum = 0;

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => targetInsLoop"); */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long seq;
        /* VARCHAR writer[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } writer;

        /* VARCHAR regno[24+1]; */ 
struct { unsigned short len; unsigned char arr[25]; } regno;

        /* VARCHAR subject[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } subject;

        /* VARCHAR crdate[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } crdate;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE c_plnSelOne CURSOR FOR
        SELECT seq, writer, regno, subject, to_char(crdate, 'YYYY-MM-DDHH24MISS') crdate 
        FROM zcube_zsource ; */ 


    /* EXEC SQL OPEN c_plnSelOne; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0011;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )318;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    while(1)
    {
	    memset(&writer, 0x00, sizeof(writer));
        memset(&regno, 0x00, sizeof(regno));
        memset(&subject, 0x00, sizeof(subject));
        memset(&crdate, 0x00, sizeof(crdate));

        /* EXEC SQL FETCH c_plnSelOne INTO
            :seq,
            :writer,
            :regno,
            :subject,
			:crdate ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )333;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&regno;
        sqlstm.sqhstl[2] = (unsigned long )27;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&crdate;
        sqlstm.sqhstl[4] = (unsigned long )23;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE c_plnSelOne; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )368;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}


            exit(-1);
        }

        if(++nRownum%1000 == 10) break;    

        printf ("%ld||%s||%s||%s||%s\n" , seq, writer.arr, regno.arr, subject.arr, crdate.arr);

    }

    printf ("--------------------------------------------------------------------------------------------\n\n\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_plnSelOne; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )383;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



}


void decSelOne() {

    printf("************************************************\n");
    printf("****** CubeOneAPI Decrypt One Select  ********\n");
    printf("************************************************\n\n");

    int nRownum = 0;

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => targetInsLoop"); */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long seq;
        /* VARCHAR writer[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } writer;

        /* VARCHAR regno[24+1]; */ 
struct { unsigned short len; unsigned char arr[25]; } regno;

        /* VARCHAR subject[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } subject;

        /* VARCHAR crdate[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } crdate;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE C_DECSEL CURSOR FOR
        SELECT seq, writer, regno, subject, crdate 
        FROM zcube_ztarget ; */ 


    /* EXEC SQL OPEN C_DECSEL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0012;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )398;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    while(1)
    {
	    memset(&writer, 0x00, sizeof(writer));
        memset(&regno, 0x00, sizeof(regno));
        memset(&subject, 0x00, sizeof(subject));
        memset(&crdate, 0x00, sizeof(crdate));

        /* EXEC SQL FETCH C_DECSEL INTO
            :seq,
            :writer,
            :regno,
            :subject,
			:crdate ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )413;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&writer;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&regno;
        sqlstm.sqhstl[2] = (unsigned long )27;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&subject;
        sqlstm.sqhstl[3] = (unsigned long )23;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&crdate;
        sqlstm.sqhstl[4] = (unsigned long )23;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C_DECSEL; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 5;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )448;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => targetInsLoop");
}


            exit(-1);
        }

        if(++nRownum%1000 == 10) break;    

        CO_dec_char(regno.arr, regno.len,  sItem, 10, NULL, NULL, sDecOut);

        if (nRtn == CTR_SUCCESS) {
            // printf ("<<< CubeLog :: strlen(encrypt) = %d,%d \n" , strlen(sEncOut), nEncLen ); 
        }
        else {
            printf("<<< CubeLog :: insertEncTable() : Failed Encryption data with return [%d].\n",nRtn);
        }

        printf ("%ld||%s||%s||%s||%s||%s\n" , seq, writer.arr, regno.arr, sDecOut, subject.arr, crdate.arr);

    }

    printf ("--------------------------------------------------------------------------------------------\n\n\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C_DECSEL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )463;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



}
