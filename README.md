# sequence

A _sequence_ is an iterator having `operator bool() const`
that can be dereferenced as long as it evaluates to `true`.

The Achilles' heel of the Range proposal is that not only
does it require you to drag around two iterators, as in
STL algorithms, they can now be of two different types.

This paints one into the corner of requiring many algorithms
to take an extra predicate argument.

One thing is simpler than two things and adding arguments
to functions thwarts composition.

There is a simpler and more elegant approach.

The class `sequence::iterator<I>` should publicly inherit
from `I` and implement `operator bool() const`, but it doesn't.

  