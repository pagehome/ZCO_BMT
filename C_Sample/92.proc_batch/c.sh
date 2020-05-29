#!/bin/ksh
clear
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-0] CLEAR : files  .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
rm co_batch.c co_batch.lis co_batch
echo "rm co_batch.c co_batch.lis co_batch"
echo ""


echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-1] COMPILE : PROC .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
proc  iname=co_batch include=$HOME/include 
#proc  iname=co_batch include=$HOME/include CHAR_MAP=CHARZ
#proc  iname=co_batch include=/usr/lib/gcc/i386-redhat-linux/4.1.1/include include=$HOME/include
#include=. include=$ORACLE_HOME/precomp/public,$ORACLE_HOME/rdbms/demo,$ORACLE_HOME/plsql/public,$ORACLE_HOME/network/public
echo ""




echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-2] COMPILE : C .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"

# for HPi64
  CCHOME=/opt/ansic/bin
# SHLIB_PATH=$HOME/lib
# $CCHOME/cc -o co_batch co_batch.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh
  $CCHOME/cc -o co_batch co_batch.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh


# for AIX3
# CCHOME=/usr/vac/bin
# LIBPATH=$HOME/lib
# $CCHOME/cc -o co_batch co_batch.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_batch co_batch.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_batch co_batch.c  -q64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh


# for Sun2
# CCHOME=/export/home/OPT/SUNWspro/bin
# $CCHOME/cc -o co_batch co_batch.c -lsocket -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_batch co_batch.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# cc -o co_batch co_batch.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi

# for Linux
# CCHOME=/usr/bin
# $CCHOME/cc -m32 -o co_batch co_batch.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
# $CCHOME/cc -o co_batch co_batch.c -L$HOME/lib -I$HOME/include -lCOencapi  -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -c co_batch.c -L$HOME/lib32 -I$HOME/include 
echo ""



