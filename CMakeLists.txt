cmake_minimum_required(VERSION 3.30)
project(OpenGL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

file(COPY ${CMAKE_SOURCE_DIR}/res/shaders DESTINATION ${CMAKE_BINARY_DIR}/res)

add_executable(OpenGL src/main.cpp
        src/Renderer.cpp
        src/Renderer.h
        src/VertexBuffer.cpp
        src/VertexBuffer.h
        src/IndexBuffer.cpp
        src/IndexBuffer.h
)

target_include_directories(OpenGL PRIVATE dependencies)

target_link_libraries(OpenGL glfw GLEW::GLEW OpenGL::GL)