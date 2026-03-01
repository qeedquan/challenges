/*

Your wet dog rand across your hardwood floor. It drops a series of water droplets randomly across the floor. The water droplets each land at particular positions on your infinite floor, and they each create a wet circle of a given radius across the floor.

What is the total area of wet? The input file will be a list of drop descriptions, one per line. Each drop description is three floating point numbers of the format x0 y0 radius, describing the center of the circle and the radius.

Estimate the area of wet accurate to 3 decimal places.

Example input file:

0.479477  -0.634017   0.137317
-0.568894  -0.450312  0.211238
-0.907263  -0.434144   0.668432
0.279875   0.309700   0.242502
-0.999968  -0.910107  0.455271
0.889064  -0.864342  1.292949
-0.701553   0.285499  0.321359
-0.947186   0.261604  0.028034
0.805749  -0.175108   0.688808
0.813269  -0.117034  0.340474
-0.630897  -0.659249  0.298656
-0.054129  -0.661273  0.270216
0.042748   0.469534  0.759090
0.079393  -0.803786   0.635903
-0.987166   0.561186   0.740386
-0.246960  -0.774309   1.035616
-0.189155  -0.244443  0.187699
0.683683  -0.569687   0.275045
-0.249028  -0.452500   0.713051
-0.070789  -0.898363   0.135069
Example output: (warning: flawed mod solution might be wrong)

Total wet area: 12.065 (UPDATE: 9.73178 is the correct answer)
EDIT: I apologize, I generated the radii randomly and didn't notice some were negative. My solution simply takes the absolute value of the radius by default. (I'm using an r2) so it didn't matter. I'm fixing the data now.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

double
sq(double x)
{
	return x * x;
}

double
rnd(double x, double d)
{
	return x + (d * drand48());
}

ulong
covered(double v[][3], size_t n, double x, double y)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (sq(x - v[i][0]) + sq(y - v[i][1]) < v[i][2])
			return 1;
	}
	return 0;
}

// Ported from @Ledrug solution
// Standard Monte Carlo, with sigma estimates.
void
sim(double v[][3], size_t n)
{
	static const double eps = 1e-3;

	double x0, y0;
	double x1, y1;
	double *p;

	double total;
	double area;
	double r, s;

	ulong tries;
	ulong ntries;
	ulong hit;

	size_t i;

	x0 = y0 = 1;
	x1 = y1 = -1;
	for (i = 0; i < n; i++) {
		p = v[i];
		x0 = fmin(x0, p[0] - p[2]);
		x1 = fmax(x1, p[0] + p[2]);
		y0 = fmin(y0, p[1] - p[2]);
		y1 = fmax(y1, p[1] + p[2]);
		p[2] *= p[2];
	}

	x1 -= x0;
	y1 -= y0;

	total = x1 * y1;
	tries = 0;
	ntries = 65536;
	hit = 0;
	for (;;) {
		hit += covered(v, n, rnd(x0, x1), rnd(y0, y1));
		if (++tries >= ntries) {
			area = total * hit / tries;
			r = hit * 1.0 / tries;
			s = area * sqrt(r * (1 - r) / tries);
			printf("%.4f +/- %.4f\n", area, s);

			// stop at 3 sigma
			if (s * 3 <= eps)
				break;

			ntries *= 2;
		}
	}
}

int
main()
{
	double data[][3] = {
		{ 0.479477,  -0.634017, 0.137317 },
		{ -0.568894, -0.450312, 0.211238 },
		{ -0.907263, -0.434144, 0.668432 },
		{ 0.279875,  0.309700,  0.242502 },
		{ -0.999968, -0.910107, 0.455271 },
		{ 0.889064,  -0.864342, 1.292949 },
		{ -0.701553, 0.285499,  0.321359 },
		{ -0.947186, 0.261604,  0.028034 },
		{ 0.805749,  -0.175108, 0.688808 },
		{ 0.813269,  -0.117034, 0.340474 },
		{ -0.630897, -0.659249, 0.298656 },
		{ -0.054129, -0.661273, 0.270216 },
		{ 0.042748,  0.469534,  0.759090 },
		{ 0.079393,  -0.803786, 0.635903 },
		{ -0.987166, 0.561186,  0.740386 },
		{ -0.246960, -0.774309, 1.035616 },
		{ -0.189155, -0.244443, 0.187699 },
		{ 0.683683,  -0.569687, 0.275045 },
		{ -0.249028, -0.452500, 0.713051 },
		{ -0.070789, -0.898363, 0.135069 }
	};

	srand48(time(NULL));
	sim(data, nelem(data));
	return 0;
}
