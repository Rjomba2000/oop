@echo off

REM Ioou e oanoe?oaiie i?ia?aiia ia?aaa?ony ?a?ac 1-e a?aoiaio eiiaiaiie no?iee
SET MyProgram="%~1"

REM Caueoa io caionea aac a?aoiaioa, caaa?uaai ionou e i?ia?aiia
if %MyProgram%=="" (
	echo Please specify file path to the program
)

REM Aeie n oanoaie
REM Copy empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" || goto err
echo Test 1 passed

REM Copy non empty file
%MyProgram% NonEmpty.txt "%TEMP%\output.txt" || goto err
fc NonEmpty.txt "%TEMP%\output.txt" || goto err
echo Test 2 passed

REM Copy missing file should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
fc NonEmpty.txt "%TEMP%\output.txt" || goto err
echo Test 3 passed

REM If output file is not specified, program must fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM If input and output file are not specified, program must fail 
%MyProgram% && goto err
echo Test 5 passed

REM Oanou i?ioee oniaoii
echo All tests passed successfuly
exit /B 0

REM N?aa iiiaaaai a neo?aa ioeaee
:err
echo Test failed
exit /B 1