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
        // exp(x) = sum_0^infty x^n/n!
        auto expx = power(x) / factorial();
        // stop when terms are less than machine epsilon
        auto e = sum(epsilon(expx));
        // how many terms are required?
        size_t n = length(epsilon(expx));
        assert(n == 18);
        double ex = exp(x);
        double delta = e - ex;
        assert(delta == 2 * std::numeric_limits<double>::epsilon());
    }

    return 0;
}

int test_binop_ = test_binop();