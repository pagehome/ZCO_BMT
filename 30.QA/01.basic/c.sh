osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."

    #for HP-PARISC
    #JAVAHOME=/opt/java1.4/bin

    # 32 bit
    # JAVAHOME=/opt/java1.5/bin/IA64N
    
    # 64 bit
    JAVAHOME=/opt/java1.5/bin/IA64W

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

echo
echo  ====================================================================================================
echo  === [0] rm *.class
echo  ====================================================================================================
rm *.class

echo
echo  ====================================================================================================
echo  === [1] $JAVAHOME/javac -source 1.4 -classpath $HOME/lib/CubeOneAPI.jar -d . *.java
echo  ====================================================================================================
$JAVAHOME/javac -source 1.4 -classpath $HOME/lib/CubeOneAPI.jar -d . *.java

