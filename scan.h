// scan.h - accumulate a sequence using a binary operator
#pragma once
#include <functional>
#include "sequence.h"

namespace seq {

	template<class Op, class S, class T = std::iterator_traits<S>::value_type>
	class scan : public S
	{
		static T op(const T& u, const T& v)
		{
			static Op op_;

			return op_(u, v);
		}
		T t;
	public:
		scan(S s, T t)
			: S(s), t(t + s ? *s : 0)
		{ }

		bool operator==(const scan& s) const
		{
			return S::operator==(s) && t == s.t;
		}
		bool operator!=(const scan& s) const
		{
			return !operator==(s);
		}

		T operator*() const
		{
			return t;
		}
		scan& operator++()
		{
			t = op(t, *S::operator++());

			return *this;
		}
		scan operator++(int)
		{
			auto s(*this);

			scan::operator++();

			return s;
		}
	};
	template<class Op, class S, class T = std::iterator_traits<S>::value_type>
	inline auto make_scan(S s, T t)
	{
		return scan<Op,S,T>(s, t);
	}
	template<class S, class T = std::iterator_traits<S>::value_type>
	inline auto sum(S s, T t = 0)
	{
		return make_scan<std::plus<T>,S,T>(s, t);
	}
}

#ifdef _DEBUG
#include <cassert>

inline void test_scan()
{
	int i[] = {1,2,3};
	auto s = seq::sum(seq::make_sequence(i));
	auto s2(s);
	s = s2;
	assert (s == s2);
	assert (!(s != s2));
	assert (*s == 1);
	assert (*++s == 3);
	s++;
	assert (*s == 6);

}

#endif // _DEBUG