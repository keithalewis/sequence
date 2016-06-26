// skip.h - Skip along a sequence
#pragma once
#include "sequence.h"

namespace sequence {

	template<class S, typename N = std::iterator_traits<S>::difference_type>
	inline auto skip(N n, S s)
	{
		std::advance(s, n);
			
		return s;
	}

}

#ifdef _DEBUG
#include <cassert>
#include "sequence.h"

inline void test_skip()
{
	int i[] = {1,2,3};
	auto s = sequence::make_iterator(i);
	s = skip(0,s);
	assert (*s == 1);
	s = skip(1,s);
	assert (*s == 2);
	s = skip(-2, s);
}

#endif // _DEBUG