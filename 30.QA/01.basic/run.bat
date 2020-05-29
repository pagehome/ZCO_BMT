set JAVAHOME="C:\Program Files\Java\jdk1.7.0_45\bin"
set LIBPATH="C:\Program Files\eGlobal Systems\CubeOne Server\coapi\lib"


REM gaTest
%JAVAHOME%\java  -classpath .;%LIBPATH%\CubeOneAPI.jar -Djava.library.path=%LIBPATH% gaTest > gaTest.out

REM encValOut
%JAVAHOME%\java  -classpath .;%LIBPATH%\CubeOneAPI.jar -Djava.library.path=%LIBPATH% encValOut > encVal.out
