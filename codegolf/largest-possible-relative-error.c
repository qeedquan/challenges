/*

Output
20 float64s with absolute value between 1 and 2 inclusive whose sum has the largest possible relative error. We can assume the true sum is not zero.

The sum is to be computed from left to right in a loop in the obvious fashion.

The relative error is abs(true sum - computed sum)/true sum.

Score
The relative error you achieve. Larger is better.

This is different Find 10 float64s that give the least accurate sum which asks about absolute error. Good answers to that question will not be good answers to this question.

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

Ported from @Bubbler solution

Got a hint from l4m2's solution that I can keep increasing the error while coming back to e.

*/

void
solve()
{
	double e = pow(2.0, -52);
	double x1 = 1.0;
	double x2 = 2.0 - e;
	double x3 = 2.0 - e * 2.0;
	double x4 = 2.0 - e * 4.0;
	double x5 = 2.0 - e * 8.0;
	double y1 = -1.875 - e * 8.0;
	double y2 = -1.875 - e * 4.0;
	double y3 = -1.875 - e * 2.0;
	double y4 = -1.875 - e * 1.0;
	double y5 = -2.0;
	double y6 = -2.0 + e * 65.0;
	double v[] = {
		x1, x2, x3, x3, x4, x4, x4, x4, x5, x5,
		y1, y2, y2, y2, y2, y3, y3, y4, y5, y6
	};
	double errors[] = {
		x1 - 1.0, x2 - 2.0, x3 - 2.0, x3 - 2.0, x4 - 2.0,
		x4 - 2.0, x4 - 2.0, x4 - 2.0, x5 - 2.0, x5 - 2.0,
		y1 + 1.875, y2 + 1.875, y2 + 1.875, y2 + 1.875, y2 + 1.875,
		y3 + 1.875, y3 + 1.875, y4 + 1.875, y5 + 2.0, y6 + 2.0
	};
	double sum = 0.0;
	double true_sum = 0.0;
	for (size_t i = 0; i < nelem(v); i++) {
		sum += v[i];
		true_sum += errors[i];
	}

	for (size_t i = 0; i < nelem(v); i++) {
		printf("% .6f ", v[i]);
		if ((i & 7) == 7)
			printf("\n");
	}
	printf("\n");
	printf("True: %.60f\n", true_sum);
	printf("Got:  %.60f\n", sum);
	printf("Rel.Error: %.10f\n", fabs(sum - true_sum) / fabs(true_sum));
}

int
main()
{
	solve();
	return 0;
}
