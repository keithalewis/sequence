// flatten.h - convert sequence of sequences to a sequence
#pragma once
//#include <compare>

namespace fms::sequence {

    // {{a,b,...},{c,d,...}...} => {a,b,...,c,d,...}
    template<class II>
    class flatten {
        II ii;
    public:
        flatten(II ii)
            : ii(ii)
        { }
        //const auto operator<=>(const flatten&) const = default;
        operator bool() const
        {
            return ii;
        }
        auto operator*() const
        {
            return **ii;
        }
        flatten& operator++()
        {
            if (ii) {
                if (*ii)
                    ++*ii;
                else
                    ++ii;
            }

            return *this;
        }

    };

}
