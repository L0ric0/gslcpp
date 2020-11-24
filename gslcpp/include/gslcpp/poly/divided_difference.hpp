#pragma once

//stllib
#include <vector>

namespace gslcpp::polynomial
{
    class DividedDifference
    {
      public:
        DividedDifference(const std::vector<double>& xa, const std::vector<double>& ya);
        DividedDifference(
            const std::vector<double>& xa,
            const std::vector<double>& ya,
            const std::vector<double>& dya);

        double operator()(const double x) const;

        std::vector<double> to_taylor(const double xp) const;

      private:
        std::vector<double> m_dd;
        std::vector<double> m_xa;
    };
} // namespace gslcpp::polynomial