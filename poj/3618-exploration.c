/*

Description

Bessie is traveling on a road teeming with interesting landmarks. The road is labeled just like a number line, and Bessie starts at the "origin" (x = 0). A total of N (1 ≤ N ≤ 50,000) landmarks are located at points x1, x2, ..., xN (-100,000 ≤ xi ≤ 100,000). Bessie wants to visit as many landmarks as possible before sundown, which occurs in T (1 ≤ T ≤ 1,000,000,000) minutes. She travels 1 distance unit in 1 minute.

Bessie will visit the landmarks in a particular order. Since the landmarks closer to the origin are more important to Farmer John, she always heads for the unvisited landmark closest to the origin. No two landmarks will be the same distance away from the origin.

Help Bessie determine the maximum number of landmarks she can visit before the day ends.

Input

* Line 1: Two space-separated integers: T and N
* Lines 2..N+1: Line i+1 contains a single integer that is the location of the ith landmark: xi

Output

* Line 1: The maximum number of landmarks Bessie can visit.

Sample Input

25 5
10
-3
8
-7
1

Sample Output

4

Source

USACO 2007 November Bronze

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;

	x = abs(x);
	y = abs(y);

	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
landmarks(int t, int *a, size_t n)
{
	int d, p;
	size_t i;

	qsort(a, n, sizeof(*a), cmp);

	d = p = 0;
	for (i = 0; i < n; i++) {
		d += abs(a[i] - p);
		if (d > t)
			break;
		p = a[i];
	}
	return i;
}

int
main(void)
{
	int a1[] = {10, -3, 8, -7, 1};

	assert(landmarks(25, a1, nelem(a1)) == 4);

	return 0;
}
