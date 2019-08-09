#include <cassert>
#include "tuple.h"
#include "constant.h"
#include "zip.h"

using namespace fms::sequence;

int test_zip()
{
    auto z = zip(constant(0), tuple({1, 2, 3 }));
    assert(z);
    auto p = *z;
    assert(p);
    assert(*p == 0);
    assert(*++p == 1);
    assert(!++p);
    
    ++z;
    assert(z);
    p = *z;
    assert(p);
    assert(*p == 0);
    assert(*++p == 2);
    assert(!++p);

    ++z;
    assert(z);
    p = *z;
    assert(p);
    assert(*p == 0);
    assert(*++p == 3);
    assert(!++p);

    assert(!++z);

    return 0;
}

int test_zip_ = test_zip();