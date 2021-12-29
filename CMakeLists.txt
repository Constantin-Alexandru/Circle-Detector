cmake_minimum_required(VERSION 3.21.4)

#Project Name
project(cdetect)

#Getting every file from source
file(GLOB cdetect_SRC CMAKE_CONFIGURE_DEPENDS ./src/include/*.h ./src/*.cpp)

#Setting program to C++20
set(CMAKE_CXX_STANDARD 20)

#Including OpenCV
find_package(OpenCV COMPONENTS core imgproc highgui REQUIRED)

#Including OpenCV Include Dirs
include_directories(${OpenCV_INCLUDE_DIRS})

#Setting build type to release
set(CMAKE_BUILD_TYPE Release)

#Adding executable
add_executable(${PROJECT_NAME} ${cdetect_SRC})

#Linking OpenCV Libs
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})