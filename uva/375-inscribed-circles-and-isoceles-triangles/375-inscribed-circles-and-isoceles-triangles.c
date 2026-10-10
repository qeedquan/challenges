#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
solve(double B, double H)
{
	static const double eps = 1e-6;
	double area, L, R, T, C;

	area = (B * H) / 2;
	C = 0;
	L = (sqrt((H * H) + (B * B / 4)) * 2) + B;
	R = area * 2 / L;
	while (R >= eps) {
		C += 2 * M_PI * R;
		T = H;
		H -= 2 * R;
		R *= H / T;
	}
	return C;
}

int
main()
{
	printf("%f\n", solve(0.263451, 0.263451));

	return 0;
}
