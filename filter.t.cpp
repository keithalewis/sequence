#include <cassert>
#include "array.h"
#include "filter.h"

using namespace fms::sequence;

int test_filter()
{
    int i[] = { 0, 1, 2, 3 };
    auto even = [](int i) { return i % 2 == 0; };
    auto f = filter(even, array(i));
    assert(f);
    assert(*f == 0);
    assert(++f);
    assert(*f == 2);
    assert(!++f);

    return 0;
}

int test_filter_ = test_filter();