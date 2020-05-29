clear
echo 
echo  ============================
echo  === [0] Tibero Environment
echo  ============================
. ./tbr.env
env | grep ORA
echo 

echo  ============================
echo  === [1] delete co_pc
echo  ============================
rm co_pc co_pc.c co_pc.lis
echo "rm co_pc.c co_pc.lis co_pc"
echo 



echo  ============================
echo  === [2] Pre-Compile Pro*C
echo  ============================
tbpc  iname=co_pc include=$HOME/include CHAR_MAP=CHARZ
#proc  iname=co_pc include=/usr/lib/gcc/i386-redhat-linux/4.1.1/include include=$HOME/include
#include=. include=$ORACLE_HOME/precomp/public,$ORACLE_HOME/rdbms/demo,$ORACLE_HOME/plsql/public,$ORACLE_HOME/network/public
echo 

echo  ============================
echo  === [3] compile co_pc.c
echo  ============================

osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`
echo

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."

    CCHOME=/opt/ansic/bin
    SHLIB_PATH=$HOME/lib

    #######################################################
    # link .so
    # $CCHOME/cc -o co_pc co_pc.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh
    $CCHOME/cc -o co_pc co_pc.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh

    #######################################################
    # link .a
    # $CCHOME/cc -o co_pc co_pc.c -DHPUX +DD32 -DBIT32 -I$HOME/include $HOME/lib/libCOencapi.a -L$ORACLE_HOME/lib -lclntsh
    # $CCHOME/cc -o co_pc co_pc.c -DHPUX +DD64 -DBIT64 -I$HOME/include $HOME/lib/libCOencapi.a -L$ORACLE_HOME/lib -lclntsh
    ;;

'AIX')
    echo "AIX compile : start ..."

    CCHOME=/usr/vac/bin
    LIBPATH=$HOME/lib

    $CCHOME/cc -o co_pc co_pc.c -brtl -q64 -I$HOME/include -I$TB_HOME/client/include -L$HOME/lib -lCOencapi -L$TB_HOME/client/lib -ltbertl -ltbcli -lpthread -lm

    # $CCHOME/cc -o co_pc co_pc.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread -L$ORACLE_HOME/lib -lclntsh
    # $CCHOME/cc -o co_pc co_pc.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread -L$ORACLE_HOME/lib -lclntsh
    ;;

'SunOS')
    echo "SunOS compile : start ..."

    CCHOME=/export/home/OPT/SUNWspro/bin

    cc -o co_pc co_pc.c -m64 -L$HOME/lib -I$HOME/include -lCOencapi -L$ORACLE_HOME/lib -lclntsh
    # cc -o co_pc co_pc.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a -L$ORACLE_HOME/lib -lclntsh
    ;;

'Linux')
    echo "Linux compile : start ..."

    CCHOME=/usr/bin

    $CCHOME/cc -o co_pc co_pc.c -I$HOME/include -I$TB_HOME/client/include -L$HOME/lib -lCOencapi -L$TB_HOME/client/lib -ltbertl -ltbcli -lpthread -lm

    # $CCHOME/cc -m32 -o co_pc co_pc.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm -L$ORACLE_HOME/lib -lclntsh
    # $CCHOME/cc -c co_pc.c -L$HOME/lib32 -I$HOME/include -L$ORACLE_HOME/lib -lclntsh
    ;;

*)
    echo "Compile failed !! Check OS name !!"

    exit 1;

esac
