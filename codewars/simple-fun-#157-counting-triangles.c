/*

Task
Given some sticks by an array V of positive integers, where V[i] represents the length of the sticks, find the number of ways we can choose three of them to form a triangle.

Example
For V = [2, 3, 7, 4], the result should be 1.

There is only (2, 3, 4) can form a triangle.

For V = [5, 6, 7, 8], the result should be 4.

(5, 6, 7), (5, 6, 8), (5, 7, 8), (6, 7, 8)

Input/Output
[input] integer array V

stick lengths

3 <= V.length <= 100

0 < V[i] <=100

[output] an integer

number of ways we can choose 3 sticks to form a triangle.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
count(int *v, size_t n)
{
	size_t i, j, k, r;

	if (n < 3)
		return 0;

	r = 0;
	for (i = 0; i < n - 2; i++) {
		for (j = i + 1; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				if (v[i] + v[j] > v[k] && v[i] + v[k] > v[j] && v[j] + v[k] > v[i])
					r++;
			}
		}
	}
	return r;
}

int
main()
{
	int v1[] = {2, 3, 7, 4};
	int v2[] = {5, 6, 7, 8};
	int v3[] = {2, 2, 2, 2};
	int v4[] = {1, 2, 5};
	int v5[] = {1, 2, 3, 10, 20, 30, 4};
	int v6[] = {1, 2, 3};

	assert(count(v1, nelem(v1)) == 1);
	assert(count(v2, nelem(v2)) == 4);
	assert(count(v3, nelem(v3)) == 4);
	assert(count(v4, nelem(v4)) == 0);
	assert(count(v5, nelem(v5)) == 1);
	assert(count(v6, nelem(v6)) == 0);
	return 0;
}
