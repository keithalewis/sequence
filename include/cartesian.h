// cartesian.h - Cartesian product
// https://stackoverflow.com/questions/759554/how-to-express-2n3m1n-m%e2%88%88n-in-list-comprehension-form-n-is-the-set-of-natu
#pragma once
#include <functional>
#include "cons.h"
#include "fmap.h"
#include "merge.h"
#include "tuple.h"

namespace fms::sequence {

    /*
    template<class I, class J>
    inline auto cartesian(I i, J j)
    {
        if (!i)
            return tuple({ *i, *j });

        auto l = fmap([i](auto _j) { return tuple({ *i, _j }); }, j);

        return l;
        return cons(tuple({ *i, *j }), 
            merge(fmap([i](auto _j) { return tuple({ *i, _j }); }, j),
                merge(fmap([j](auto _i) { return tuple({ _i, *j }); }, i),
                    cartesian(++i, ++j))));
    }
*/
}