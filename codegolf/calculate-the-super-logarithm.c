/*

This should be a simple challenge.

Given a number n≥0, output the super-logarithm (or the log∗, log-star, or iterated logarithm, which are equivalent since n is never negative for this challenge.) of n.

log∗(n)= 0                if n <= 1
         1 + log∗(log(n)) if n>1

This is one of the two inverse functions to tetration. The other is the super-root, which is in a related question.

Examples
Input       Output
0           0
1           0
2           1
3           2
4           2
...
15          2
16          3
...
3814279     3
3814280     4

Rules
You do not need to support decimals, though you may.
You need to support input of at least 3814280=⌈e^(e^e)⌉.
You may not hard-code the values like 3814280. (Your program must theoretically support higher numbers.) I want an algorithm to be implemented.

Shortest code wins.

Related OEIS
https://oeis.org/A171990

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

double
recurse(double n)
{
	if (n <= 1)
		return 0;
	return 1 + recurse(log(n));
}

vlong
superlog(vlong n)
{
	return recurse(n);
}

int
main(void)
{
	assert(superlog(0) == 0);
	assert(superlog(1) == 0);
	assert(superlog(2) == 1);
	assert(superlog(3) == 2);
	assert(superlog(4) == 2);
	assert(superlog(15) == 2);
	assert(superlog(16) == 3);
	assert(superlog(3814279) == 3);
	assert(superlog(3814280) == 4);

	return 0;
}
