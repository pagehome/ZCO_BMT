
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "co_proc.pc"
};


static unsigned int sqlctx = 76643;


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
   unsigned int   sqlpfmem;
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {13,6};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned int *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ unsigned char *, signed int * _*/);

 static char *sq0011 = 
"select seq ,writer ,regno ,subject ,cnt ,wrdate  from zcube_board8  order b\
y seq desc             ";

 static char *sq0012 = 
"select seq ,writer ,regno ,subject ,cnt ,wrdate  from zcube_board#  order b\
y seq desc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{13,4130,840,0,0,
5,0,0,1,0,0,32,39,0,0,0,0,0,1,0,
20,0,0,0,0,0,27,58,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
51,0,0,3,0,0,32,63,0,0,0,0,0,1,0,
66,0,0,4,0,0,30,99,0,0,0,0,0,1,0,
81,0,0,5,55,0,4,117,0,0,1,0,0,1,0,2,3,0,0,
100,0,0,6,110,0,3,140,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
135,0,0,7,0,0,29,143,0,0,0,0,0,1,0,
150,0,0,8,55,0,4,166,0,0,1,0,0,1,0,2,3,0,0,
169,0,0,9,110,0,3,200,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
204,0,0,10,0,0,29,203,0,0,0,0,0,1,0,
219,0,0,11,98,0,9,233,0,0,0,0,0,1,0,
234,0,0,11,0,0,13,247,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,
9,0,0,
273,0,0,11,0,0,15,258,0,0,0,0,0,1,0,
288,0,0,11,0,0,15,270,0,0,0,0,0,1,0,
303,0,0,12,98,0,9,293,0,0,0,0,0,1,0,
318,0,0,12,0,0,13,307,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,
9,0,0,
357,0,0,12,0,0,15,318,0,0,0,0,0,1,0,
372,0,0,12,0,0,15,343,0,0,0,0,0,1,0,
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
char sEncOut[2000];
char *sItem = "JUMIN1";

int nDecLen, nEncLen, nRtn;

void selectPlain();
void selectEncTable();

void insertPlain();
void insertEncTable();

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
    sqlstm.sqlvsn = 13;
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

        char userid[40]= "scott/TIGER@ORA12";
    /* EXEC SQL END DECLARE SECTION; */ 


    printf("<<< CubeLog :: id/pass = [%s]\n\n", userid);

    /* EXEC SQL CONNECT :userid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
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
        sqlstm.sqlvsn = 13;
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
    /* nRtn = CO_init (0, "ORA11", "SCOTT", "","",     "",    "",     "",    "",      "",   0); */
    /*nRtn = CO_init_api ("ORCL"); */

    if (nRtn != CTR_SUCCESS) {
        printf("<<< CubeLog :: CO_init failed. returned %d\n", nRtn);
        exit(1);
    }

/*
    insertPlain();
    insertEncTable();
    selectEncTable();
    selectPlain();
*/
    selectEncTable();

    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
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

void insertPlain() {

    printf ("<<< [1] Insert Plain Table\n" );

    char buf[100];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR writer[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } writer;

        /* VARCHAR regno[13+1]; */ 
struct { unsigned short len; unsigned char arr[14]; } regno;

        /* VARCHAR subject[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } subject;

        /* VARCHAR contents[4000+1]; */ 
struct { unsigned short len; unsigned char arr[4001]; } contents;

        long seq;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL SELECT NVL(MAX(seq),0)+1 
             INTO seq
             FROM zcube_board8; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select (NVL(max(seq),0)+1) into :b0  from zcube_board8 ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
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
}



    memset(buf,0x00,100);
    sprintf(buf, "%ld", seq);

    strcpy(writer.arr,"wri000"); strcat(writer.arr, buf);
    writer.len = strlen(writer.arr);

    strcpy(regno.arr,"reg000"); strcat(regno.arr, buf);
    regno.len = strlen(regno.arr);

    strcpy(subject.arr,"sub000"); strcat(subject.arr, buf);
    subject.len = strlen(subject.arr);

    strcpy(contents.arr,"cnt000"); strcat(contents.arr, buf);
    contents.len = strlen(contents.arr);

    printf(" - [%s],[%s],[%s],[%s]\n\n",writer.arr, regno.arr, subject.arr, contents.arr);

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("void insertPlain() :: ERROR !!"); */ 


    /* EXEC SQL INSERT INTO zcube_board8
        (seq, writer, regno, subject, cnt, contents, wrdate) 
    VALUES(:seq, :writer, :regno, :subject, 0, :contents, SYSDATE); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into zcube_board8 (seq,writer,regno,subject,cnt,c\
ontents,wrdate) values (:b0,:b1,:b2,:b3,0,:b4,SYSDATE)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )100;
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
    sqlstm.sqhstl[1] = (unsigned long )103;
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
    sqlstm.sqhstl[3] = (unsigned long )103;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&contents;
    sqlstm.sqhstl[4] = (unsigned long )4003;
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
    if (sqlca.sqlcode < 0) sql_error("void insertPlain() :: ERROR !!");
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )135;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("void insertPlain() :: ERROR !!");
}



    if (sqlca.sqlcode != 0) {
        printf("<<< CubeLog :: insertPlain : sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
        printf("<<< CubeLog :: insertPlain : %s\n", sqlca.sqlerrm.sqlerrmc);
        exit(-1);
    }   
}

void insertEncTable() {

    printf ("<<< [2] Insert Enc Table\n" );

    char buf[100];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR writer[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } writer;

        /* VARCHAR regno[24+1]; */ 
struct { unsigned short len; unsigned char arr[25]; } regno;

        /* VARCHAR subject[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } subject;

        /* VARCHAR contents[4000+1]; */ 
struct { unsigned short len; unsigned char arr[4001]; } contents;

        long seq;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL SELECT NVL(MAX(seq),0)+1 
             INTO seq
             FROM zcube_board#; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select (NVL(max(seq),0)+1) into :b0  from zcube_board# ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )150;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
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
    if (sqlca.sqlcode < 0) sql_error("void insertPlain() :: ERROR !!");
}



    memset(buf,0x00,100);
    sprintf(buf, "%ld", seq);

    strcpy(writer.arr,"wri000"); strcat(writer.arr, buf);
    writer.len = strlen(writer.arr);

    strcpy(regno.arr,"reg000"); strcat(regno.arr, buf);
    nRtn = CO_enc_char(regno.arr, sItem,10,"TBL","COL",sEncOut,&nEncLen);
        if (nRtn == CTR_SUCCESS) {
                /*printf ("<<< CubeLog :: encrypt = [%s]\n" , sEncOut);
                printf ("<<< CubeLog :: strlen(encrypt) = %d,%d \n" , strlen(sEncOut), nEncLen ); */
        }
        else {
                printf("<<< CubeLog :: insertEncTable() : Failed Encryption data with return [%d].\n",nRtn);
                return ;
        }

    strcpy(regno.arr,sEncOut);
    regno.len = strlen(regno.arr);

    strcpy(subject.arr,"sub000"); strcat(subject.arr, buf);
    subject.len = strlen(subject.arr);

    strcpy(contents.arr,"cnt000"); strcat(contents.arr, buf);
    contents.len = strlen(contents.arr);

    printf(" - [%s],[%s],[%s],[%s]\n\n",writer.arr, regno.arr, subject.arr, contents.arr);

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("void insertPlain() :: ERROR !!"); */ 


    /* EXEC SQL INSERT INTO zcube_board#
        (seq, writer, regno, subject, cnt, contents, wrdate) 
    VALUES(:seq, :writer, :regno, :subject, 0, :contents, SYSDATE); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into zcube_board# (seq,writer,regno,subject,cnt,c\
ontents,wrdate) values (:b0,:b1,:b2,:b3,0,:b4,SYSDATE)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )169;
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
    sqlstm.sqhstl[1] = (unsigned long )103;
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
    sqlstm.sqhstl[3] = (unsigned long )103;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&contents;
    sqlstm.sqhstl[4] = (unsigned long )4003;
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
    if (sqlca.sqlcode < 0) sql_error("void insertPlain() :: ERROR !!");
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )204;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("void insertPlain() :: ERROR !!");
}



    if (sqlca.sqlcode != 0) {
        printf("<<< CubeLog :: insertPlain() : sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
        printf("<<< CubeLog :: insertPlain() : %s\n", sqlca.sqlerrm.sqlerrmc);
        exit(-1);
    }   
}
void selectPlain() {

    int nRownum = 0;

    printf ("<<< [3] Select Plain\n" );
    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("<<< call : sql_error => selectPlain"); */ 


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* VARCHAR writer[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } writer;

        /* VARCHAR regno[13+1]; */ 
struct { unsigned short len; unsigned char arr[14]; } regno;

        /* VARCHAR subject[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } subject;

        /* VARCHAR wrdate[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } wrdate;

        long cnt;
        long seq;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE C1 CURSOR FOR
        SELECT seq, writer, regno, subject, cnt, wrdate 
        FROM zcube_board8
        ORDER BY seq DESC ; */ 


    /* EXEC SQL OPEN C1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0011;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )219;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => selectPlain");
}



    printf ("---------------------------------------------------------------------------------------------\n");
    printf ("|%3s|%-10s|%-30s|%-10s|%3s|%-30s|\n" , "Seq", "Writer", "Regno", "Subject", "Cnt", "Wrdate");
    printf ("---------------------------------------------------------------------------------------------\n");

    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    while(1)
    {
        memset(&writer, 0x00, sizeof(writer));
        memset(&regno, 0x00, sizeof(regno));
        memset(&subject, 0x00, sizeof(subject));
        memset(&wrdate, 0x00, sizeof(wrdate));

        /* EXEC SQL FETCH C1 INTO
            :seq,
            :writer,
            :regno,
            :subject,
            :cnt,
            :wrdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )234;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
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
        sqlstm.sqhstl[1] = (unsigned long )103;
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
        sqlstm.sqhstl[3] = (unsigned long )103;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&cnt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&wrdate;
        sqlstm.sqhstl[5] = (unsigned long )52;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => selectPlain");
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog(!0) :: sqlca.sqlcode = [%ld]\n", sqlca.sqlcode);
            printf("<<< CubeLog(!0) :: %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 6;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )273;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) sql_error("<<< call : sql_error => selectPlain");
}


            exit(-1);
        }

        if(++nRownum > 10) break;    

        printf ("|%3d|%-10s|%-30s|%-10s|%3d|%-30s|\n" , seq, writer.arr, regno.arr, subject.arr, cnt, wrdate.arr);
    }

    printf ("--------------------------------------------------------------------------------------------\n\n\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )288;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



}

void selectEncTable() {

    printf ("<<< [4] Select Enc Table\n" );

    int nRownum = 0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

            /* VARCHAR writer[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } writer;

            /* VARCHAR regno[24+1]; */ 
struct { unsigned short len; unsigned char arr[25]; } regno;

            /* VARCHAR subject[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } subject;

            /* VARCHAR wrdate[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } wrdate;

            long cnt;
            long seq;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE C2 CURSOR FOR
        SELECT seq, writer, regno, subject, cnt, wrdate 
        FROM zcube_board#
        ORDER BY seq DESC; */ 

    /* EXEC SQL OPEN C2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0012;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )303;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    printf ("------------------------------------------------------------------------------------------------------------------\n");
    printf ("|%3s|%-10s|%-30s|%-20s|%-10s|%3s|%-30s|\n" , "Seq", "Writer", "Regno(Enc)", "Regno(Dec)", "Subject", "Cnt", "Wrdate");
    printf ("------------------------------------------------------------------------------------------------------------------\n");

    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    while(1)
    {
        memset(&writer, 0x00, sizeof(writer));
        memset(&regno, 0x00, sizeof(regno));
        memset(&subject, 0x00, sizeof(subject));
        memset(&wrdate, 0x00, sizeof(wrdate));

        /* EXEC SQL FETCH C2 INTO
            :seq,
            :writer,
            :regno,
            :subject,
            :cnt,
            :wrdate ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )318;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
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
        sqlstm.sqhstl[1] = (unsigned long )103;
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
        sqlstm.sqhstl[3] = (unsigned long )103;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&cnt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&wrdate;
        sqlstm.sqhstl[5] = (unsigned long )52;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
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
}



        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog :: selectEncTable() : sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog :: selectEncTable() : %s\n", sqlca.sqlerrm.sqlerrmc);
            /* EXEC SQL CLOSE C2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 6;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )357;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            exit(-1);
        }

        nRtn = CO_dec_char(regno.arr,regno.len,sItem,10,"TBL","COL", sDecOut);

        if (nRtn == CTR_SUCCESS) {
            /*
            printf ("<<< CubeLog :: decrypt = [%s]\n" , sDecOut);
            printf ("<<< CubeLog :: strlen(decrypt) = %d \n" , strlen(sDecOut) );
            */
        }
        else {
            printf("<<< CubeLog :: selectEncTable() : Failed Decryption regno with return [%d].\n",nRtn);
        }

        printf ("|%3d|%-10s|%-30s|%-20s|%-10s|%3d|%-30s|\n" , seq, writer.arr, regno.arr, sDecOut, subject.arr, cnt, wrdate.arr);

        if(++nRownum > 10) break;

    }

    printf ("------------------------------------------------------------------------------------------------------------------\n");
    
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C2; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )372;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

