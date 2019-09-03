// merge.h
#pragma once
#include "flatten.h"
#include "zip.h"

namespace fms::sequence {

    template<class S, class T>
    inline auto merge(S s, T t)
    {
        return flatten(zip(s, t));
        //return s ? l : cons(*s, merge(l, ++s));
    }

}
