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

int test_fmap_ = test_fmap();