/*

There are infinitely many lamps, all initially turned off.
At each phase of the game, all lamps whose numbers are divisible by the phase number are toggled: if a lamp is off, it is turned on; if it is on, it is turned off.

Input
The first line contains the number of test cases t (1≤t≤10).
Each of the following t lines contains the number n (0<n≤10^5) representing the phase number of the game.

Output
For each test case, print one line indicating the state of lamp number n after phase n of the game: 0 — the lamp is off, 1 — the lamp is on.

Examples
Input #1
2
1
5

Answer #1
1
0

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A010052
int
solve(int n)
{
	int s;

	if (n < 1)
		return 0;

	s = sqrt(n);
	return s * s == n;
}

int
solvebf(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (!(n % i))
			r ^= 1;
	}
	return r;
}

int
main()
{
	static const int tab[] = {
		1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	size_t i;

	assert(solve(1) == 1);
	assert(solve(5) == 0);

	for (i = 0; i <= 10000; i++)
		assert(solve(i) == solvebf(i));

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
