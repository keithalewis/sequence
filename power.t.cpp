// power.t.cpp - test power
#include <cassert>
#include "power.h"

using namespace fms::sequence;

int test_power()
{
    {
        power p(2);
        assert(*p == 1);
        assert(*++p == 2);
        assert(*++p == 4);
        assert(*++p == 8);
    }
    {
        power p(2,3);
        assert(*p == 3);
        assert(*++p == 6);
        assert(*++p == 12);
        assert(*++p == 24);
    }

    return 0;
}

int test_power_ = test_power();