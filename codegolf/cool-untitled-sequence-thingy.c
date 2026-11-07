/*

Let's define fn(k) as the sum of the first k terms of the natural numbers [1, ∞) where each number is repeated n times.

k       | 0    1    2    3    4    5    6    7    8    9
--------+-------------------------------------------------
f_1(k)  | 0    1    3    6    10   15   21   28   36   45
deltas  |   +1   +2   +3   +4   +5   +6   +7   +8   +9
--------+-------------------------------------------------
f_2(k)  | 0    1    2    4    6    9    12   16   20   25
deltas  |   +1   +1   +2   +2   +3   +3   +4   +4   +5
--------+-------------------------------------------------
f_3(k)  | 0    1    2    3    5    7    9    12   15   18
deltas  |   +1   +1   +1   +2   +2   +2   +3   +3   +3
The anti-diagonals of this as a square array is similar to OEIS sequence A134546.

Challenge
Write a program/function that takes two non-negative integers n and k and outputs fn(k).

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
Your solution can either be 0-indexed or 1-indexed for n and/or k but please specify which.
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions that compute this sequence are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.
Test cases
In these test cases, n is 1-indexed and k is 0-indexed.

n   k      fn(k)

1   2      3
2   11     36
11  14     17
14  21     28
21  24     27
24  31     38
31  0      0
In a few better formats:

1 2
2 11
11 14
14 21
21 24
24 31
31 0

1, 2
2, 11
11, 14
14, 21
21, 24
24, 31
31, 0
Reference implementation
This is written in Haskell.

f n k = sum $ take k $ replicate n =<< [1..]
Try it online!

This challenge was sandboxed.

*/

#include <assert.h>

typedef unsigned uint;

uint
f(uint n, uint k)
{
	if (n == 0)
		return 0;
	return (k + (k % n)) * ((k / n) + 1) / 2;
}

int
main()
{

	assert(f(1, 2) == 3);
	assert(f(2, 11) == 36);
	assert(f(11, 14) == 17);
	assert(f(14, 21) == 28);
	assert(f(21, 24) == 27);
	assert(f(24, 31) == 38);
	assert(f(31, 0) == 0);

	return 0;
}
