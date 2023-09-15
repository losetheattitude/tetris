
cmake_minimum_required(VERSION 3.0.0)
project(tetris-c++ VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB tetris-c++_SRC
    "src/*.cpp"
    "src/scenes/*.cpp"
    "src/components/*.cpp"
    "src/levels/*.cpp"
    "src/util/*.cpp"
)

add_executable(tetris-c++ 
main.cpp
${tetris-c++_SRC}
)

target_link_libraries(tetris-c++ 
/usr/local/lib/libraylib.so
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
