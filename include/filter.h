// filter.h - filter sequence using a predicate
#pragma once

namespace fms::sequence {

    template<class P, class S>
    class filter {
        P p;
        S s;
    public:
        filter(P p, S s)
            : p(p), s(s)
        {
            while (s && !p(*s))
                ++s;
        }
        operator bool() const
        {
            return s;
        }
        auto operator*() const
        {
                return *s;
        }
        filter& operator++()
        {
            while (++s && !p(*s))
                ;

            return *this;
        }
    };

}
