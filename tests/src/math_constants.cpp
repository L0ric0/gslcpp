// gslcpp
#include "gslcpp/math.hpp"

// gtest
#include <gtest/gtest.h>

TEST(Constants, e)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::e, M_E);
}

TEST(Constants, log2e)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::log2e, M_LOG2E);
}

TEST(Constants, log10e)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::log10e, M_LOG10E);
}

TEST(Constants, sqrt2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::sqrt2, M_SQRT2);
}

TEST(Constants, sqrt1_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::sqrt1_2, M_SQRT1_2);
}

TEST(Constants, sqrt3)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::sqrt3, M_SQRT3);
}

TEST(Constants, pi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi, M_PI);
}

TEST(Constants, pi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi_2, M_PI_2);
}

TEST(Constants, pi_4)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi_4, M_PI_4);
}

TEST(Constants, sqrtpi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::sqrtpi, M_SQRTPI);
}

TEST(Constants, inv_sqrtpi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_sqrtpi_2, M_2_SQRTPI);
}

TEST(Constants, inv_pi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_pi, M_1_PI);
}

TEST(Constants, inv_pi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_pi_2, M_2_PI);
}

TEST(Constants, ln10)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::ln10, M_LN10);
}

TEST(Constants, ln2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::ln2, M_LN2);
}

TEST(Constants, lnpi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::lnpi, M_LNPI);
}

TEST(Constants, euler)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::euler, M_EULER);
}
