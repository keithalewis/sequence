// tuple.h - sequence backed by a tuple
#pragma once
#include <compare>
#include <initializer_list>
#include <vector>

namespace fms::sequence {

    template<class T>
    class tuple {
        std::vector<T> a;
        size_t i;
    public:
        tuple(size_t n = 0)
            : a(n), i(0)
        { }
        // Turn a tuple into a sequence
        tuple(std::initializer_list<T> l)
            : a(l.begin(), l.end()), i(0)
        { }
        size_t size() const
        {
            return a.size();
        }
        tuple& push_back(T t)
        {
            a.push_back();

            return *this;
        }
        const auto operator<=>(const tuple&) const = default;
        operator bool() const
        {
            return i < size();
        }
        auto operator*() const
        {
            return a[i];
        }
        tuple& operator++()
        {
            if (operator bool())
                ++i;

            return *this;
        }
        tuple& operator--()
        {
            if (i > 0)
                --i;

            return *this;
        }
    };

}
