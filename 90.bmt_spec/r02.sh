# for HPi64 32bit
#JAVAHOME=/opt/java1.5/bin

# for HPi64 64bit
JAVAHOME=/opt/java1.5/bin/IA64W

# for AIX3 32bit
#JAVAHOME=/usr/java5/bin

# for AIX3 64bit
#JAVAHOME=/usr/java5_64/bin

# for Sun2 if 32bit, delete -d64 option.
#JAVAHOME=/usr/bin

# for Linux 
#JAVAHOME=/home/cubeapi/jdk1.7.0_40/bin


$JAVAHOME/java  -classpath .:$HOME/lib/CubeOneAPI.jar:Altibase.jar -Djava.library.path=$HOME/lib BMT02_COL


