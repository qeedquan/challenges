/*

Write a function that takes a positive integer and calculates how many dots exist in a pentagonal shape around the center dot on the Nth iteration.

In the image below you can see the first iteration is only a single dot. On the second, there are 6 dots. On the third, there are 16 dots, and on the fourth there are 31 dots.

alt text

Return the number of dots that exist in the whole pentagon on the Nth iteration.
Examples

pentagonal(1) ➞ 1

pentagonal(2) ➞ 6

pentagonal(3) ➞ 16

pentagonal(8) ➞ 141

*/

#include <assert.h>
#include <stdio.h>

// https://oeis.org/A005891
unsigned
pentagonal(unsigned n)
{
	return ((5 * n * n) - (5 * n) + 2) / 2;
}

int
main(void)
{
	assert(pentagonal(1) == 1);
	assert(pentagonal(3) == 16);
	assert(pentagonal(8) == 141);
	assert(pentagonal(10) == 226);
	assert(pentagonal(15) == 526);
	assert(pentagonal(33) == 2641);
	assert(pentagonal(43) == 4516);
	assert(pentagonal(13) == 391);
	assert(pentagonal(50) == 6126);
	assert(pentagonal(62) == 9456);
	assert(pentagonal(21) == 1051);

	return 0;
}
