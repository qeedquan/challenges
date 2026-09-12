/*

The task
In this challenge, you are given a number and a list. Your task is to remove from the list all occurrences of the given number except the first (leftmost) one, and output the resulting list. The other elements of the list should be left intact.

The number will be a positive integer below 1000, and the list will only contain positive integers below 1000.
The list is not guaranteed to contain any occurrences of the given number. It may even be empty. In these cases you should output the list as-is.
Input and output formats are flexible within reason. You can output by modifying the list in place.
The lowest byte count wins.

Test cases
5 [] -> []
5 [5] -> [5]
5 [5,5] -> [5]
10 [5,5] -> [5,5]
10 [5,5,10,10,5,5,10,10] -> [5,5,10,5,5]
2 [1,2,3,1,2,3,1,2,3] -> [1,2,3,1,3,1,3]
7 [9,8,7,6,5] -> [9,8,7,6,5]
7 [7,7,7,7,7,7,7,3,7,7,7,7,7,7,3,7,1,7,3] -> [7,3,3,1,3]
432 [432,567,100,432,100] -> [432,567,100,100]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
trm(int *a, size_t n, int t)
{
	size_t c, i, j;

	for (c = i = j = 0; i < n; i++) {
		c += (a[i] == t);
		if (a[i] != t || c <= 1)
			a[j++] = a[i];
	}
	return j;
}

void
test(int *a, size_t n, int t, int *r, size_t nr)
{
	size_t m;

	m = trm(a, n, t);
	assert(m == nr);
	assert(!memcmp(a, r, nr * sizeof(*r)));
}

int
main()
{
	int a1[] = { 5 };
	int a2[] = { 5, 5 };
	int a3[] = { 5, 5 };
	int a4[] = { 5, 5, 10, 10, 5, 5, 10, 10 };
	int a5[] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
	int a6[] = { 9, 8, 7, 6, 5 };
	int a7[] = { 7, 7, 7, 7, 7, 7, 7, 3, 7, 7, 7, 7, 7, 7, 3, 7, 1, 7, 3 };
	int a8[] = { 432, 567, 100, 432, 100 };

	int r1[] = { 5 };
	int r2[] = { 5 };
	int r3[] = { 5, 5 };
	int r4[] = { 5, 5, 10, 5, 5 };
	int r5[] = { 1, 2, 3, 1, 3, 1, 3 };
	int r6[] = { 9, 8, 7, 6, 5 };
	int r7[] = { 7, 3, 3, 1, 3 };
	int r8[] = { 432, 567, 100, 100 };

	test(NULL, 0, 5, NULL, 0);
	test(a1, nelem(a1), 5, r1, nelem(r1));
	test(a2, nelem(a2), 5, r2, nelem(r2));
	test(a3, nelem(a3), 10, r3, nelem(r3));
	test(a4, nelem(a4), 10, r4, nelem(r4));
	test(a5, nelem(a5), 2, r5, nelem(r5));
	test(a6, nelem(a6), 7, r6, nelem(r6));
	test(a7, nelem(a7), 7, r7, nelem(r7));
	test(a8, nelem(a8), 432, r8, nelem(r8));

	return 0;
}
