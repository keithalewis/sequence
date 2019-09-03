#include <cassert>
#include "flatten.h"
#include "pointer.h"
#include "take.h"
#include "zip.h"

using namespace fms::sequence;

int test_flatten()
{
    int p[] = { 1, 2, 3 };
    auto z = zip(take(1,pointer(p)), take(2,pointer(p)));
    auto f = flatten(z);
    assert(f);
    int i = *f;
    assert(i == 1);
    i = *++f;
    assert(i == 2);
    //assert(*f == 1);
    //assert(*++f == 4);

    return 0;
}

//static int test_flatten_ = test_flatten();