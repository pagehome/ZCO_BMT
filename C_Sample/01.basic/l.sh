clear

# for HPi64
#SHLIB_PATH=$HOME/lib; export SHLIB_PATH

# for AIX3
LIBPATH=$HOME/lib; export LIBPATH

# for Sun2
LD_LIBRARY_PATH=$HOME/lib; export LD_LIBRARY_PATH

# for Linux
#LD_LIBRARY_PATH=$HOME/lib; export LD_LIBRARY_PATH

#strace -s 132 -e open,write,shmget,shmat  ./co_bmt AES


for i in {1..1000000}
do
	./co_bmt &
done




