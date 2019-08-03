// counted.t.cpp - counted sequences
#include <cassert>
#include "counted.h"

using namespace fms::sequence;

int test_counted() 
{
    int i[] = { 1, 2, 3 };

    {
        auto ci = counted(i, 3);
        assert(ci.size() == 3);
        auto ci2{ ci };
        assert(ci2 == ci);
        ci = ci2;
        assert(!(ci2 != ci));
        assert(ci && *ci == 1);
        assert(++ci && *ci == 2);
        assert(++ci && *ci == 3);
        assert(!++ci);
    }

    return 0;
}

int test_counted_ = test_counted();