/*

Take a look at this pirate game.

Give Amaro an array to confirm his logic for the next time, when the number of pirates changes.

Keep in mind that each time the pirates find a treasure, the amount of gold equals to the number of pirates * 20.

Example:

If number of pirates is 2, including Amaro, then array = [40, 0], So he can keep all of the gold to himself.

If number of pirates is 3, including Amaro, then array = [59, 0, 1], and 59 gold is his for the taking.

If number of pirates is 4, including Amaro, then array = [79, 0, 1, 0], and 79 gold is his to take.

If number of pirates is 5, including Amaro, then array = [98, 0, 1, 0, 1], and 98 gold is his for the taking.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
amaroplan(int p, int *r)
{
	int i, c, s;

	c = p * 20;
	s = (p - 1) / 2;
	r[0] = c - s;
	for (i = 0; i < p - 1; i++)
		r[i + 1] = i & 1;
	return i + 1;
}

void
test(int p, int *r, int n)
{
	int x[128];
	int m;

	m = amaroplan(p, x);
	assert(n == m);
	assert(!memcmp(x, r, sizeof(*r) * n));
}

int
main()
{
	int r1[] = { 40, 0 };
	int r2[] = { 59, 0, 1 };
	int r3[] = { 79, 0, 1, 0 };
	int r4[] = { 98, 0, 1, 0, 1 };

	test(2, r1, nelem(r1));
	test(3, r2, nelem(r2));
	test(4, r3, nelem(r3));
	test(5, r4, nelem(r4));

	return 0;
}
