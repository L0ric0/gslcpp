// tests
#include "poly.hpp"

// gslcpp
#include "gslcpp/poly.hpp"

// gtest
#include <gtest/gtest.h>

// stllib
#include <complex>
#include <limits>
#include <vector>

const double eps = 100.0 * std::numeric_limits<double>::epsilon();

const std::vector<EvalParam> eval_params { { { 1.0, 0.5, 0.3 }, 0.5, 1.325 },
                                           { { 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1 }, 1.0, 1.0 } };

INSTANTIATE_TEST_SUITE_P(Eval, PolyEval, testing::ValuesIn(eval_params));

TEST_P(PolyEval, ParamTest)
{
    EvalParam param = GetParam();
    ASSERT_DOUBLE_EQ(param.result, gslcpp::polynomial::eval(param.c, param.x));
}

const std::vector<EvalComplexParam> eval_complex_params {
    { { 0.3 }, { 0.75, 1.2 }, { 0.3, 0.0 } },
    { { 2.1, -1.34, 0.76, 0.45 }, { 0.49, 0.95 }, { 0.3959143, -0.6433305 } }
};

INSTANTIATE_TEST_SUITE_P(EvalComplex, PolyEvalComplex, testing::ValuesIn(eval_complex_params));

TEST_P(PolyEvalComplex, ParamTest)
{
    EvalComplexParam param = GetParam();
    ASSERT_NEAR(param.result.real(), gslcpp::polynomial::eval(param.c, param.x).real(), eps);
    ASSERT_NEAR(param.result.imag(), gslcpp::polynomial::eval(param.c, param.x).imag(), eps);
}

const std::vector<ComplexEvalComplexParam> complex_eval_complex_params {
    { { { 0.674, -1.423 } }, { -1.44, 9.55 }, { 0.674, -1.423 } },
    { { { -2.31, 0.44 }, { 4.21, -3.19 }, { 0.93, 1.04 }, { -0.42, 0.68 } },
      { 0.49, 0.95 },
      { 1.82462012, 2.30389412 } }
};

INSTANTIATE_TEST_SUITE_P(
    ComplexEvalComplex,
    PolyComplexEvalComplex,
    testing::ValuesIn(complex_eval_complex_params));

TEST_P(PolyComplexEvalComplex, ParamTest)
{
    ComplexEvalComplexParam param = GetParam();
    ASSERT_NEAR(param.result.real(), gslcpp::polynomial::eval(param.c, param.x).real(), eps);
    ASSERT_NEAR(param.result.imag(), gslcpp::polynomial::eval(param.c, param.x).imag(), eps);
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

const std::vector<SolveParam> solve_quadratic_params {
    { 4.0, -20.0, 26.0, {} },           { 4.0, -20.0, 25.0, { 2.5, 2.5 } },
    { 4.0, -20.0, 21.0, { 1.5, 3.5 } }, { 4.0, 7.0, 0.0, { -1.75, 0.0 } },
    { 5.0, 0.0, -20.0, { -2.0, 2.0 } }, { 0.0, 3.0, -21.0, { 7.0 } }
};

INSTANTIATE_TEST_SUITE_P(
    SolveQuadratic,
    PolySolveQuadratic,
    testing::ValuesIn(solve_quadratic_params));

TEST_P(PolySolveQuadratic, ParamTest)
{
    SolveParam param = GetParam();
    std::vector<double> x = gslcpp::polynomial::solve_quadratic(param.a, param.b, param.c);
    ASSERT_EQ(param.result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_DOUBLE_EQ(param.result[i], x[i]);
    }
}

const std::vector<SolveParam> solve_cubic_params {
    { 0.0, 0.0, -27.0, { 3.0 } },
    { -51.0, 867.0, -4913.0, { 17.0, 17.0, 17.0 } },
    { -57.0, 1071.0, -6647.0, { 17.0, 17.0, 23.0 } },
    { -11.0, -493.0, 6647.0, { -23.0, 17.0, 17.0 } },
    { -143.0, 5087.0, -50065.0, { 17.0, 31.0, 95.0 } },
    { -109.0, 803.0, 50065.0, { -17.0, 31.0, 95.0 } }
};

INSTANTIATE_TEST_SUITE_P(SolveCubic, PolySolveCubic, testing::ValuesIn(solve_cubic_params));

TEST_P(PolySolveCubic, ParamTest)
{

    SolveParam param = GetParam();

    std::vector<double> x = gslcpp::polynomial::solve_cubic(param.a, param.b, param.c);
    ASSERT_EQ(param.result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_DOUBLE_EQ(param.result[i], x[i]);
    }
}

const std::vector<SolveComplexParam> solve_quadratic_complex_param {
    { { 4.0, 0.0 }, { -20.0, 0.0 }, { 26.0, 0.0 }, { { 2.5, -0.5 }, { 2.5, 0.5 } } },
    { { 4.0, 0.0 }, { -20.0, 0.0 }, { 25.0, 0.0 }, { { 2.5, 0.0 }, { 2.5, 0.0 } } },
    { { 4.0, 0.0 }, { -20.0, 0.0 }, { 21.0, 0.0 }, { { 1.5, 0.0 }, { 3.5, 0.0 } } },
    { { 4.0, 0.0 }, { 7.0, 0.0 }, { 0.0, 0.0 }, { { -1.75, 0.0 }, { 0.0, 0.0 } } },
    { { 5.0, 0.0 }, { 0.0, 0.0 }, { -20.0, 0.0 }, { { -2.0, 0.0 }, { 2.0, 0.0 } } },
    { { 5.0, 0.0 }, { 0.0, 0.0 }, { 20.0, 0.0 }, { { 0.0, -2.0 }, { 0.0, 2.0 } } },
    { { 0.0, 0.0 }, { 3.0, 0.0 }, { -21.0, 0.0 }, { { 7.0, 0.0 } } },
    { { 0.0, 0.0 }, { 0.0, 0.0 }, { 1.0, 0.0 }, {} }
};

INSTANTIATE_TEST_SUITE_P(
    SolveQuadraticComplex,
    PolySolveQuadraticComplex,
    testing::ValuesIn(solve_quadratic_complex_param));

TEST_P(PolySolveQuadraticComplex, ParamTest)
{
    SolveComplexParam param = GetParam();

    std::vector<std::complex<double>> x
        = gslcpp::polynomial::solve_quadratic(param.a, param.b, param.c);
    ASSERT_EQ(param.result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_DOUBLE_EQ(param.result[i].real(), x[i].real());
        ASSERT_DOUBLE_EQ(param.result[i].imag(), x[i].imag());
    }
}

const std::vector<SolveComplexParam> solve_cubic_complex_param {
    { { 0.0, 0.0 },
      { 0.0, 0.0 },
      { -27.0, 0.0 },
      { { -1.5, -1.5 * std::sqrt(3.0) }, { -1.5, 1.5 * std::sqrt(3.0) }, { 3.0, 0.0 } } },
    { { -1.0, 0.0 }, { 1.0, 0.0 }, { 39.0, 0.0 }, { { -3.0, 0.0 }, { 2.0, -3.0 }, { 2.0, 3.0 } } },
    { { -51.0, 0.0 },
      { 867.0, 0.0 },
      { -4913.0, 0.0 },
      { { 17.0, 0.0 }, { 17.0, 0.0 }, { 17.0, 0.0 } } },
    { { -57.0, 0.0 },
      { 1071.0, 0.0 },
      { -6647.0, 0.0 },
      { { 17.0, 0.0 }, { 17.0, 0.0 }, { 23.0, 0.0 } } },
    { { -11.0, 0.0 },
      { -493.0, 0.0 },
      { 6647.0, 0.0 },
      { { -23.0, 0.0 }, { 17.0, 0.0 }, { 17.0, 0.0 } } },
    { { -143.0, 0.0 },
      { 5087.0, 0.0 },
      { -50065.0, 0.0 },
      { { 17.0, 0.0 }, { 31.0, 0.0 }, { 95.0, 0.0 } } }
};

INSTANTIATE_TEST_SUITE_P(
    SolveCubicComplex,
    PolySolveCubicComplex,
    testing::ValuesIn(solve_cubic_complex_param));

TEST_P(PolySolveCubicComplex, ParamTest)
{
    SolveComplexParam param = GetParam();

    std::vector<std::complex<double>> x
        = gslcpp::polynomial::solve_cubic(param.a, param.b, param.c);
    ASSERT_EQ(param.result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_DOUBLE_EQ(param.result[i].real(), x[i].real());
        ASSERT_DOUBLE_EQ(param.result[i].imag(), x[i].imag());
    }
}

TEST(ComplexSolve, WilkinsonPolynomial)
{
    std::vector<double> a { -120, 274, -225, 85, -15, 1 };
    std::vector<std::complex<double>> result { { 1.0, 0.0 },
                                               { 2.0, 0.0 },
                                               { 3.0, 0.0 },
                                               { 4.0, 0.0 },
                                               { 5.0, 0.0 } };

    std::vector<std::complex<double>> x = gslcpp::polynomial::solve(a);

    ASSERT_EQ(result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_NEAR(result[i].real(), x[i].real(), 1e-9);
        ASSERT_NEAR(result[i].imag(), x[i].imag(), 1e-9);
    }
}

TEST(ComplexSolve, 8thOrderPolynomial)
{
    std::vector<double> a { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    double C = 0.5;
    double S = std::sqrt(3.0) / 2.0;

    std::vector<std::complex<double>> result { { -S, C }, { -S, -C }, { -C, S }, { -C, -S },
                                               { C, S },  { C, -S },  { S, C },  { S, -C } };

    std::vector<std::complex<double>> x = gslcpp::polynomial::solve(a);

    ASSERT_EQ(result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_NEAR(result[i].real(), x[i].real(), 1e-9);
        ASSERT_NEAR(result[i].imag(), x[i].imag(), 1e-9);
    }
}

TEST(ComplexSolve, 15thOrderPolynomial)
{
    std::vector<double> a { 32, -48, -8, 28, -8, 16, -16, 12, -16, 6, 10, -17, 10, 2, -4, 1 };
    std::vector<std::complex<double>> result { { -1.6078107423472359, 0.00000000000000000 },
                                               { -1.3066982484920768, 0.00000000000000000 },
                                               { -1.0000000000000000, 0.00000000000000000 },
                                               { -0.65893856175240950, -0.83459757287426684 },
                                               { -0.65893856175240950, 0.83459757287426684 },
                                               { -0.070891117403341281, -1.1359249087587791 },
                                               { -0.070891117403341281, 1.1359249087587791 },
                                               { 0.57284747839410854, -1.1987808988289705 },
                                               { 0.57284747839410854, 1.1987808988289705 },
                                               { 1.0000000000000000, 0.00000000000000000 },
                                               { 1.0000000000000000, 0.00000000000000000 },
                                               { 1.1142366961812986, -0.48083981203389980 },
                                               { 1.1142366961812986, 0.48083981203389980 },
                                               { 2.0000000000000000, 0.00000000000000000 },
                                               { 2.0000000000000000, 0.00000000000000000 } };

    std::vector<std::complex<double>> x = gslcpp::polynomial::solve(a);

    std::sort(x.begin(), x.end(), [](std::complex<double> a, std::complex<double> b) {
        std::complex<double> r = a - b;
        if (r.real() == 0) {
            return r.imag() < 0.0 ? true : false;
        } else if (r.real() < 0.0) {
            return true;
        } else {
            return false;
        }
    });

    ASSERT_EQ(result.size(), x.size());
    for (size_t i = 0; i < x.size(); i++) {
        ASSERT_NEAR(result[i].real(), x[i].real(), 1e-7);
        ASSERT_NEAR(result[i].imag(), x[i].imag(), 1e-7);
    }
}
