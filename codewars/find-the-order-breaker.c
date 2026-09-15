/*

In this kata, you have an integer array which was ordered by ascending except one number.

For Example: [1,2,3,4,17,5,6,7,8]
For Example: [19,27,33,34,112,578,116,170,800]
You need to figure out the first breaker. Breaker is the item, when removed from sequence, sequence becomes ordered by ascending.

For Example: [1,2,3,4,17,5,6,7,8] => 17 is the only breaker.

For Example: [19,27,33,34,112,578,116,170,800] => 578 is the only breaker.

For Example: [105, 110, 111, 112, 114, 113, 115] => 114 and 113 are breakers. 114 is the first breaker.
    When removed 114, sequence becomes ordered by ascending => [105, 110, 111, 112, 113, 115]
    When removed 113, sequence becomes ordered by ascending => [105, 110, 111, 112, 114, 115]

For Example: [1, 0, 2] => 1 and 0 are the breakers. 1 is the first breaker.
    When removed 1, sequence becomes ordered by ascending => [0, 2]
    When removed 0, sequence becomes ordered by ascending => [1, 2]

For Example: [1, 2, 0, 3, 4] => 0 is the only breaker.
    When removed 0, sequence becomes ordered by ascending. => [1, 2, 3, 4]

TASK:
Write a function that returns the first breaker.

Notes:

Input array does not contain any duplicate element.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
check(size_t i, int *a, size_t n)
{
	if (i == n - 1 && a[i] < a[i - 1])
		return true;
	if (i == 0 && a[i] > a[i + 1])
		return true;
	if (i > 0 && i < n - 1 && a[i - 1] < a[i + 1] && (a[i] > a[i + 1] || a[i] < a[i - 1]))
		return true;
	return false;
}

int
orderbreaker(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (check(i, a, n))
			return a[i];
	}
	return -1;
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 17, 5, 6, 7, 8 };
	int a2[] = { 19, 27, 33, 34, 112, 578, 116, 170, 800 };
	int a3[] = { 105, 110, 111, 112, 114, 113, 115 };
	int a4[] = { 1, 0, 2 };
	int a5[] = { 1, 2, 0, 3, 4 };

	assert(orderbreaker(a1, nelem(a1)) == 17);
	assert(orderbreaker(a2, nelem(a2)) == 578);
	assert(orderbreaker(a3, nelem(a3)) == 114);
	assert(orderbreaker(a4, nelem(a4)) == 1);
	assert(orderbreaker(a5, nelem(a5)) == 0);

	return 0;
}
