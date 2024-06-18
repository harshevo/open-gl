cmake_minimum_required(VERSION 3.5.0)
project(openglapp VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(my_opengl_project 
    src/main.cpp
)

target_link_libraries(my_opengl_project 
    glfw
    OpenGL::GL
    GLEW
)
