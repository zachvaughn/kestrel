#include<gtest/gtest.h>
#include<Eigen/Geometry>
#include "kestrel/rigid_body.hpp"

TEST(Sanity, IdentityQuaternionIsUnit) {
    EXPECT_DOUBLE_EQ(Eigen::Quaterniond::Identity().norm(), 1.0);
}

TEST(RigidBodyState, DefaultIsAtRest) {
    kestrel::RigidBodyState state;
    EXPECT_TRUE(state.position.isZero());
    EXPECT_TRUE(state.velocity.isZero());
    EXPECT_TRUE(state.angular_velocity.isZero());
    EXPECT_TRUE(state.attitude.isApprox(Eigen::Quaterniond::Identity()));
}

TEST(RigidBodyParams, DefaultValues) {
    kestrel::RigidBodyParams params;
    EXPECT_TRUE(params.inertia.isApprox(Eigen::Matrix3d::Identity()));
    EXPECT_DOUBLE_EQ(params.mass, 1.0);
}

TEST(RigidBodyDerivative, DefaultIsZero) {
    kestrel::RigidBodyDerivative derivative;
    EXPECT_TRUE(derivative.position_dot.isZero());
    EXPECT_TRUE(derivative.velocity_dot.isZero());
    EXPECT_TRUE(derivative.angular_velocity_dot.isZero());
    EXPECT_TRUE(derivative.attitude_dot.coeffs().isZero());
}

TEST(RigidBodyInputs, DefaultIsZero) {
    kestrel::RigidBodyInputs inputs;
    EXPECT_TRUE(inputs.force.isZero());
    EXPECT_TRUE(inputs.torque.isZero());
}

TEST(ComputeDerivative, PositionDotEqualsVelocity) {
    kestrel::RigidBodyState state;
    kestrel::RigidBodyParams params;
    kestrel::RigidBodyInputs inputs;

    state.velocity = Eigen::Vector3d(1, 2, 3);

    kestrel::RigidBodyDerivative derivative = kestrel::compute_derivative(state, params, inputs);

    EXPECT_TRUE(derivative.position_dot.isApprox(Eigen::Vector3d(1, 2, 3)));
}

TEST(ComputeDerivative, GravityAcceleratesDown) {
    kestrel::RigidBodyState state;
    kestrel::RigidBodyParams params;
    kestrel::RigidBodyInputs inputs;

    params.mass = 2.0;
    inputs.force = Eigen::Vector3d(0, 0, 2.0 * 9.81);

    kestrel::RigidBodyDerivative derivative = kestrel::compute_derivative(state, params, inputs);

    EXPECT_TRUE(derivative.velocity_dot.isApprox(Eigen::Vector3d(0, 0, 9.81)));
}