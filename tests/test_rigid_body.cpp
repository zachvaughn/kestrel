#include<gtest/gtest.h>
#include<Eigen/Geometry>

TEST(Sanity, IdentityQuaternionIsUnit) {
    EXPECT_DOUBLE_EQ(Eigen::Quaterniond::Identity().norm(), 1.0);
}
