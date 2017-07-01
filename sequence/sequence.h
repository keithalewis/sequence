// sequence.h - iterators with operator bool() const
#pragma once
#include <functional>
#include <iterator>

namespace sequence {

	template<class I>
	using iterator = std::iterator<
						typename std::iterator_traits<I>::iterator_category,
						typename std::iterator_traits<I>::value_type,
						typename std::iterator_traits<I>::difference_type,
						typename std::iterator_traits<I>::pointer,
						typename std::iterator_traits<I>::reference
	                 >;

	// null terminated sequence
	template<class I>
	class null : public iterator<I> {
//		using T = typename std::iterator_traits<I>::value_type;
		I i;
	public:
//		typedef typename T value_type;
		null(I i)
			: i(i)
		{ }
		operator bool() const
		{
			return *i != 0;
		}
		null& operator++()
		{
			operator bool() && ++i;

			return *this;
		}
		value_type operator*() const
		{
			return *i;
		}
	};

	// machine epsilon terminated sequence
	template<class I>
	class epsilon : public iterator<I> {
		I i;
	public:
		epsilon(I i)
			: i(i)
		{ }
		operator bool() const
		{
			return *i + value_type(1) != value_type(1);
		}
		epsilon& operator++()
		{
			operator bool() && ++i;

			return *this;
		}
		value_type operator*() const
		{
			return *i;
		}
	};

	// constant sequence
	template<class T>
	class constant {
		T t;
	public:
		typedef typename T value_type;
		constant(T t)
			: t(t)
		{ }
		operator bool() const
		{
			return false;
		}
		T operator*() const
		{
			return t;
		}
		constant& operator++()
		{
			return *this;
		}
	};

	// t, t + dt, ...
	template<class T>
	class iota {
		T t, dt;
	public:
		typedef typename T value_type;
		iota(T t = T(0), T dt = T(1))
			: t(t), dt(dt)
		{ }
		operator bool() const
		{
			return true;
		}
		T operator*() const
		{
			return t;
		}
		iota& operator++()
		{
			t += dt;

			return *this;
		}
	};

	// t^n, t^{n+1}, ...
	template<class T>
	class power {
		T t, tn;
	public:
		typedef typename T value_type;
		power(T t, size_t n = 0)
			: t(t), tn(1)
		{
			while (n--)
				tn *= t;
		}
		operator bool() const
		{
			return false;
		}
		T operator*() const
		{
			return tn;
		}
		power& operator++()
		{
			tn *= t;

			return *this;
		}
	};

	// t, t(t + dt), t(t + dt)(t + 2 dt)
	template<class T = unsigned long long>
	class pochhammer {
		T t_, t, dt;
	public:
		typedef typename T value_type;
		pochhammer(T t, T dt = T(1))
			: t_(t), t(t), dt(dt)
		{ }
		operator bool() const
		{
			return true;
		}
		T operator*() const
		{
			return t_;
		}
		pochhammer& operator++()
		{
			t += dt;
			t_ *= t;

			return *this;
		}
	};

	template<class Op, class I, class J>
	class bin_op {
		using U = typename I::value_type;
		using V = typename J::value_type;
		using T = std::result_of_t<Op(U,V)>;
		Op op;
		I i;
		J j;
	public:
		typedef typename T value_type;
		bin_op(Op op, I i, J j)
		  : op(op), i(i), j(j)
		{ }
		operator bool() const
		{
			return i && j;
		}
		T operator*() const
		{
			return op(*i, *j);
		}
		bin_op& operator++()
		{
			++i;
			++j;

			return *this;
		}
	};

	template<class I>
	inline I last(I i)
	{
		I j;
		
		while (i) {
			j = i;
			++i;
		}

		return j;
	}
}

template<class I, class J>
inline auto add(I i, J j)
{
	using U = typename I::value_type;
	using V = typename J::value_type;
	using T = std::common_type_t<U,V>;

	return sequence::bin_op<std::plus<T>,I,J>(std::plus<T>(), i, j);
}
