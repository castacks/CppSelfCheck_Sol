cmake_minimum_required(VERSION 3.20)
project(CppSelfCheck)

set(CMAKE_CXX_STANDARD 17)

# Global packages.
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

# Sub-projects.
add_subdirectory(ConcreteLibrary)
add_subdirectory(HeaderOnlyLibrary)

# Main executable.
set(EXE_MAIN ${PROJECT_NAME}_exe)
add_executable(${EXE_MAIN} process_image.cpp main.cpp)
target_link_libraries(${EXE_MAIN}
        Eigen3::Eigen
        ${OpenCV_LIBRARIES}
        concrete
        headeronly)
