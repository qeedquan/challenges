/*

Introduction
We have 22 Collatz conjecture-related challenges as of October 2020, but none of which cares about the restrictions on counter-examples, if any exists, to the conjecture.

Considering a variant of the operation defined in the conjecture:

f(x) = x / 2         for even x
      (3x + 1) / 2   for odd x

The Wikipedia article suggests that a modular restriction can be easily calculated and used to speed up the search for the first counter-example.
For a pair of k and  b where 0≤b<2k, if it is possible to prove that  fk(2ka + b) < 2ka + b for all sufficiently
large non-negative integers a, the pair can be discarded.
This is because if the inequality holds for the counter-example, we can find a smaller counter-example from that,
contradicting the assumption that the counter-example is the first one.

For example,  b=0,k=1 is discarded because  f(2a)=a<2a, while  b=3,k=2 is not because  f2(4a+3)=9a+8>4a+3.
Indeed, for k=1 we only have b=1 and for k=2, b=3, to remain (survive) after the sieving process.
When  k=5, though, we have 4 survivors, namely 7, 15, 27 and 31.

<strikeout>
However, there are still 12,771,274 residues mod  2^30 surviving, so just still about a 100x boost even at this level
</strikeout>

Challenge
Write a program or function, given a natural number k as input, count the number of moduli mod 2k that
survives the sieving process with the operation applied k times.
The algorithm used must in theory generalize for arbitrary size of input.

The sequence is indeed A076227.

Examples
Input > Output
1     > 1
2     > 1
3     > 2
4     > 3
5     > 4
6     > 8
7     > 13
8     > 19
9     > 38
10    > 64
15    > 1295
20    > 27328
30    > 12771274

Winning criteria
This is a code-golf challenge, so the shortest submission of each language wins. Standard loopholes are forbidden.

*/

#include <assert.h>
#include <stdbit.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
survives(uvlong r, uvlong m, uvlong lm, int p2, int fp2)
{
	while (!(m & 1) && (m >= lm)) {
		if (r & 1) {
			r += (r + 1) >> 1;
			m += m >> 1;
		} else {
			r >>= 1;
			m >>= 1;
		}
	}

	if (m < lm)
		return 0;
	if (p2 == fp2)
		return 1;

	return survives(r, m << 1, lm << 1, p2 + 1, fp2) +
	       survives(r + m, m << 1, lm << 1, p2 + 1, fp2);
}

// https://oeis.org/A076227
uvlong
solve(uvlong n)
{
	return survives(0, 1, 1, 0, n);
}

int
main()
{
	static const uvlong tab[] = {
		1, 1, 1, 2, 3, 4, 8, 13, 19, 38, 64, 128, 226, 367, 734, 1295, 2114,
		4228, 7495, 14990, 27328, 46611, 93222, 168807, 286581, 573162, 1037374,
		1762293, 3524586, 6385637, 12771274, 23642078, 41347483, 82694966,
		151917636
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
