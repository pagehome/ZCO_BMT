#ifndef _TBPC_COMMON_SRC_GEN
#define _TBPC_COMMON_SRC_GEN



#define TBSQLCODE_NOTFOUND 1403



/*
==========================================
        host variable type
==========================================
*/

typedef enum esql_hostvar_type_e {

    /* string */
    ESQL_TYPE_CHARP = 0,        /* (signed) char* */
    ESQL_TYPE_UCHARP,           /* unsigned char* */
    ESQL_TYPE_CHAR_ARRAY,       /* (signed) char[n] */
    ESQL_TYPE_UCHAR_ARRAY,      /* unsigned char[n] */

    /* char */
    ESQL_TYPE_CHAR,             /* (signed) char */
    ESQL_TYPE_UCHAR,            /* unsigned char */

    /* int */
    ESQL_TYPE_INT,              /* (signed) int */
    ESQL_TYPE_UINT,             /* unsigned int */

    /* short */
    ESQL_TYPE_SHORT,            /* (signed) short (int) */
    ESQL_TYPE_USHORT,           /* unsigned short */

    /* long */
    ESQL_TYPE_LONG,             /* (signed) long (int) */
    ESQL_TYPE_ULONG,            /* unsigned long (int) */

    /* float/double */
    ESQL_TYPE_FLOAT,            /* float */
    ESQL_TYPE_DOUBLE,           /* double */

    /* VARCHAR */
    ESQL_TYPE_VARCHAR,          /* VARCHAR[n] */
    ESQL_TYPE_VARCHARP,         /* VARCHAR* */

    /* EXTERNAL DATATYPE */
    ESQL_TYPE_VARRAW,           /* VARRAW */
    ESQL_TYPE_LONG_VARRAW,      /* LONG VARRAW */

    /* EXTENED DATATYPE */
    ESQL_TYPE_NCHAR_ARRAY,      /* NCHAR */

    /* LOB */
    ESQL_TYPE_CLOB,             /* CLOB */
    ESQL_TYPE_BLOB,             /* BLOB */
    ESQL_TYPE_BFILE,            /* BFILE */

    /* COBOL COMP3 */
    ESQL_TYPE_CBL_COMP3,        /* COBOL COMP3 */
    ESQL_TYPE_EXT_VARCHAR,      /* external datatype */

    /* CURSOR */
    ESQL_TYPE_CURSOR,           /* SQL_CURSOR */

    ESQL_HVTYPE_EXT_NUMBER          = 30,
    ESQL_HVTYPE_EXT_VARNUM          = 31,
    ESQL_HVTYPE_EXT_INTEGER         = 32,
    ESQL_HVTYPE_EXT_FLOAT           = 33,
    ESQL_HVTYPE_EXT_LONG            = 34,
    ESQL_HVTYPE_EXT_UNSIGNED        = 35,
    ESQL_HVTYPE_EXT_CHAR            = 36,
    ESQL_HVTYPE_EXT_CHARZ           = 37,
    ESQL_HVTYPE_EXT_CHARF           = 38,
    ESQL_HVTYPE_EXT_STRING          = 39,
    ESQL_HVTYPE_EXT_VARCHAR         = 40,
    ESQL_HVTYPE_EXT_VARCHAR2        = 41,
    ESQL_HVTYPE_EXT_LONG_VARCHAR    = 42,
    ESQL_HVTYPE_EXT_VARRAW          = 43,
    ESQL_HVTYPE_EXT_LONG_VARRAW     = 44,
    ESQL_HVTYPE_EXT_RAW             = 45,
    ESQL_HVTYPE_EXT_ROWID           = 46,
    ESQL_HVTYPE_EXT_LONG_RAW        = 47 
} esql_hostvar_type_t;



/*
==========================================
       ESQL type 
==========================================
*/

typedef enum esql_type_t {
    /* CONNECT */
    ESQL_TYPE_CONNECT = 1,

    /* DML */
    ESQL_TYPE_SELECT,
    ESQL_TYPE_EXECUTE_DML,

    /* cursor */
    ESQL_TYPE_OPEN_CURSOR,
    ESQL_TYPE_CLOSE_CURSOR,
    ESQL_TYPE_FETCH,

    ESQL_TYPE_COMMIT,
    ESQL_TYPE_COMMIT_RELEASE,
    ESQL_TYPE_ROLLBACK,
    ESQL_TYPE_ROLLBACK_RELEASE,
    ESQL_TYPE_ROLLBACK_TO_SAVEPOINT,

    /* DDL */
    ESQL_TYPE_DDL,  

    /* PSM */
    ESQL_TYPE_PSM,  

    ESQL_TYPE_DYN_EXEC_IMMED,
    ESQL_TYPE_DYN_EXECUTE,
    ESQL_TYPE_DYN_PREPARE,
    ESQL_TYPE_DYN_OPEN_CURSOR,
    ESQL_TYPE_DYN_DESC_BIND,
    ESQL_TYPE_DYN_DESC_SELECT,

    ESQL_TYPE_ANSIDYN_ALLOC_DESC,
    ESQL_TYPE_ANSIDYN_DEALLOC_DESC,
    ESQL_TYPE_ANSIDYN_SET_DESC,
    ESQL_TYPE_ANSIDYN_GET_DESC,
    ESQL_TYPE_ANSIDYN_DESC_INPUT,
    ESQL_TYPE_ANSIDYN_DESC_OUTPUT,

    /* THREAD & CONTEXT */
    ESQL_TYPE_ENABLE_THREADS,
    ESQL_TYPE_CONTEXT_ALLOCATE,
    ESQL_TYPE_CONTEXT_USE,
    ESQL_TYPE_CONTEXT_FREE,

    /* ALLOCATE & FREE */
    ESQL_TYPE_ALLOCATE,
    ESQL_TYPE_FREE,

    /* LOB */
    ESQL_TYPE_LOB_APPEND,
    ESQL_TYPE_LOB_ASSIGN,
    ESQL_TYPE_LOB_CLOSE,
    ESQL_TYPE_LOB_COPY,
    ESQL_TYPE_LOB_CREATE_TEMP,
    ESQL_TYPE_LOB_DESCRIBE,
    ESQL_TYPE_LOB_ERASE,
    ESQL_TYPE_LOB_FREE_TEMP,
    ESQL_TYPE_LOB_OPEN,
    ESQL_TYPE_LOB_READ,
    ESQL_TYPE_LOB_TRIM,
    ESQL_TYPE_LOB_WRITE,

    /* ETC */
    ESQL_TYPE_START_SQL,
    ESQL_TYPE_END_SQL,

    ESQL_TYPE_REGISTER_CONNECT,
    ESQL_TYPE_XA_SET_CONNECTION
} esql_type_t;



/*
==========================================
       char_map 
==========================================


CHAR_MAP  fixed-length  blank-padded  null-terminated  NULL is fixed-length
(DBMS)                                                      blank-padded
---------------------------------------------------------------------------
VARCHAR2        o           o             x               o
CHARF           o           o             x               x
CHARZ           o           o             o               o
STRING          x           x             o               x
*/

typedef enum char_map_e {
    CHAR_MAP_DEFAULT = 0,
    CHAR_MAP_VARCHAR2,
    CHAR_MAP_CHARF,
    CHAR_MAP_CHARZ,
    CHAR_MAP_STRING
} char_map_t;



typedef enum esql_desc_item_e {
    ESQL_DESC_ITEM_NONE = 0,
    ESQL_DESC_ITEM_TYPE,
    ESQL_DESC_ITEM_LENGTH,
    ESQL_DESC_ITEM_INDICATOR,
    ESQL_DESC_ITEM_INDICATOR_P,
    ESQL_DESC_ITEM_DATA,
    ESQL_DESC_ITEM_DATA_P,
    ESQL_DESC_ITEM_OCTET_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH_P,
    ESQL_DESC_ITEM_RETURNED_OCTET_LENGTH,
    ESQL_DESC_ITEM_PRECISION,
    ESQL_DESC_ITEM_SCALE,
    ESQL_DESC_ITEM_NULLABLE,
    ESQL_DESC_ITEM_NAME,
    ESQL_DESC_ITEM_CHARACTER_SET_NAME,
    ESQL_DESC_COUNT
} esql_desc_item_t;



#include <string.h>


#include "sqlca.h"
typedef struct esql_cpool_env_s {
    int cpool_max;
    int cpool_min;
    int cpool_incr;
    int cpool_timeout;
    int cpool_nowait;
}esql_cpool_env_t;


typedef void * sql_context;
typedef void * SQL_CONTEXT;



typedef void * sql_cursor;
typedef void * SQL_CURSOR;



typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;




typedef struct esql_sqlctx_ext {
    unsigned short     version;
    esql_cpool_env_t  *cp_env;
    void* reserved[20];
}esql_sqlctx_ext_t;




static struct esql_sqlctx {
    esql_type_t     stmt_type;

    char           *db_name;
    char           *cursor_name;
    char           *pstmt_name;
    char           *savepoint;
    char           *stmt;

    char_map_t      char_map;
    int             stmt_cache_size;
    int             fetch_type;
    int             abs_rel_nth;
    int             flag;
    int             option;

    struct sqlca   *sqlca;
    void           *sqlda;

    char           *desc_name;
    char           *desc_into;
    int             value;

    sql_context    *sql_ctx;
    char           *sqlstate;

    unsigned int    file_id;
    unsigned int    prefetch;

    int             rmid;

    unsigned int    dummy[2];

    esql_sqlctx_ext_t *sqlctx_ext;

    void           *oraca;
    void           *ep_ctx;

    unsigned int    iter_cnt;               /* count of iteration */
    unsigned int    host_var_total_cnt;     /* total # of host var */
    unsigned int    host_var_out_cnt;       /* # of out host var */

    void               **p_hostvar;         /* array of host var */
    unsigned int        *p_hostvar_len;     /* array of length of host var */
    unsigned int        *p_hostvar_stride;  /* array of stride of host var */
    esql_hostvar_type_t *p_hostvar_type;    /* array of host var type */
    unsigned int        *p_param_type;      /* array of param type */
    esql_desc_item_t    *p_ansi_dyn_type;   /* array of ansi dyn item type */
    void               **p_hostind;         /* array of host ind */
    unsigned int        *p_hostind_stride;  /* array of stride of host ind */
    long                *p_ind;             /* array of indicator */


    void                *hostvar[2];        /* array of host var */
    unsigned int         hostvar_len[2];    /* array of length of host var */
    unsigned int         hostvar_stride[2]; /* array of stride of host var */
    esql_hostvar_type_t  hostvar_type[2];   /* array of host var type */
    unsigned int         param_type[2];     /* array of param type */
    esql_desc_item_t     ansi_dyn_type[2];  /* array of ansi dyn item type */
    void                *hostind[2];        /* array of host ind */
    unsigned int         hostind_stride[2]; /* array of stride of host ind */
    long                 ind[2];            /* array of indicator */

} sqlstm;


extern void esql_do(struct esql_sqlctx *_sqlctx);



#endif



/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <time.h> */
/* #include <sys/timeb.h> */
/* #include <string.h> */

#include "coapi_user.h" 
/*EXEC SQL INCLUDE coapi_user;*/

	/*
		EXEC SQL INCLUDE SQLCA;
	 */
#ifndef _SQLCA_H
#define _SQLCA_H

#define SQLERRMC_LEN	70

struct sqlca {
    char    sqlcaid[8];              /* "SQLCA" id */
    int     sqlabc;                  /* byte length of SQL structure */
    int     sqlcode;                 /* status code of SQL execution */

    struct {
        unsigned short sqlerrml;     /* message length */
        char           sqlerrmc[SQLERRMC_LEN]; /* error message */
    } sqlerrm;

    char    sqlerrp[8];              /* RESERVED */
    int     sqlerrd[6];              /* error */
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows affected after an INSERT, UPDATE, DELETE	*/
	/* 3: empty							*/
	/* 4: empty							*/
	/* 5: empty							*/

    char    sqlwarn[8];              /* warning */
  	/* Element 0: set to 'W' if at least one other is 'W'		*/
	/* 1: if 'W' at least one character string			*/
	/* value was truncated when it was stored into a host variable.	*/
	/* 2: if 'W' a (hopefully) non-fatal notice occured		*/
	/* 3: empty 							*/
	/* 4: empty							*/
	/* 5: empty							*/
	/* 6: empty							*/
	/* 7: empty							*/
    char    sqlext[8];               /* RESERVED */
};

#ifndef _WIN32
extern struct sqlca sqlca;
#else   /* _WIN32 */
#   ifdef __cplusplus
extern "C" struct sqlca __declspec(dllimport) sqlca;
#   else
extern struct sqlca __declspec(dllimport) sqlca;
#   endif
#endif  /* _WIN32 */

#endif  /* _SQLCA_H */

char plain[100] = "1234567890123";
char item[10] = "SSN";

char encOut[2000], decOut[2000];
int nDecLen, nEncLen, nRtn;

void selDateDual();
void encDecAPI();
void selDualPlg();

int main(int argc, char *argv[])
{

    printf("################################################\n");
    printf("###### CubeOne API SelfTest : PRO*C TEST #######\n");
    printf("################################################\n\n");

    /* Connect to DB */
    
	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
        /*char userid[40]= "scott/one123@ORCL";*/
        char userid[40]= "test/test";
    
	/*
		EXEC SQL END DECLARE SECTION;
	 */

    printf("<<< main :: id/pass = [%s]\n", userid);

    /* printf(" - Press Enter to Next-A !!!\n"); getchar();	*/
    
	/*
		EXEC SQL CONNECT :userid;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CONNECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 262144;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(userid);
    __sqlctx.hostvar_len[0]     = (unsigned int)40;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
    /* printf(" - Press Enter to Next-B !!!\n"); getchar();	*/

    if (sqlca.sqlcode < 0)
    {
        printf("<<< main :: %s\n", sqlca.sqlerrm.sqlerrmc);
        
	/*
		EXEC SQL ROLLBACK WORK RELEASE;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_ROLLBACK_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
        exit(0);
    }

    if (nRtn != CTR_SUCCESS) {
        printf("<<< CubeLog :: CO_init failed. returned %d\n", nRtn);
        exit(1);
    }

    printf("<<< main :: plain = [%s]\n", plain);
    printf("<<< main :: item = [%s]\n", item);
    printf("\n");

    selDateDual();
    /*selDualPlg(); */
    encDecAPI();

    
	/*
		EXEC SQL COMMIT WORK RELEASE;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_COMMIT_RELEASE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    return 0;
}

void encDecAPI() {

    printf ("<<< encDecAPI() :: start !!!!!\n" );

    /* nRtn = CO_init_api("ORCL"); */
    /******************************************************/
    nRtn = CO_enc_char(plain,item,10,"TBL","COL",encOut,&nEncLen);
    
    if (nRtn == CTR_SUCCESS) {
        printf (" - encrypt = [%s]\n",encOut);
        printf (" - strlen(encrypt) = %ld,%d \n",strlen((char *)encOut),nEncLen );
    }
    else {
        printf("<<< CubeLog :: Failed Encryption data with return [%d].\n",nRtn);
        return ; 
    }
    printf ("\n",decOut);

    /******************************************************/
    nRtn = CO_dec_char(encOut,nEncLen,item,10,"TBL","COL",decOut);

    if (nRtn == CTR_SUCCESS) {
        printf (" - decrypt = [%s]\n",decOut);
        printf (" - strlen(decrypt) = %ld \n",strlen(decOut) );
    }
    else {
        printf("<<< CubeLog :: Failed Decryption data with return [%d].\n",nRtn);
        return ; 
    }

    printf ("<<< encDecAPI() :: end !!!!!\n\n" );
}

void selDateDual() {

    printf ("<<< selDateDual() :: start !!!!!\n" );

    
	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
            /*	VARCHAR sysdate[100+1];	*/
struct __tag02 { unsigned short len; unsigned char arr[100+1]; } sysdate;
    
	/*
		EXEC SQL END DECLARE SECTION;
	 */

    /*****************************************************************/
    char stmt[20000];
    memset(stmt, 0x00, sizeof(stmt));

    sprintf(stmt, "SELECT sysdate FROM DUAL");
    
	/*
		EXEC SQL PREPARE SEL_PRE FROM :stmt;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_DYN_PREPARE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "SEL_PRE";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(stmt);
    __sqlctx.hostvar_len[0]     = (unsigned int)20000;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    
	/*
		EXEC SQL DECLARE C2 CURSOR FOR SEL_PRE;
	 */
    
	/*
		EXEC SQL OPEN C2 ;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_DYN_OPEN_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C2";
    __sqlctx.pstmt_name  = "SEL_PRE";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 256;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 0;
    __sqlctx.host_var_out_cnt   = 0;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf(" - sql = [%s]\n", stmt);

    
	/*
		EXEC SQL WHENEVER NOT FOUND DO break;
	 */
    while(1)
    {
        memset(&sysdate, 0x00, sizeof(sysdate));

        
	/*
		EXEC SQL FETCH C2 INTO
            :sysdate ;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_FETCH;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C2";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(sysdate));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(sysdate.arr);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_VARCHAR;
    __sqlctx.param_type[0]      = 1;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
    if (sqlca.sqlcode == TBSQLCODE_NOTFOUND) break;
}

        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog :: selDateDual() : sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog :: selDateDual() : %s\n", sqlca.sqlerrm.sqlerrmc);
            
	/*
		EXEC SQL CLOSE C2;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CLOSE_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C2";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
            exit(-1);
        }
        printf (" - sysdate = [%s]\n" , sysdate.arr);
    }

    
	/*
		EXEC SQL WHENEVER SQLERROR CONTINUE;
	 */
    
	/*
		EXEC SQL CLOSE C2;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CLOSE_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C2";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf ("<<< selDateDual() :: end !!!!!\n\n" );
}


void selDualPlg() {

    printf ("<<< selDualPlg() :: start !!!!!\n" );

    
	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */
            /*	VARCHAR enc[100+1];	*/
struct __tag03 { unsigned short len; unsigned char arr[100+1]; } enc;
    
	/*
		EXEC SQL END DECLARE SECTION;
	 */

    nRtn = CO_init_api("API");
    /*****************************************************************/
    char stmt[20000];
    memset(stmt, 0x00, sizeof(stmt));

    sprintf(stmt, "SELECT xx1.enc_varchar2_ins(:plain,10,:item) FROM DUAL");
    
	/*
		EXEC SQL PREPARE SEL_PRE FROM :stmt;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_DYN_PREPARE;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "SEL_PRE";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(stmt);
    __sqlctx.hostvar_len[0]     = (unsigned int)20000;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    
	/*
		EXEC SQL DECLARE C1 CURSOR FOR SEL_PRE;
	 */
    
	/*
		EXEC SQL OPEN C1 USING :plain, :item  ;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_DYN_OPEN_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C1";
    __sqlctx.pstmt_name  = "SEL_PRE";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 256;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(plain);
    __sqlctx.hostvar_len[0]     = (unsigned int)100;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(item);
    __sqlctx.hostvar_len[1]     = (unsigned int)10;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.param_type[1]      = 0;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf(" - sql = [%s]\n", stmt);

    
	/*
		EXEC SQL WHENEVER NOT FOUND DO break;
	 */
    while(1)
    {
        memset(&enc, 0x00, sizeof(enc));

        
	/*
		EXEC SQL FETCH C1 INTO
            :enc ;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_FETCH;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C1";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(enc));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(enc.arr);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_VARCHAR;
    __sqlctx.param_type[0]      = 1;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
    if (sqlca.sqlcode == TBSQLCODE_NOTFOUND) break;
}

        if (sqlca.sqlcode != 0) {
            printf("<<< CubeLog :: selectEncTable() : sqlca.sqlcode = [%d]\n", sqlca.sqlcode);
            printf("<<< CubeLog :: selectEncTable() : %s\n", sqlca.sqlerrm.sqlerrmc);
            
	/*
		EXEC SQL CLOSE C2;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CLOSE_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C2";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}
            exit(-1);
        }

        printf (" - enc = [%s]\n" , enc.arr);

    }

    
	/*
		EXEC SQL WHENEVER SQLERROR CONTINUE;
	 */
    
	/*
		EXEC SQL CLOSE C1;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_CLOSE_CURSOR;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "C1";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 0;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 160;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    printf ("<<< selDualPlg() :: end !!!!!\n\n" );
}

