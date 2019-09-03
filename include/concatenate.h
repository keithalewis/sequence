// concatenate.h - concatenate two sequence
#pragma once
#include <compare>

namespace fms::sequence {

    template<class I, class J>
    class concatenate {
        I i;
        J j;
    public:
        concatenate(I i, J j)
            : i(i), j(j)
        { }
        const auto operator<=>(const concatenate&) const = default;
        operator bool() const
        {
            return i || j;
        }
        auto operator*() const
        {
            return i ? *i : *j;
        }
        concatenate& operator++()
        {
            i ? ++i : ++j;

            return *this;
        }

    };

}

template<class I, class J>
inline auto operator,(I i, J j)
{
    return concatenate(i, j);
}