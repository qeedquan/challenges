/*

The Chef had a box with N numbers arranged inside it: A1, A2, ..., AN.
He also had the number N at the front, so that he knows how many numbers are in it.
That is, the box actually contains N+1 numbers. But in his excitement due the ongoing IOI,
he started dancing with the box in his pocket, and the N+1 numbers got jumbled up.
So now, he no longer knows which of the N+1 numbers is N, and which the actual numbers are.

He wants to find the largest of the N numbers. Help him find this.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
find(int *a, ssize_t n)
{
	ssize_t i, s;
	int m;

	if (n == 0)
		return INT_MIN;

	m = INT_MIN;
	s = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == n - 1)
			s++;
		if (m < a[i] && (a[i] != n - 1 || s != 1))
			m = a[i];
	}
	return m;
}

int
main(void)
{
	int a[] = { 1, 2, 1 };
	int b[] = { 3, 1, 2, 8 };
	int c[] = { 1, 5, 1, 4, 3, 2 };
	int d[] = { 1, 3, 3 };

	printf("%d\n", find(a, nelem(a)));
	printf("%d\n", find(b, nelem(b)));
	printf("%d\n", find(c, nelem(c)));
	printf("%d\n", find(d, nelem(d)));

	return 0;
}
