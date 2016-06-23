// null_sequence.h - null terminated sequence
#pragma once

namespace seq {

	template<class I>
	struct null_sequence : public sequence<I>
	{
		null_sequence(I i)
		: sequence(i)
		{ }

		bool operator_bool() const
		{
			return *i != 0;
		}
	};

	template<class I>
	inline auto make_null_sequence(I i)
	{
		return null_sequence<I>(i);
	}

}

#ifdef _DEBUG
#include <cassert>

inline void test_null_sequence()
{
	char* abc = "abc";
	auto s = seq::make_null_sequence(abc); 
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