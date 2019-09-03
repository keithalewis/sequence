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
        // compare remaining elements of two tuples
        const int operator<=>(const tuple& t) const
        {
            size_t n;
            for (n = 0; n + i < size() && n + t.i < t.size(); ++n) {
                if (a[n + i] < t.a[n + t.i])
                    return -1;
                if (a[n + i] > t.a[n + t.i])
                    return 1;
            }

            if (n + i == size() && n + t.i == t.size())
                return 0;
            if (n + i == size())
                return -1;

            return 1; // n + t.i == t.size();
        }
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
