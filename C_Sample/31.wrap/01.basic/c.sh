echo  ============================
echo  === [1] delete co_wrap
echo  ============================
rm co_wrap

echo 
echo  ============================
echo  === [2] compile co_wrap.c
echo  ============================

#########################################################################
# for HPi64
#########################################################################
# CCHOME=/opt/ansic/bin
# SHLIB_PATH=$HOME/lib
# $CCHOME/cc -o co_wrap co_wrap.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi
# $CCHOME/cc -o co_wrap co_wrap.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi
cc -o co_wrap co_wrap.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi

#########################################################################
# for AIX3
#########################################################################
# CCHOME=/usr/vac/bin
# LIBPATH=$HOME/lib
# $CCHOME/cc -o co_wrap co_wrap.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi
# $CCHOME/cc -o co_wrap co_wrap.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi -lpthread


#########################################################################
# for Sun2
#  1) static link
#     cc -o co_wrap co_wrap.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a
#########################################################################
# CCHOME=/export/home/OPT/SUNWspro/bin
# cc -o co_wrap co_wrap.c -m64 -L$HOME/lib -I$HOME/include -lCOencapi
# cc -o co_wrap co_wrap.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a



#########################################################################
# for Linux
#########################################################################
# CCHOME=/usr/bin
# $CCHOME/cc -m32 -o co_wrap co_wrap.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
# $CCHOME/cc -o co_wrap co_wrap.c -L$HOME/lib -I$HOME/include -lCOencapi -lm
# $CCHOME/cc -c co_wrap.c -L$HOME/lib32 -I$HOME/include 
