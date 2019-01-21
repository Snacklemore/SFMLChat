cmake_minimum_required(VERSION 3.13)
project(SockRefac)

set(CMAKE_CXX_STANDARD 11)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(EXECUTABLE_NAME "SockR")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")
find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics network audio REQUIRED)


add_executable(${EXECUTABLE_NAME} main.cpp ClientObject.cpp ClientObject.h MessageObject.cpp MessageObject.h ClientClass.cpp ClientClass.h ServerClass.cpp ServerClass.h TextField.cpp TextField.h Cursor.cpp Cursor.h MessageWidget.cpp MessageWidget.h)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-system sfml-window sfml-audio sfml-network )