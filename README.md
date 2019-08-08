# sequence

The Achilles' heel of the [Range v3](https://github.com/ericniebler/range-v3)
proposal is that not only does it require you to drag around two iterators, as in
STL algorithms, but they can now be of two different types! This paints one into the corner of
requiring many algorithms to take an extra predicate argument.

There is a simpler and more elegant approach.

A _sequence_ is a class having `operator bool() const`
indicating when it can be dereferenced, and `operator*() const` to dereference
the current item, and `operator++()` to increment to the next item.
This is not a new approach.
C# enumerators have this and Linq illustrates how to provide powerful
programming abstractions that seem to be little known in the C++ community.

One thing is simpler than two things and adding arguments
to functions thwarts composition.

A primary design goal of the library is to keep sequences lightweight. Users
should not be concerned about making a copy. It is just a pointer and maybe
a counter if the length is known. A secondary design goal is to break free
from the STL notion of an interval. Sequences are more flexible when it
comes to traversing higher dimensional data structures. 

A canonical example of a sequence is a null terminated string. In this case
`operator bool() const` returns false when it reaches the null character. 
A more interesting example is a sequence of floating point numbers
that terminates when the value is less than machine epsilon.

For example, we can compute `exp(x) = sum_{n>=0} x^n/n!` by `sum(epsilon(power(x)/factorial()))` 

## NOTES

If `s` is a sequence and `!s` then `!++s`, i.,e., incrementing a sequence that is
done behaves like a noop.

We need to `enable_if` the global binary operators to check for approriate members. (Hinnant's trick)

