@ECHO OFF
setlocal enabledelayedexpansion
for %%f in (samples\*.c) do (
  echo "name: %%~nf"
  %tcc% "%%f" 
)
