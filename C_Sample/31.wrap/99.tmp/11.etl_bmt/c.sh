# rm
rm *.a *.so *.o dataStage

# compile ..
gcc -o co_etl.o -c co_etl.c -I$HOME/include -fPIC

# Make .a
#ar rs libCOetl.a co_etl.o

# Make .so
gcc -o libCOetl.so  co_etl.o -shared -I$HOME/include

# compile ..
gcc -o dataStage dataStage.c -L$HOME/lib -lCOencapi -L. -lCOetl
#gcc -o dataStage dataStage.c -L$HOME/lib -L. -lCOetl


