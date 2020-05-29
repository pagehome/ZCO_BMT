clear
rm *.o *.ar *.so
gcc -c fn.c 
ar rs libfn.a fn.o 
gcc -o main main.c libfn.a


