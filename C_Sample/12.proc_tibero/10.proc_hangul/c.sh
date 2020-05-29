#!/bin/ksh
clear
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-0] CLEAR : files  .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
rm co_hangul.c co_hangul.lis co_hangul
echo "rm co_hangul.c co_hangul.lis co_hangul"
echo ""


echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-1] COMPILE : PROC .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
proc CHAR_MAP=CHARZ   iname=co_hangul include=$HOME/include PARSE=FULL
#proc  iname=co_hangul include=/usr/lib/gcc/i386-redhat-linux/4.1.1/include include=$HOME/include
#include=. include=$ORACLE_HOME/precomp/public,$ORACLE_HOME/rdbms/demo,$ORACLE_HOME/plsql/public,$ORACLE_HOME/network/public




echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "<<< [STEP-2] COMPILE : C .... "
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"

# for HPi64
# CCHOME=/opt/ansic/bin
# SHLIB_PATH=$HOME/lib
# $CCHOME/cc -o co_bmt co_bmt.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_bmt co_bmt.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh


# for AIX3
# CCHOME=/usr/vac/bin
# LIBPATH=$HOME/lib
# $CCHOME/cc -o co_bmt co_bmt.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_bmt co_bmt.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread -L$ORACLE_HOME/lib -lclntsh


# for Sun2
# CCHOME=/export/home/OPT/SUNWspro/bin
# $CCHOME/cc -o co_bmt co_bmt.c -lsocket -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o co_bmt co_bmt.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
#cc -o co_bmt co_bmt.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi

# for Linux
CCHOME=/usr/bin
#$CCHOME/cc -m32 -o co_bmt co_bmt.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
$CCHOME/cc -o co_hangul co_hangul.c -L$HOME/lib -I$HOME/include -lCOencapi  -L$ORACLE_HOME/lib -lclntsh -lm
#$CCHOME/cc -c co_bmt.c -L$HOME/lib32 -I$HOME/include 



