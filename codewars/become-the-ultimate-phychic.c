/*

Let's play Psychic
A box contains green, red, and blue balls. The total number of balls is given by n (0 < n < 50).

Each ball has a mass that depends on the ball color. Green balls weigh 5kg, red balls weigh 4kg, and blue balls weigh 3kg.

Given the total number of balls in the box, n, and a total mass, m, your task is to craft a program that will determine the quantities of each colored ball. Return a list of these quantities as the answer.

Don't forget that some combinations of n and m may have more than one possibility!

Examples
Python
>>> Guess_it(3, 12)
[[0,3,0], [1,1,1]]
Elixir
iex(1)> GuessIt.guess(3, 12)
[{0,3,0}, {1,1,1}]
Note: Order of the returned elements is unimportant in the Elixir version.

Assumptions
You can assume that all inputs are of the correct type
You can assume that the range of n will be [1, 50]
Each element of the returned list should return the quantities in the order of g, r, b.
Python
[[green, red, blue]]
Elixir
[{green, red, blue}]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
guess(int n, int m, int p[][3])
{
	int s, r, g, b;
	size_t l;

	l = 0;
	s = m - (3 * n);
	for (g = 0; g <= n; g++) {
		r = s - (2 * g);
		b = n - g - r;
		if (r >= 0 && b >= 0) {
			p[l][0] = g;
			p[l][1] = r;
			p[l][2] = b;
			l += 1;
		}
	}
	return l;
}

void
test(int n, int m, int r[][3], size_t nr)
{
	int p[32][3];
	size_t np;

	np = guess(n, m, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int r1[][3] = {
		{ 0, 3, 0 },
		{ 1, 1, 1 },
	};

	int r2[][3] = {
		{ 28, 2, 0 },
		{ 29, 0, 1 },
	};

	int r3[][3] = {
		{ 16, 10, 0 },
		{ 17, 8, 1 },
		{ 18, 6, 2 },
		{ 19, 4, 3 },
		{ 20, 2, 4 },
		{ 21, 0, 5 },
	};

	test(3, 12, r1, nelem(r1));
	test(30, 148, r2, nelem(r2));
	test(26, 120, r3, nelem(r3));

	return 0;
}
