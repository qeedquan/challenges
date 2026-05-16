/*

Hablu likes odd numbers a lot. So he wants the sum of all odd numbers in range [a, b]. That is, find the sum of all odd numbers i such that (a ≤ i ≤ b). Seems easy right? Because it is.

Input
The first and only line will contain 2 integers a, b where (0 ≤ a ≤ 10^8) and (0 ≤ b ≤ 10^8).

Output
In one line, output the value of the sum

*/

#include <assert.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
odds(int a, int b)
{
	int x, y;

	if (b < a)
		swap(&a, &b);

	x = a / 2;
	y = (b + 1) / 2;
	return (y * y) - (x * x);
}

int
main(void)
{
	assert(odds(0, 9) == 25);
	assert(odds(3, 9) == 24);
	assert(odds(1, 5) == 9);
	assert(odds(3, 5) == 8);

	return 0;
}
