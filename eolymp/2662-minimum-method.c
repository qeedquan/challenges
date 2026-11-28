/*

The array is sorted using the selection sort method in ascending order.
How many times does the first element in the original array change its position?

Input
The first line contains the number of elements in the array n (1≤n≤1000).
The second line contains the array itself.
It is guaranteed that all array elements are different and their absolute value does not exceed 10^9.

Output
Print the number of movements of the first element.

Examples
Input #1
3
1 3 2

Answer #1
0

Input #2
2
2 1

Answer #2
1

Input #3
4
4 1 5 3

Answer #3
3

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

size_t
solve(int *a, size_t n)
{
	size_t i, j, r;
	int f, m;

	if (n == 0)
		return 0;

	f = a[0];
	for (r = i = 0; i < n - 1; i++) {
		m = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[m])
				m = j;
		}
		if ((a[i] == f || a[m] == f) && a[i] != a[m])
			r++;

		swap(&a[i], &a[m]);
	}
	return r;
}

int
main()
{
	int a1[] = { 1, 3, 2 };
	int a2[] = { 2, 1 };
	int a3[] = { 4, 1, 5, 3 };

	assert(solve(a1, nelem(a1)) == 0);
	assert(solve(a2, nelem(a2)) == 1);
	assert(solve(a3, nelem(a3)) == 3);

	return 0;
}
