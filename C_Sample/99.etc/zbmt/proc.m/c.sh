#!/bin/ksh
clear
echo "================================================="
echo "=== [STEP-1] CLEAR : files  .... "
echo "================================================="
rm Thread_example1.c Thread_example1.lis Thread_example1
echo "rm Thread_example1.c Thread_example1.lis Thread_example1"

echo 
echo "================================================="
echo "=== [STEP-2] COMPILE : PROC .... "
echo "================================================="
proc  iname=Thread_example1 include=$HOME/include CHAR_MAP=CHARZ THREADS=YES
#proc  iname=Thread_example1 include=/usr/lib/gcc/i386-redhat-linux/4.1.1/include include=$HOME/include
#include=. include=$ORACLE_HOME/precomp/public,$ORACLE_HOME/rdbms/demo,$ORACLE_HOME/plsql/public,$ORACLE_HOME/network/public

echo 
echo "================================================="
echo "=== [STEP-3] COMPILE : C .... "
echo "================================================="

# for HPi64
# CCHOME=/opt/ansic/bin
# SHLIB_PATH=$HOME/lib
# $CCHOME/cc -o Thread_example1 Thread_example1.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o Thread_example1 Thread_example1.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh

# for AIX3
#CCHOME=/usr/vac/bin
#LIBPATH=$HOME/lib
# $CCHOME/cc -o Thread_example1 Thread_example1.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
#$CCHOME/cc -o Thread_example1 Thread_example1.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
#$CCHOME/cc -o Thread_example1 Thread_example1.c  -q64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh

# for Sun2
# CCHOME=/export/home/OPT/SUNWspro/bin
# $CCHOME/cc -o Thread_example1 Thread_example1.c -lsocket -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
# $CCHOME/cc -o Thread_example1 Thread_example1.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
#cc -o Thread_example1 Thread_example1.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi

# for Linux
CCHOME=/usr/bin
#$CCHOME/cc -m32 -o Thread_example1 Thread_example1.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
$CCHOME/cc -o Thread_example1 Thread_example1.c -L$HOME/lib -I$HOME/include -lCOencapi  -L$ORACLE_HOME/lib -lclntsh
#$CCHOME/cc -c Thread_example1.c -L$HOME/lib32 -I$HOME/include 

echo 

