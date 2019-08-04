// vector.h - sequence backed by a vector
#pragma once
#include <compare>
#include <vector>

namespace fms::sequence {

    template<class T, size_t N>
    class vector {
        std::vector<T> a;
        size_t i;
    public:
        vector(size_t n = 0)
            : a(n), i(0)
        { }
        size_t size() const
        {
            return a.size();
        }
        vector& push_back(T t)
        {
            a.push_back();

            return *this;
        }
        const auto operator<=>(const vector&) const = default;
        operator bool() const
        {
            return i < size();
        }
        auto operator*() const
        {
            return a[i];
        }
        vector& operator++()
        {
            if (operator bool())
                ++i;

            return *this;
        }
        vector& operator--()
        {
            if (i > 0)
                --i;

            return *this;
        }
    };

}
