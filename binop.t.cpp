// binop.t.cpp - binary operators
#include <cassert>
#include <cmath>
#include "binop.h"
#include "epsilon.h"
#include "factorial.h"
#include "fold.h"
#include "length.h"
#include "power.h"

using namespace fms::sequence;

int test_binop()
{
    factorial n;
    auto n2 = n + n;
    assert(*n2 == 2);
    ++n2;
    assert(*n2 == 2);
    ++n2;
    assert(*n2 == 4);
    {
        double x = 1;
        auto s = epsilon(power(x) / factorial());
        auto e = sum(s);
        size_t n = length(s);
        double ex = exp(x);
        double delta = e - ex;
        assert(delta == 2 * std::numeric_limits<double>::epsilon());
    }

    return 0;
}

int test_binop_ = test_binop();