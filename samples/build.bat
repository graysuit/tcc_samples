for %%f in (*.c) do (
  echo "name: %%~nf.c" 
  %tcc% -bench "%%~nf.c" 
)

set "rootdir=%CD%"
cd video/libvlc video & compile.bat & cd %rootdir%
