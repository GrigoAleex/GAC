cmake_minimum_required(VERSION 3.28)
project(vectors)

set(CMAKE_CXX_STANDARD 17)

add_executable(vectors main.cpp
        vec2.cpp
        vec2.h
        vec3.cpp
        vec3.h
        vec4.cpp
        vec4.h
        mat3.cpp
        mat3.h
        mat4.cpp
        mat4.h
        testMatrix.cpp
        testMatrix.h)
