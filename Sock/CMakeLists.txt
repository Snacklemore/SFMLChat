cmake_minimum_required(VERSION 3.13)
project(Sock)

set(CMAKE_CXX_STANDARD 11)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(EXECUTABLE_NAME "Sock")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")
find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics network audio REQUIRED)
add_executable(Sock main.cpp )
target_link_libraries(${EXECUTABLE_NAME}  sfml-system sfml-window sfml-graphics sfml-audio sfml-network )