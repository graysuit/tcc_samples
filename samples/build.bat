for %%f in (*.c) do (
  echo "name: %%~nf.c" 
  %tcc% -bench "%%~nf.c" 
)

set "rootdir=%CD%"
cd video/libvlc & compile.bat & cd %rootdir%
