@echo off

copy "Leap".dll C:\Windows\SysWOW64\"Leap".dll
echo "Leap.dll as been moved succesfuly !"

copy "SDL2".dll C:\Windows\SysWOW64\"SDL2".dll
echo "SDL2.dll as been moved succesfuly !"

copy "SDL2_image".dll C:\Windows\SysWOW64\"SDL2_image".dll
echo "SDL2_image.dll as been moved succesfuly !"

C:\Windows\SysWow64\regsvr32 "Leap".dll
C:\Windows\SysWow64\regsvr32 "SDL2".dll
C:\Windows\SysWow64\regsvr32 "SDL2_image".dll
pause