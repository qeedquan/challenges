/*

Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.

A complete day is defined as a time duration that is an exact multiple of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

Example 1:

Input: hours = [12,12,30,24,24]

Output: 2

Explanation: The pairs of indices that form a complete day are (0, 1) and (3, 4).

Example 2:

Input: hours = [72,48,24,3]

Output: 3

Explanation: The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).

Constraints:

1 <= hours.length <= 5 * 10^5
1 <= hours[i] <= 10^9

Hint 1
A pair (i, j) forms a valid complete day if (hours[i] + hours[j]) % 24 == 0.

Hint 2
Using an array or a map, for each index j moving from left to right, increase the answer by the count of (24 - hours[j]) % 24, and then increase the count of hours[j].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
days(vlong *h, size_t n)
{
	vlong c[24];
	vlong r, x, y;
	size_t i;

	memset(c, 0, sizeof(c));
	r = x = y = 0;
	for (i = 0; i < n; i++) {
		x = ((-h[i] % 24) + 24) % 24;
		y = h[i] % 24;

		r += c[x];
		c[y] += 1;
	}
	return r;
}

int
main()
{
	vlong h1[] = { 12, 12, 30, 24, 24 };
	vlong h2[] = { 72, 48, 24, 3 };

	assert(days(h1, nelem(h1)) == 2);
	assert(days(h2, nelem(h2)) == 3);

	return 0;
}
