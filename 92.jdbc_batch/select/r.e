export LD_LIBRARY_PATH=$HOME/lib  # for LINUX(so), Solaris 
export LIBPATH=$HOME/lib               # for AIX
export SHLIB_PATH=$HOME/lib          # for HP
java -classpath .:$HOME/lib/CubeOneAPI.jar:$ORACLE_HOME/jdbc/lib/ojdbc14.jar DecPrint
