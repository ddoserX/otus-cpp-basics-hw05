cmake_minimum_required(VERSION 3.25)

project(hw05 VERSION 1.0 LANGUAGES CXX)

set(SRC_MAIN
    main.cpp
)

set(SRC_ADDIT
    statistics.cpp
)

add_executable(hw05 
    ${SRC_ADDIT}
    ${SRC_MAIN}
)

target_compile_features(hw05 PUBLIC 
    cxx_std_17
)

target_compile_options(hw05 PUBLIC
    -Wall
    -Wextra
    -Werror
    -pedantic
)