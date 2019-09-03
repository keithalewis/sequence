// pointer.h - convert pointer to a (unsafe) sequence
#pragma once
#include <compare>

namespace fms::sequence {

    template<class T>
    class pointer {
        const T* a;
        size_t i;
    public:
        pointer(const T* a)
            : a(a), i(0)
        { }
        const auto operator<=>(const pointer&) const = default;
        operator bool() const
        {
            return true; // unchecked!!!
        }
        auto operator*() const
        {
            return a[i];
        }
        pointer& operator++()
        {
            ++i;

            return *this;
        }
    };

}