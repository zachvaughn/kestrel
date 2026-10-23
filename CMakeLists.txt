cmake_minimum_required(VERSION 3.25)
project(kestrel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_Declare(Eigen
        URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        SYSTEM
)
FetchContent_MakeAvailable(Eigen)

add_library(kestrel_core src/rigid_body.cpp)
target_include_directories(kestrel_core PUBLIC include)
target_link_libraries(kestrel_core PUBLIC Eigen3::Eigen)

add_executable(kestrel src/main.cpp)

target_link_libraries(kestrel PRIVATE kestrel_core)