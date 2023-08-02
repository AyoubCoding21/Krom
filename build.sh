if [ -d build ]
then
    cd build
else
    mkdir build && cd build
fi
if [ -d CMakeFiles/ ]
then
    rm CMakeFiles/ -rf cmake_install.cmake Makefile lexer
fi
cmake .. && make

