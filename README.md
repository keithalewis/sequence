# sequence

The Achilles' heel of the [Range v3](https://github.com/ericniebler/range-v3)
proposal is that not only does it require you to drag around two iterators, as in
STL algorithms, they can now be of two different types! This paints one into the corner of
requiring many algorithms to take an extra predicate argument.

There is a simpler and more elegant approach.

A _sequence_ is an iterator having `operator bool() const`
indicating when it can be dereferenced. This is not a new approach.
C# enumerators have this and Linq illustrates how to provide powerful
programming abstractions that seem to be little known in the C++ community.

One thing is simpler than two things and adding arguments
to functions thwarts composition.

Earlier implementations had the class `sequence::iterator<I>` publicly inherit
from `I` but the current implmentation inherits from `std::iterator` using the `std::iterator_traits` 
from `I` and holds a copy of the iterator. This makes the class self-contained and sequences
of type `T*` are no longer a special case. 
They are merely as compact, fast, and dangerous as naked pointers.

A primary design goal of the library is to keep sequences lightweight. Users
should not be concerned about making a copy. It is just a pointer and maybe
a counter if the length is known. A secondary design goal is to break free
from the STL notion of an interval. Sequences are more flexible when it
comes to traversing higher dimensional data structure. 

Google `SelectMany`.

The `sequence::iterator` class implements all of the appropriate member
functions based on what the iterator category requries and uses the 
[NVI](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface) idiom.
The public non-virtual functions call private virtual functions.
Derived classes override these functions and optimizing compilers turn the
virtual function calls into direct calls.

A canonical example of a sequence is a null terminated string. In this case
`operator bool() const` returns the value of dereferencing the character
pointer. A more interesting example is a sequence of floating point numbers
that terminates when the value is less than machine epsilon.


