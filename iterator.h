// iterator.h - iterator with operator bool const
// see http://www.gotw.ca/publications/mill18.htm
#pragma once
#include <iterator>
#include <type_traits>

namespace sequence {

	template<class I, 
		class C = typename std::iterator_traits<I>::iterator_category,
		class T = typename std::iterator_traits<I>::value_type,
		class D = typename std::iterator_traits<I>::difference_type,
		class P = typename std::iterator_traits<I>::pointer,
		class R = typename std::iterator_traits<I>::reference
	>
	class iterator : public std::iterator<C, T, D, P, R>
	{
	protected:
		I i;
		// polymorphic delete not allowed
		// ~iterator() {}
	public:
		iterator(I i)
			: i(i)
		{ }
		// return true if iterator is dereferenceable.	
		operator bool() const
		{
			return operator_bool();
		}
		bool operator==(const iterator& s) const
		{
			return operator_equal(s);
		}
		bool operator!=(const iterator& s) const
		{
			return !operator_equal(s);
		}
		const R operator*() const
		{
			return operator_star_const();
		}
		/*
		std::enable_if<std::is_base_of<std::forward_iterator_tag,C>::value,R>
		operator*()
		{
			return operator_star();
		}
		*/
		iterator& operator++()
		{
			return operator_plus();
		}
		iterator operator++(int)
		{
			return operator_plus_int();
		}
	private:
		virtual bool operator_bool() const
		{
			return true;
		}
		virtual bool operator_equal(const iterator& s) const
		{
			return i == s.i;
		}
		virtual const R operator_star_const() const
		{
			return *i;
		}
		virtual R operator_star()
		{
			return *i;
		}
		iterator& operator_plus()
		{
			++i;

			return *this;
		}
		iterator operator_plus_int()
		{
			return iterator(operator_plus());
		}
	};
	
	template<class I>
	inline auto make_iterator(I i)
	{
		return iterator<I>(i);
	}
}

#ifdef _DEBUG
#include <cassert>

inline void test_iterator()
{
	int i[] = {1,2,3};
	auto s = sequence::make_iterator(i);
	auto s2(s);
	s = s2;
	assert (s == s2);
	assert (!(s != s2));

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