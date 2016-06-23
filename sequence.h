#pragma once
#include <iterator>

namespace seq {

	template<class I, class T = typename std::iterator_traits<I>::value_type>
	class sequence : public std::iterator<std::input_iterator_tag, T> // ...
	{
	protected:
		I i;
	public:
		// use super class input iterator functions
		sequence(I i)
			: i(i)
		{ }
		// NVI idiom
		operator bool() const
		{
			return operator_bool();
		}
		// The following can be overridden.
		bool operator==(const sequence& s) const
		{
			return i == s.i;
		}
		bool operator!=(const sequence& s) const
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
		sequence& operator++()
		{
			++i;

			return *this;
		}
		sequence operator++(int)
		{
			return sequence(i++);
		}
	private:
		virtual bool operator_bool() const
		{
			return true;
		}
	};
	
	template<class I>
	inline auto make_sequence(I i)
	{
		return sequence<I>(i);
	}
}

#ifdef _DEBUG
#include <cassert>

inline void test_sequence()
{
	int i[] = {1,2,3};
	auto s = seq::make_sequence(i);
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