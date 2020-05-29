
osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."

    # 32 bit
    #JAVAHOME=/opt/java1.5/bin/IA64N
    # 64 bit
    JAVAHOME=/opt/java1.5/bin/IA64W

    export LANG=ko_KR.eucKR

    ;;

'AIX')
    echo "AIX compile : start ..."

    # 32 bit
    #JAVAHOME=/usr/java5/bin
    # 64 bit
    JAVAHOME=/usr/java5_64/bin
    ;;

'SunOS')
    echo "SunOS compile : start ..."
    export LANG=ko_KR.EUC

    #for Sun2 64bit if 32bit, delete -d64 option.
    JAVAHOME=/usr/bin
    ;;

'Linux')
    echo "Linux compile : start ..."
    export LANG=ko_KR.euckr 
    JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;
esac

#$JAVAHOME/javac -classpath $HOME/lib/CubeOneAPI.jar co_adv_euc.java
javac -classpath $HOME/lib/CubeOneAPI.jar co_adv_euc.java
