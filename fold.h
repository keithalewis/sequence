// scan.h - accumulate a sequence using a binary operator
#pragma once
#include <functional>

namespace fms::sequence {

    template<class Op, class I, class T = decltype(I::operator*())>
    inline T foldl(Op op, I i, T i0)
    {
        while (i) {
            i0 = op(*i, i0);
            ++i;
        }

        return i0;
    }

    template<class Op, class I, class T = decltype(I::operator*())>
    inline T foldr(Op op, I i, T i0)
    {
        while (i) {
            i0 = op(i0, *i);
            ++i;
        }

        return i0;
    }

    template<class I>
    inline auto sum(I i)
    {
        using T = decltype(*i);

        return foldr(std::plus<T>{}, i, T(0));
    }

    template<class I>
    inline auto product(I i)
    {
        using T = decltype(*i);

        return foldr(std::multiplies<T>{}, i, T(1));
    }

}