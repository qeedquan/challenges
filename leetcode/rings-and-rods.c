/*

There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.

You are given a string rings of length 2n that describes the n rings that are placed onto the rods.
Every two characters in rings forms a color-position pair that is used to describe each ring where:

    The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').
    The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').

For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.

Return the number of rods that have all three colors of rings on them.

Example 1:

Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation:
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.

Example 2:

Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation:
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.

Example 3:

Input: rings = "G4"
Output: 0
Explanation:
Only one ring is given. Thus, no rods have all three colors.

Constraints:

    rings.length == 2 * n
    1 <= n <= 100
    rings[i] where i is even is either 'R', 'G', or 'B' (0-indexed).
    rings[i] where i is odd is a digit from '0' to '9' (0-indexed).

*/

#include <assert.h>

typedef unsigned long ulong;

ulong
rri(ulong c, ulong r)
{
	ulong h, l;

	switch (c) {
	case 'R':
		h = 0;
		break;
	case 'G':
		h = 10;
		break;
	case 'B':
		h = 20;
		break;
	default:
		h = 30;
		break;
	}

	l = 0;
	if ('0' <= r && r <= '9')
		l = r - '0';

	return h + l;
}

ulong
points(const char *s)
{
	ulong i, m, p, r;

	for (p = 0; s[0] && s[1]; s += 2)
		p |= (1UL << rri(s[0], s[1]));

	r = 0;
	for (i = '0'; i <= '9'; i++) {
		m = 1UL << rri('R', i);
		m |= 1UL << rri('G', i);
		m |= 1UL << rri('B', i);
		if ((p & m) == m)
			r++;
	}

	return r;
}

int
main(void)
{
	assert(points("B0B6G0R6R0R6G9") == 1);
	assert(points("B0R0G0R9R0B0G0") == 1);
	assert(points("G4") == 0);
	assert(points("R3B2G1") == 0);
	assert(points("R0G0B0R1G1B1R2G2B2R3B3G3R4G4B4R5G5B5R6G6B6R7G7B7R8G8B8R9G9B9") == 10);
	assert(points("R3B2G2B3R2G3") == 2);

	return 0;
}
