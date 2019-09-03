// length.h - length of a sequence
#pragma once
#include "counted.h"

namespace fms::sequence {

    template<class I>
    inline size_t length(I i)
    {
        size_t n = 0;

        while (++i)
            ++n;

        return n;
    }
    template<class I>
    inline size_t length(counted<I> i)
    {
        return i.size();
    }

}
