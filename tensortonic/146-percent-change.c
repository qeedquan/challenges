/*

Percent change measures the relative change between consecutive observations. For each index i beginning at 1, compute

p[i] = (x[i] - x[i-1]) / x[i-1]

The numerator is the current value minus the previous value, and the denominator is the previous value.
If the previous value is zero, use 0.0 for that position.
Return the consecutive fractional changes as a list.

Examples
Input: series = [100, 110, 105]

Output: [0.1, -0.045455]

Explanation: The first change is 10 / 100, and the second is -5 / 110.

Input: series = [50, 100, 200]

Output: [1.0, 1.0]

Hint 1
Begin the loop at index 1 so both the current and previous values exist.

Hint 2
Check the previous value before performing the division.

Requirements
Compute one fractional change for each consecutive pair.
Divide by the previous value.
Use 0.0 when the previous value is zero.
Return a list with len(series) - 1 values.
Constraints
series contains at least two numeric values.
Time limit: 300 ms.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
percent_change(double *series, size_t length, double *result)
{
	size_t i;

	for (i = 1; i < length; i++)
		result[i - 1] = (series[i] - series[i - 1]) / series[i - 1];
}

void
test(double *series, size_t length, double *expected)
{
	double percent[16];
	size_t i;

	percent_change(series, length, percent);
	for (i = 0; i < length - 1; i++) {
		printf("%f ", percent[i]);
		assert(fabs(percent[i] - expected[i]) < 1e-4);
	}
	printf("\n");
}

int
main()
{
	double series_1[] = { 100, 110, 105 };
	double series_2[] = { 50, 100, 200 };

	double result_1[] = { 0.1, -0.045455 };
	double result_2[] = { 1.0, 1.0 };

	test(series_1, nelem(series_1), result_1);
	test(series_2, nelem(series_2), result_2);

	return 0;
}
