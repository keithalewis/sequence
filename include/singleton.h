// singleton.h - sequence having one item
#pragma once
#include <compare>
#include "constant.h"
#include "take.h"

namespace fms::sequence {

    template<class T>
    inline auto singleton(T t)
    {
        return take(1, constant(t));
    }

}
