#include <cassert>
#include "drop.h"
#include "tuple.h"

using namespace fms::sequence;

int test_drop()
{
    auto s = tuple({ 1, 2, 3 });
    auto d = drop(2, s);
    assert(d);
    assert(*d == 3);
    assert(!++d);

    return 0;
}
int test_drop_ = test_drop();