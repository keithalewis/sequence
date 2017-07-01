// sequence_test.cpp
#include <cassert>
#include "sequence.h"

using namespace sequence;
 
void null_test()
{
	double t[] = { 1, 2, 0 };
	auto nt = null<double*>(t);
	assert(nt);
	assert(*nt == 1);
	++nt;
	assert(nt);
	assert(*nt == 2);
	++nt;
	assert(!nt);

	const char* s = "hi";
	null<const char*> ns(s);
	assert(ns);
	assert(*ns == 'h');
	++ns;
	assert(ns);
	assert(*ns == 'i');
	++ns;
	assert(!ns);
}
template<class T>
void epsilon_test()
{
	T t[] = { T(1), std::numeric_limits<T>::epsilon() / 2 };
	epsilon<T*> nt(t);
	assert(nt);
	assert(*nt == 1);
	++nt;
	assert(!nt);
}

void constant_test()
{
	constant<int> c(2);
	assert(c);
	assert(*c == 2);
	++c;
	assert(c);
	assert(*c == 2);
}

void bin_op_test()
{

	null<char*> hi("hi"), you("you");
	auto hiyou = bin_op<std::plus<char>,null<char*>,null<char*>>(std::plus<char>(), hi, you);
	assert(hiyou);
	assert(*hiyou == std::plus<char>()('h', 'y'));
	assert(++hiyou);
	assert(*hiyou == std::plus<char>()('i', 'o'));
	assert(!++hiyou);

	auto plus = std::plus<char>();
	auto hy = add(hi, you);
	assert(hy);
	assert(*hy == plus('h', 'y'));
	assert(++hy);
	assert(*hy == plus('i', 'o'));
	assert(!++hy);
}

int main()
{
	null_test();
	epsilon_test<double>();
	epsilon_test<float>();
	bin_op_test();

	return 0;
}