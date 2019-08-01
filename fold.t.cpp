// fold.t.cpp - test fold
#include <cassert>
#include "counted.h"
#include "fold.h"

using namespace fms::sequence;

int test_sum()
{
    int i[] = { 1, 2, 3};
    auto ci = counted(i, 3);
    assert(6 == foldr(std::plus{}, ci, 0));
    assert(6 == sum(ci));
    assert(3 == sum(counted(i, 2)));
    assert(1 == sum(counted(i, 1)));
    assert(0 == sum(counted(i, 0)));

    return 0;
}
int test_product()
{
    int i[] = { 1, 2, 3 };
    auto ci = counted(i, 3);
    assert(6 == foldr(std::multiplies{}, ci, 1));
    assert(6 == product(ci));
    assert(2 == product(counted(i, 2)));
    assert(1 == product(counted(i, 1)));
    assert(1 == product(counted(i, 0)));

    return 0;
}

int test_sum_ = test_sum();
int test_product_ = test_product();