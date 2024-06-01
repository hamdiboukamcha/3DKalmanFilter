# 3D Kalman Filter

This repository contains a C++ implementation of a 3D Kalman Filter. The Kalman Filter is an algorithm used to estimate the state of a system from a series of noisy measurements. This implementation is self-contained, with matrix operations handled manually without relying on external libraries such as Eigen.

## Features

- State estimation for a 3D system
- Manual implementation of matrix operations
- Modular design with separate header and source files
- Simple and customizable

## Project Structure
<!-- Project Directory Structure -->
│
├── src
│ ├── main.cpp
│ ├── KalmanFilter3D.cpp
│ ├── KalmanFilter3D.h
│
├── CMakeLists.txt
└── README.md
<!-- End of Project Directory Structure -->


## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler (supporting C++11 or higher)

### Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/3D-Kalman-Filter.git
   cd 3D-Kalman-Filter
2. Create a build directory:
   mkdir build
  cd build
3. Run CMake to configure the project:
   cmake ..
4. Build the project:
   cmake --build .

## Code Overview
KalmanFilter3D Class
The KalmanFilter3D class encapsulates the state estimation logic. It includes methods for prediction and update steps, as well as utility functions for matrix operations.

predict(): Performs the prediction step, updating the state estimate and covariance matrix based on the process model.
update(const double z[3]): Performs the update step, incorporating a new measurement into the state estimate.
getState(double state[6]) const: Retrieves the current state estimate.
main.cpp
The main.cpp file demonstrates how to use the KalmanFilter3D class. It initializes the filter, performs a prediction-update cycle with a sample measurement, and prints the estimated state.

CMakeLists.txt
The CMakeLists.txt file defines the build configuration for the project. It specifies the project name, required C++ standard, source files, and include directories.

Contributing
Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
For any questions or inquiries, please contact us.

BY: HAMDI BOUKAMCHA





