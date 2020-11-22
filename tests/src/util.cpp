// gslcpp
#include "gslcpp/util.hpp"

// gsl
#include <gsl/gsl_complex_math.h>

// gtest
#include <gtest/gtest.h>

// stllib
#include <complex>
#include <vector>

using gslcpp::util::conversion::to_complex;

TEST(ComplexConversion, toStdComplex)
{
    std::complex<double> z = to_complex(gsl_complex_rect(5., 9.));

    ASSERT_DOUBLE_EQ(5., z.real());
    ASSERT_DOUBLE_EQ(9., z.imag());
}

TEST(ComplexConversion, toGSLComplex)
{
    gsl_complex z = to_complex(std::complex<double>(5., 9.));

    ASSERT_DOUBLE_EQ(5., GSL_REAL(z));
    ASSERT_DOUBLE_EQ(9., GSL_IMAG(z));
}

TEST(ComplexConversion, toStdComplexVec)
{
    size_t size = 100;
    gsl_complex* z = new gsl_complex[size];

    for (size_t i = 0; i < size; i++) {
        z[i] = gsl_complex_rect(i, i);
    }

    std::vector<std::complex<double>> zz = to_complex(z, size);

    for (size_t i = 0; i < size; i++) {
        ASSERT_DOUBLE_EQ(i, zz[i].real());
        ASSERT_DOUBLE_EQ(i, zz[i].imag());
    }
}

TEST(ComplexConversion, toGSLComplexVec)
{
    size_t size = 100;
    std::vector<std::complex<double>> z;

    for (size_t i = 0; i < size; i++) {
        z.push_back(std::complex<double>(i, i));
    }

    std::vector<gsl_complex> zz = to_complex(z);

    for (size_t i = 0; i < size; i++) {
        ASSERT_DOUBLE_EQ(i, GSL_REAL(zz[i]));
        ASSERT_DOUBLE_EQ(i, GSL_IMAG(zz[i]));
    }
}
