#include <stdio.h>

double
solve(int T, int, int B, double Z[][2])
{
	double R, S, P;
	int i;

	R = 0;
	for (i = 0; i < T; i++) {
		S = Z[i][0];
		P = Z[i][1];
		R += S * (100 - P) / 100.0;
	}
	return R / B;
}

int
main()
{
	double Z1[][2] = {
		{ 100.00, 90 },
		{ 40.40, 70 },
		{ 60.30, 70 },
		{ 40.40, 80 },
		{ 40.40, 85 },
		{ 40.40, 88 },
	};

	double Z2[][2] = {
		{ 12.34, 100 },
	};

	printf("%.2f\n", solve(6, 3, 90, Z1));
	printf("%.2f\n", solve(1, 1, 56, Z2));

	return 0;
}
