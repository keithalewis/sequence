// array.h - convert an array to a sequence
#pragma once
#include <compare>

namespace fms::sequence {

    template<class T, size_t N>
    class array {
        const T* a;
        size_t i;
    public:
        array(T(&a)[N])
            : a(&a[0]), i(0)
        { }
        size_t size() const
        {
            return N;
        }
        const auto operator<=>(const array&) const = default;
        operator bool() const
        {
            return i < N;
        }
        auto operator*() const
        {
            return a[i];
        }
        array& operator++()
        {
            if (operator bool())
                ++i;

            return *this;
        }
    };
 
}
