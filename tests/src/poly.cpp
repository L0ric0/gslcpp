#include "gslcpp/poly.hpp"

// gtest
#include <gtest/gtest.h>

// stllib
#include <complex>
#include <limits>
#include <vector>

const double eps = 100.0 * std::numeric_limits<double>::epsilon();

TEST(Poly, Eval)
{
    std::vector<double> c { 1.0, 0.5, 0.3 };
    double x = 0.5;
    ASSERT_DOUBLE_EQ(1 + 0.5 * x + 0.3 * std::pow(x, 2), gslcpp::polynomial::eval(c, x));

    c = { 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1 };
    x = 1.0;
    ASSERT_DOUBLE_EQ(1.0, gslcpp::polynomial::eval(c, x));
}

TEST(Poly, EvalComplex)
{
    std::vector<double> c { 0.3 };
    std::complex<double> z { 0.75, 1.2 };
    ASSERT_NEAR(0.3, gslcpp::polynomial::eval(c, z).real(), eps);
    ASSERT_NEAR(0.0, gslcpp::polynomial::eval(c, z).imag(), eps);

    c = { 2.1, -1.34, 0.76, 0.45 };
    z = { 0.49, 0.95 };
    ASSERT_NEAR(0.3959143, gslcpp::polynomial::eval(c, z).real(), eps);
    ASSERT_NEAR(-0.6433305, gslcpp::polynomial::eval(c, z).imag(), eps);
}

TEST(Poly, ComplexEvalComplex)
{
    std::vector<std::complex<double>> c { { 0.674, -1.423 } };
    std::complex<double> z { -1.44, 9.55 };
    ASSERT_NEAR(0.674, gslcpp::polynomial::eval(c, z).real(), eps);
    ASSERT_NEAR(-1.423, gslcpp::polynomial::eval(c, z).imag(), eps);

    c = { { -2.31, 0.44 }, { 4.21, -3.19 }, { 0.93, 1.04 }, { -0.42, 0.68 } };
    z = { 0.49, 0.95 };
    ASSERT_NEAR(1.82462012, gslcpp::polynomial::eval(c, z).real(), eps);
    ASSERT_NEAR(2.30389412, gslcpp::polynomial::eval(c, z).imag(), eps);
}

TEST(Poly, EvalDerivs)
{
    std::vector<double> c { 1.0, -2.0, 3.0, -4.0, 5.0, -6.0 };
    double x = -0.5;

    std::vector<double> res = gslcpp::polynomial::eval_derivs(c, x, 6);

    ASSERT_DOUBLE_EQ(
        res[0],
        c[0] + c[1] * x + c[2] * std::pow(x, 2) + c[3] * std::pow(x, 3) + c[4] * std::pow(x, 4)
            + c[5] * std::pow(x, 5));
    ASSERT_DOUBLE_EQ(
        res[1],
        c[1] + 2.0 * c[2] * x + 3.0 * c[3] * std::pow(x, 2) + 4.0 * c[4] * std::pow(x, 3)
            + 5.0 * c[5] * std::pow(x, 4));
    ASSERT_DOUBLE_EQ(
        res[2],
        2.0 * c[2] + 3.0 * 2.0 * c[3] * x + 4.0 * 3.0 * c[4] * std::pow(x, 2)
            + 5.0 * 4.0 * c[5] * std::pow(x, 3));
    ASSERT_DOUBLE_EQ(
        res[3],
        3.0 * 2.0 * c[3] + 4.0 * 3.0 * 2.0 * c[4] * x + 5.0 * 4.0 * 3.0 * c[5] * std::pow(x, 2));
    ASSERT_DOUBLE_EQ(res[4], 4.0 * 3.0 * 2.0 * c[4] + 5.0 * 4.0 * 3.0 * 2.0 * c[5] * x);
    ASSERT_DOUBLE_EQ(res[5], 5.0 * 4.0 * 3.0 * 2.0 * c[5]);
}

TEST(Poly, DividedDifference)
{
    std::vector<double> xa { 0.16, 0.97, 1.94, 2.74, 3.58, 3.73, 4.70 };
    std::vector<double> ya { 0.73, 1.11, 1.49, 1.84, 2.30, 2.41, 3.07 };

    gslcpp::polynomial::DividedDifference dd(xa, ya);

    for (size_t i = 1; i < xa.size(); i++) {
        ASSERT_DOUBLE_EQ(ya[i], dd(xa[i]));
    }

    std::vector<double> coeff = dd.to_taylor(1.5);

    for (size_t i = 1; i < xa.size(); i++) {
        ASSERT_DOUBLE_EQ(ya[i], gslcpp::polynomial::eval(coeff, xa[i] - 1.5));
    }
}

TEST(Poly, DividedDifferenceHermite)
{
    std::vector<double> xa { 1.3, 1.6, 1.9 };
    std::vector<double> ya { 0.6200860, 0.4554022, 0.2818186 };
    std::vector<double> dya { -0.5220232, -0.5698959, -0.5811571 };

    gslcpp::polynomial::DividedDifference dd(xa, ya, dya);

    for (size_t i = 0; i < xa.size(); i++) {
        ASSERT_DOUBLE_EQ(ya[i], dd(xa[i]));
    }

    std::vector<double> coeff;
    for (size_t i = 0; i < xa.size(); i++) {
        coeff = dd.to_taylor(xa[i]);
        ASSERT_DOUBLE_EQ(coeff[1], dya[i]);
    }
}

TEST(Poly, SolveQuadratic)
{
    std::vector<double> x;

    x = gslcpp::polynomial::solve_quadratic(4.0, -20.0, 26.0);
    ASSERT_EQ(0, x.size());

    x = gslcpp::polynomial::solve_quadratic(4.0, -20.0, 25.0);
    ASSERT_EQ(2, x.size());
    ASSERT_DOUBLE_EQ(2.5, x[0]);
    ASSERT_DOUBLE_EQ(2.5, x[1]);
    ASSERT_EQ(x[0], x[1]);

    x = gslcpp::polynomial::solve_quadratic(4.0, -20.0, 21.0);
    ASSERT_EQ(2, x.size());
    ASSERT_DOUBLE_EQ(1.5, x[0]);
    ASSERT_DOUBLE_EQ(3.5, x[1]);

    x = gslcpp::polynomial::solve_quadratic(4.0, 7.0, 0.0);
    ASSERT_EQ(2, x.size());
    ASSERT_DOUBLE_EQ(-1.75, x[0]);
    ASSERT_DOUBLE_EQ(0.0, x[1]);

    x = gslcpp::polynomial::solve_quadratic(5.0, 0.0, -20.0);
    ASSERT_EQ(2, x.size());
    ASSERT_DOUBLE_EQ(-2.0, x[0]);
    ASSERT_DOUBLE_EQ(2.0, x[1]);

    x = gslcpp::polynomial::solve_quadratic(0.0, 3.0, -21.0);
    ASSERT_EQ(1, x.size());
    ASSERT_DOUBLE_EQ(7.0, x[0]);
}

TEST(Poly, SolveCubic)
{
    std::vector<double> x;

    x = gslcpp::polynomial::solve_cubic(0.0, 0.0, -27.0);
    ASSERT_EQ(1, x.size());
    ASSERT_DOUBLE_EQ(3.0, x[0]);

    x = gslcpp::polynomial::solve_cubic(-51.0, 867.0, -4913.0);
    ASSERT_EQ(3, x.size());
    ASSERT_DOUBLE_EQ(17.0, x[0]);
    ASSERT_DOUBLE_EQ(17.0, x[1]);
    ASSERT_DOUBLE_EQ(17.0, x[2]);

    x = gslcpp::polynomial::solve_cubic(-57, 1071.0, -6647.0);
    ASSERT_EQ(3, x.size());
    ASSERT_DOUBLE_EQ(17.0, x[0]);
    ASSERT_DOUBLE_EQ(17.0, x[1]);
    ASSERT_DOUBLE_EQ(23.0, x[2]);

    x = gslcpp::polynomial::solve_cubic(-11.0, -493.0, 6647.0);
    ASSERT_EQ(3, x.size());
    ASSERT_DOUBLE_EQ(-23.0, x[0]);
    ASSERT_DOUBLE_EQ(17.0, x[1]);
    ASSERT_DOUBLE_EQ(17.0, x[2]);

    x = gslcpp::polynomial::solve_cubic(-143.0, 5087.0, -50065.0);
    ASSERT_EQ(3, x.size());
    ASSERT_DOUBLE_EQ(17.0, x[0]);
    ASSERT_DOUBLE_EQ(31.0, x[1]);
    ASSERT_DOUBLE_EQ(95.0, x[2]);

    x = gslcpp::polynomial::solve_cubic(-109.0, 803.0, 50065.0);
    ASSERT_EQ(3, x.size());
    ASSERT_DOUBLE_EQ(-17.0, x[0]);
    ASSERT_DOUBLE_EQ(31.0, x[1]);
    ASSERT_DOUBLE_EQ(95.0, x[2]);
}
