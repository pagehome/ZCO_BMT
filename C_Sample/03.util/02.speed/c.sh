osname=`uname`
echo '[INFOR] OS Version = '`uname -a`
echo '[INFOR] Login User = '`whoami`

echo  ============================
echo  === [1] delete co_speed
echo  ============================
rm co_speed

echo 
echo  ============================
echo  === [2] compile co_speed.c
echo  ============================

case "$osname" in
'HP-UX')
    echo "HP-UX compile : start ..."	

	CCHOME=/opt/ansic/bin
	# SHLIB_PATH=$HOME/lib

	# $CCHOME/cc -o co_speed co_speed.c -DHPUX +DD32 -DBIT32 -I$HOME/include -L$HOME/lib -lCOencapi
	$CCHOME/cc -o co_speed co_speed.c -DHPUX +DD64 -DBIT64 -I$HOME/include -L$HOME/lib -lCOencapi

    ;;

'AIX')
	echo "AIX compile : start ..."	

	CCHOME=/usr/vac/bin
	LIBPATH=$HOME/lib

	$CCHOME/cc -o co_speed co_speed.c -brtl -q64 -L$HOME/lib -I$HOME/include -lCOencapi 
	#$CCHOME/cc -o co_speed co_speed.c -brtl -q32 -L$HOME/lib -I$HOME/include -lCOencapi

    ;;

'SunOS')
	echo "SunOS compile : start ..."	

	#  1) static link
	#     cc -o co_speed co_speed.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a

	CCHOME=/export/home/OPT/SUNWspro/bin

	cc -o co_speed co_speed.c -lnsl -lrt -lsocket -m64 -I$HOME/include /data/cubeapi/lib/libCOencapi.a
	#cc -o co_speed co_speed.c -m64 -L$HOME/lib -I$HOME/include -lCOencwrap

    ;;

'Linux')
	echo "Linux compile : start ..."	

	CCHOME=/usr/bin

	$CCHOME/cc -o co_speed co_speed.c -L$HOME/lib -I$HOME/include  -lCOencapi
	# $CCHOME/cc -m32 -o co_speed co_speed.c -L$HOME/lib32 -I$HOME/include -lCOencapi -lm
	# $CCHOME/cc -c co_speed.c -L$HOME/lib32 -I$HOME/include 

    ;;

*)

	echo "Compile failed !! Check OS name !!"	

esac

