#pragma once

// gsl
#include <gsl/gsl_poly.h>

// stllib
#include <complex>
#include <functional>
#include <memory>
#include <vector>

namespace gslcpp::polynomial
{
    class PolynomialSolver
    {
      public:
        PolynomialSolver(const size_t data_size);
        std::vector<std::complex<double>> solve(const std::vector<double>& a);

        const size_t size;

      private:
        std::
            unique_ptr<gsl_poly_complex_workspace, std::function<void(gsl_poly_complex_workspace*)>>
                m_workspace;
    };
} // namespace gslcpp::polynomial
