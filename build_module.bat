:: del "module.dll"
cd ./build/Debug
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
cmake.exe --build . --config Debug --target all -- -j 6 || pause && exit
:: echo F | xcopy "module.dll" "../../module.dll" /y
cd ../..