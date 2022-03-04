cmake_minimum_required(VERSION 3.0.0)
project(
    TML
    VERSION      0.0.1
    DESCRIPTION  "I can't count so I create a library to do it for me"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(src/TML)

add_executable(
    tml_test
    src/main.cpp
)

# target_link_libraries(tml_test tml)
