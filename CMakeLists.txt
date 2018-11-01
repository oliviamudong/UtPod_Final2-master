cmake_minimum_required(VERSION 3.12)
project(UtPod_Final2_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UtPod_Final2_master
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/UtPod_Final.cbp
        cmake-build-debug/UtPod_Final.exe
        CMakeLists.txt
        main.cpp
        Song.cpp
        Song.h
        UtPod.cpp
        UtPod.h)
