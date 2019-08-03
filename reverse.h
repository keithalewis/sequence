// reverse.h - reverse sequence if they have operator--()
#pragma once
#include <compare>

namespace fms::sequence {

    template<class I>
    class reverse {
        I i;
    public:
        // Constructor should be the last element of the sequence, not one past the end.
        reverse(I i)
            : i(i)
        { }
        const auto operator<=>(const reverse&) const = default;
        operator bool() const
        {
            return true; // unchecked!!!
        }
        auto operator*() const
        {
            return *i;
        }
        reverse& operator++()
        {
            --i;

            return *this;
        }
    };

}
