echo  ============================
echo  === [1] delete co_adv
echo  ============================
rm co_adv

echo 
echo  ============================
echo  === [2] compile co_adv.c
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

    # $CCHOME/cc -o co_adv co_adv.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi
    $CCHOME/cc -o co_adv co_adv.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi
    ;;

'AIX')
    echo "AIX compile : start ..."

    CCHOME=/usr/vac/bin
    LIBPATH=$HOME/lib

    $CCHOME/cc -o co_adv co_adv.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread
    # $CCHOME/cc -o co_adv co_adv.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi
    ;;

'SunOS')
    echo "SunOS compile : start ..."

    CCHOME=/export/home/OPT/SUNWspro/bin

    cc -o co_adv co_adv.c -m64 -L$HOME/lib -I$HOME/include -lcrypto -lssl -lCOencapi
    # cc -o co_adv co_adv.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a
    ;;

'Linux')
    echo "Linux compile : start ..."

    CCHOME=/usr/bin

    $CCHOME/cc -o co_adv co_adv.c -L$HOME/lib -I$HOME/include -lCOencapi -lm
    # $CCHOME/cc -m32 -o co_adv co_adv.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
    # $CCHOME/cc -c co_adv.c -L$HOME/lib32 -I$HOME/include
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;

esac



