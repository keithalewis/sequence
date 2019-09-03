// power.h - 1, x, x^2, ...
#pragma once
#include <compare>

namespace fms::sequence {
    template<class T = double>
    class power {
        T x, xn;
    public:
        power(T x, T xn = 1)
            : x(x), xn(xn)
        { }
        const auto operator<=>(const power&) const = default;
        operator bool() const
        {
            return true;
        }
        T operator*() const
        {
            return xn;
        }
        power& operator++()
        {
            xn *= x;

            return *this;
        }

    };
}
