// gslcpp
#include "gslcpp/poly/solver.hpp"

// gsl
#include <gsl/gsl_poly.h>

// stllib
#include <complex>
#include <functional>
#include <memory>
#include <vector>

namespace gslcpp::polynomial
{
    PolynomialSolver::PolynomialSolver(const size_t data_size)
        : size(data_size),
          m_workspace(std::unique_ptr<
                      gsl_poly_complex_workspace,
                      std::function<void(gsl_poly_complex_workspace*)>>(
              gsl_poly_complex_workspace_alloc(size),
              &gsl_poly_complex_workspace_free))
    {
    }

    std::vector<std::complex<double>> PolynomialSolver::solve(const std::vector<double>& a)
    {
        std::vector<std::complex<double>> result(size - 1);
        gsl_poly_complex_solve(
            a.data(),
            size,
            m_workspace.get(),
            reinterpret_cast<gsl_complex_packed_ptr>(result.data()));
        return result;
    }
} // namespace gslcpp::polynomial
