

osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."

    # 32 bit
    #JAVAHOME=/opt/java1.5/bin/IA64N
    # 64 bit
    JAVAHOME=/opt/java6/bin/IA64W
    ;;

'AIX')
    echo "AIX compile : start ..."

    # 32 bit
    #JAVAHOME=/usr/java6/bin
    # 64 bit
    JAVAHOME=/usr/java6_64/bin
    ;;

'SunOS')
    echo "SunOS compile : start ..."
    #for Sun2 64bit if 32bit, delete -d64 option.
    JAVAHOME=/usr/bin
    ;;

'Linux')
    echo "Linux compile : start ..."

    JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;
esac

$JAVAHOME/javac -classpath $HOME/lib/CubeOneAPI.jar:../../../ojdbc5.jar *.java



