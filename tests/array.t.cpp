// array.t.cpp - test array sequence
#include <cassert>
#include "array.h"

using namespace fms::sequence;

int test_array()
{
    {
        int i[] = { 1, 2, 3 };
        auto s = array(i);
        assert(s.size() == 3);
        assert(s);
        assert(*s == 1);
        ++s;
        ++s;
        assert(*s == 3);
        assert(!++s);
    }

    return 0;
}

int test_array_ = test_array();