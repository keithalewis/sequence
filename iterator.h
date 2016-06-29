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
		R operator*()
		{
			return operator_star();
		}
		const R operator*() const
		{
			return operator_star_const();
		}
		iterator& operator++()
		{
			return operator_plus_plus();
		}
		iterator operator++(int)
		{
			return operator_plus_plus_int();
		}
		iterator& operator--()
		{
			return operator_minus_minus();
		}
		iterator operator--(int)
		{
			return operator_minus_minus_int();
		}
		iterator& operator+=(D n)
		{
			return operator_plus_equal(n);
		}
		iterator& operator-=(D n)
		{
			return operator_minus_equal(n);
		}
		std::enable_if<
			std::is_same<C,std::random_access_iterator_tag>::value,D>
		operator-(const iterator& s) const
		{
			return operator_minus(s);
		}
	private:
		// unsafe
		virtual bool operator_bool() const
		{
			return true;
		}
		virtual bool operator_equal(const iterator& s) const
		{
			return i == s.i;
		}
		virtual R operator_star()
		{
			return *i;
		}
		virtual const R operator_star_const() const
		{
			return *i;
		}
		virtual iterator& operator_plus_plus()
		{
			++i;

			return *this;
		}
		virtual iterator operator_plus_plus_int()
		{
			return iterator(operator_plus_plus());
		}
		virtual iterator& operator_minus_minus()
		{
			--i;

			return *this;
		}
		virtual iterator operator_minus_minus_int()
		{
			return iterator(operator_minus_minus());
		}
		virtual iterator& operator_plus_equal(D n)
		{
			i += n;

			return *this;
		}
		virtual iterator& operator_minus_equal(D n)
		{
			i -= n;

			return *this;
		}
		virtual D operator_minus(const iterator& s) const
		{
			return i - s.i;
		}
	};
	
	template<class I, 
		class C = typename std::iterator_traits<I>::iterator_category,
		class T = typename std::iterator_traits<I>::value_type,
		class D = typename std::iterator_traits<I>::difference_type,
		class P = typename std::iterator_traits<I>::pointer,
		class R = typename std::iterator_traits<I>::reference
	>
	inline auto make_iterator(I i)
	{
		return iterator<I,C,T,D,P,R>(i);
	}
}

#ifdef _DEBUG
#include <cassert>
#include <vector>
#include <list>

inline void test_iterator()
{
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
		*s = 4;
		assert (*s == 4);
		*s = 1;
		assert (*++s == 2);
		s++;
		assert (*s == 3);
		assert (++s); // always true

		s = sequence::make_iterator(i);
		++s; 
		--s;
		assert (*s == 1);
		s += 2;
		assert (*s == 3);
		s -= 2;
		assert (*s == 1);
	}
	{
		const int i[] = {1,2,3};
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
		// *s = 4; // compile time failure
		// assert (*s == 4);
		assert (*++s == 2);
		s++;
		assert (*s == 3);
		assert (++s); // always true

		s = sequence::make_iterator(i);
		++s; 
		--s;
		assert (*s == 1);
		s += 2;
		assert (*s == 3);
		s -= 2;
		assert (*s == 1);
		assert (s - s == 0);
	}
	{
		std::vector<int> i = {1,2,3};
		auto s = sequence::make_iterator(std::begin(i));
		auto s2(s);
		s = s2;
		assert (s == s2);
		assert (!(s != s2));

		assert (s == s2);
		assert (!(s != s2));

		assert (s);
		assert (s2);
		assert (*s == 1);
		*s = 4;
		assert (*s == 4);
		*s = 1;
		assert (*++s == 2);
		s++;
		assert (*s == 3);
		assert (++s); // always true
		s = sequence::make_iterator(i.begin());

		++s; 
		--s;
		assert (*s == 1);
		s += 2;
		assert (*s == 3);
		s -= 2;
		assert (*s == 1);
	}
	{
		std::list<int> i = {1,2,3};
		auto s = sequence::make_iterator(std::begin(i));
		auto s2(s);
		s = s2;
		assert (s == s2);
		assert (!(s != s2));

		assert (s == s2);
		assert (!(s != s2));

		assert (s);
		assert (s2);
		assert (*s == 1);
		*s = 4;
		assert (*s == 4);
		*s = 1;
		assert (*++s == 2);
		s++;
		assert (*s == 3);
		assert (++s); // always true
/*
		s = sequence::make_iterator(i.begin());

		++s; 
		--s;
		assert (*s == 1);
		s += 2;
		assert (*s == 3);
		s -= 2;
		assert (*s == 1);
*/
	}
}

#endif // _DEBUG