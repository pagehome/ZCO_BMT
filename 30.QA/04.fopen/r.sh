clear
###################################################################
## LIB PATH ..  ###################################################################
export LD_LIBRARY_PATH=/data1/cubeapi/lib32  # for LINUX(so), Solaris 
export LIBPATH=/data1/cubeapi/lib32          # for AIX
export SHLIB_PATH=/data1/cubeapi/lib32       # for HP


###################################################################
## JAVA PATH ..
###################################################################

osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."

    # 32 bit
    # JAVAHOME=/opt/java1.5/bin/IA64N
    # 64 bit
    JAVAHOME=/opt/java1.5/bin/IA64W
    ;;

'AIX')
    echo "AIX compile : start ..."

    # 32 bit
    # JAVAHOME=/usr/java5/bin
    # 64 bit
    JAVAHOME=/usr/java5_64/bin
    ;;

'SunOS')
    echo "SunOS compile : start ..."
    #for Sun2 64bit if 32bit, delete -d64 option.
    JAVAHOME=/usr/bin

	#JAVAHOME=/usr/jdk/instances/jdk1.5.0/bin/sparcv9
	#JAVAHOME=/usr/jdk/instances/jdk1.6.0/bin/sparcv9

	#JAVAHOME=/usr/jdk/instances/jdk1.5.0/bin/
	JAVAHOME=/usr/jdk/instances/jdk1.6.0/bin/
        #JAVAHOME=/data/nspais/jdk1.5.0_85/bin
        #JAVAHOME=/data/nspais/jdk1.5.0_22/bin

    ;;

'Linux')
    echo "Linux compile : start ..."

    JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin
    ;;

*)
    echo "Compile failed !! Check OS name !!"
    exit 1;
esac

export CLASSPATH=.:/data1/cubeapi/lib/CubeOneAPI.jar
###################################################################
## RUN ..
###################################################################
# use java-option 
# $JAVAHOME/java -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib co_bmt

# use environment ..
#$JAVAHOME/java -d64 co_bmt
#$JAVAHOME/java  co_bmt 
#/usr/jdk1.7.0_80/bin/sparcv9/java  -d64 co_bmt 
#/usr/jdk1.7.0_80/bin/sparcv9/java   co_bmt 
#/usr/jdk/jdk1.5.0_30/bin/java  co_fopen  

echo $JAVAHOME
$JAVAHOME/java co_fopen  

