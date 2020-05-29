cls

echo off
::===================================================================
:: 64 bit                                       =====================
:: C:\Windows\System32                          =====================
::===================================================================
::set JAVAHOME=C:\Program Files\Java\jdk1.7.0_45\bin
::set CUBEHOME=C:\Program Files\eGlobal Systems\CubeOne Server\coapi


::===================================================================
:: 32 bit                                       =====================
:: C:\Windows\SysWOW64                          =====================
::===================================================================

set JAVAHOME="C:\Program Files (x86)\Java\jdk1.7.0_40\bin"
set CUBEHOME="C:\Program Files (x86)\eGlobal Systems\CubeOne Server\coapi"


echo on

%JAVAHOME%\java -classpath .;%CUBEHOME%\lib\CubeOneAPI.jar -Djava.library.path=%CUBEHOME%\lib co_prompt






