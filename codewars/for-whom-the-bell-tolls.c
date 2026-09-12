/*

For whom the Bell tolls
Write a function bell that will receive a positive integer and return an array. That's all splaining you receive; what needs to be done you'll have to figure out with the examples below.

 n => resulting array

 1 => [1]
 2 => [2, 2]
 3 => [3, 4, 3]
 4 => [4, 6, 6, 4]
 5 => [5, 8, 9, 8, 5]
 6 => [6, 10, 12, 12, 10, 6]
 7 => [7, 12, 15, 16, 15, 12, 7]
 8 => [8, 14, 18, 20, 20, 18, 14, 8]
 9 => [9, 16, 21, 24, 25, 24, 21, 16, 9]
10 => [10, 18, 24, 28, 30, 30, 28, 24, 18, 10]
11 => [11, 20, 27, 32, 35, 36, 35, 32, 27, 20, 11]
12 => [12, 22, 30, 36, 40, 42, 42, 40, 36, 30, 22, 12]

*/

#include <stdio.h>

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
bell(size_t n, int *r)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			r[j] += j + 1;
		r[i] = i + 1;
	}
}

void
test(size_t n)
{
	int b[128];

	bell(n, b);
	print(b, n);
}

int
main()
{
	size_t i;

	for (i = 1; i <= 12; i++)
		test(i);
	return 0;
}
