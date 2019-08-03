// drop.h - drop items from a sequence
#pragma once
#include "array.h"
#include "counted.h"

namespace fms::sequence {

	template<class S>
	inline auto drop(size_t n, S s)
	{
        while (s && n--)
            ++s;
			
		return s;
	}

}
