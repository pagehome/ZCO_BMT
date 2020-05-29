clear
rm *.o *.ar *.so
gcc -c fn.c -fPIC
gcc -o libCOencapi.so fn.o -shared 
gcc -o main main.c -L. -lCOencapi


