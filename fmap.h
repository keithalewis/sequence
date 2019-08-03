// fmap.h - map a functor over a sequence
#pragma once
#include <compare>
#include <functional>

namespace fms::sequence {
    template<class F, class I>
    class fmap {
        F f;
        I i;
    public:
        fmap(F f, I i)
            : f(f), i(i)
        { }
        const auto operator<=>(const fmap&) const = default;
        operator bool() const
        {
            return i;
        }
        auto operator*() const
        {
            return f(*i);
        }
        fmap& operator++()
        {
            ++i;

            return *this;
        }

    };
}