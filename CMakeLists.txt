cmake_minimum_required(VERSION 3.19)
project(ppm_editor)

set(CMAKE_CXX_STANDARD 14)

set(PPM
        file_exception.h
        ppm_loader.h ppm_loader.cpp)

add_executable(ppm_editor
        main.cpp
        ${PPM}
        canvas.h canvas.cpp
        rgb_color.h
        )
