set JAVAHOME="C:\Program Files\Java\jdk1.7.0_45\bin"

rem %JAVAHOME%\java -classpath .;..\..\lib\CubeOneAPI.jar -Djava.library.path=..\..\lib ThreadMain

%JAVAHOME%\java -classpath . -Djava.library.path=..\..\lib ThreadMain
