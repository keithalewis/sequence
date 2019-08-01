// scan.h - fold sequence
#pragma once
#include <compare>
#include <functional>

namespace fms::sequence {
    template<class Op, class I, class T>
    class fold {
        inline static Op op = Op{};
        I i;
        T i0;
    public:
        fold(I i, T i0)
            : i(i), i0(i0)
        { }
        const auto operator<=>(const fold&) const = default;
        operator bool() const
        {
            return i;
        }
        T operator*() const
        {
            return i0;
        }
        fold& operator++()
        {
            if (i) {
                i0 = op(i0, *i);
            }

            return *this;
        }

    };
    
    template<class I>
    inline auto scan(I i)
    {
        using T = decltype(*i);

        return fold<std::plus<T>,I,T>(i, T(0));
    }

    template<class T = double>
    inline auto arithmetic(T t0 = 0, T dt = 1)
    {
        return fold<std::plus<T>,constant<T>,T>(constant(dt), t0);
    }
}

