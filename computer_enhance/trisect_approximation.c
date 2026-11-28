/*

https://iquilezles.org/articles/trisect/

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

float
f(float x)
{
	return cos(acos(x) / 3.0);
}

float
g1(float x)
{
	x = sqrt(0.5 + 0.5 * x);
	return x * 0.5 + 0.5;
}

float
g2(float x)
{
	x = sqrt(0.5 + 0.5 * x);
	return x * (-0.064913 * x + 0.564913) + 0.5;
}

float
g3(float x)
{
	x = sqrt(0.5 + 0.5 * x);
	return x * (x * (x * 0.021338 - 0.096562) + 0.575223) + 0.5;
}

float
g4(float x)
{
	x = sqrt(0.5 + 0.5 * x);
	return x * (x * (x * (x * -0.008978 + 0.039075) - 0.107071) + 0.576974) + 0.5;
}

int
main()
{
	double x, y1, y2, y3, y4, y5;
	double e1, e2, e3, e4;

	e1 = 0;
	for (x = 0; x <= M_PI; x += 1e-5) {
		y1 = f(x);
		y2 = g1(x);
		y3 = g2(x);
		y4 = g3(x);
		y5 = g4(x);
		e1 = fmax(e1, fabs(y1 - y2));
		e2 = fmax(e2, fabs(y1 - y3));
		e3 = fmax(e3, fabs(y1 - y4));
		e4 = fmax(e4, fabs(y1 - y5));
	}
	printf("Max Error: %f %f %f %f\n", e1, e2, e3, e4);

	return 0;
}
