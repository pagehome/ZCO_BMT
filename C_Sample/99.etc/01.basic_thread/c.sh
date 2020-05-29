# for HPi64
CCHOME=/opt/ansic/bin
# SHLIB_PATH=$HOME/lib
# $CCHOME/cc -o co_bmt co_bmt.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi
$CCHOME/cc -o co_bmt co_bmt.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi


# for AIX3
# CCHOME=/usr/vac/bin
# LIBPATH=$HOME/lib
# $CCHOME/cc -o co_bmt co_bmt.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi
# $CCHOME/cc -o co_bmt co_bmt.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread


# for Sun2
# CCHOME=/export/home/OPT/SUNWspro/bin
# $CCHOME/cc -o co_bmt co_bmt.c -lsocket -L$HOME/lib -I$HOME/include -lCOencapi
# $CCHOME/cc -o co_bmt co_bmt.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi
#cc -o co_bmt co_bmt.c -lsocket -m64 -L$HOME/lib -I$HOME/include -lCOencapi


# for Linux
# CCHOME=/usr/bin
# $CCHOME/cc -o co_bmt co_bmt.c -L$HOME/lib -I$HOME/include -lCOencapi
