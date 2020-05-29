# for HPi64
#SHLIB_PATH=$HOME/lib; export SHLIB_PATH

# for AIX3
#LIBPATH=$HOME/lib; export LIBPATH

# for Sun2
LD_LIBRARY_PATH=$HOME/lib; export LD_LIBRARY_PATH

# for Linux
LD_LIBRARY_PATH=$HOME/lib; export LD_LIBRARY_PATH


date
c=1

while [ ${c} -le 800 ]
do
	echo $c
	co_adv  
	((c = c + 1))
done

date

