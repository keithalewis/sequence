// merge.h
#pragma once
#include "cons.h"

namespace fms::sequence {

    template<class S>
    inline S merge(S s, S l)
    {
        return s ? l : cons(*s, merge(l, ++s));
    }

}
