/*

You are given an array a consisting of n integers. The array is sorted if a1≤a2≤⋯≤an.

You want to make the array a sorted by applying the following operation exactly once:

choose an integer x, then for every i∈[1,n], replace ai by |ai−x|.
Find any value of x that will make the array sorted, or report that there is no such value.

Input
The first line contains one integer t (1≤t≤2⋅10^4) — the number of test cases.

Each test case consists of two lines. The first line contains one integer n (2≤n≤2⋅10^5). The second line contains n integers a1,a2,…,an (1≤ai≤10^8).

Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, print any integer x (0≤x≤10^9) that makes the array sorted. It can be shown that if such an integer x exists, there is at least one such integer between 0 and 10^9.

If there is no such integer, then print −1. If there are multiple suitable values of x, print any of them.

Example

input
8
5
5 3 3 3 5
4
5 3 4 5
8
1 2 3 4 5 6 7 8
6
10 5 4 3 2 1
3
3 3 1
3
42 43 42
2
100000000 99999999
6
29613295 52036613 75100585 78027446 81409090 73215

output
4
-1
0
42
2
-1
100000000
40741153

Note
In the first test case, after using x=4, the array becomes [1,1,1,1,1].

In the third test case, after using x=0, the array becomes [1,2,3,4,5,6,7,8].

In the fourth test case, after using x=42, the array becomes [32,37,38,39,40,41].

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
sorted(long *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1])
			return false;
	}
	return true;
}

void
subabs(long *a, size_t n, long x)
{
	size_t i;

	for (i = 0; i < n; i++)
		a[i] = labs(a[i] - x);
}

long
findx(long *a, size_t n)
{
	long l, r;
	size_t i;

	l = 0;
	r = LONG_MAX;
	for (i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			r = min(r, (a[i] + a[i - 1]) / 2);
		else if (a[i] < a[i - 1])
			l = max(l, (a[i] + a[i - 1] + 1) / 2);
	}
	return (l > r) ? -1 : l;
}

void
test(long *a, size_t n, long r)
{
	long x;

	x = findx(a, n);
	printf("%ld %ld\n", x, r);

	if (x >= 0) {
		subabs(a, n, x);
		assert(sorted(a, n));
	} else
		assert(x == r);
}

int
main(void)
{
	long a1[] = {5, 3, 3, 3, 5};
	long a2[] = {5, 3, 4, 5};
	long a3[] = {1, 2, 3, 4, 5, 6, 7, 8};
	long a4[] = {10, 5, 4, 3, 2, 1};
	long a5[] = {3, 3, 1};
	long a6[] = {42, 43, 42};
	long a7[] = {100000000L, 99999999L};
	long a8[] = {29613295L, 52036613L, 75100585L, 78027446L, 81409090L, 73215L};

	test(a1, nelem(a1), 4);
	test(a2, nelem(a2), -1);
	test(a3, nelem(a3), 0);
	test(a4, nelem(a4), 42);
	test(a5, nelem(a5), 2);
	test(a6, nelem(a6), -1);
	test(a7, nelem(a7), 100000000L);
	test(a8, nelem(a8), 40741153L);

	return 0;
}
