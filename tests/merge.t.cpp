#include <cassert>
#include "merge.h"
#include "tuple.h"

using namespace fms::sequence;

int test_merge()
{
    auto m = merge(tuple{ 1, 2 }, tuple{ 3, 4 });
    assert(m);
    assert(*m == 1);
    assert(*++m == 3);
    assert(*++m == 2);
    assert(*++m == 4);
    assert(!++m);

    return 0;
}

//int test_merge_ = test_merge();
