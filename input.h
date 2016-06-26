// input.h - sequence satisfying input iterator properties
#pragma once
#include <iterator>

namespace sequence {

	template<class I, class T = typename std::iterator_traits<I>::value_type>
	class input : public std::iterator<std::input_iterator_tag, T> // ...
	{
	protected:
		I i;
	public:
		input(I i)
			: i(i)
		{ }
		// NVI idiom
		operator bool() const
		{
			return operator_bool();
		}
		// The following can be overridden.
		bool operator==(const input& s) const
		{
			return i == s.i;
		}
		bool operator!=(const input& s) const
		{
			return !operator==(s);
		}
		const T& operator*() const
		{
			return *i;
		}
		T& operator*()
		{
			return *i;
		}
		input& operator++()
		{
			++i;

			return *this;
		}
		input operator++(int)
		{
			return input(i++);
		}
	private:
		virtual bool operator_bool() const
		{
			return true;
		}
	};
	
	template<class I>
	inline auto make_input(I i)
	{
		return input<I>(i);
	}
}

#ifdef _DEBUG
#include <cassert>

inline void test_input()
{
	int i[] = {1,2,3};
	auto s = sequence::make_input(i);
	auto s2(s);
	s = s2;

	assert (s == s2);
	assert (!(s != s2));
	
	assert (s);
	assert (s2);
	assert (*s == 1);
	assert (*++s == 2);
	s++;
	assert (*s == 3);
	assert (++s); // always true
}

#endif // _DEBUG