/*

The representation of an integer in two's complement binary encoding is given. Output the decimal representation of this integer.

Input
A string S (2≤∣S∣≤16) consisting only of the characters 0 and 1.

Output
Output the decimal representation of the given integer.

Examples

Input #1
00000101

Answer #1
5

Input #2
11111011

Answer #2
-5

*/

#include <assert.h>
#include <stdio.h>

int
solve(const char *s)
{
	int f, r;

	f = 0;
	if (*s == '1') {
		f = 1;
		s += 1;
	}

	for (r = 0; *s; s++) {
		r <<= 1;
		if ((*s == '1' && !f) || (*s == '0' && f))
			r |= 1;
	}
	if (f)
		r = -(r + 1);
	return r;
}

int
main()
{
	assert(solve("00000101") == 5);
	assert(solve("11111011") == -5);

	return 0;
}
