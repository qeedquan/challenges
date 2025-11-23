/*

Given a number n, we have its sum of divisors, σ(n) =∑d|nd, that is, the sum of all numbers which divide n (including 1 and n). For example, σ(28)=1+2+4+7+14+28=56. This is OEIS A000203.

We can now define the sum of sum of divisors as S(n)=∑ni=1σ(i), the sum of σ(i) for all numbers from 1 to n. This is OEIS A024916.

Your task is to calculate S(n), in time sublinear in n, o(n).

Test cases
10 -> 87
100 -> 8299
123 -> 12460
625 -> 321560
1000 -> 823081
1000000 (10^6) -> 822468118437
1000000000 (10^9) -> 822467034112360628

Rules
Your complexity must be o(n). That is, if your code takes time T(n) for input n, you must have limn→∞T(n)n=0. Examples of valid time complexities are O(nlog(n)), O(sqrt(n)), O(n^(5/7)*log^4(n)), etc.
You can use any reasonable I/O format.
Note that due to the limited complexity you can't take the input in unary nor output in it (because then the I/O takes Ω(n) time), and the challenge might be impossible in some languages.
Your algorithm should in theory be correct for all inputs, but it's fine if it fails for some of the big test cases (due to overflow or floating-point inaccuracies, for example).
Standard loopholes are disallowed.
This is code golf, so the shortest answer in each language wins.

*/
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
triangular(uvlong n)
{
	return (n * (n + 1)) / 2;
}

/*

https://oeis.org/A024916
https://math.stackexchange.com/questions/3287652/fast-computation-of-the-divisor-summatory-function-sum-i-1x-sum-did

*/

uvlong
sumsigma(uvlong n)
{
	uvlong i, s, r;

	r = 0;
	s = sqrt(n);
	for (i = 1; i <= s; i++)
		r += (i * (n / i)) + triangular(n / i);
	r -= triangular(s) * s;

	return r;
}

int
main(void)
{
	static const uvlong tab[] = {1, 4, 8, 15, 21, 33, 41, 56, 69, 87, 99, 127, 141, 165, 189, 220, 238, 277, 297, 339, 371, 407, 431, 491, 522, 564, 604, 660, 690, 762, 794, 857, 905, 959, 1007, 1098, 1136, 1196, 1252, 1342, 1384, 1480, 1524, 1608, 1686, 1758, 1806, 1930, 1987, 2080, 2152};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(sumsigma(i + 1) == tab[i]);

	assert(sumsigma(10) == 87);
	assert(sumsigma(100) == 8299);
	assert(sumsigma(123) == 12460);
	assert(sumsigma(625) == 321560ULL);
	assert(sumsigma(1000) == 823081ULL);
	assert(sumsigma(1000000ULL) == 822468118437ULL);
	assert(sumsigma(1000000000ULL) == 822467034112360628ULL);

	return 0;
}
