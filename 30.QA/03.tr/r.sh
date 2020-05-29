###################################################################
## LIB PATH ..
###################################################################
LD_LIBRARY_PATH=$HOME/lib;export LD_LIBRARY_PATH  # for LINUX(so), Solaris 
LIBPATH=$HOME/lib;export LIBPATH          				# for AIX
SHLIB_PATH=$HOME/lib;export SHLIB_PATH       			# for HP

#java -classpath .:CubeOneAPI.class -Djava.library.path=$HOME/lib ThreadMain 
#/data/oracle10/product/jdk/bin/java  -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain
#/data/oracle10/product/jdk/bin/java -d64  -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain
#java  -d64 -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain
#java  -classpath . -Djava.library.path=$HOME/lib ThreadMain

java  -d64 -classpath .:$HOME/lib/CubeOneAPI.jar -Djava.library.path=$HOME/lib ThreadMain
