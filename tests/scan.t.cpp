// scan.t.cpp - test scan
#include <cassert>
#include "constant.h"
#include "scan.h"

using namespace fms::sequence;

int test_scan()
{
    auto c = constant(1);
    auto s = scan(c);
    assert(*s == 0);
    assert(*++s == 1);
    assert(*++s == 2);
    assert(*++s == 3);
    assert(*++s == 4);

    auto a = arithmetic(2, 3);
    assert(*a == 2);
    assert(*++a == 5);
    assert(*++a == 8);

    return 0;
}

int test_scan_ = test_scan();