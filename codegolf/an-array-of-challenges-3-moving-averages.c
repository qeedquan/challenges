/*

Moving Average of a List
The moving average of a list is a calculation resulting in a new, smoothed out list, created by averaging small overlapping sublists of the original.

When creating a moving average, we first generate the list of overlapping sublists using a certain 'window size', shifting this window to the right once each time.

For example, given the list [8, 4, 6, 2, 2, 4] and the window size 3, the sublists would be:

[8,  4,  6,  2,  2,  4]          Sublists:
(         )                  <-  [8, 4, 6]
    (         )              <-  [4, 6, 2]
        (         )          <-  [6, 2, 2]
            (         )      <-  [2, 2, 4]
We then calculate the mean average of each sublist to obtain the result: [6.0, 4.0, 3.3, 2.7] (each value rounded to one decimal place).

The Challenge
Your task is to write a program or function which, given a list L, and an integer 1 ≤ n ≤ length(L), calculate the moving average for L using the window size n.

Rules:

Your program may use integer division or float division. In the case of float division, small inaccuracies due to the data type's limitations are permitted, as long as the value is otherwise correct.
You may submit a full program, or a function (but not a snippet).
You may assume that the list will only contain positive integers.
Standard loopholes are forbidden.
This is code-golf, so the shortest answer (in bytes) wins!
Test Cases
Note that, for ease of readability, all values are rounded to one decimal place.

n=5, [1, 2, 3, 4, 5, 6, 7, 8]      ->      [3, 4, 5, 6]
n=3, [100, 502, 350, 223, 195]     ->      [317.3, 358.3, 256]
n=1, [10, 10, 10]                  ->      [10, 10, 10]
n=3, [10, 20, 30]                  ->      [20]
n=2, [90, 40, 45, 100, 101]        ->      [65, 42.5, 72.5, 100.5]

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
sma(int *a, size_t l, size_t n)
{
	size_t i, j;
	double s;

	if (n == 0 || n > l) {
		printf("\n");
		return;
	}

	for (i = 0; i + n <= l; i++) {
		s = 0;
		for (j = n; j > 0; j--)
			s += a[i + j - 1];
		printf("%.1f ", s / n);
	}
	printf("\n");
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int a2[] = { 100, 502, 350, 223, 195 };
	int a3[] = { 10, 10, 10 };
	int a4[] = { 10, 20, 30 };
	int a5[] = { 90, 40, 45, 100, 101 };

	sma(a1, nelem(a1), 5);
	sma(a2, nelem(a2), 3);
	sma(a3, nelem(a3), 1);
	sma(a4, nelem(a4), 3);
	sma(a5, nelem(a5), 2);

	return 0;
}
