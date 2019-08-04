// singleton.h - sequence having one item
#pragma once
#include <compare>

namespace fms::sequence {

    template<class T>
    class singleton {
        T t;
        bool done;
    public:
        singleton(T t)
            : t(t), done(false)
        { }
        const auto operator<=>(const singleton&) const = default;
        operator bool() const
        {
            return !done;
        }
        T operator*() const
        {
            return t;
        }
        singleton& operator++()
        {
            done = true;

            return *this;
        }
    };

}
