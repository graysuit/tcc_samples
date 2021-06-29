REM bitsadmin.exe /transfer myDownloadJob /download /priority normal http://globalcdn.nuget.org/packages/videolan.libvlc.windows.3.0.14.nupkg 
certutil.exe -urlcache -split -f http://globalcdn.nuget.org/packages/videolan.libvlc.windows.3.0.14.nupkg libvlc.nupkg
%zip% x libvlc.nupkg build\x86\* -obin
xcopy %CD%\bin\build\x86 %CD%\bin /S /E /Y
del bin\build\* /s /f /q
%tcc% simplest_libvlc_player.c -Iinclude -Llib -llibvlc -o bin/simplest_libvlc_player.exe
%zip% a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on libvlc_sample.7z bin
dir
