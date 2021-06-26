set "tcc=%CD%\tcc.exe"
cd samples
%tcc% native_winform.c
%tcc% console_sum.c
%tcc% dll.c -shared
