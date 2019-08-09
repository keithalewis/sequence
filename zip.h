#pragma once
#include <compare>
#include "tuple.h"

namespace fms::sequence {

    template<class I, class J>
    class zip {
        I i;
        J j;
    public:
        zip(I i, J j)
            : i(i), j(j)
        { }
        const auto operator<=>(const zip&) const = default;
        operator bool() const
        {
            return i && j;
        }
        auto operator*() const
        {
            return tuple({ *i, *j });
        }
        zip& operator++()
        {
            ++i;
            ++j;

            return *this;
        }
    };

}