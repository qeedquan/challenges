/*

The goal of this challenge is to extend the OEIS sequence A334581.

Number of ways to choose 3 points that form an equilateral triangle from the binomial(n+2, 3) points in a regular tetrahedral grid of side length n.

The sequence begins 0, 0, 4, 24, 84, 224, 516, 1068, ...

Example
For example, if we take side lengths of n=4, as in the example below, there are binomial(4+2, 3)=20 vertices and binomial(20, 3)=1140 ways to choose three of them.
Of these, there are 84 ways to choose 3vertices that form an equilateral triangle:

https://i.sstatic.net/dhf87.gif

Challenge
This fastest-code challenge will have you compute as many terms of the sequence [A334581(0), A334581(1), ...] that you can in ten minutes, as measured on my machine.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

double
distance(double x1, double x2, double y1, double y2, double z1, double z2)
{
	double dx, dy, dz;

	dx = x1 - x2;
	dy = y1 - y2;
	dz = z1 - z2;
	return (dx * dx) + (dy * dy) + (dz * dz);
}

// ported from @Arnauld solution
// https://oeis.org/A334581
uvlong
count(uvlong n)
{
	static const double eps = 1e-9;

	double r0, r1, r2;
	double S1, S2, S3;

	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;

	double X1, Y1, Z1;
	double X2, Y2, Z2;
	double X3, Y3, Z3;

	uvlong cnt;

	r0 = sqrt(8.0 / 3);
	r1 = 2.0 / 3;
	r2 = sqrt(3.0);
	cnt = 0;

	for (z1 = 0; z1 < n; z1++) {
		Z1 = z1 * r0;
		for (y1 = 0; y1 <= z1; y1++) {
			Y1 = (y1 - z1 * r1) * r2;
			for (x1 = 0; x1 <= y1; x1++) {
				X1 = 2 * x1 - y1;
				for (z2 = z1; z2 < n; z2++) {
					Z2 = z2 * r0;
					for (y2 = (z2 > z1) ? 0 : y1; y2 <= z2; y2++) {
						Y2 = (y2 - z2 * r1) * r2;
						for (x2 = z2 > z1 || y2 > y1 ? 0 : x1 + 1; x2 <= y2; x2++) {
							X2 = 2 * x2 - y2;
							S1 = distance(X1, X2, Y1, Y2, Z1, Z2);
							for (z3 = z2; z3 < n; z3++) {
								Z3 = z3 * r0;
								for (y3 = (z3 > z2) ? 0 : y2; y3 <= z3; y3++) {
									Y3 = (y3 - z3 * r1) * r2;
									for (x3 = (z3 > z2 || y3 > y2) ? 0 : x2 + 1; x3 <= y3; x3++) {
										X3 = 2 * x3 - y3;
										S2 = distance(X1, X3, Y1, Y3, Z1, Z3);
										if (fabs(S1 - S2) < eps) {
											S3 = distance(X2, X3, Y2, Y3, Z2, Z3);
											if (fabs(S1 - S3) < eps) {
												cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int
main()
{
	static const uvlong tab[] = {
		0, 4, 24, 84, 224, 516, 1068, 2016, 3528, 5832, 9256, 14208, 21180,
		30728, 43488, 60192, 81660, 108828, 142764, 184708
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++) {
		assert(count(i + 1) == tab[i]);
	}
	return 0;
}
