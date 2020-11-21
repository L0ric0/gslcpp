// cppgsl
#include "gslcpp/math.hpp"

// gsl
#include "gsl/gsl_math.h"

namespace gslcpp
{
    namespace math
    {
        bool isnan(const double x)
        {
            return gsl_isnan(x);
        }

        int isinf(const double x)
        {
            return gsl_isinf(x);
        }

        bool finite(const double x)
        {
            return gsl_finite(x);
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

        double ldexp(double x, int e)
        {
            return gsl_ldexp(x, e);
        }

        double frexp(double x, int* e)
        {
            return gsl_frexp(x, e);
        }
    } // namespace math
} // namespace gslcpp
