#-----------------------------------------------------------------------------
# UCM ENV
# -----------------------------------------------------------------------------
CC_EXE=cc
CC_OPT=-g -m64
SYSNAME=ucm10
SYSTYPE=sun
#SYSOPS="-DSUNOS -D_REENTRANT"
SYSOPS="-D_REENTRANT"
LD_TCP="-lsocket -lnsl"
LD_CUR="-lcurses"
LD_ORA="${ORACLE_HOME}/lib"
#-----------------------------------------------------------------------------     

###########################################
### Proc/C++ Makefile      ################
###########################################
CC        = ${CC_EXE}
PROC      = $(ORACLE_HOME)/bin/proc
LIB       = -L${LD_ORA} -lclntsh \
 `cat ${LD_ORA}/ldflags` \
 `cat ${LD_ORA}/sysliblist` -L${LD_ORA} -lm  -lthread
#------------------------------------------------------------------------------
SFLAGS   = ${SYSOPS} -DSLMXMX_ENABLE -DSLTS_ENABLE -D_SVID_GETTOD -D_REENTRANT
DFLAGS   = -DCOMPILEDATE=\"`date +%Y/%m/%d`\" \
     -DCOMPILETIME=\"`date +%H:%M:%S`\" -DCOMPILESYS=\"${SYSTYPE}\"
IFLAGS   = -I${UCMENV}/inc -I${HOME}/src/bt/inc
CFLAGS   = -DPACKED ${CC_OPT} $(SFLAGS) $(DFLAGS) $(IFLAGS)
#CFLAGS   = ${CC_OPT}  $(IFLAGS)
#UCM_LIB  = -L${UCMENV}/lib -lkoreaoracle  -lbtlib \
 -lucm -lucmtcp -lucmthr -lpthread ${LD_TCP}
PROCFG   = include=${UCMENV}/inc
PROCINC  = -I$(ORACLE_HOME)/precomp/public -I$(ORACLE_HOME)/rdbms/public \
 -I$(ORACLE_HOME)/rdbms/demo -I$(ORACLE_HOME)/plsql/public \
 -I$(ORACLE_HOME)/network/public
ORA_OPT=ireclen=132 oreclen=132 release_cursor=no \
     UNSAFE_NULL=YES MODE=ORACLE DBMS=v7 
#------------------------------------------------------------------------------
PROG    = co_thread
SRCS    =
PSRC    = $(PROG).pc
CSRC    = $(PSRC:.pc=.c)
LSRC    = $(PSRC:.pc=.lis)
OBJS    = $(SRCS:.c=.o) $(CSRC:.c=.o)
.SUFFIXES: .pc .c
#------------------------------------------------------------------------------
ORA_GARBAGE=$(CSRC) $(LSRC)
 
$(PROG): $(PSRC) $(CSRC) $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB) $(UCM_LIB) $(PROCINC)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB) $(PROCINC)
	@echo
	@echo " ------ Make Successful ------"
	@echo
 
.pc.c:
	@echo "===================================================="
	@echo "ขั precompile: [ $*.pc ] --->  [ $*.c ] : start !!!!"
	@echo "===================================================="

#	$(PROC) $(ORA_OPT) $(PROCFG) iname=$*.pc CODE=ANSI_C LINES=YES PARSE=NONE
	$(PROC) $(ORA_OPT) $(PROCFG) iname=$*.pc CODE=ANSI_C LINES=YES
	@echo "===================================================="

	$(CC) $(CFLAGS) $(PROCINC) $(PROINC) -c $*.c

	@echo "===================================================="
	@echo "ขั precompile: [ $*.pc ] --->  [ $*.c ] : end !!!!"
	@echo "===================================================="
	@echo
	@echo
 
.c.o:
	@echo "======================================="
	@echo "ขั compile: [ $*.c ] --->  [ $*.o ]"
	@echo "======================================="
#	$(CC) $(PROCINC) $(LIB) -c $<
	$(CC) $(CFLAGS) $(PROCINC) -c $<
 
install: $(PROG)
	cp -p ./$(PROG) $HOME/SAMPLE/$(PROG)
	chmod 755 $HOME/SAMPLE/$(PROG)
 
clean:
	rm -f $(PROG) $(OBJS) $(ORA_GARBAGE)


