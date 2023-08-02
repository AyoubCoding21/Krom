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
if [ -f ./lexer ]
then
    echo -e "\e[1;32m${bold}Built succesfully.\e[0m"
    chmod u+w+x ./lexer && ./lexer
else
    echo -e "\e[1;31m${bold}Errors occured, See output above !!\e[0m";
fi
