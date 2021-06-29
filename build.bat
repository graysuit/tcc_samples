@ECHO OFF
setlocal enabledelayedexpansion
set "tcc=%CD%/tcc.exe"
set "7z=%CD%/7z.exe"
cd samples
build.bat 
