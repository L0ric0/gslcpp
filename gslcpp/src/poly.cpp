#include "gslcpp/poly.hpp"

#include "gslcpp/util.hpp"

// gsl
#include <gsl/gsl_poly.h>

// stllib
#include <complex>
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
        return to_complex(
            gsl_complex_poly_complex_eval(reinterpret_cast<const gsl_complex*>(c.data()), c.size(), to_complex(z)));
    }

    std::vector<double>
    eval_derivs(const std::vector<double>& c, const double x, const size_t num_derivs)
    {
        std::vector<double> res(num_derivs);
        gsl_poly_eval_derivs(c.data(), c.size(), x, res.data(), num_derivs);
        return res;
    }

} // namespace gslcpp::polynomial
