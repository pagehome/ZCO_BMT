
osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

###################################################################
## LIB PATH ..
###################################################################
export LD_LIBRARY_PATH=$HOME/lib  # for LINUX(so), Solaris 
export LIBPATH=$HOME/lib          # for AIX
export SHLIB_PATH=$HOME/lib       # for HP

###################################################################
## JAVA PATH ..
###################################################################

case "$osname" in
'HP-UX')
    echo "HP-UX runtime : start ..."

    # 32 bit
    # JAVAHOME=/opt/java1.5/bin/IA64N
    # 64 bit
    JAVAHOME=/opt/java1.5/bin/IA64W
    ;;

'AIX')
    echo "AIX runtime : start ..."

    # 32 bit
    #JAVAHOME=/usr/java5/bin
    # 64 bit
    JAVAHOME=/usr/java5_64/bin
    ;;

'SunOS')
    echo "SunOS runtime : start ..."
    #for Sun2 64bit if 32bit, delete -d64 option.
    JAVAHOME=/usr/bin
    ;;

'Linux')
    echo "Linux runtime : start ..."

    JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;
esac


echo
echo  ====================================================================================================
echo  === [1] $JAVAHOME/java -classpath .:$HOME/lib/CubeOneAPI.jar ThreadMain
echo  ====================================================================================================
# use environment ..
#$JAVAHOME/java -d64 -classpath .:$HOME/lib/CubeOneAPI.jar ThreadMain
#$JAVAHOME/java -d64 -classpath .:$HOME/lib/CubeOneAPI.jar ThreadMain
java -d64 -classpath .:$HOME/lib/CubeOneAPI.jar ThreadMain

# use java-option 
#$JAVAHOME/java -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain
