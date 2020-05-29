clear
rm *.o *.ar *.so
gcc -c fn.c -fPIC
gcc -o libfn.so fn.o -shared 
gcc -o main main.c -L. -lfn


