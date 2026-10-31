/*

There are n coins on the table. Some of them are heads-up, while others are tails-up.
Determine the minimum number of coins that need to be flipped so that all the coins end up facing the same side up.

https://static.e-olymp.com/content/61/61334b3762de2da16a9c1e4b5861d45c17959dd4.jpg

Input
The first line contains the number of coins n (1≤n≤100).

Each of the following n lines contains an integer: 1 if the coin is tails-up, and 0 if it is heads-up.

Output
Print the minimum number of coins that need to be flipped.

Examples

Input #1
5
1
0
1
1
0

Answer #1
2

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
solve(int *c, size_t n)
{
	size_t i, x, y;

	for (i = x = y = 0; i < n; i++) {
		if (!c[i])
			x++;
		else
			y++;
	}
	return min(x, y);
}

int
main()
{
	int c1[] = { 1, 0, 1, 1, 0 };

	assert(solve(c1, nelem(c1)) == 2);

	return 0;
}
