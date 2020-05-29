rm -f *.dec co_bmt.lis co_bmt.c
proc iname=co_bmt include=/egs_app/cubejco/include include=$ORACLE_HOME/rdbms/public
if [ $? -eq 0 ]; then
	cc co_bmt.c -o co_bmt -I/egs_app/cubejco/include -L/egs_app/cubejco/lib -lCOencapi -L$ORACLE_HOME/lib -lclntsh -I$ORACLE_HOME/rdbms/public -I$ORACLE_HOME/precomp/public
fi
