// gslcpp
#include "gslcpp/poly.hpp"

#include "gslcpp/poly/solver.hpp"
#include "gslcpp/util.hpp"

// gsl
#include <gsl/gsl_poly.h>

// stllib
#include <complex>
#include <functional>
#include <memory>
#include <vector>

namespace gslcpp::polynomial
{
    using gslcpp::util::conversion::to_complex;

    double eval(const std::vector<double>& c, const double x)
    {
        return gsl_poly_eval(c.data(), c.size(), x);
    }

    std::complex<double> eval(const std::vector<double>& c, const std::complex<double> z)
    {
        return to_complex(gsl_poly_complex_eval(c.data(), c.size(), to_complex(z)));
    }

    std::complex<double>
    eval(const std::vector<std::complex<double>>& c, const std::complex<double> z)
    {
        return to_complex(gsl_complex_poly_complex_eval(
            reinterpret_cast<const gsl_complex*>(c.data()),
            c.size(),
            to_complex(z)));
    }

    std::vector<double>
    eval_derivs(const std::vector<double>& c, const double x, const size_t num_derivs)
    {
        std::vector<double> res(num_derivs);
        gsl_poly_eval_derivs(c.data(), c.size(), x, res.data(), num_derivs);
        return res;
    }

    std::vector<double> solve_quadratic(const double a, const double b, const double c)
    {
        double x0, x1;
        int num_roots = gsl_poly_solve_quadratic(a, b, c, &x0, &x1);
        if (num_roots == 0) {
            return std::vector<double> {};
        }
        if (num_roots == 1) {
            return std::vector<double> { x0 };
        }
        return std::vector<double> { x0, x1 };
    }

    std::vector<std::complex<double>> solve_quadratic(
        const std::complex<double> a,
        const std::complex<double> b,
        const std::complex<double> c)
    {
        std::complex<double> x0, x1;
        int num_roots = gsl_poly_complex_solve_quadratic(
            a.real(),
            b.real(),
            c.real(),
            reinterpret_cast<gsl_complex*>(&x0),
            reinterpret_cast<gsl_complex*>(&x1));
        if (num_roots == 0) {
            return std::vector<std::complex<double>> {};
        }
        if (num_roots == 1) {
            return std::vector<std::complex<double>> { x0 };
        }
        return std::vector<std::complex<double>> { x0, x1 };
    }

    std::vector<double> solve_cubic(const double a, const double b, const double c)
    {
        double x0, x1, x2;
        int num_roots = gsl_poly_solve_cubic(a, b, c, &x0, &x1, &x2);
        if (num_roots == 1) {
            return std::vector<double> { x0 };
        }
        return std::vector<double> { x0, x1, x2 };
    }

    std::vector<std::complex<double>> solve_cubic(
        const std::complex<double> a,
        const std::complex<double> b,
        const std::complex<double> c)
    {
        std::complex<double> x0, x1, x2;
        int num_roots = gsl_poly_complex_solve_cubic(
            a.real(),
            b.real(),
            c.real(),
            reinterpret_cast<gsl_complex*>(&x0),
            reinterpret_cast<gsl_complex*>(&x1),
            reinterpret_cast<gsl_complex*>(&x2));

        if (num_roots == 1) {
            return std::vector<std::complex<double>> { x0 };
        }
        return std::vector<std::complex<double>> { x0, x1, x2 };
    }

    std::vector<std::complex<double>> solve(const std::vector<double>& a)
    {
        PolynomialSolver solver(a.size());
        return solver.solve(a);
    }
} // namespace gslcpp::polynomial
