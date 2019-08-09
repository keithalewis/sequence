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

#include "tuple.h"

int test_pythagorean()
{
    // {i, i + 1, ..., j - 1}
    auto interval = [](int i, int j) { return take(j - i, arithmetic(i)); };
    // {2, 3, 4, ... }
    auto i = arithmetic(2);
    // n -> {{2,n},{3,n},...,{n,n}}
    auto q = [](int j) { return [](int i) { return tuple({ i, 3 }); }; };
    auto p = fmap([&q](int k) { return q(k); }, i);
    //auto a = p(5);
    //auto p = [](int i) { return [i](int j) { return tuple({ i, j }); };
    //auto i2 = p(3);
    //auto i2 = [](int n) { return fmap([n](int i) { return pair(i, n); }, interval(2, n));
    //auto f = [](int n) { return fmap([n](int i) { return pair(i, n); }, interval(2, n)); };
    //auto f = [&i](int n) { return fmap([n](int j) { return tuple({ j, n }); }, i); };
    // {{{2,2}}, {{2,3},{3,3}}, {{2,4},{3,4},{4,4}}, ...
    //auto j = fmap([](int n) { return vector({ n, n }); };
    
    return 0;
}

int test_fmap_ = test_fmap();
int test_select_many_ = test_select_many();
int test_pythagorean_ = test_pythagorean();