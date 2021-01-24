cmake_minimum_required(VERSION 3.12)
project(tensorlib C)

set(CMAKE_C_STANDARD 99)

add_executable(tensorlib src/main.c src/inpt.c src/inpt.h src/term.c src/term.h src/tensor.c src/tensor.h src/helper.c src/helper.h src/constants.h src/elt.c src/elt.h src/point.c src/point.h src/manifold.c src/manifold.h src/tensorfield.c src/tensorfield.h src/curve.c src/curve.h src/sphere.h src/sphere.c
        src/euclidean.c src/euclidean.h)