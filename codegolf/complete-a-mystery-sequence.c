/*

Given a sequence of three integers, determine if the sequence is arithmetic (of the form [a, a+d, a+2*d]) or geometric (of the form [a, a*r, a*r^2]) by outputting a fourth term that completes it (a+3*d for arithmetic, a*r^3 for geometric).

Examples:

[1, 2, 3] -> 4 (This is an arithmetic sequence with a difference of 1)
[2, 4, 8] -> 16 (This is a geometric sequence with a ratio 2)
[20, 15, 10] -> 5 (arithmetic sequence, d=-5)
[6, 6, 6] -> 6 (arithmetic with d=0 OR geometric with r=1)
[3, -9, 27] -> -81 (geometric with r=-3)
The input is guaranteed to be a valid arithmetic and/or geometric sequence (so you won't have to handle something like [10, 4, 99])
None of the inputted terms will be 0 (both [2, 0, 0] and [1, 0, -1] would not be given)
For geometric sequences, the ratio between terms is guaranteed to be an integer (ie. [4, 6, 9] would be an invalid input, as the ratio would be 1.5)
If a sequence could be either arithmetic or geometric, you may output either term that completes it
You may take input as a 3-term array (or whatever equivalent) or as three separate inputs
This is code golf, so aim for the lowest byte count possible!

*/

#include <assert.h>

/*

@loopy walt

How?
Uses the fact that the increments form a geometric sequence in either case.

Indeed:

c + (c-b)^2/(b-a) = c + (c-b)     = 2c - b if c-b = b-a
                    c + (c-b)*c/b = c^2/b  if c/b = b/a

*/

int
seq(int a, int b, int c)
{
	int d, e;

	d = b - a;
	e = c - b;
	if (d == 0)
		d = 1;
	return c + ((e * e) / d);
}

int
main()
{
	assert(seq(1, 2, 3) == 4);
	assert(seq(2, 4, 8) == 16);
	assert(seq(20, 15, 10) == 5);
	assert(seq(6, 6, 6) == 6);
	assert(seq(3, -9, 27) == -81);

	return 0;
}
