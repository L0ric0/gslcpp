#pragma once

// gslcpp
#include "gslcpp/poly/divided_difference.hpp"
#include "gslcpp/poly/solver.hpp"

// stllib
#include <complex>
#include <vector>

namespace gslcpp::polynomial
{

    /*! This function evaluates a polynomial with real coefficients for the real variable `x`.
     */
    double eval(const std::vector<double>& c, const double x);

    /*! This function evaluates a polynomial with real coefficients for the complex variable `z`.
     */
    std::complex<double> eval(const std::vector<double>& c, const std::complex<double> z);

    /*! This function evaluates a polynomial with complex coefficients for the complex variable `z`.
     */
    std::complex<double>
    eval(const std::vector<std::complex<double>>& c, const std::complex<double> z);

    /*! This function evaluates a polynomial and its derivatives. The output vector contains the
     * values of $d^k P(x)/d x^k$ for the specified value of $x$ starting with $k = 0$.
     */
    std::vector<double>
    eval_derivs(const std::vector<double>& c, const double x, const size_t num_derivs = 1);

    /*! This function finds the real roots of the quadratic equation, $a x^2 + b x + c = 0$.
     *
     * The number of roots found depends on the sign of the discriminant b^2 - 4 a c. This will be
     * subject to rounding and cancellation errors when computed in double precision, and will also
     * be subject to errors if the coefficients of the polynomial are inexact. These errors may
     * cause a discrete change in the number of roots. However, for polynomials with small integer
     * coefficients the discriminant can always be computed exactly.
     */
    std::vector<double> solve_quadratic(const double a, const double b, const double c);

    /*! This function finds the complex roots of the quadratic equation, $a z^2 + b z + c = 0$.
     *
     * Only the real components of the parameters are used. This is done as function overloads can't
     * only differ by return type.
     */
    std::vector<std::complex<double>> solve_quadratic(
        const std::complex<double> a,
        const std::complex<double> b,
        const std::complex<double> c);

    /*! This function finds the real roots of the cubic equation, $x ^ 3 + a x ^ 2 + b x + c = 0$
     * with a leading coefficient of unity.
     */
    std::vector<double> solve_cubic(const double a, const double b, const double c);

    /*! This function finds the real roots of the cubic equation, $x ^ 3 + a x ^ 2 + b x + c = 0$
     * with a leading coefficient of unity.
     *
     * Only the real components of the parameters are used. This is done as function overloads can't
     * only differ by return type.
     */
    std::vector<std::complex<double>> solve_cubic(
        const std::complex<double> a,
        const std::complex<double> b,
        const std::complex<double> c);

    /*! This function computes the roots of the general polynomial $P(x) = a_0 + a_1 x + a_2 x^2 +
     * \cdots + a_{n-1} x^{n-1}$
     *
     * using balanced-QR reduction of the companion matrix. The coefficient of the highest order
     * term must be non-zero. The n-1 roots are returned.
     */
    std::vector<std::complex<double>> solve(const std::vector<double>& a);

} // namespace gslcpp::polynomial
