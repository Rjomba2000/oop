@echo off
set PROGRAM="%~1"

rem Incorrect input type
%PROGRAM% aaa > %TEMP%\test01.txt
fc test01.txt %TEMP%\test01.txt
if ERRORLEVEL 1 goto err

rem Negative number
%PROGRAM% -12 > %TEMP%\test02.txt
fc test02.txt %TEMP%\test02.txt
if ERRORLEVEL 1 goto err

rem Number more than 255
%PROGRAM% 32535 > %TEMP%\test03.txt
fc test03.txt %TEMP%\test03.txt
if ERRORLEVEL 1 goto err

rem Min correct number
%PROGRAM% 0 > %TEMP%\test04.txt
if ERRORLEVEL 1 goto err
fc test04.txt %TEMP%\test04.txt
if ERRORLEVEL 1 goto err

rem Max correct number
%PROGRAM% 255 > %TEMP%\test05.txt
fc test05.txt %TEMP%\test05.txt
if ERRORLEVEL 1 goto err

rem Wrong number of arguments
%PROGRAM% 12 7 > %TEMP%\test06.txt
fc test06.txt %TEMP%\test06.txt
if ERRORLEVEL 1 goto err

rem Correct number
%PROGRAM% 6 > %TEMP%\test07.txt
fc test07.txt %TEMP%\test07.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1