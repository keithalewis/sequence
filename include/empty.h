#pragma once

namespace fms::sequence {

    template<class I>
    struct empty {
        operator bool() const
        {
            return false;
        }
    };

}