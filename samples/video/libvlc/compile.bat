bitsadmin.exe /transfer myDownloadJob /download /priority normal http://globalcdn.nuget.org/packages/videolan.libvlc.windows.3.0.14.nupkg libvlc.nupkg
%7z% x libvlc.nupkg build\x86\* -obin
xcopy %CD%\bin\build\x86 %CD%\bin /S /E /Y
del bin\build\* /s /f /q
%tcc% simplest_libvlc_player.c -Iinclude -Llib -llibvlc -o bin/simplest_libvlc_player.exe
7z a -t7z -mx=9 -mfb=273 -ms -md=31 -myx=9 -mtm=- -mmt -mmtf -md=1536m -mmf=bt3 -mmc=10000 -mpb=0 -mlc=0 libvlc_sample.7z bin
