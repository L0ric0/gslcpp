#pragma once

// gsl
#include <gsl/gsl_math.h>

// global
#import <compare>
#include <type_traits>

namespace gslcpp
{
    namespace math
    {
        /*! The GSL Math Constants
         * \note GSL_POSINF, GSL_NEGINF and GSL_NAN are not implemented as the c++ versions should
         * be used.
         */
        namespace constants
        {
            /// The base of exponentials, $e$
            constexpr double e { M_E };
            /// The base-2 logarithm of $e$, $log_2(e)$
            constexpr double log2e { M_LOG2E };
            /// The base-10 logarithm of $e$, $log_10(e)$
            constexpr double log10e { M_LOG10E };
            /// The square root of two, $\sqrt{2}$
            constexpr double sqrt2 { M_SQRT2 };
            /// The square root of one-half, $\sqrt{\frac{1}/{2}}$
            constexpr double sqrt1_2 { M_SQRT1_2 };
            /// The square root of three, $\sqrt{3}$
            constexpr double sqrt3 { M_SQRT3 };
            /// The constant pi, $\pi$
            constexpr double pi { M_PI };
            /// Pi divided by two, $\frac{\pi}{2}
            constexpr double pi_2 { M_PI_2 };
            /// Pi divided by four, $\frac{\pi}{4}$
            constexpr double pi_4 { M_PI_4 };
            /// The square root of pi, $\sqrt{\pi}$
            constexpr double sqrtpi { M_SQRTPI };
            /// Two divided by the square root of pi, $\frac{2}{\sqrt{\pi}}$
            constexpr double inv_sqrtpi_2 { M_2_SQRTPI };
            /// The reciprocal of pi, $\frac{1}{\pi}
            constexpr double inv_pi { M_1_PI };
            /// Twice the reciprocal of pi, $\frac{2}{\pi}
            constexpr double inv_pi_2 { M_2_PI };
            /// The natural logarithm of ten, $\ln(10)$
            constexpr double ln10 { M_LN10 };
            /// The natural logarithm of two, $\ln(2)$
            constexpr double ln2 { M_LN2 };
            /// The natural logarithm of pi, $\ln(\pi)$
            constexpr double lnpi { M_LNPI };
            /// Euler's constant, $\gamma$
            constexpr double euler { M_EULER };
        } // namespace constants

        /*! This function returns true if x is not-a-number.
         */
        bool isnan(const double x);

        /*! This function returns $+1$ if $x$ is positive infinity, $-1$ if $x$ is negative infinity
         * and $0$ otherwise.
         */
        int isinf(const double x);

        /*! This function returns true if $x$ is a real number, and false if it is infinite or
         * not-a-number.
         */
        bool finite(const double x);

        /*! This function computes the value of $\log(1+x)$ in a way that is accurate for small $x$.
         * It provides an alternative to the stdlib function `std::log1p(x)`.
         */
        double log1p(const double x);

        /*! This function computes the value of $\exp(x) - 1$ in a way that is accurate for small x.
         * It provides an alternative to the stdlib function `std::expm1(x)`.
         */
        double expm1(const double x);

        /*! This function computes the value of $\sqrt{x^2 + y^2}$ in a way that avoids overflow. It
         * provides an alternative to the stdlib function `std::hypot(x,y)`.
         */
        double hypot(const double x, const double y);

        /*! This function computes the value of $\sqrt{x^2+y^2+z^2}$ in a way that avoids overflow.
         * It provides an alternative to the stdlib function ``std::hypot(x,y,z).
         */
        double hypot(const double x, const double y, const double z);

        /*! This function computes the value of $arccosh(x)$. It provides an alternative to the
         * stdlib function `std::acosh(x)`.
         */
        double acosh(const double x);

        /*! This function computes the value of $srcsinh(x)$. It provides an alternative to the
         * stdlib function `std::asinh(x)`.
         */
        double asinh(const double x);

        /*! This function computes the value of $arctanh(x)$. It provides an alternative to the
         * stdlib function `std::atanh(x)`.
         */
        double atanh(const double x);

        /*! This function computes the value of $x*2^e$. It provides an alternative to the stdlib
         * function `std::ldexp(x)`.
         */
        double ldexp(const double x, const int e);

        /*! This function splits the number $x$ into its normalized fraction $f$ and exponent $e$,
         * such that $x=f*2^e$ and $0.5 \leq f < 1$. The function returns $f$ and stores the
         * exponent in $e$. If $x$ is zero, both $f$ and $e$ are set to zero. This function provides
         * an alternative to the stdlib function `std::frexp(x, e)`.
         */
        double frexp(const double x, int* e);

        /*! This routine computes the power $x^n$ for integer $n$. The power is computed efficiently
         * - for example, $x^8$ is computed as $((x^2)^2)^2$, requiring only 3 multiplications. A
         * version of this function also computes the numerical error in the result is available as
         * `\todo`.
         */
        double pow(const double x, const int n);

        /*! This routine computes the power $x^n$ for integer $n$. The power is computed efficiently
         * - for example, $x^8$ is computed as $((x^2)^2)^2$, requiring only 3 multiplications. A
         * version of this function also computes the numerical error in the result is available as
         * `\todo`.
         */
        double pow(const double x, const unsigned int n);

        /*!This function determines whether x and y are approximately equal to a relative accuracy
         * epsilon.
         *
         * The relative accuracy is measured using an interval of size $2 \delta$, where $\delta =
         * 2^k \epsilon$ and $k$ is the maximum $base-2$ exponent of $x$ and $y$ as computed by the
         * function `frexp()`.
         *
         * If $x$ and $y$ lie within this interval, they are considered approximately equal and the
         * function returns `std::strong_ordering::equal`. Otherwise if $x < y$, the function
         * returns `std::strong_ordering::less`, or if $x > y$, the function returns
         * `std::strong_ordering::greater`.
         *
         * Note that $x$ and $y$ are compared to relative accuracy, so this function is not suitable
         * for testing whether a value is approximately zero.
         */
        std::strong_ordering fcmp(const double x, const double y, const double epsilon);

    } // namespace math
} // namespace gslcpp
