// drop.h - drop items from a sequence
#pragma once

namespace fms::sequence {

	template<class S>
	inline auto drop(size_t n, S s)
	{
        while (s && n--)
            ++s;
			
		return s;
	}

}
