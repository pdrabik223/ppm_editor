cmake_minimum_required(VERSION 3.19)
project(ppm_editor)

set(CMAKE_CXX_STANDARD 14)

set(PPM
        file_exception.h
        ppm_loader.h ppm_loader.cpp)

SET(SCML
        simple_console_media_layer.h simple_console_media_layer.cpp
        button.h button.cpp
        text_field.h text_field.cpp)
set(CONSOLE_UI
        console_ui.h console_ui.cpp
        ${SCML})


add_executable(ppm_editor
        main.cpp
        ${PPM}
        ${CONSOLE_UI}
        canvas.h canvas.cpp
        rgb_color.h
        )
