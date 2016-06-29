# sequence

A _sequence_ is an iterator having `operator bool() const`
that can be dereferenced as long as it evaluates to `true`.

The Achilles' heel of the [Range v3](https://github.com/ericniebler/range-v3)
proposal is that not only does it require you to drag around two iterators, as in
STL algorithms, they can now be of two different types. This paints one into the corner of 
requiring many algorithms to take an extra predicate argument.

One thing is simpler than two things and adding arguments
to functions thwarts composition.

There is a simpler and more elegant approach.

The class `sequence::iterator<I>` should publicly inherit
from `I` and implement `operator bool() const`, but it doesn't.

Instead it inherits from `std::iterator` using the `std::iterator_traits` from `I`
and has a copy of the iterator. The class implements all of the appropriate member
functions based on what the iterator category requries and uses the NVI idiom.

The public non-virtual functions call private virtual functions
that forward to the iterator and return `true` for every invocation of 
`operator bool() const`.

Derived classes override these functions and compilers turn the
virtual function calls in to direct calls.


