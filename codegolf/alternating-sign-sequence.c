/*

Introduction
The sign of a number is either a +, or a - for every non-zero integer. Zero itself is signless (+0 is the same as -0). In the following sequence, we are going to alternate between the positive sign, the zero and the negative sign. The sequence starts with 1, so we write 1 with a positive sign, with zero (this one is weird, but we just multiply the number by 0) and the negative sign:

1, 0, -1
The next number is 2, and we do the same thing again:

2, 0, -2
The sequence eventually is:

1, 0, -1, 2, 0, -2, 3, 0, -3, 4, 0, -4, 5, 0, -5, 6, 0, -6, 7, 0, -7, ...
Or a more readable form:

a(0) = 1
a(1) = 0
a(2) = -1
a(3) = 2
a(4) = 0
a(5) = -2
a(6) = 3
a(7) = 0
a(8) = -3
a(9) = 4
...
The Task
Given a non-negative integer n, output the nth term of the above sequence. You can choose if you use the zero-indexed or one-indexed version.

Test cases:
Zero-indexed:

a(0) = 1
a(11) = -4
a(76) = 0
a(134) = -45
a(296) = -99
Or if you prefer one-indexed:

a(1) = 1
a(12) = -4
a(77) = 0
a(135) = -45
a(297) = -99

This is code-golf, so the submission with the smallest number of bytes wins!

*/

#include <assert.h>

/*

@Lynn

+6      Add 6:     x+6
d3      Divmod:    [(x+6)/3, (x+6)%3]
’       Decrement: [(x+6)/3-1, (x+6)%3-1]
P       Product    ((x+6)/3-1) * ((x+6)%3-1)

*/

int
altsign(int n)
{
	int x, y;

	if (n < 0)
		return 0;

	x = (n + 6) / 3 - 1;
	y = (n + 6) % 3 - 1;
	return -x * y;
}

int
main(void)
{
	assert(altsign(0) == 1);
	assert(altsign(1) == 0);
	assert(altsign(2) == -1);
	assert(altsign(3) == 2);
	assert(altsign(4) == 0);
	assert(altsign(5) == -2);
	assert(altsign(6) == 3);
	assert(altsign(7) == 0);
	assert(altsign(8) == -3);
	assert(altsign(9) == 4);
	assert(altsign(11) == -4);
	assert(altsign(76) == 0);
	assert(altsign(134) == -45);
	assert(altsign(296) == -99);

	return 0;
}
