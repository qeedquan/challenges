/*

Once, the king rewarded a farmer with an apple from his garden.
The farmer went to the garden and saw that it was surrounded by n fences.
Each fence had only one gate, and at each gate stood a guard.
The farmer approached the first guard and showed him the royal decree.
The guard said: "Go ahead and take, but upon exit, give me half of the apples you carry, and one more."
The same was said by the second, third guard, and so on.
How many apples must the farmer take so that after paying all the guards, he is left with exactly one apple?

Input
The only number n — the number of fences in the garden (1≤n≤62).

Output
The only number K — the number of apples the farmer must take so that after paying all the guards, he has exactly one apple left.

Examples

Input #1
1

Answer #1
4

Input #2
2

Answer #2
10

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A033484
uvlong
solve(uvlong n)
{
	return (3 * (1ULL << n)) - 2;
}

int
main()
{
	static const uvlong tab[] = {
		1, 4, 10, 22, 46, 94, 190, 382, 766, 1534, 3070, 6142, 12286, 24574,
		49150, 98302, 196606, 393214, 786430, 1572862, 3145726, 6291454,
		12582910, 25165822, 50331646, 100663294, 201326590, 402653182, 805306366,
		1610612734, 3221225470
	};

	size_t i;

	assert(solve(1) == 4);
	assert(solve(2) == 10);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
