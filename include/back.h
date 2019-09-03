// back.h - last element of sequence
#pragma once

namespace fms::sequence {

    template<class S>
    auto back(S s)
    {
        auto t = *s;
        while (s) {
            t = *s;
            ++s;
        }

        return t;
    }

}