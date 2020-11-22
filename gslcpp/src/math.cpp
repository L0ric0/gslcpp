// cppgsl
#include "gslcpp/math.hpp"

// gsl
#include "gsl/gsl_math.h"

namespace gslcpp::math
{
    bool isnan(const double x)
    {
        return gsl_isnan(x) != 0;
    }

    int isinf(const double x)
    {
        return gsl_isinf(x);
    }

    bool finite(const double x)
    {
        return gsl_finite(x) != 0;
    }

    double log1p(const double x)
    {
        return gsl_log1p(x);
    }

    double expm1(const double x)
    {
        return gsl_expm1(x);
    }

    double hypot(const double x, const double y)
    {
        return gsl_hypot(x, y);
    }

    double hypot(const double x, const double y, const double z)
    {
        return gsl_hypot3(x, y, z);
    }

    double acosh(const double x)
    {
        return gsl_acosh(x);
    }

    double asinh(const double x)
    {
        return gsl_asinh(x);
    }

    double atanh(const double x)
    {
        return gsl_atanh(x);
    }

    double ldexp(const double x, const int e)
    {
        return gsl_ldexp(x, e);
    }

    double frexp(const double x, int* e)
    {
        return gsl_frexp(x, e);
    }

    double pow(const double x, const int n)
    {
        return gsl_pow_int(x, n);
    }

    double pow(const double x, const unsigned int n)
    {
        return gsl_pow_uint(x, n);
    }

    std::strong_ordering fcmp(const double x, const double y, const double epsilon)
    {
        int res = gsl_fcmp(x, y, epsilon);
        if (res == 0) {
            return std::strong_ordering::equal;
        }
        if (res == -1) {
            return std::strong_ordering::less;
        }
        return std::strong_ordering::greater;
    }
} // namespace gslcpp::math
