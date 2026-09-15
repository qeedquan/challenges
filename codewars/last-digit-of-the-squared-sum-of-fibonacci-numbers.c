/*

In this kata you will compute the last digit of the sum of squares of Fibonacci numbers.

Consider the sum Sn=F0^2+F1^2+...+Fn^2, where F0=0, F1=1 and Fi=Fi−1+Fi−2 for i≥2, you must compute the last digit of Sn.

Example: Given input n=7, Sn=273. Therefore the output is 3.

Note that 0≤n≤10^18 . So bruteforce will not work.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
fss(uvlong n)
{
	uvlong a, b, c, i;

	if (n < 1)
		return 0;

	n %= 60;
	a = 0;
	b = 1;
	for (i = 0; i < n; i++) {
		c = (a + b) % 10;
		a = b;
		b = c;
	}
	return (a * b) % 10;
}

int
main()
{
	assert(fss(0) == 0);
	assert(fss(7) == 3);
	assert(fss(77) == 8);
	assert(fss(1234567890) == 0);
	assert(fss(1000000000000000000) == 5);

	return 0;
}
