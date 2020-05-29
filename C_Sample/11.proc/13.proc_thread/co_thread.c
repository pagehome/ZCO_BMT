
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
  1,0,0,
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
           char  filnam[13];
};
static const struct sqlcxp sqlfpn =
{
    12,
    "co_thread.pc"
};


static unsigned int sqlctx = 306923;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0001 = 
"select xx1.dec_varchar2_sel(jumin_no,11,'ARIA256')  from cube_test01#      \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4242,840,0,0,
5,0,0,0,0,0,60,78,0,0,0,0,0,1,0,
20,0,0,0,0,0,58,84,0,0,1,1,0,1,0,3,109,0,0,
39,0,0,0,0,0,59,126,0,0,1,1,0,1,0,3,109,0,0,
58,0,0,1,81,0,9,183,0,0,0,0,0,1,0,
73,0,0,1,0,0,13,192,0,0,1,0,0,1,0,2,9,0,0,
92,0,0,1,0,0,15,205,0,0,0,0,0,1,0,
107,0,0,2,0,0,29,207,0,0,0,0,0,1,0,
122,0,0,0,0,0,27,234,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
153,0,0,4,0,0,30,243,0,0,0,0,0,1,0,
};


#line 1 "co_thread.pc"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <string.h>
#include <sqlca.h>

#include <pthread.h>

/* Function prototypes */
void err_report();
void do_transaction();

void get_transaction();
void logon();
void logoff();

#define CONNINFO "scott/tiger"
#define THREADS 4

struct parameters
{ 
	sql_context *ctx;
	int thread_id;
};
typedef struct parameters parameters;

struct record_log
{ 
	char action;
	unsigned int from_account;
	unsigned int to_account;
	float amount;
};
typedef struct record_log record_log;

record_log records[]= { 
	{ 'M', 10001, 10002, 12.50 },
	{ 'M', 10001, 10003, 25.00 },
	{ 'M', 10001, 10003, 123.00 },
	{ 'M', 10001, 10003, 125.00 },
	{ 'M', 10002, 10006, 12.23 },
	{ 'M', 10007, 10008, 225.23 },
	{ 'M', 10002, 10008, 0.70 },
	{ 'M', 10001, 10003, 11.30 },
	{ 'M', 10003, 10002, 47.50 },
	{ 'M', 10002, 10006, 125.00 },
	{ 'M', 10007, 10008, 225.00 },
	{ 'M', 10002, 10008, 0.70 },
	{ 'M', 10001, 10003, 11.00 },
	{ 'M', 10003, 10002, 47.50 },
	{ 'M', 10002, 10006, 125.00 },
	{ 'M', 10007, 10008, 225.00 },
	{ 'M', 10002, 10008, 0.70 },
	{ 'M', 10001, 10003, 11.00 },
	{ 'M', 10003, 10002, 47.50 },
	{ 'M', 10008, 10001, 1034.54}};

static unsigned int trx_nr=0;

pthread_mutex_t mutex;

int main(int argc, char *argv[])
{

    printf("################################################\n");
    printf("###### CubeOne PlugIn Pro*C Thread Test  #######\n");
    printf("################################################\n\n");

	sql_context ctx[THREADS];

	pthread_t thread_id[THREADS];
	pthread_attr_t status;

	parameters params[THREADS];
	int i;

	/* EXEC SQL ENABLE THREADS; */ 
#line 78 "co_thread.pc"

{
#line 78 "co_thread.pc"
 struct sqlexd sqlstm;
#line 78 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 78 "co_thread.pc"
 sqlstm.arrsiz = 0;
#line 78 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 78 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 78 "co_thread.pc"
 sqlstm.stmt = "";
#line 78 "co_thread.pc"
 sqlstm.iters = (unsigned int  )1;
#line 78 "co_thread.pc"
 sqlstm.offset = (unsigned int  )5;
#line 78 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 78 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 78 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 78 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 78 "co_thread.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 78 "co_thread.pc"
}

#line 78 "co_thread.pc"

	/* EXEC SQL WHENEVER SQLERROR DO err_report(sqlca); */ 
#line 79 "co_thread.pc"


	for(i=0;i<THREADS;i++)
	{
		printf("Start Session %d....",i);
		/* EXEC SQL CONTEXT ALLOCATE :ctx[i]; */ 
#line 84 "co_thread.pc"

{
#line 84 "co_thread.pc"
  struct sqlexd sqlstm;
#line 84 "co_thread.pc"
  sqlstm.sqlvsn = 13;
#line 84 "co_thread.pc"
  sqlstm.arrsiz = 1;
#line 84 "co_thread.pc"
  sqlstm.sqladtp = &sqladt;
#line 84 "co_thread.pc"
  sqlstm.sqltdsp = &sqltds;
#line 84 "co_thread.pc"
  sqlstm.stmt = "";
#line 84 "co_thread.pc"
  sqlstm.iters = (unsigned int  )1;
#line 84 "co_thread.pc"
  sqlstm.offset = (unsigned int  )20;
#line 84 "co_thread.pc"
  sqlstm.cud = sqlcud0;
#line 84 "co_thread.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 84 "co_thread.pc"
  sqlstm.sqlety = (unsigned short)4352;
#line 84 "co_thread.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 84 "co_thread.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)&ctx[i];
#line 84 "co_thread.pc"
  sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
#line 84 "co_thread.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 84 "co_thread.pc"
  sqlstm.sqindv[0] = (         short *)0;
#line 84 "co_thread.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 84 "co_thread.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 84 "co_thread.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 84 "co_thread.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 84 "co_thread.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 84 "co_thread.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 84 "co_thread.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 84 "co_thread.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 84 "co_thread.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 84 "co_thread.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 84 "co_thread.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 84 "co_thread.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 84 "co_thread.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 84 "co_thread.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 84 "co_thread.pc"
  if (sqlca.sqlcode < 0) err_report(sqlca);
#line 84 "co_thread.pc"
}

#line 84 "co_thread.pc"

		logon(ctx[i],CONNINFO);
	}

	if (pthread_mutex_init(&mutex,NULL))
 	{
		printf("Can't initialize mutex\n");
 		exit(1);
	}

	/*Spawn threads*/
	for(i=0;i<THREADS;i++)
	{
		params[i].ctx=ctx[i];
		params[i].thread_id=i;
		printf("Thread %d... \n",i);
		if (pthread_create(&thread_id[i], NULL, do_transaction, &params[i]))
			printf("Cant create thread %d\n",i);
		else
			printf("Created\n");
	}


	// log off ...
	for(i=0;i<THREADS;i++)
	{
		/*wait for thread to end */
		printf("Thread %d ....",i);
		if (pthread_join(thread_id[i],&status))
			printf("Error when waiting for thread % to terminate\n", i);
		else
			printf("stopped\n");

		printf("Detach thread...");

		if (pthread_detach(&thread_id[i]))
			printf("Error detaching thread! \n");
		else
			printf("Detached!\n");

		printf("Stop Session %d....",i);
		logoff(ctx[i]);
		/* EXEC SQL CONTEXT FREE :ctx[i]; */ 
#line 126 "co_thread.pc"

{
#line 126 "co_thread.pc"
  struct sqlexd sqlstm;
#line 126 "co_thread.pc"
  sqlstm.sqlvsn = 13;
#line 126 "co_thread.pc"
  sqlstm.arrsiz = 1;
#line 126 "co_thread.pc"
  sqlstm.sqladtp = &sqladt;
#line 126 "co_thread.pc"
  sqlstm.sqltdsp = &sqltds;
#line 126 "co_thread.pc"
  sqlstm.stmt = "";
#line 126 "co_thread.pc"
  sqlstm.iters = (unsigned int  )1;
#line 126 "co_thread.pc"
  sqlstm.offset = (unsigned int  )39;
#line 126 "co_thread.pc"
  sqlstm.cud = sqlcud0;
#line 126 "co_thread.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 126 "co_thread.pc"
  sqlstm.sqlety = (unsigned short)4352;
#line 126 "co_thread.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 126 "co_thread.pc"
  sqlstm.sqhstv[0] = (unsigned char  *)&ctx[i];
#line 126 "co_thread.pc"
  sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
#line 126 "co_thread.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 126 "co_thread.pc"
  sqlstm.sqindv[0] = (         short *)0;
#line 126 "co_thread.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 126 "co_thread.pc"
  sqlstm.sqharm[0] = (unsigned long )0;
#line 126 "co_thread.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 126 "co_thread.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 126 "co_thread.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 126 "co_thread.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 126 "co_thread.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 126 "co_thread.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 126 "co_thread.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 126 "co_thread.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 126 "co_thread.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 126 "co_thread.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 126 "co_thread.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 126 "co_thread.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 126 "co_thread.pc"
  if (sqlca.sqlcode < 0) err_report(sqlca);
#line 126 "co_thread.pc"
}

#line 126 "co_thread.pc"

	}

	/*Destroys mutex*/
	if (pthread_mutex_destroy(&mutex))
	{
		printf("Can't destroy mutex\n");
		exit(1);
	}
}

/*****************************************************************
 * Function: err_report
 *
 * Description: This routine prints out the most recent error
 *
 ****************************************************************/
void err_report(sqlca)
struct sqlca sqlca;
{
	if (sqlca.sqlcode < 0)
	printf("\n%.*s\n\n",sqlca.sqlerrm.sqlerrml,sqlca.sqlerrm.sqlerrmc); 
	exit(1);
}

void do_transaction(params)
parameters *params;
{
	printf ("<<< do_transaction() :: start !!!!!\n" );

	struct sqlca sqlca;
	record_log *trx;
	sql_context ctx=params->ctx;

	// Done all transactions 
	get_transaction(&trx);

	/* EXEC SQL WHENEVER SQLERROR DO err_report(sqlca); */ 
#line 163 "co_thread.pc"

	/* EXEC SQL CONTEXT USE :ctx; */ 
#line 164 "co_thread.pc"


	printf("Thread %d executing transaction\n",params->thread_id);
	printf("trx->action : %c\n", trx->action);

	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 169 "co_thread.pc"

	        /* VARCHAR dec[100+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } dec;
#line 170 "co_thread.pc"

	/* EXEC SQL END DECLARE SECTION; */ 
#line 171 "co_thread.pc"


	printf ("<<< do_transaction() :: step-1   \n" );

	/*****************************************************************/
	/* EXEC SQL
	    DECLARE  C1 CURSOR  FOR
	    select xx1.dec_varchar2_sel(jumin_no,11,'ARIA256') from cube_test01#  ; */ 
#line 178 "co_thread.pc"

	    //select jumin_no from cube_test01# ;

	printf ("<<< do_transaction() :: step-2   \n" );

	/* EXEC SQL OPEN C1   ; */ 
#line 183 "co_thread.pc"

{
#line 183 "co_thread.pc"
 struct sqlexd sqlstm;
#line 183 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 183 "co_thread.pc"
 sqlstm.arrsiz = 1;
#line 183 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 183 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 183 "co_thread.pc"
 sqlstm.stmt = sq0001;
#line 183 "co_thread.pc"
 sqlstm.iters = (unsigned int  )1;
#line 183 "co_thread.pc"
 sqlstm.offset = (unsigned int  )58;
#line 183 "co_thread.pc"
 sqlstm.selerr = (unsigned short)1;
#line 183 "co_thread.pc"
 sqlstm.sqlpfmem = (unsigned int  )0;
#line 183 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 183 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 183 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 183 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 183 "co_thread.pc"
 sqlstm.sqcmod = (unsigned int )0;
#line 183 "co_thread.pc"
 sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 183 "co_thread.pc"
 if (sqlca.sqlcode < 0) err_report(sqlca);
#line 183 "co_thread.pc"
}

#line 183 "co_thread.pc"


	printf ("<<< do_transaction() :: step-3   \n" );

	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
#line 187 "co_thread.pc"

	while(1)
	{
	    memset(&dec, 0x00, sizeof(dec));

	    /* EXEC SQL FETCH C1 INTO
	        :dec ; */ 
#line 193 "co_thread.pc"

{
#line 192 "co_thread.pc"
     struct sqlexd sqlstm;
#line 192 "co_thread.pc"
     sqlstm.sqlvsn = 13;
#line 192 "co_thread.pc"
     sqlstm.arrsiz = 1;
#line 192 "co_thread.pc"
     sqlstm.sqladtp = &sqladt;
#line 192 "co_thread.pc"
     sqlstm.sqltdsp = &sqltds;
#line 192 "co_thread.pc"
     sqlstm.iters = (unsigned int  )1;
#line 192 "co_thread.pc"
     sqlstm.offset = (unsigned int  )73;
#line 192 "co_thread.pc"
     sqlstm.selerr = (unsigned short)1;
#line 192 "co_thread.pc"
     sqlstm.sqlpfmem = (unsigned int  )0;
#line 192 "co_thread.pc"
     sqlstm.cud = sqlcud0;
#line 192 "co_thread.pc"
     sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 192 "co_thread.pc"
     sqlstm.sqlety = (unsigned short)4352;
#line 192 "co_thread.pc"
     sqlstm.occurs = (unsigned int  )0;
#line 192 "co_thread.pc"
     sqlstm.sqfoff = (         int )0;
#line 192 "co_thread.pc"
     sqlstm.sqfmod = (unsigned int )2;
#line 192 "co_thread.pc"
     sqlstm.sqhstv[0] = (unsigned char  *)&dec;
#line 192 "co_thread.pc"
     sqlstm.sqhstl[0] = (unsigned long )103;
#line 192 "co_thread.pc"
     sqlstm.sqhsts[0] = (         int  )0;
#line 192 "co_thread.pc"
     sqlstm.sqindv[0] = (         short *)0;
#line 192 "co_thread.pc"
     sqlstm.sqinds[0] = (         int  )0;
#line 192 "co_thread.pc"
     sqlstm.sqharm[0] = (unsigned long )0;
#line 192 "co_thread.pc"
     sqlstm.sqadto[0] = (unsigned short )0;
#line 192 "co_thread.pc"
     sqlstm.sqtdso[0] = (unsigned short )0;
#line 192 "co_thread.pc"
     sqlstm.sqphsv = sqlstm.sqhstv;
#line 192 "co_thread.pc"
     sqlstm.sqphsl = sqlstm.sqhstl;
#line 192 "co_thread.pc"
     sqlstm.sqphss = sqlstm.sqhsts;
#line 192 "co_thread.pc"
     sqlstm.sqpind = sqlstm.sqindv;
#line 192 "co_thread.pc"
     sqlstm.sqpins = sqlstm.sqinds;
#line 192 "co_thread.pc"
     sqlstm.sqparm = sqlstm.sqharm;
#line 192 "co_thread.pc"
     sqlstm.sqparc = sqlstm.sqharc;
#line 192 "co_thread.pc"
     sqlstm.sqpadto = sqlstm.sqadto;
#line 192 "co_thread.pc"
     sqlstm.sqptdso = sqlstm.sqtdso;
#line 192 "co_thread.pc"
     sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 192 "co_thread.pc"
     if (sqlca.sqlcode == 1403) break;
#line 192 "co_thread.pc"
     if (sqlca.sqlcode < 0) err_report(sqlca);
#line 192 "co_thread.pc"
}

#line 193 "co_thread.pc"


	    if (sqlca.sqlcode != 0) {
	        printf("<<< CubeLog :: selectEncTable() : sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
	        printf("<<< CubeLog :: selectEncTable() : %s\n", sqlca.sqlerrm.sqlerrmc);
	        exit(-1);
	    }

	    printf (" - dec = [%s]\n" , dec.arr);
	}

	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 
#line 204 "co_thread.pc"

	/* EXEC SQL CLOSE C1; */ 
#line 205 "co_thread.pc"

{
#line 205 "co_thread.pc"
 struct sqlexd sqlstm;
#line 205 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 205 "co_thread.pc"
 sqlstm.arrsiz = 1;
#line 205 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 205 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 205 "co_thread.pc"
 sqlstm.iters = (unsigned int  )1;
#line 205 "co_thread.pc"
 sqlstm.offset = (unsigned int  )92;
#line 205 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 205 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 205 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 205 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 205 "co_thread.pc"
 sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 205 "co_thread.pc"
}

#line 205 "co_thread.pc"


	/* EXEC SQL COMMIT; */ 
#line 207 "co_thread.pc"

{
#line 207 "co_thread.pc"
 struct sqlexd sqlstm;
#line 207 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 207 "co_thread.pc"
 sqlstm.arrsiz = 1;
#line 207 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 207 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 207 "co_thread.pc"
 sqlstm.iters = (unsigned int  )1;
#line 207 "co_thread.pc"
 sqlstm.offset = (unsigned int  )107;
#line 207 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 207 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 207 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 207 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 207 "co_thread.pc"
 sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 207 "co_thread.pc"
}

#line 207 "co_thread.pc"


	printf ("<<< do_transaction() :: end !!!!!\n" );
}


void get_transaction(trx)
record_log ** trx;
{
	if (pthread_mutex_lock(&mutex))
		printf("Can't lock mutex\n");

	*trx=&records[trx_nr];
	trx_nr++;

	if (pthread_mutex_unlock(&mutex))
		printf("Can't unlock mutex\n");
}



void logon(ctx,connect_info)
sql_context ctx;
char * connect_info;
{
	/* EXEC SQL WHENEVER SQLERROR DO err_report(sqlca); */ 
#line 232 "co_thread.pc"

	/* EXEC SQL CONTEXT USE :ctx; */ 
#line 233 "co_thread.pc"

	/* EXEC SQL CONNECT :connect_info; */ 
#line 234 "co_thread.pc"

{
#line 234 "co_thread.pc"
 struct sqlexd sqlstm;
#line 234 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 234 "co_thread.pc"
 sqlstm.arrsiz = 4;
#line 234 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 234 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 234 "co_thread.pc"
 sqlstm.iters = (unsigned int  )10;
#line 234 "co_thread.pc"
 sqlstm.offset = (unsigned int  )122;
#line 234 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 234 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 234 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 234 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 234 "co_thread.pc"
 sqlstm.sqhstv[0] = (unsigned char  *)connect_info;
#line 234 "co_thread.pc"
 sqlstm.sqhstl[0] = (unsigned long )0;
#line 234 "co_thread.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 234 "co_thread.pc"
 sqlstm.sqindv[0] = (         short *)0;
#line 234 "co_thread.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 234 "co_thread.pc"
 sqlstm.sqharm[0] = (unsigned long )0;
#line 234 "co_thread.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 234 "co_thread.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 234 "co_thread.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 234 "co_thread.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 234 "co_thread.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 234 "co_thread.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 234 "co_thread.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 234 "co_thread.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 234 "co_thread.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 234 "co_thread.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 234 "co_thread.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 234 "co_thread.pc"
 sqlstm.sqlcmax = (unsigned int )100;
#line 234 "co_thread.pc"
 sqlstm.sqlcmin = (unsigned int )2;
#line 234 "co_thread.pc"
 sqlstm.sqlcincr = (unsigned int )1;
#line 234 "co_thread.pc"
 sqlstm.sqlctimeout = (unsigned int )0;
#line 234 "co_thread.pc"
 sqlstm.sqlcnowait = (unsigned int )0;
#line 234 "co_thread.pc"
 sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 234 "co_thread.pc"
 if (sqlca.sqlcode < 0) err_report(sqlca);
#line 234 "co_thread.pc"
}

#line 234 "co_thread.pc"

	printf("Connected!\n");
}

void logoff(ctx)
sql_context ctx;
{
	/* EXEC SQL WHENEVER SQLERROR DO err_report(sqlca); */ 
#line 241 "co_thread.pc"

	/* EXEC SQL CONTEXT USE :ctx; */ 
#line 242 "co_thread.pc"

	/* EXEC SQL COMMIT WORK RELEASE; */ 
#line 243 "co_thread.pc"

{
#line 243 "co_thread.pc"
 struct sqlexd sqlstm;
#line 243 "co_thread.pc"
 sqlstm.sqlvsn = 13;
#line 243 "co_thread.pc"
 sqlstm.arrsiz = 4;
#line 243 "co_thread.pc"
 sqlstm.sqladtp = &sqladt;
#line 243 "co_thread.pc"
 sqlstm.sqltdsp = &sqltds;
#line 243 "co_thread.pc"
 sqlstm.iters = (unsigned int  )1;
#line 243 "co_thread.pc"
 sqlstm.offset = (unsigned int  )153;
#line 243 "co_thread.pc"
 sqlstm.cud = sqlcud0;
#line 243 "co_thread.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 243 "co_thread.pc"
 sqlstm.sqlety = (unsigned short)4352;
#line 243 "co_thread.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 243 "co_thread.pc"
 sqlcxt(&ctx, &sqlctx, &sqlstm, &sqlfpn);
#line 243 "co_thread.pc"
 if (sqlca.sqlcode < 0) err_report(sqlca);
#line 243 "co_thread.pc"
}

#line 243 "co_thread.pc"

	printf("Logged off!\n");
}


