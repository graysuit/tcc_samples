@ECHO OFF
setlocal enabledelayedexpansion
set "tcc=%CD%/tcc.exe"
set "zip=%CD%/7z.exe"
cd samples
build.bat 
