#include <iostream>
#include <cstdlib>
#include <ctime>
#include "KalmanFilter3D.h"

// Function to generate random noise
double generateNoise(double stddev) {
    double u = ((double)rand() / (RAND_MAX)) * 2 - 1;
    double v = ((double)rand() / (RAND_MAX)) * 2 - 1;
    double w = ((double)rand() / (RAND_MAX));
    double c = std::sqrt(-2 * std::log(w)) / std::sqrt(u * u + v * v);
    return stddev * u * c;
}

// Function to simulate the true position of the ball
void simulateTruePosition(double& x, double& y, double& z, double vx, double vy, double vz, double dt) {
    x += vx * dt;
    y += vy * dt;
    z += vz * dt;
}

// Function to simulate noisy measurements
void simulateMeasurement(double& x, double& y, double& z, double stddev) {
    x += generateNoise(stddev);
    y += generateNoise(stddev);
    z += generateNoise(stddev);
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Time step
    double dt = 0.1;

    // Process noise standard deviation
    double process_noise_std = 0.1;

    // Measurement noise standard deviation
    double measurement_noise_std = 0.5;

    // Initialize the Kalman filter
    KalmanFilter3D kf(dt, process_noise_std, measurement_noise_std);

    // Initial true position and velocity of the ball
    double true_x = 0, true_y = 0, true_z = 0;
    double true_vx = 1, true_vy = 0.5, true_vz = 0.2;

    // Simulate and track the ball for 100 time steps
    for (int i = 0; i < 100; ++i) {
        // Simulate the true position of the ball
        simulateTruePosition(true_x, true_y, true_z, true_vx, true_vy, true_vz, dt);

        // Simulate noisy measurements
        double measured_x = true_x;
        double measured_y = true_y;
        double measured_z = true_z;
        simulateMeasurement(measured_x, measured_y, measured_z, measurement_noise_std);

        // Predict the position using the Kalman filter
        kf.predict();

        // Update the Kalman filter with the measured position
        double z[3] = { measured_x, measured_y, measured_z };
        kf.update(z);

        // Get the estimated position from the Kalman filter
        double estimated_state[6];
        kf.getState(estimated_state);

        // Print the true position, measured position, and estimated position
        std::cout << "Time step " << i << ":\n";
        std::cout << "True position: (" << true_x << ", " << true_y << ", " << true_z << ")\n";
        std::cout << "Measured position: (" << measured_x << ", " << measured_y << ", " << measured_z << ")\n";
        std::cout << "Estimated position: (" << estimated_state[0] << ", " << estimated_state[1] << ", " << estimated_state[2] << ")\n";
        std::cout << "----------\n";
    }

    return 0;
}