# Notes

If `s` is a sequence and `!s` then `!++s`, i.,e., incrementing a sequence that is
done behaves like a noop.

We need to `enable_if` the global binary operators to check for approriate members. (Hinnant's trick)

## Examples

Pythagorean triples example.

BTW, m^2 - n^2, 2mn, m^2 + n^2 generate all triples.

|zw|^2 = |z|^2 |w|^2 where z = m + in, w = m - in.

Generate x <= y <= z filtered through x^2 + y^2 = z^2.

z | y <= z | x <= y <= z | where x^2 + y^2 = z^2

Prime number example.

2, rest not divisible by 2, rest not divisible by first of the rest..

## References

https://ericlippert.com/category/monads/ - How LINQ uses monads

https://bartoszmilewski.com/2014/10/28/category-theory-for-programmers-the-preface/
