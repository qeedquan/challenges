/*

Description

There is an area bounded by a fence on some flat field. The fence has the height h and in the plane projection it has a form of a closed polygonal line (without self-intersections), which is specified by Cartesian coordinates (Xi, Yi) of its N vertices. At the point with coordinates (0, 0) a lamp stands on the field. The lamp may be located either outside or inside the fence, but not on its side as it is shown in the following sample pictures (parts shown in a thin line are not illuminated by the lamp):

http://poj.org/images/1031_1.jpg

The fence is perfectly black, i.e. it is neither reflecting, nor diffusing, nor letting the light through. Research and experiments showed that the following law expresses the intensity of light falling on an arbitrary illuminated point of this fence:
I0=k/r

where k is a known constant value not depending on the point in question, r is the distance between this point and the lamp in the plane projection. The illumination of an infinitesimal narrow vertical board with the width dl and the height h is
dI=I0*|cosα|*dl*h

where I0 is the intensity of light on that board of the fence, α is the angle in the plane projection between the normal to the side of the fence at this point and the direction to the lamp.
You are to write a program that will find the total illumination of the fence that is defined as the sum of illuminations of all its illuminated boards.
Input

The first line of the input file contains the numbers k, h and N, separated by spaces. k and h are real constants. N (3 <= N <= 100) is the number of vertices of the fence. Then N lines follow, every line contains two real numbers Xi and Yi, separated by a space.
Output

Write to the output file the total illumination of the fence rounded to the second digit after the decimal point.
Sample Input

0.5 1.7 3
1.0 3.0
2.0 -1.0
-4.0 -1.0

Sample Output

5.34

Source

Northeastern Europe 1998

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define TAU (2 * M_PI)

typedef struct {
	double x, y;
} Point;

double
angle(Point p)
{
	double a, r;

	r = hypot(p.x, p.y);
	a = acos(p.x / r);
	if (p.y < 0)
		a = TAU - a;
	return a;
}

double
cover(double a0, double a1)
{
	if (a1 - a0 > M_PI)
		a0 += TAU;
	if (a0 - a1 > M_PI)
		a1 += TAU;
	return a1 - a0;
}

double
illumination(double k, double h, Point *p, size_t n)
{
	double min, max, sum;
	double pa, na, fa;
	size_t i;

	if (n == 0)
		return 0;

	min = max = sum = 0;
	fa = pa = angle(p[0]);
	for (i = 1; i < n; i++) {
		na = angle(p[i]);
		sum += cover(pa, na);
		min = fmin(min, sum);
		max = fmax(max, sum);
		pa = na;
		if (max - min >= TAU)
			break;
	}

	if (max - min < TAU) {
		sum += cover(pa, fa);
		min = fmin(min, sum);
		max = fmax(max, sum);
	}

	return k * h * fmin(max - min, TAU);
}

void
test(double k, double h, Point *p, size_t n, double r)
{
	double v;

	v = illumination(k, h, p, n);
	printf("%.2f\n", v);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	Point p1[] = {
	    {1.0, 3.0},
	    {2.0, -1.0},
	    {-4.0, -1.0},
	};

	Point p2[] = {
	    {0.0, 1.0},
	    {-0.5, 0.5},
	    {0.0, -1.0},
	    {-1.0, -0.5},
	    {0.0, -2.0},
	    {2.0, 0},
	};

	Point p3[] = {
	    {0.0, 1.0},
	    {1.0, 0.0},
	    {0.0, -1.0},
	    {-1.0, 0.0},
	    {0.0, -2.0},
	    {2.0, 0},
	};

	Point p4[] = {
	    {2.07, -13.61},
	    {3.00, -14.20},
	    {-0.00, -10.04},
	    {1.86, -11.80},
	    {3.39, -12.20},
	    {0.26, -9.71},
	    {1.50, -10.13},
	    {0.76, -9.49},
	    {0.41, -9.07},
	    {5.08, -10.77},
	    {5.58, -10.38},
	    {3.31, -9.47},
	    {3.83, -9.07},
	    {2.57, -8.64},
	    {5.82, -8.30},
	    {2.22, -7.97},
	    {0.49, -7.87},
	    {3.86, -7.37},
	    {3.04, -6.92},
	    {0.49, -7.31},
	    {0.60, -7.09},
	    {0.02, -7.23},
	    {3.53, -5.52},
	    {2.63, -5.57},
	    {2.90, -5.01},
	    {-0.27, -6.71},
	    {0.64, -5.78},
	    {-0.46, -6.50},
	    {-0.41, -6.35},
	    {2.21, -3.15},
	    {0.50, -4.28},
	    {1.65, -1.86},
	    {0.68, -2.91},
	    {0.24, -3.12},
	    {0.86, -1.22},
	    {0.12, -1.79},
	    {-0.14, -0.25},
	    {-0.81, -0.28},
	    {-1.40, -2.44},
	    {-1.82, -3.45},
	    {-2.16, -3.32},
	    {-2.34, -4.22},
	    {-2.89, -0.51},
	    {-2.54, -5.47},
	    {-3.49, -1.88},
	    {-3.84, -2.44},
	    {-3.88, -2.93},
	    {-3.40, -4.97},
	    {-3.92, -4.42},
	    {-5.70, -2.52},
	    {-6.50, -1.99},
	    {-3.99, -5.67},
	    {-5.81, -4.00},
	    {-3.99, -6.04},
	    {-3.57, -6.67},
	    {-3.83, -6.74},
	    {-8.21, -3.85},
	    {-8.67, -4.49},
	    {-3.98, -7.09},
	    {-6.19, -6.24},
	    {-4.09, -7.36},
	    {-5.11, -7.19},
	    {-6.31, -7.10},
	    {-6.43, -7.47},
	    {-7.10, -7.71},
	    {-4.44, -7.99},
	    {-6.50, -8.28},
	    {-6.86, -8.53},
	    {-9.64, -9.68},
	    {-9.41, -10.02},
	    {-6.45, -9.50},
	    {-6.99, -10.13},
	    {-7.88, -10.71},
	    {-8.06, -11.49},
	    {-7.10, -11.48},
	    {-4.35, -9.67},
	    {-4.76, -10.20},
	    {-6.53, -12.47},
	    {-5.46, -11.80},
	    {-4.70, -11.27},
	    {-6.18, -13.54},
	    {-3.24, -9.90},
	    {-4.04, -11.55},
	    {-3.71, -11.52},
	    {-2.90, -10.46},
	    {-2.81, -10.53},
	    {-2.66, -10.49},
	    {-2.61, -11.38},
	    {-2.27, -10.39},
	    {-2.42, -14.36},
	    {-1.93, -11.18},
	    {-1.48, -15.52},
	    {-1.26, -13.19},
	    {-0.72, -14.68},
	    {-1.24, -10.99},
	    {-1.26, -10.41},
	    {-0.46, -11.60},
	    {-1.09, -9.87},
	    {1.23, -14.03},
	    {1.78, -14.05},
	};

	test(0.5, 1.7, p1, nelem(p1), 5.34);
	test(0.5, 1.7, p2, nelem(p2), 5.34);
	test(0.5, 1.7, p3, nelem(p3), 4.01);
	test(5.06, 4.04, p4, nelem(p4), 43.37);

	return 0;
}
