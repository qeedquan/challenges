/*

Create a function that takes a number and returns the sum of factors of factors of the given number.

Examples
sumFF(69) ➞ 3, 23 ➞ 0
// Both 3 and 23 are prime numbers and have no factors
// other than 1 and themselves so the result is 0.

sumFF(12) ➞ 2, 3, 4, 6 ➞ (0) + (0) + (2) + (2+3) ➞ 7

sumFF(420) ➞ 2,4, 6, 10, 12 ... ➞ (2) + (2+3) + (2+5) + (2+3+4+6) ... ➞ 1175

sumFF(619) ➞ ___ ➞ 0
// 619 doesn't have any factors (other than 1 and 619).

Notes
The number will always be greater than 0.
Factors that are equal to the number or 1, don't count (see example #1).

*/

#include <assert.h>

int
sumff(int n)
{
	int i, j, r;

	r = 0;
	for (i = 2; i < n; i++) {
		if (n % i)
			continue;

		for (j = 2; j < i; j++) {
			if (!(i % j))
				r += j;
		}
	}
	return r;
}

int
main(void)
{
	assert(sumff(69) == 0);
	assert(sumff(420) == 1175);
	assert(sumff(619) == 0);
	assert(sumff(98) == 16);
	assert(sumff(435) == 74);
	assert(sumff(534) == 188);
	assert(sumff(3123) == 353);
	assert(sumff(1232) == 1931);
	assert(sumff(12) == 7);
	assert(sumff(31232) == 32630);
	assert(sumff(4234) == 208);
	assert(sumff(655) == 0);
	assert(sumff(432) == 1240);
	assert(sumff(2343) == 170);

	return 0;
}
