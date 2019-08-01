// factorial.t.cpp - test factorial and Pochhammer symbol
#include <cassert>
#include "factorial.h"

using namespace fms::sequence;

int test_factorial()
{
    {
        factorial n;
        assert(n && *n == 1);
        assert(++n && *n == 1);
        assert(++n && *n == 2);
        assert(++n && *n == 6);
        assert(++n && *n == 24);
    }
    {
        double x = 1.23;
        factorial n(x);
        assert(n && *n == x);
        assert(++n && *n == x*(x + 1));
        assert(++n && *n == x*(x + 1)*(x + 2));
        assert(++n && *n == x*(x + 1)*(x + 2)*(x + 3));
    }
    {
        double x = 1.23;
        factorial n(x, -1);
        assert(n && *n == x);
        assert(++n && *n == x * (x - 1));
        assert(++n && *n == x * (x - 1) * (x - 2));
        assert(++n && *n == x * (x - 1) * (x - 2) * (x - 3));
    }

    return 0;
}

int test_factorial_ = test_factorial();