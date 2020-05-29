echo  ============================
echo  === [1] delete co_bmt
echo  ============================
rm co_bmt

echo 
echo  ============================
echo  === [2] compile co_bmt.cpp
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
    # $CCHOME/cc -o co_bmt co_bmt.cpp -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi
    $CCHOME/cc -o co_bmt co_bmt.cpp -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi

    #######################################################
    # link .a
    # $CCHOME/cc -o co_bmt co_bmt.cpp -DHPUX +DD32 -DBIT32 -I$HOME/include $HOME/lib/libCOencapi.a
    # $CCHOME/cc -o co_bmt co_bmt.cpp -DHPUX +DD64 -DBIT64 -I$HOME/include $HOME/lib/libCOencapi.a

    $CCHOME/aCC -o co_bmt co_bmt.cpp +DD32 -I$HOME/include -L$HOME/lib -lCOencapi


    ;;

'AIX')
    echo "AIX compile : start ..."

    CCHOME=/usr/vacpp/bin
    LIBPATH=$HOME/lib

    $CCHOME/xlC -o co_bmt co_bmt.cpp -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi 
    #$CCHOME/xlC -o co_bmt co_bmt.cpp -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread
    # $CCHOME/cc -o co_bmt co_bmt.cpp -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi
    ;;

'SunOS')
    echo "SunOS compile : start ..."

    CCHOME=/export/home/OPT/SUNWspro/bin

    cc -o co_bmt co_bmt.cpp -m64 -L$HOME/lib -I$HOME/include -lCOencapi
    # cc -o co_bmt co_bmt.cpp -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a
    ;;

'Linux')
    echo "Linux compile : start ..."

    CCHOME=/usr/bin

    $CCHOME/g++ -o co_bmt co_bmt.cpp -L$HOME/lib -I$HOME/include -lCOencapi -lm
    # $CCHOME/cc -m32 -o co_bmt co_bmt.cpp -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
    # $CCHOME/cc -c co_bmt.cpp -L$HOME/lib32 -I$HOME/include
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;

esac



