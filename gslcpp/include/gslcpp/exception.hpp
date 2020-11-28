#pragma once

// stllib
#include <exception>
#include <stdexcept>

namespace gslcpp::exception
{
    void gsl_errno_to_exception(const int gsl_errno);

    struct gslcpp_exception : public std::exception {
        const char* what() const throw()
        {
            return "Generic gslcpp exception.";
        };
    };

    struct failure : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Failure.";
        };
    };

    struct domain_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Input domain error.";
        };
    };

    struct range_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Output domain error.";
        };
    };

    struct invalid_pointer : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Invalid pointer.";
        };
    };

    struct invalid_argument : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Invalid argument supplied by user.";
        };
    };

    struct factorization_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Factorization failed.";
        };
    };

    struct sanity_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Sanity check failed. This shouldn't happen.";
        };
    };

    struct bad_alloc : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Malloc failed.";
        };
    };

    struct bad_function_call : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Problem with user-supplied function.";
        };
    };

    struct runaway_argument : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Iterative process is out of control.";
        };
    };

    struct max_iteration_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Exeeded max number of iterations.";
        };
    };

    struct zero_devision : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Tried to divide by zero.";
        };
    };

    struct bad_tolerance : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Specified tolerance is invalid or theoretically unattainable.";
        };
    };

    struct tolerance_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Failed to reach the specified tolerance.";
        };
    };

    struct underflow_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Underflow";
        };
    };

    struct overflow_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Overflow";
        };
    };

    struct accuracy_loss : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Loss of accuracy.";
        };
    };

    struct roundoff_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Roundoff error";
        };
    };

    struct dimension_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Matrix/vector sizes are not conformant.";
        };
    };

    struct square_matrix_error : dimension_error {
        const char* what() const throw()
        {
            return "Matrix is not square.";
        };
    };

    struct singularity_error : gslcpp_exception {
        const char* what() const throw()
        {
            return "Singularity or extremely bad function behavior detected.";
        };
    };

    struct divergens_error : gslcpp_exception {
        const char* what() const throw()
        {
            return "Integral or series is divergent.";
        };
    };

    struct unsuproted_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "The required feature is not supported by this hardware platform.";
        };
    };

    struct unimplemented_error : gslcpp_exception {
        const char* what() const throw()
        {
            return "The requested feature is not (yet) implemented.";
        };
    };

    struct cache_error : gslcpp_exception {
        const char* what() const throw()
        {
            return "Cache limit exceeded.";
        };
    };

    struct table_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Table limit exceeded.";
        };
    };

    struct progress_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Iteration is not making progress towards solution.";
        };
    };

    struct jacobian_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "Jacobian evaluations are not improving the solution.";
        };
    };

    struct tolerance_f_error : public tolerance_error {
        const char* what() const throw()
        {
            return "Cannot reach the specified tolerance in F.";
        };
    };

    struct tolerance_x_error : public tolerance_error {
        const char* what() const throw()
        {
            return "Cannot reach the specified tolerance in X.";
        };
    };

    struct tolerance_gradient_error : public tolerance_error {
        const char* what() const throw()
        {
            return "Cannot reach the specified tolerance in gradient.";
        };
    };

    struct eof_error : public gslcpp_exception {
        const char* what() const throw()
        {
            return "end of file";
        };
    };
} // namespace gslcpp::exception
