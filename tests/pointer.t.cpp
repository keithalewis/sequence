#include <cassert>
#include "pointer.h"
#include "take.h"

using namespace fms::sequence;

int test_pointer()
{

    int i[] = { 1, 2, 3 };
    {
        auto s = pointer(i);
        assert(s);
        assert(*s == 1);
        ++s;
        ++s;
        assert(*s == 3);
        assert(++s);
    }
    {
        auto s = take(3, pointer(i));
        assert(s);
        assert(*s == 1);
        ++s;
        ++s;
        assert(*s == 3);
        assert(!++s);
    }

    return 0;
}

int test_pointer_ = test_pointer();