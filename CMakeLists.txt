cmake_minimum_required(VERSION 3.10)

# Set the project name
project(KalmanFilter3D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_executable(KalmanFilter3D
    main.cpp
    src/KalmanFilter3D.cpp
)

# Include the header files
target_include_directories(KalmanFilter3D PRIVATE "${PROJECT_SOURCE_DIR}/src")
