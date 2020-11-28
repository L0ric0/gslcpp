// gslcpp
#include "gslcpp/poly/divided_difference.hpp"

#include "gslcpp/exception.hpp"

// gsl
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
        int gsl_errno = gsl_poly_dd_init(m_dd.data(), xa.data(), ya.data(), xa.size());
        gslcpp::exception::gsl_errno_to_exception(gsl_errno);
    }

    DividedDifference::DividedDifference(
        const std::vector<double>& xa,
        const std::vector<double>& ya,
        const std::vector<double>& dya)
        : m_xa(2 * xa.size()),
          m_dd(2 * xa.size())
    {
        int gsl_errno = gsl_poly_dd_hermite_init(
            m_dd.data(),
            m_xa.data(),
            xa.data(),
            ya.data(),
            dya.data(),
            xa.size());
        gslcpp::exception::gsl_errno_to_exception(gsl_errno);
    }

    double DividedDifference::operator()(const double x) const
    {
        return gsl_poly_dd_eval(m_dd.data(), m_xa.data(), m_dd.size(), x);
    }

    std::vector<double> DividedDifference::to_taylor(const double xp) const
    {
        std::vector<double> w(m_xa.size()), c(m_xa.size());
        int gsl_errno
            = gsl_poly_dd_taylor(c.data(), xp, m_dd.data(), m_xa.data(), m_xa.size(), w.data());
        gslcpp::exception::gsl_errno_to_exception(gsl_errno);
        return c;
    }
} // namespace gslcpp::polynomial
