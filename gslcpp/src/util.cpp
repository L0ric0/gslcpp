#include "gslcpp/util.hpp"

// gsl
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

// stllib
#include <complex>
#include <cstring>
#include <vector>

namespace gslcpp::util::conversion
{
    std::complex<double> to_complex(const gsl_complex z)
    {
        return std::complex<double> { GSL_REAL(z), GSL_IMAG(z) };
    }

    gsl_complex to_complex(const std::complex<double> z)
    {
        return gsl_complex_rect(z.real(), z.imag());
    }

    std::vector<std::complex<double>> to_complex(const gsl_complex* z, const size_t size)
    {
        return std::vector<std::complex<double>>(
            reinterpret_cast<const std::complex<double>*>(z),
            reinterpret_cast<const std::complex<double>*>(z + size));
    }

    std::vector<std::complex<double>> to_complex(const std::vector<gsl_complex>& z)
    {
        return std::vector<std::complex<double>>(
            reinterpret_cast<const std::complex<double>*>(z.data()),
            reinterpret_cast<const std::complex<double>*>(z.data() + z.size()));
    }

    std::vector<gsl_complex> to_complex(const std::vector<std::complex<double>>& z)
    {
        return std::vector<gsl_complex>(
            reinterpret_cast<const gsl_complex*>(z.data()),
            reinterpret_cast<const gsl_complex*>(z.data() + z.size()));
    }
} // namespace gslcpp::util::conversion
