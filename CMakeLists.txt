cmake_minimum_required(VERSION 3.6)
project(k24_r)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/includes/bmp_edit.cpp src/header/bmp_edit.h src/includes/k24_r.cpp src/header/k24_r.h src/classes/color_handler.cpp src/classes/header/color_handler.h src/classes/color_corpus.cpp src/classes/header/color_corpus.h src/includes/pixel_operations.cpp src/header/pixel_operations.h src/classes/header/values.h)
add_executable(k24_r ${SOURCE_FILES})