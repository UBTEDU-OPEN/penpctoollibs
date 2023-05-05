cd build
# rm * -rf
cmake -G "Visual Studio 15 2017" ..
cmake --build . --config Release
cp Release/handwrittenwrapper.lib ../../install/lib
cp Release/handwrittenwrapper.dll ../../install/bin
cp ../handwrittenwrapper.h ../../install/include
cp ../handwrittenwrapper_global.h ../../install/include
cd ..