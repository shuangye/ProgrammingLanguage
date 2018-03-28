REM WARNING: The following commands shall be ran in Command Prompty for Visual Studio.
@ECHO The following commands shall be ran in Command Prompty for Visual Studio.

REM To build an executable, linking to the dll:

cl.exe /D OSA_MODULE_NAME='"OSA"' /D OSA_EXPORTS /D_USRDLL /D_WINDLL /I ../include /I ../tests /I ../src ../src/*.c /LD /link /DLL /out:osa.dll

REM cl.exe /D OSA_MODULE_NAME='"OSA"' /I ../include /I ../include/sqlite3 /I ../tests /I ../src ../tests/main.c ../tests/TestDbm.c /link /LIBPATH:../project/Debug DbManager.lib

REM xcopy /Y ..\project\Debug\osa.dll .\