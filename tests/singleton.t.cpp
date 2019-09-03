#include <cassert>
#include "singleton.h"

using namespace fms::sequence;

int test_singleton()
{
    auto s = singleton(2);
    assert(s);
    assert(*s == 2);
    assert(!++s);

    return 0;
}

int test_singleton_ = test_singleton();