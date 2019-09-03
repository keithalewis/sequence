#pragma once
#include "concatenate.h"
#include "singleton.h"

namespace fms::sequence {

    template<class T, class S>
    inline auto cons(T t, S s)
    {
        return concatenate(singleton(t), s);
    }

}