clear

#if [ $# -eq 0 ]
#then
#    echo "Usage: $0 fileName item"
#    exit 1
#fi



###################################################################
## LIB PATH ..
###################################################################
export LD_LIBRARY_PATH=$HOME/lib  # for LINUX(so), Solaris
export LIBPATH=$HOME/lib          # for AIX
export SHLIB_PATH=$HOME/lib       # for HP


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
    JAVAHOME=/opt/java6/bin/IA64W
    ;;

'AIX')
    echo "AIX compile : start ..."

    # 32 bit
    # JAVAHOME=/usr/java6/bin
    # 64 bit
    # JAVAHOME=/usr/java5_64/bin
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

export CLASSPATH=.:$HOME/lib/CubeOneAPI.jar:../../../../ojdbc6.jar:../../../tibero6-jdbc.jar

###################################################################
## RUN ..
###################################################################
# use java-option
# $JAVAHOME/java -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib co_bmt


echo
echo  ====================================================================================================
echo  === [0] rm *.dec
echo  ====================================================================================================
rm *.dec

echo
echo  ====================================================================================================
echo  === [1] $JAVAHOME/java co_blob unix.pdf.bin AES256
echo  ====================================================================================================
echo
# use environment ..
$JAVAHOME/java co_blob unix.pdf.bin AES256


echo
echo  ====================================================================================================
echo  === [2] diff unix.pdf.bin unix.pdf.bin.dec
echo  ====================================================================================================
diff unix.pdf.bin unix.pdf.bin.dec


