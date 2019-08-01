// epsilon.h - terminate at machine epsilon
#pragma once

namespace fms::sequence {

    // machine epsilon terminated sequence
    template<class I>
    class epsilon {
        I i;
    public:
        epsilon(I i)
            : i(i)
        { }
        const auto operator<=>(const epsilon&) const = default;
        operator bool() const
        {
            using T = decltype(*i);

            return *i + T(1) != T(1);
        }
        auto operator*() const
        {
            return *i;
        }
        epsilon& operator++()
        {
            operator bool() && ++i;

            return *this;
        }
    };

}
