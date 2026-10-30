#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>

namespace kestrel {
    struct RigidBodyState {
        Eigen::Vector3d position = Eigen::Vector3d::Zero(); // position, world NED, in meters
        Eigen::Vector3d velocity = Eigen::Vector3d::Zero(); // velocity, world NED, in m/s
        Eigen::Quaterniond attitude = Eigen::Quaterniond::Identity(); // attitude, body -> world
        Eigen::Vector3d angular_velocity = Eigen::Vector3d::Zero(); // angular velocity, body frame, in rad/s
    };

    struct RigidBodyParams {
        double mass = 1.0; // mass in kg
        Eigen::Matrix3d inertia = Eigen::Matrix3d::Identity(); // inertia tensor, body frame, in kg * m^2
    };

    struct RigidBodyInputs {
        Eigen::Vector3d force = Eigen::Vector3d::Zero(); // total force, world frame, in N
        Eigen::Vector3d torque = Eigen::Vector3d::Zero(); // total torque, body frame in N*m
    };

    struct RigidBodyDerivative {
        Eigen::Vector3d position_dot = Eigen::Vector3d::Zero(); // equals velocity in m/s
        Eigen::Vector3d velocity_dot = Eigen::Vector3d::Zero(); // acceleration, world frame, in m/s^2
        Eigen::Quaterniond attitude_dot = Eigen::Quaterniond(0, 0, 0, 0); // quaternion rate, raw coeffs, not a unit quaternion
        Eigen::Vector3d angular_velocity_dot = Eigen::Vector3d::Zero(); // angular acceleration, body frame, in rad/s^2
    };
} // namespace kestrel