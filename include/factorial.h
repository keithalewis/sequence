// factorial.h - factorial and Pochhammer symbols
#pragma once
#include <compare>

namespace fms::sequence {

    template<class T = double>
    class factorial {
        T x, x_;
        long n;
    public:
        factorial(T x = 0, long n = 1)
            : x(x), x_(x), n(n)
        { }
        const auto operator<=>(const factorial&) const = default;
        operator bool() const
        {
            return true;
        }
        T operator*() const
        {
            return x_ == 0 ? 1 : x_;
        }
        factorial& operator++()
        {
            if (x == 0) {
                x = x_ = 1;
            }
            else {
                x_ *= (x + n);
                n > 0 ? ++n : --n;
            }

            return *this;
        }

    };

}
