/*

I have the following Haskell code to generate the the values of the Fibonacci sequence which are even as an infinite list:

z=zipWith(+)
g=z((*2)<$>0:0:g)$z(0:g)$(*2)<$>scanl(+)1g
This works by starting with 0,2 and then defining every following term to be the sum of:

twice all prior terms
the previous term
twice the term before that
2
I'd like to make it shorter, however I want to preserve a few properties of it.

It must produce the same list.
The solution mustn't calculate intermediate terms of the Fibonacci sequence. The above code calculates each term purely in terms of previous terms of the sequence, and improved versions should as well.
The solution can't use any helper functions, other than point-free aliases like z.
I really feel like this can be done with only 1 zip, however I can't get anything to work.

How can I shorten this.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

/*

https://oeis.org/A014445

@xnor

The even fibonacci sequence can be represented by the recursive relationship:
g[n] = 4*g[n-1] + g[n-2]

*/

uvlong
f(uvlong n)
{
	uvlong a, b, c, i;

	a = 0;
	b = 2;
	for (i = 0; i < n; i++) {
		c = (4 * b) + a;
		a = b;
		b = c;
	}
	return a;
}

int
main()
{
	uvlong i;

	for (i = 0; i <= 10; i++)
		printf("%llu\n", f(i));

	return 0;
}
