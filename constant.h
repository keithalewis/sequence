// constant.h - constant sequence
#pragma once

#include <compare>

namespace fms::sequence {
    template<class T = double>
    class constant {
        T c;
    public:
        constant(T c)
            : c(c)
        { }
        const auto operator<=>(const constant&) const = default;
        operator bool() const
        {
            return true;
        }
        T operator*() const
        {
            return c;
        }
        constant& operator++()
        {
            return *this;
        }

    };
}

