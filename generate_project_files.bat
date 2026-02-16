@echo off
call ThirdParty\premake5.exe --file=ember.build.lua vs2022
REM If the output code is not 0, there is probably an error
IF %ERRORLEVEL% NEQ 0 PAUSE