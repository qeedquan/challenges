#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double
NPV(double CF[], int T, double IRR)
{
	double npv;
	int i;

	npv = CF[0];
	for (i = 1; i <= T; ++i)
		npv += CF[i] / pow(1.0 + IRR, i);
	return npv;
}

double
solve(double CF[], int T)
{
	static const double EPS = 1e-9;

	double L, U, IRR;
	double M, npv;

	L = -0.99;
	U = DBL_MAX;
	IRR = -1.0;
	while (L <= U + EPS) {
		M = (L + U) / 2.0;
		npv = NPV(CF, T, M);
		if (fabs(npv) <= EPS) {
			IRR = M;
			break;
		}
		if (npv > EPS)
			L = M;
		else
			U = M;
	}
	if (fabs(IRR + 1.0) <= EPS)
		return NAN;
	return IRR;
}

int
main()
{

	double CF1[] = { -1, 2 };
	double CF2[] = { -8, 6, 9 };

	printf("%f\n", solve(CF1, 1));
	printf("%f\n", solve(CF2, 2));
	return 0;
}
