// binop.h - binary operators on sequences
#pragma once
#include <compare>

namespace fms::sequence {

    template<class Op, class I, class J>
    class binop {
        inline static Op op = Op{};
        I i;
        J j;
    public:
        binop(I i, J j)
            : i(i), j(j)
        { }
        const auto operator<=>(const binop&) const = default;
        operator bool() const
        {
            return i && j;
        }
        auto operator*() const
        {
            return op(*i, *j);
        }
        binop& operator++()
        {
            ++i;
            ++j;

            return *this;
        }

    };

}

template<class I, class J>
inline auto operator+(I i, J j)
{
    using T = std::common_type_t<decltype(*i), decltype(*j)>;

    return binop<std::plus<T>, I, J>(i, j);
}
template<class I, class J>
inline auto operator-(I i, J j)
{
    using T = std::common_type_t<decltype(*i), decltype(*j)>;

    return binop<std::minus<T>, I, J>(i, j);
}
template<class I, class J>
inline auto operator*(I i, J j)
{
    using T = std::common_type_t<decltype(*i), decltype(*j)>;

    return binop<std::multiplies<T>, I, J>(i, j);
}
template<class I, class J>
inline auto operator/(I i, J j)
{
    using T = std::common_type_t<decltype(*i), decltype(*j)>;

    return binop<std::divides<T>, I, J>(i, j);
}