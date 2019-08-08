// fmap.t.cpp - test fmap
#include <cassert>
#include "array.h"
#include "fmap.h"

using namespace fms::sequence;

int sq(int i)
{
    return i * i;
}
int test_fmap()
{
    int i[] = { 1, 2, 3 };
    {
        auto f = fmap([](int i) { return i * i; }, array(i));
        assert(f);
        assert(*f == 1);
        assert(*++f == 4);
        assert(*++f == 9);
        assert(!++f);
    }
    {
        auto f = fmap(sq, array(i));
        assert(f);
        assert(*f == 1);
        assert(*++f == 4);
        assert(*++f == 9);
        assert(!++f);
    }
    {
        auto sq = [](int i) { return i * i; };
        auto f = fmap(sq, array(i));
        assert(f);
        assert(*f == 1);
        assert(*++f == 4);
        assert(*++f == 9);
        assert(!++f);
    }

    return 0;
}

#include "fmap.h"
#include "scan.h"
#include "take.h"

int test_select_many()
{
    // {0,...,i-1}
    auto f = [](int i) { return take(i, arithmetic(0)); };
    // {0,1,2} -> {{}, {0}, {0,1}}
    auto ii = fmap(f, f(3));
    
    assert(ii);
    auto i0 = *ii;
    assert(!i0);

    auto i1 = *++ii;
    assert(i1);
    assert(*i1 == 0);
    assert(!++i1);

    auto i2 = *++ii;
    assert(*i2 == 0);
    assert(*++i2 == 1);
    assert(!++i2);
    assert(!++ii);
    
    return 0;
}

int test_fmap_ = test_fmap();
int test_select_many_ = test_select_many();