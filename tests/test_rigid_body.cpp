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