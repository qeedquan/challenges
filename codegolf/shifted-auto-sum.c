/*

Let’s take a positive integer such as 123. We define the shifted auto-sum of this integer as follows:

123 has 3 digits. We thus consider 3 copies of 123.

We stack each copy on top of each other, shifted by 1 digit each time:

123
 123
  123
We pad each copy with 0s (excluding the last one) to get a standard column addition:

12300
 1230
  123
-----
13653
Test cases
Input                Shifted auto-sum

1                    1
12                   132
100                  11100
123                  13653
6789                 7542579
4815162342           5350180379464981962

Scoring
This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
shiftsum(uvlong n)
{
	uvlong r, x;

	r = 0;
	x = n;
	do {
		r += x;
		x *= 10;
		n /= 10;
	} while (n);

	return r;
}

int
main(void)
{
	assert(shiftsum(1) == 1);
	assert(shiftsum(12) == 132);
	assert(shiftsum(100) == 11100);
	assert(shiftsum(123) == 13653);
	assert(shiftsum(6789) == 7542579ULL);
	assert(shiftsum(4815162342ULL) == 5350180379464981962ULL);

	return 0;
}
