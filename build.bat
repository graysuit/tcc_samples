set "tcc=%CD%\tcc.exe"
cd samples
%tcc% native_winform.c
%tcc% sum.c
%tcc% dll.c -shared
pause