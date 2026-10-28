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
} // namespace kestrel