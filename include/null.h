// null.h - null terminated sequence
#pragma once
#include <compare>

namespace fms::sequence {

    template<class I>
    class null {
        I i;
    public:
        null(I i)
            : i(i)
        { }
        const auto operator<=>(const null&) const = default;
        operator bool() const
        {
            return *i != 0;
        }
        const auto& operator*() const
        {
            return *i;
        }
        null& operator++()
        {
            if (operator bool())
                ++i;

            return *this;
        }
    };

}