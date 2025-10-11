/*

Task
N candles are placed in a row, some of them are initially lit. For each candle from the 1st to the Nth the following algorithm is applied: if the observed candle is lit then states of this candle and all candles before it are changed to the opposite. Which candles will remain lit after applying the algorithm to all candles in the order they are placed in the line?

Example
For a = [1, 1, 1, 1, 1], the output should be [0, 1, 0, 1, 0].

Check out the image below for better understanding:

https://codefightsuserpics.s3.amazonaws.com/tasks/switchLights/img/example.png?_tm=1484040239470

For a = [0, 0], the output should be [0, 0].

The candles are not initially lit, so their states are not altered by the algorithm.

Input/Output
[input] integer array a

Initial situation - array of zeros and ones of length N, 1 means that the corresponding candle is lit.

Constraints: 2 ≤ a.length ≤ 5000.

[output] an integer array

Situation after applying the algorithm - array in the same format as input with the same length.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
switchlights(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		if (!a[i])
			continue;

		for (j = 0; j <= i; j++)
			a[j] = !a[j];
	}
}

void
test(int *a, size_t n, int *r)
{
	switchlights(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {1, 1, 1, 1, 1};
	int a2[] = {0, 0};
	int a3[] = {1, 0, 0, 1, 0, 1, 0, 1};
	int a4[] = {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1};

	int r1[] = {0, 1, 0, 1, 0};
	int r2[] = {0, 0};
	int r3[] = {1, 1, 1, 0, 0, 1, 1, 0};
	int r4[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
