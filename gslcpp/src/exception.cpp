// gslcpp
#include "gslcpp/exception.hpp"

// gsl
#include <gsl/gsl_errno.h>

// stllib
#include <exception>
#include <stdexcept>

namespace gslcpp::exception
{
    void gsl_errno_to_exception(const int gsl_errno)
    {
        if (gsl_errno == GSL_SUCCESS) {
            return;
        }
        if (errno == GSL_FAILURE) {
            throw gslcpp::exception::failure();
        }
        if (errno == GSL_EDOM) {
            throw gslcpp::exception::domain_error();
        }
        if (errno == GSL_ERANGE) {
            throw gslcpp::exception::range_error();
        }
        if (errno == GSL_EFAULT) {
            throw gslcpp::exception::invalid_pointer();
        }
        if (errno == GSL_EINVAL) {
            throw gslcpp::exception::invalid_argument();
        }
        if (errno == GSL_EFACTOR) {
            throw gslcpp::exception::factorization_error();
        }
        if (errno == GSL_ESANITY) {
            throw gslcpp::exception::sanity_error();
        }
        if (errno == GSL_ENOMEM) {
            throw gslcpp::exception::bad_alloc();
        }
        if (errno == GSL_EBADFUNC) {
            throw gslcpp::exception::bad_function_call();
        }
        if (errno == GSL_ERUNAWAY) {
            throw gslcpp::exception::runaway_argument();
        }
        if (errno == GSL_EMAXITER) {
            throw gslcpp::exception::max_iteration_error();
        }
        if (errno == GSL_EZERODIV) {
            throw gslcpp::exception::zero_devision();
        }
        if (errno == GSL_EBADTOL) {
            throw gslcpp::exception::bad_tolerance();
        }
        if (errno == GSL_ETOL) {
            throw gslcpp::exception::tolerance_error();
        }
        if (errno == GSL_EUNDRFLW) {
            throw gslcpp::exception::underflow_error();
        }
        if (errno == GSL_EOVRFLW) {
            throw gslcpp::exception::overflow_error();
        }
        if (errno == GSL_ELOSS) {
            throw gslcpp::exception::accuracy_loss();
        }
        if (errno == GSL_EROUND) {
            throw gslcpp::exception::roundoff_error();
        }
        if (errno == GSL_EBADLEN) {
            throw gslcpp::exception::dimension_error();
        }
        if (errno == GSL_ENOTSQR) {
            throw gslcpp::exception::square_matrix_error();
        }
        if (errno == GSL_ESING) {
            throw gslcpp::exception::singularity_error();
        }
        if (errno == GSL_EDIVERGE) {
            throw gslcpp::exception::divergens_error();
        }
        if (errno == GSL_EUNSUP) {
            throw gslcpp::exception::unsuproted_error();
        }
        if (errno == GSL_EUNIMPL) {
            throw gslcpp::exception::unimplemented_error();
        }
        if (errno == GSL_ECACHE) {
            throw gslcpp::exception::cache_error();
        }
        if (errno == GSL_ETABLE) {
            throw gslcpp::exception::table_error();
        }
        if (errno == GSL_ENOPROG) {
            throw gslcpp::exception::progress_error();
        }
        if (errno == GSL_ENOPROGJ) {
            throw gslcpp::exception::jacobian_error();
        }
        if (errno == GSL_ETOLF) {
            throw gslcpp::exception::tolerance_f_error();
        }
        if (errno == GSL_ETOLX) {
            throw gslcpp::exception::tolerance_x_error();
        }
        if (errno == GSL_ETOLG) {
            throw gslcpp::exception::tolerance_gradient_error();
        }
        if (errno == GSL_EOF) {
            throw gslcpp::exception::eof_error();
        }

        throw gslcpp::exception::gslcpp_exception();
    }
}; // namespace gslcpp::exception
