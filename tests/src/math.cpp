#include "util.hpp"

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

TEST(MathConstants, pi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi, M_PI);
}

TEST(MathConstants, pi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi_2, M_PI_2);
}

TEST(MathConstants, pi_4)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::pi_4, M_PI_4);
}

TEST(MathConstants, sqrtpi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::sqrtpi, M_SQRTPI);
}

TEST(MathConstants, inv_sqrtpi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_sqrtpi_2, M_2_SQRTPI);
}

TEST(MathConstants, inv_pi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_pi, M_1_PI);
}

TEST(MathConstants, inv_pi_2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::inv_pi_2, M_2_PI);
}

TEST(MathConstants, ln10)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::ln10, M_LN10);
}

TEST(MathConstants, ln2)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::ln2, M_LN2);
}

TEST(MathConstants, lnpi)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::lnpi, M_LNPI);
}

TEST(MathConstants, euler)
{
    ASSERT_DOUBLE_EQ(gslcpp::math::constants::euler, M_EULER);
}

TEST(ElementaryFunctions, expm1)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::expm1(0));
    ASSERT_DOUBLE_EQ(1.000000000050000000002e-10, gslcpp::math::expm1(1e-10));
    ASSERT_DOUBLE_EQ(-9.999999999500000000017e-11, gslcpp::math::expm1(-1e-10));
    ASSERT_DOUBLE_EQ(0.1051709180756476248117078264902, gslcpp::math::expm1(0.1));
    ASSERT_DOUBLE_EQ(-0.09516258196404042683575094055356, gslcpp::math::expm1(-0.1));
    ASSERT_DOUBLE_EQ(22025.465794806716516957900645284, gslcpp::math::expm1(10));
    ASSERT_DOUBLE_EQ(-0.99995460007023751514846440848444, gslcpp::math::expm1(-10));
}

TEST(ElementaryFunctions, log1p)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::log1p(0));
    ASSERT_DOUBLE_EQ(9.9999999995000000000333333333308e-11, gslcpp::math::log1p(1e-10));
    ASSERT_DOUBLE_EQ(0.095310179804324860043952123280765, gslcpp::math::log1p(0.1));
    ASSERT_DOUBLE_EQ(2.3978952727983705440619435779651, gslcpp::math::log1p(10.0));
}

TEST(ElementaryFunctions, hypot2)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::hypot(0.0, 0.0));
    ASSERT_DOUBLE_EQ(1.414213562373095048801688e-10, gslcpp::math::hypot(1e-10, 1e-10));
    ASSERT_DOUBLE_EQ(1.414213562373095048801688e-38, gslcpp::math::hypot(1e-38, 1e-38));
    ASSERT_DOUBLE_EQ(1.000000000000000000005, gslcpp::math::hypot(1e-10, -1.0));
    ASSERT_DOUBLE_EQ(1.000000000000000000005, gslcpp::math::hypot(-1.0, 1e-10));
    ASSERT_DOUBLE_EQ(1.000000000000499999999999e307, gslcpp::math::hypot(1e307, 1e301));
    ASSERT_DOUBLE_EQ(1.000000000000499999999999e307, gslcpp::math::hypot(1e301, 1e307));
    ASSERT_DOUBLE_EQ(1.414213562373095048801688e307, gslcpp::math::hypot(1e307, 1e307));
}

TEST(ElementaryFunctions, hypot2_inf_finite)
{
    double inf = std::numeric_limits<double>::infinity();

    ASSERT_TRUE(isposinf(gslcpp::math::hypot(inf, 1.2)));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(-inf, 1.2)));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(1.2, inf)));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(1.2, -inf)));
}

TEST(ElementaryFunctions, hypot2_nan_finite)
{
    ASSERT_TRUE(std::isnan(gslcpp::math::hypot(std::nan(""), 1.2)));
    ASSERT_TRUE(std::isnan(gslcpp::math::hypot(1.2, std::nan(""))));
}

TEST(ElementaryFunctions, hypot2_nan_nan)
{
    ASSERT_TRUE(std::isnan(gslcpp::math::hypot(std::nan(""), std::nan(""))));
}

TEST(ElementaryFunctions, hypot2_nan_inf)
{
    double y;
    double inf = std::numeric_limits<double>::infinity();

    ASSERT_TRUE(isposinf(gslcpp::math::hypot(inf, std::nan(""))));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(-inf, std::nan(""))));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(std::nan(""), inf)));
    ASSERT_TRUE(isposinf(gslcpp::math::hypot(std::nan(""), -inf)));
}

TEST(ElementaryFunctions, hypot3)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::hypot(0.0, 0.0, 0.0));
    ASSERT_DOUBLE_EQ(1.732050807568877293527446e-10, gslcpp::math::hypot(1e-10, 1e-10, 1e-10));
    ASSERT_DOUBLE_EQ(1.732050807568877293527446e-38, gslcpp::math::hypot(1e-38, 1e-38, 1e-38));
    ASSERT_DOUBLE_EQ(1.000000000000000000099, gslcpp::math::hypot(1e-10, 1e-10, -1.0));
    ASSERT_DOUBLE_EQ(1.000000000000000000099, gslcpp::math::hypot(1e-10, -1.0, 1e-10));
    ASSERT_DOUBLE_EQ(1.000000000000000000099, gslcpp::math::hypot(-1.0, 1e-10, 1e-10));
    ASSERT_DOUBLE_EQ(1.0000000000009999999999995e307, gslcpp::math::hypot(1e307, 1e301, 1e301));
    ASSERT_DOUBLE_EQ(1.732050807568877293527446e307, gslcpp::math::hypot(1e307, 1e307, 1e307));
    ASSERT_DOUBLE_EQ(1.0e307, gslcpp::math::hypot(1e307, 1e-307, 1e-307));
}

TEST(ElementaryFunctions, acosh)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::acosh(1.0));
    ASSERT_DOUBLE_EQ(4.435682543851151891329110663525e-1, gslcpp::math::acosh(1.1));
    ASSERT_DOUBLE_EQ(2.9932228461263808979126677137742e0, gslcpp::math::acosh(10.0));
    ASSERT_DOUBLE_EQ(2.3718998110500402149594646668302e1, gslcpp::math::acosh(1e10));
}

TEST(ElementaryFunctions, asinh)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::asinh(0.0));
    ASSERT_DOUBLE_EQ(9.9999999999999999999833333333346e-11, gslcpp::math::asinh(1e-10));
    ASSERT_DOUBLE_EQ(-9.9999999999999999999833333333346e-11, gslcpp::math::asinh(-1e-10));
    ASSERT_DOUBLE_EQ(9.983407889920756332730312470477e-2, gslcpp::math::asinh(0.1));
    ASSERT_DOUBLE_EQ(-9.983407889920756332730312470477e-2, gslcpp::math::asinh(-0.1));
    ASSERT_DOUBLE_EQ(8.8137358701954302523260932497979e-1, gslcpp::math::asinh(1.0));
    ASSERT_DOUBLE_EQ(-8.8137358701954302523260932497979e-1, gslcpp::math::asinh(-1.0));
    ASSERT_DOUBLE_EQ(2.9982229502979697388465955375965e0, gslcpp::math::asinh(10.0));
    ASSERT_DOUBLE_EQ(-2.9982229502979697388465955375965e0, gslcpp::math::asinh(-10.0));
    ASSERT_DOUBLE_EQ(2.3718998110500402149599646668302e1, gslcpp::math::asinh(1e10));
    ASSERT_DOUBLE_EQ(-2.3718998110500402149599646668302e1, gslcpp::math::asinh(-1e10));
}

TEST(ElementaryFunctions, atanh)
{
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::atanh(0.0));
    ASSERT_DOUBLE_EQ(1e-20, gslcpp::math::atanh(1e-20));
    ASSERT_DOUBLE_EQ(-1e-20, gslcpp::math::atanh(-1e-20));
    ASSERT_DOUBLE_EQ(1.0033534773107558063572655206004e-1, gslcpp::math::atanh(0.1));
    ASSERT_DOUBLE_EQ(-1.0033534773107558063572655206004e-1, gslcpp::math::atanh(-0.1));
    ASSERT_DOUBLE_EQ(1.4722194895832202300045137159439e0, gslcpp::math::atanh(0.9));
    ASSERT_DOUBLE_EQ(-1.4722194895832202300045137159439e0, gslcpp::math::atanh(-0.9));
}

TEST(ElementaryFunctions, ldexp)
{
    ASSERT_DOUBLE_EQ(
        gslcpp::math::constants::pi_4,
        gslcpp::math::ldexp(gslcpp::math::constants::pi, -2));
    ASSERT_DOUBLE_EQ(4.000000, gslcpp::math::ldexp(1.0, 2));
    ASSERT_DOUBLE_EQ(0.0, gslcpp::math::ldexp(0.0, 2));
    ASSERT_DOUBLE_EQ(
        std::numeric_limits<double>::max(),
        gslcpp::math::ldexp(9.999999999999998890e-01, 1024));
    ASSERT_DOUBLE_EQ(8.7098098162172166755761e-295, gslcpp::math::ldexp(1e308, -2000));
    ASSERT_DOUBLE_EQ(
        2.554675596204441378334779940e294,
        gslcpp::math::ldexp(std::numeric_limits<double>::min(), 2000));
}

TEST(ElementaryFunctions, ldexp_subnormals)
{
    for (auto [x, i] = std::tuple { std::numeric_limits<double>::min() / 2, int(1) }; x > 0;
         x /= 2, i++) {
        ASSERT_DOUBLE_EQ(2.554675596204441378334779940e294, gslcpp::math::ldexp(x, 2000 + i))
            << x << " " << i;
    }
}

TEST(ElementaryFunctions, frexp)
{
    int e;

    ASSERT_DOUBLE_EQ(0, gslcpp::math::frexp(0.0, &e));
    ASSERT_EQ(0, e);

    ASSERT_DOUBLE_EQ(
        gslcpp::math::constants::pi_4,
        gslcpp::math::frexp(gslcpp::math::constants::pi, &e));
    ASSERT_EQ(2, e);

    ASSERT_DOUBLE_EQ(0.5, gslcpp::math::frexp(2.0, &e));
    ASSERT_EQ(2, e);

    ASSERT_DOUBLE_EQ(0.5, gslcpp::math::frexp(1.0 / 4.0, &e));
    ASSERT_EQ(-1, e);

    ASSERT_DOUBLE_EQ(
        0.999999999999996447,
        gslcpp::math::frexp(1.0 / 4.0 - 4.0 * std::numeric_limits<double>::epsilon(), &e));
    ASSERT_EQ(-2, e);

    ASSERT_DOUBLE_EQ(
        9.999999999999998890e-01,
        gslcpp::math::frexp(std::numeric_limits<double>::max(), &e));
    ASSERT_EQ(1024, e);

    ASSERT_DOUBLE_EQ(
        -9.999999999999998890e-01,
        gslcpp::math::frexp(-std::numeric_limits<double>::max(), &e));
    ASSERT_EQ(1024, e);

    ASSERT_DOUBLE_EQ(0.5, gslcpp::math::frexp(std::numeric_limits<double>::min(), &e));
    ASSERT_EQ(-1021, e);

    ASSERT_DOUBLE_EQ(-0.5, gslcpp::math::frexp(-std::numeric_limits<double>::min(), &e));
    ASSERT_EQ(-1021, e);
}

TEST(ElementaryFunctions, frexp_subnormals)
{
    int e;
    for (auto [x, i, exp] = std::tuple { std::numeric_limits<double>::min() / 2, 1, -1022 }; x > 0;
         x /= 2, i++, exp--) {
        ASSERT_DOUBLE_EQ(0.5, gslcpp::math::frexp(x, &e));
        ASSERT_EQ(exp, e);
    }
}

TEST(Numbers, isinf)
{
    double inf = std::numeric_limits<double>::infinity();
    double nan = std::numeric_limits<double>::quiet_NaN();

    ASSERT_EQ(0, gslcpp::math::isinf(0));
    ASSERT_EQ(0, gslcpp::math::isinf(1));
    ASSERT_EQ(1, gslcpp::math::isinf(inf));
    ASSERT_EQ(-1, gslcpp::math::isinf(-inf));
    ASSERT_EQ(0, gslcpp::math::isinf(nan));
}

TEST(Numbers, isnan)
{
    double inf = std::numeric_limits<double>::infinity();
    double nan = std::numeric_limits<double>::quiet_NaN();

    ASSERT_FALSE(gslcpp::math::isnan(0));
    ASSERT_FALSE(gslcpp::math::isnan(1));
    ASSERT_FALSE(gslcpp::math::isnan(inf));
    ASSERT_FALSE(gslcpp::math::isnan(-inf));
    ASSERT_TRUE(gslcpp::math::isnan(nan));
}

TEST(Numbers, finite)
{
    double inf = std::numeric_limits<double>::infinity();
    double nan = std::numeric_limits<double>::quiet_NaN();

    ASSERT_TRUE(gslcpp::math::finite(0));
    ASSERT_TRUE(gslcpp::math::finite(1));
    ASSERT_FALSE(gslcpp::math::finite(inf));
    ASSERT_FALSE(gslcpp::math::finite(-inf));
    ASSERT_FALSE(gslcpp::math::finite(nan));
}
