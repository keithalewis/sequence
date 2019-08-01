// take.h - take items from a sequence
#pragma once
#include "counted.h"

namespace fms::sequence {

    template<class S>
    inline auto take(size_t n, S s)
    {
        return counted(s, n);
    }

}

