/*

The Fibtraction sequence (as I call it) is similar to the Fibonacci sequence except, instead of adding numbers, you subtract them.

The first few numbers of this challenge are:

1, 2, -1, 3, -4, 7, -11, 18, -29, 47, -76, 123, -199, 322, -521, 843, -1364...
The sequence starts with 1 and 2. Every next number can be calculated by subtracting the previous number from the number before it.

1
2
-1 = 1 - 2
3  = 2 - (-1) = 2 + 1
-4 = -1 - 3
7  = 3 - (-4) = 3 + 4
...
In other words:

f(1) = 1
f(2) = 2
f(n) = f(n - 2) - f(n - 1)
This is OEIS sequence A061084.

Challenge
Write a program/function that takes a positive integer n as input and prints the nth number of the Fibtraction sequence.

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
Your solution can either be 0-indexed or 1-indexed but please specify which.
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions that compute this sequence are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.
Test cases
These are 0-indexed.

Input      Output

1          2
2          -1
11         123
14         -521
21         15127
24         -64079
31         1860498
That pattern was totally not intentional. :P

This challenge was sandboxed.

Before you go pressing any buttons that do scary things, hear me out. This might be considered a dupe of the regular Fibonacci challenge and I agree, to some extent, that it should be easy enough to port solutions from there. However, the challenge is old and outdated; is severely under-specified; allows for two types of solutions; has answers that don't have easy ways to try online; and in general, is lacking of answers. Essentially, in my opinion, it doesn't serve as a good "catalogue" of solutions.

plz send teh codez

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A061084
vlong
fibtraction(vlong n)
{
	vlong a, b, c, i;

	if (n < 0)
		return 0;

	a = 1;
	b = 2;
	for (i = 0; i < n; i++) {
		c = a - b;
		a = b;
		b = c;
	}
	return a;
}

int
main()
{
	static const vlong tab[] = {1, 2, -1, 3, -4, 7, -11, 18, -29, 47, -76, 123, -199, 322, -521, 843, -1364, 2207, -3571, 5778, -9349, 15127, -24476, 39603, -64079, 103682, -167761, 271443, -439204, 710647, -1149851, 1860498, -3010349, 4870847, -7881196, 12752043, -20633239, 33385282, -54018521};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(fibtraction(i) == tab[i]);

	return 0;
}
