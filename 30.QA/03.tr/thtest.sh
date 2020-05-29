###################################################################
## LIB PATH ..
###################################################################
LD_LIBRARY_PATH=$HOME/lib;export LD_LIBRARY_PATH  # for LINUX(so), Solaris 
LIBPATH=$HOME/lib;export LIBPATH          				# for AIX
SHLIB_PATH=$HOME/lib;export SHLIB_PATH       			# for HP

indate=`date '+%m-%d_%H:%M'` 

echo Start Test================= > svrlog_$indate
cnt=0
while [ 1 ] 
do
cnt=`expr $cnt + 1`
#java -classpath .:CubeOneAPI.class -Djava.library.path=$HOME/lib ThreadMain 
#/data/oracle10/product/jdk/bin/java -d64 -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain 
java -d64 -classpath .:$HOME/lib/CubeOneAPI.jar  -Djava.library.path=$HOME/lib ThreadMain 
if [ $? -eq 0 ] ;then
	echo ========================================== >> svrlog_$indate
	echo $cnt >> svrlog_$indate
	date >> svrlog_$indate
	echo ========================================== >> svrlog_$indate
else 
	echo ========================================== >> svrlog_$indate
	echo $cnt >> svrlog_$indate
	date >> svrlog_$indate
	echo error >> svrlog_$indate
	echo ========================================== >> svrlog_$indate
	exit 1
fi
sleep 1

if [ $cnt -eq 2000 ]; then
	echo end $cnt >> svrlog_$indate
	exit 0
fi

done
