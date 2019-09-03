#include <cassert>
#include "take.h"
#include "reverse.h"

using namespace fms::sequence;

int test_reverse()
{
    int i[] = { 1, 2, 3 };
    auto a = take(3, reverse(i + 2));
    assert(a);
    assert(*a == 3);
    ++a;
    assert(a);
    assert(*a == 2);
    assert(*++a == 1);
    assert(!++a);

    return 0;
}

int test_reverse_ = test_reverse();