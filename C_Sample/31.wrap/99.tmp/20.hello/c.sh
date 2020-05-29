clear
gcc -c co_etl.c -I$HOME/include
ar rs libCOetl.a co_etl.o 
gcc -o dataStage dataStage.c -L$HOME/lib -lCOencapi -L. -lCOetl


