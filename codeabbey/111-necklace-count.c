/*

It is a classical puzzle. Martin Gardner mentions that it is found at "one of puzzle collections by Henry E Dudeney", though I failed to trace the original.

Little Alice has a lot of color beads. She can pick several of them and string them into necklace.

She found that with only 2 beads of only 2 colors (say, red and green) three different necklaces could be created - for example:

red-red
red-green
green-green
With 3 beads of 2 colors it is possible to make 4 necklaces. The image above shows 6 variants made of 4 two-color beads.

You see, since the necklace have ends of the string tied together, there are far less variants than for linear strings of beads - i.e. while strings like

red-green-red
red-red-green
are different before their ends are tied, they nevertheless produce the same necklace.

However we differ necklaces which are "mirror" of each other (since it is not possible to convert one into another simply by rotating it around the neck). For example

red-red-green-red-green-green
is not the same as

red-red-green-green-red-green
If we do not distinguish mirrored necklaces, they are usually called bracelets. However this does not change problem significantly so we do not include this minor implication. (so for example with 6 beads of 2 colors we can make 14 necklaces but only 13 bracelets).

Input data contains the number of testcases in the first line.
Next lines contain a pair of values each - the number of colors B - and the amount of beads to form necklace N.
Answer should contain the number of different necklaces which could be made in each case.

Example:

input data:
3
2 6
9 4
12 1

answer:
14 1665 12
Limits: B <= 12 and N (depending on it) would be such that the result will not exceed few millions.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

vlong
totient(vlong n)
{
	vlong p, r;

	r = n;
	for (p = 2; p * p <= n; p++) {
		if (!(n % p)) {
			r -= r / p;
			while (!(n % p))
				n /= p;
		}
	}
	if (n > 1)
		r -= r / n;
	return r;
}

// https://handwiki.org/wiki/Necklace_(combinatorics)
vlong
necklaces(vlong k, vlong n)
{
	vlong a, b, r;

	if (n < 1)
		return 0;

	r = 0;
	for (a = 1; a <= n; a++) {
		if (!(n % a)) {
			b = n / a;
			r += totient(a) * pow(k, b);
		}
	}
	return r / n;
}

int
main()
{
	assert(necklaces(2, 12) == 352);
	assert(necklaces(3, 7) == 315);
	assert(necklaces(9, 4) == 1665);
	assert(necklaces(21, 3) == 3101);
	assert(necklaces(99, 2) == 4950);
	assert(necklaces(3, 10) == 5934);
	assert(necklaces(2, 4) == 6);
	assert(necklaces(7, 5) == 3367);
	assert(necklaces(2, 5) == 8);
	assert(necklaces(8, 4) == 1044);
	assert(necklaces(3, 4) == 24);
	assert(necklaces(3, 5) == 51);
	assert(necklaces(5, 5) == 629);
	assert(necklaces(2, 6) == 14);
	assert(necklaces(9, 4) == 1665);
	assert(necklaces(12, 1) == 12);

	return 0;
}
