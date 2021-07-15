cmake_minimum_required(VERSION 3.19)
project(ppm_editor)

set(CMAKE_CXX_STANDARD 14)

set(PPM
        ppm/file_exception.h
        ppm/ppm_loader.h ppm/ppm_loader.cpp
        ppm/rgb_color.h)

SET(SCML
        scml/simple_console_media_layer.h scml/simple_console_media_layer.cpp
        scml/button.h scml/button.cpp
        scml/text_field.h scml/text_field.cpp)

set(CONSOLE_UI
        console_ui.h console_ui.cpp
        ${SCML})


add_executable(ppm_editor
        main.cpp
        ${PPM}
        ${CONSOLE_UI}
        canvas.h canvas.cpp)
