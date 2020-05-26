cmake_minimum_required(VERSION 3.1)

project(scan_matching VERSION 1.0)

set(CMAKE_MODULE_PATH /usr/local/Cellar/eigen/3.3.7/share/eigen3/cmake)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include ${EIGEN3_INCLUDE_DIRS})

add_library(scan_matching_libs src/csv_reader.cpp)

add_executable(01_eigen_tester apps/01_eigen_tester.cpp)

