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

    DividedDifference::DividedDifference(
        const std::vector<double>& xa,
        const std::vector<double>& ya)
        : m_xa(xa),
          m_dd(xa.size())
    {
        gsl_poly_dd_init(m_dd.data(), xa.data(), ya.data(), xa.size());
    }

    DividedDifference::DividedDifference(
        const std::vector<double>& xa,
        const std::vector<double>& ya,
        const std::vector<double>& dya)
        : m_xa(2 * xa.size()),
          m_dd(2 * xa.size())
    {
        gsl_poly_dd_hermite_init(
            m_dd.data(),
            m_xa.data(),
            xa.data(),
            ya.data(),
            dya.data(),
            xa.size());
    }

    double DividedDifference::operator()(const double x) const
    {
        return gsl_poly_dd_eval(m_dd.data(), m_xa.data(), m_dd.size(), x);
    }

    std::vector<double> DividedDifference::to_taylor(const double xp) const
    {
        std::vector<double> w(m_xa.size()), c(m_xa.size());
        gsl_poly_dd_taylor(c.data(), xp, m_dd.data(), m_xa.data(), m_xa.size(), w.data());
        return c;
    }

    double eval(const std::vector<double>& c, const double x)
    {
        return gsl_poly_eval(c.data(), c.size(), x);
    }

    std::complex<double> eval(const std::vector<double>& c, const std::complex<double> z)
    {
        return to_complex(gsl_poly_complex_eval(c.data(), c.size(), to_complex(z)));
    }

    std::complex<double>
    eval(const std::vector<std::complex<double>> c, const std::complex<double> z)
    {
        return to_complex(
            gsl_complex_poly_complex_eval(to_complex(c).data(), c.size(), to_complex(z)));
    }

    std::vector<double>
    eval_derivs(const std::vector<double> c, const double x, const size_t num_derivs)
    {
        std::vector<double> res(num_derivs);
        gsl_poly_eval_derivs(c.data(), c.size(), x, res.data(), num_derivs);
        return res;
    }

} // namespace gslcpp::polynomial
