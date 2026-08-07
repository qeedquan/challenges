/*

Description

For a given number, if greater than ten, round it to the nearest ten, then (if that result is greater than 100) take the result and round it to the nearest hundred, then (if that result is greater than 1000) take that number and round it to the nearest thousand, and so on ...

Input

Input to this problem will begin with a line containing a single integer n indicating the number of integers to round. The next n lines each contain a single integer x (0 <= x <= 99999999).

Output

For each integer in the input, display the rounded integer on its own line.

Note: Round up on fives.

Sample Input

9
15
14
4
5
99
12345678
44444445
1445
446

Sample Output

20
10
4
5
100
10000000
50000000
2000
500

Source

South Central USA 2006

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
rounder(uvlong n)
{
	uvlong i;

	for (i = 0; n > 10; i++) {
		if ((n % 10) >= 5)
			n += 10;
		n /= 10;
	}

	for (; i > 0; i--)
		n *= 10;

	return n;
}

int
main(void)
{

	assert(rounder(15ULL) == 20ULL);
	assert(rounder(14ULL) == 10ULL);
	assert(rounder(4ULL) == 4ULL);
	assert(rounder(5ULL) == 5ULL);
	assert(rounder(99ULL) == 100ULL);
	assert(rounder(12345678ULL) == 10000000ULL);
	assert(rounder(44444445ULL) == 50000000ULL);
	assert(rounder(1445ULL) == 2000ULL);
	assert(rounder(446ULL) == 500ULL);

	return 0;
}
