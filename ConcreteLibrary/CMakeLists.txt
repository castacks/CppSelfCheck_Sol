cmake_minimum_required(VERSION 3.20)
project(ConcreteLibrary)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(Eigen3 REQUIRED NO_MODULE)

set(LIB_NAME concrete)

add_library(${LIB_NAME} SHARED src/ConcreteLibrary.cpp)
target_include_directories(${LIB_NAME} PUBLIC $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>)
target_link_libraries(${LIB_NAME} PRIVATE Eigen3::Eigen)