#include <cassert>
#include "cartesian.h"

using namespace fms::sequence;

int test_cartesian()
{
    auto a = tuple({ 1, 2 });
    auto b = tuple({ 3, 4, 5 });

    //auto c = cartesian(a, b);
    //auto i = *c;

    return 0;
}

int test_cartesian_ = test_cartesian();