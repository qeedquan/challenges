/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
plusone(int *a, size_t n)
{
	size_t i;
	int c;

	if (n == 0)
		return;

	c = 1;
	for (i = n - 1;; i--) {
		a[i] += c;
		if (a[i] >= 10)
			a[i] %= 10;
		else
			break;

		if (i == 0)
			break;
	}
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n)
{
	plusone(a, n);
	print(a, n);
}

int
main(void)
{
	int a[] = { 1, 2, 3 };
	int b[] = { 4, 3, 2, 1 };
	int c[] = { 0, 9, 9, 9 };
	int d[] = { 1, 0, 9, 9 };
	int e[] = { 0 };

	test(a, nelem(a));
	test(b, nelem(b));
	test(c, nelem(c));
	test(d, nelem(d));
	test(e, nelem(e));

	return 0;
}
