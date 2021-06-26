set "tcc=%CD%\tcc.exe"
cd samples
%tcc% -run native_winform.c
%tcc% -run console_sum.c 2 2
pause
