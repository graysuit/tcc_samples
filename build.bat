@ECHO OFF
setlocal enabledelayedexpansion
set "tcc=%CD%/tcc.exe"
cd samples
for %%f in (*.c) do (
  echo "name: %%~nf.c" 
  %tcc% -bench "%%~nf.c" 
)
