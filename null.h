// null.h - null terminated sequence
#pragma once
#include "sequence.h"

namespace sequence {

	template<class I>
	struct null : public iterator<I>
	{
		using iterator<I>::i;

		null(I i)
		: iterator<I>(i)
		{ }

		bool operator_bool() const override
		{
			return *i != 0;
		}
	};

	template<class I>
	inline auto make_null(I i)
	{
		return null<I>(i);
	}

}

#ifdef _DEBUG
#include <cassert>

inline void test_null()
{
	const char* abc = "abc";
	auto s = sequence::make_null(abc); 
	auto s2(s);
	s = s2;

	assert (s == s2);
	assert (!(s != s2));

	assert (s);
	assert (!!s);		
	assert (*s == 'a');
	assert (*++s == 'b');
	s++;
	assert (*s == 'c');
	assert (s);
	assert (!++s);
}

#endif // _DEBUG