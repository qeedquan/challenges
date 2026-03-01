/*

We need the ability to divide an unknown integer into a given number of even parts — or at least as even as they can be. The sum of the parts should be the original value, but each part should be an integer, and they should be as close as possible.

Example code:

splitInteger(20, 6)  // returns [3, 3, 3, 3, 4, 4]
Complete the function so that it returns an array of integer representing the parts. Ignoring the order of the parts, there is only one valid solution for each input to your function!

(Also, there is no reason to test for edge cases: the input to your function will always be valid for this kata.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
splitint(int n, int p, int *r)
{
	int i, m;

	if (n < 1 || p < 1)
		return;

	m = n % p;
	for (i = 0; i < n; i++)
		r[i] = n / p;

	for (i = 1; i <= m; i++)
		r[p - i] += 1;
}

void
test(int n, int p, int *r, size_t nr)
{
	int x[32];

	splitint(n, p, x);
	assert(!memcmp(x, r, sizeof(*r) * nr));
}

int
main()
{
	int r1[] = { 3, 3, 3, 3, 4, 4 };

	test(20, 6, r1, nelem(r1));

	return 0;
}
