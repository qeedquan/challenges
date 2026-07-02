/*

Binary search is the ultimate divide-and-conquer algorithm.
To find a key k in a large file containing keys A[1..n] in sorted order, we first compare k with A[n/2], and depending on the result we recurse either on the first half of the file, A[1..n/2], or on the second half, A[n/2+1..n].
The recurrence now is T(n)=T(n/2)+O(1).
Plugging into the master theorem (with a=1,b=2,d=0) we get the familiar solution: a running time of just O(logn).

Source: Algorithms by Dasgupta, Papadimitriou, Vazirani. McGraw-Hill. 2006.

Problem
The problem is to find a given set of keys in a given array.

Given: Two positive integers n≤10^5 and m≤10^5, a sorted array A[1..n] of integers from -10^5 to 10^5 and a list of m integers -10^5≤k1,k2,…,km≤10^5.

Return: For each ki, output an index 1≤j≤n s.t. A[j]=ki or "-1" if there is no such index.

Sample Dataset
5
6
10 20 30 40 50
40 10 35 15 40 20
Sample Output
4 1 -1 -1 4 2

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *array, size_t length)
{
	size_t i;

	for (i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int
compare(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
search(int *array, size_t length, int *queries, size_t num_queries, int *result)
{
	size_t index;
	int *element;

	for (index = 0; index < num_queries; index++) {
		result[index] = -1;
		element = bsearch(&queries[index], array, length, sizeof(*array), compare);
		if (element)
			result[index] = element - array + 1;
	}
}

void
test(int *array, size_t length, int *queries, size_t num_queries, int *expected)
{
	int result[128];

	search(array, length, queries, num_queries, result);
	print(result, num_queries);
	assert(!memcmp(result, expected, sizeof(*expected) * num_queries));
}

int
main()
{
	int array[] = { 10, 20, 30, 40, 50 };
	int queries[] = { 40, 10, 35, 15, 40, 20 };
	int expected[] = { 4, 1, -1, -1, 4, 2 };

	test(array, nelem(array), queries, nelem(queries), expected);

	return 0;
}
