#include "gslcpp/poly/divided_difference.hpp"

//gsl
#include <gsl/gsl_poly.h>

// stllib
#include <vector>

namespace gslcpp::polynomial
{

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
} // namespace gslcpp::polynomial