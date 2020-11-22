#pragma once

// gsl
#include <gsl/gsl_complex.h>

// stllib
#include <complex>
#include <vector>

namespace gslcpp::util::conversion
{
    /*! This function converts a gsl_complex number to a std::complex<double>.
     */
    std::complex<double> to_complex(const gsl_complex x);

    /*! This function converts a std::complex<double> to a gsl_complex.
     */
    gsl_complex to_complex(const std::complex<double> x);

    /*! This funtion takes an c-style array of gsl_complex and converts it to a
     * std::vector<std::complex<double>>.
     */
    std::vector<std::complex<double>> to_complex(const gsl_complex* z, const size_t size);

    /*! This function takes an std::vector<std::complex<double>> and converts it to a
     * std::vector<gsl_complex>.
     */
    std::vector<std::complex<double>> to_complex(const std::vector<gsl_complex>& z);

    /*! This function takes an std::vector<std::complex<double>> and converts it to a
     * std::vector<gsl_complex>.
     */
    std::vector<gsl_complex> to_complex(const std::vector<std::complex<double>>& z);

} // namespace gslcpp::util::conversion
