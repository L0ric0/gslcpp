// global
#include <cmath>
#include <concepts>

template <std::floating_point T>
bool isposinf(const T x)
{
    return (std::isinf(x) and x > 0);
}

template <std::floating_point T>
bool isneginf(const T x)
{
    return (std::isinf(x) and x > 0);
}
