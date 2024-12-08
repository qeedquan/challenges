/*

Your program should take an array as input.

The array:

Will always be 1 dimensional
Will only contain integers
Can be empty
The program should reverse the array, and then add up the elements to the original for example:

Input: [1, 2, 3]

Original: [1, 2, 3]

Reversed: [3, 2, 1]

[1, 2, 3]
 +  +  +
[3, 2, 1]

[1+3, 2+2, 3+1]
Output: [4, 4, 4]

Test Cases:

#In             #Out
[8, 92],        [100, 100]
[1, 2, 3],      [4, 4, 4]
[5, 24, 85, 6], [11, 109, 109, 11]
[],             []
[999],          [1998]
This is code-golf, the shortest code (in bytes) wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
ras(int *a, size_t n, int *r)
{
	size_t i;

	for (i = 0; i < n; i++)
		r[i] = a[i] + a[n - i - 1];
}

void
test(int *a, size_t n, int *r)
{
	int p[32];

	ras(a, n, p);
	if (n)
		assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {8, 92};
	int a2[] = {1, 2, 3};
	int a3[] = {5, 24, 85, 6};
	int a4[] = {999};

	int r1[] = {100, 100};
	int r2[] = {4, 4, 4};
	int r3[] = {11, 109, 109, 11};
	int r4[] = {1998};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(NULL, 0, NULL);
	test(a4, nelem(a4), r4);

	return 0;
}
