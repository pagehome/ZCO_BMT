clear
###################################################################
## LIB PATH ..
###################################################################
export LD_LIBRARY_PATH=$HOME/lib  # for LINUX(so), Solaris 
export LIBPATH=$HOME/lib          # for AIX
export SHLIB_PATH=$HOME/lib       # for HP


###################################################################
## JAVA PATH ..
###################################################################
# for HPi64 32bit
#JAVAHOME=/opt/java1.5/bin

# for HPi64 64bit
#JAVAHOME=/opt/java1.5/bin/IA64W

# for AIX3 32bit
#JAVAHOME=/usr/java5/bin

# for AIX3 64bit
#JAVAHOME=/usr/java5_64/bin

# for Sun2 if 32bit, delete -d64 option.
#JAVAHOME=/usr/bin

# for Linux 
JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin




###################################################################
## RUN ..
###################################################################
# use java-option 
#$JAVAHOME/java -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib co_bmt
# use environment ..
#$JAVAHOME/java -Dfile.encoding=UTF-8 -classpath .:$HOME/lib/CubeOneAPI.jar:../ojdbc14.jar  -Djava.library.path=$HOME/lib co_han
#$JAVAHOME/java  -classpath .:$HOME/lib/CubeOneAPI.jar:../ojdbc14.jar  -Djava.library.path=$HOME/lib co_han

#$JAVAHOME/java -Dfile.encoding=EUC-KR -classpath .:$HOME/lib/CubeOneAPI.jar:../ojdbc14.jar  -Djava.library.path=$HOME/lib co_han
$JAVAHOME/java  -classpath .:$HOME/lib/CubeOneAPI.jar:../ojdbc14.jar  -Djava.library.path=$HOME/lib co_han
