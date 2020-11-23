#pragma once

// stllib
#include <complex>
#include <vector>

namespace gslcpp::polynomial
{
    class DividedDifference
    {
      public:
        DividedDifference(const std::vector<double>& xa, const std::vector<double>& ya);
        DividedDifference(
            const std::vector<double>& xa,
            const std::vector<double>& ya,
            const std::vector<double>& dya);

        double operator()(const double x) const;

        std::vector<double> to_taylor(const double xp) const;

      private:
        std::vector<double> m_dd;
        std::vector<double> m_xa;
    };
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
} // namespace gslcpp::polynomial
