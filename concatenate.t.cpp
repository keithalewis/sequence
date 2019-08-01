// concatenate.t.cpp - test concatenate
#include <cassert>
#include "concatenate.h"
#include "take.h"

using namespace fms::sequence;

int test_concatenate()
{
    int i[] = { 1, 2, 3 };
    {
        auto ii = concatenate(take(2, i), take(3, i));
        assert(*ii == 1);
        assert(*++ii == 2);
        assert(*++ii == 1);
        assert(*++ii == 2);
        assert(*++ii == 3);
        assert(!++ii);
    }
    {
        auto ii = (take(2, i), take(3, i));
        assert(*ii == 1);
        assert(*++ii == 2);
        assert(*++ii == 1);
        assert(*++ii == 2);
        assert(*++ii == 3);
        assert(!++ii);
    }

    return 0;
}

int test_concatenate_ = test_concatenate();
