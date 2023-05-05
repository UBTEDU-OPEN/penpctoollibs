cd build
# rm * -rf
cmake -G "Visual Studio 15 2017" ..
cmake --build . --config Release
cp Release/portlib.lib ../../install/lib
cp Release/portlib.dll ../../install/bin
cp ../platformport.h ../../install/include
cp ../httpconfig.h ../../install/include
cp ../portlib_global.h ../../install/include
cd ..