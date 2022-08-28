cmake_minimum_required(VERSION 3.23)
project(coffeeOS)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(TimHelp
        src/main.cpp
        src/coffeeOS.h
        src/coffeeOS.cpp
        src/my_config.h
        src/user.h
        src/user.cpp
        src/product.h
        src/product.cpp
        src/my_menu.h
        src/my_menu.cpp
        src/my_manager.h
        src/my_manager.cpp)
