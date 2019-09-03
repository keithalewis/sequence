// null.t.cpp - test null
#include <cassert>
#include "null.h"

using namespace fms::sequence;

int test_null() 
{
    {
        const char* abc = "abc";
        auto s = null(abc);
        auto s2(s);
        s = s2;

        assert(s == s2);
        assert(!(s != s2));

        assert(s);
        assert(!!s);
        assert(*s == 'a');
        assert(*++s == 'b');
        ++s;
        assert(*s == 'c');
        assert(s);
        assert(!++s);
    }
    {
        double t[] = { 1, 2, 0 };
        auto nt = null<double*>(t);
        assert(nt);
        assert(*nt == 1);
        ++nt;
        assert(nt);
        assert(*nt == 2);
        ++nt;
        assert(!nt);
    }
    {
        const char* s = "hi";
        null<const char*> ns(s);
        assert(ns);
        assert(*ns == 'h');
        ++ns;
        assert(ns);
        assert(*ns == 'i');
        ++ns;
        assert(!ns);

        return 0;
    }
}

int test_null_ = test_null();
