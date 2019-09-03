// counted.h - counted sequence
#pragma once
#include <compare>

namespace fms::sequence {

    template<class I>
    class counted {
        I i;
        size_t n;
    public:
        counted(I i, size_t n = 0)
            : i(i), n(n)
        { }
        size_t size() const
        {
            return n;
        }
        const auto operator<=>(const counted&) const = default;
        operator bool() const
        {
            return n != 0;
        }
        auto operator*() const
        {
            return *i;
        }
        counted& operator++()
        {
            if (operator bool()) {
                ++i;
                --n;
            }

            return *this;
        }

    };

}
