
cd build
# rm * -rf
cmake -G "Visual Studio 15 2017" ..
cmake --build . --config Release
cp Release/evaluationwrapper.lib ../../install/lib
cp Release/evaluationwrapper.dll ../../install/bin
cp ../charevaluationwrapper.h ../../install/include
cp ../evaluationserializer.h ../../install/include
cp ../evaluationwrapper_global.h ../../install/include
cd ..