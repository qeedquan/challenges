/*

Inspired by this on Spiked Math:
http://spikedmath.com/357.html
(source: spikedmath.com)

In this code golf, you are going to write a numerical integrator. Instead of weighting, you first plot on a graphic canvas pixel-by-pixel or plot on a 2D array, then calculate the integral by counting the colored pixels.

You are implementing a function with the following arguments:

f: the function, in lambda or function pointer
xmin, xmax: the interval, also the familiar window settings on a typical graphic calculator
ymin, ymax: window settings for y-axis, note: it is the caller's responsibility to choose ymax, because the function can go over ymax, and the parts went over will not be counted.
xres, yres: resolution of the plot: size of the canvas or the dimensions of the 2D array
Here is an explanation:

To integrate sin(x) from 1.0 to 8.0 with y = -1.0 to 1.0, and resolution 30 * 15, first plot

 ++++                       ++
++++++                     +++
+++++++                   ++++
++++++++                 +++++
++++++++                 +++++
+++++++++               ++++++
+++++++++              +++++++
          -------------
           -----------
           -----------
            ---------
            --------
             -------
              -----
Count the total number of +s: 83 total number of -s: 64 and N = 83 - 64 = 19

(the formula for N is actually
https://i.stack.imgur.com/wbehE.gif

notice xres-1, x never equal to xres, don't make this off-by-one error )
and calculate the integral:

N / canvas size * window area
= (N / (xres * yres) ) * ((ymax - ymin) * (xmax - xmin))
= 19 / (30 * 15) * ((1 - (-1)) * (8 - 1))
~= 0.5911
Shortest code wins.

Test cases:

| f(x)       |  xmin |  xmax |  ymin | ymax  | xres | yres | S f(x) dx |
| 3          |  0.0  |  10.0 |   0.0 |   2.0 |   25 |   25 |  20.0     |
| 3          |  0.0  |  10.0 |   0.0 |   5.0 |    5 |    5 |  30.0     |
| 3          |  0.0  |  10.0 |   0.0 |   4.0 |    5 |    5 |  32.0     |
| 2x + 2     | -5.0  |   5.0 | -10.0 |  10.0 |   50 |   50 |  18.72    |
| 2x + 2     | -5.0  |   5.0 | -20.0 |  20.0 |  500 |  500 |  20.1648  |
| x^2        |  0.0  |  10.0 |   0.0 | 120.0 |   10 |   10 | 348.0     |
| x^2        |  0.0  |  10.0 |   0.0 | 120.0 |  100 |  100 | 335.88    |
| x^2        |  0.0  |  10.0 |   0.0 | 120.0 |  500 |  500 | 333.6768  |
| x^2 sin(x) | -3.14 |  3.14 |  -5.0 |   5.0 |   50 |   50 |   0.60288 |
| x^2 sin(x) | -3.14 |  3.14 |  -5.0 |   5.0 | 1500 | 1500 |   0.02085 |
| sin(x^2)   |  0.0  | 10.0  |  -1.0 |   1.0 |  250 |   50 |   0.7808  |
| sin(x^2)   |  0.0  | 10.0  |  -1.0 |   1.0 | 1000 | 1000 |   0.59628 |

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef double (*fn)(double);

double
f1(double)
{
	return 3;
}

double
f2(double x)
{
	return (2 * x) + 2;
}

double
f3(double x)
{
	return x * x;
}

double
f4(double x)
{
	return x * x * sin(x);
}

double
f5(double x)
{
	return sin(x * x);
}

double
plow(fn f, double xmin, double xmax, double ymin, double ymax, int xres, int yres)
{
	double fx, fy, fv;
	double n;
	int x, y;

	n = 0;
	for (y = 0; y < yres; y++) {
		for (x = 0; x < xres; x++) {
			fx = ((x * (xmax - xmin)) / xres) + xmin;
			fy = ((y * (ymax - ymin)) / yres) + ymin;
			fv = f(fx);
			if (fy < fv && fy >= 0)
				n++;
			else if (fy > fv && fy < 0)
				n--;
		}
	}
	return (n / (xres * yres)) * ((ymax - ymin) * (xmax - xmin));
}

void
test(fn f, double xmin, double xmax, double ymin, double ymax, int xres, int yres, double expected)
{
	static const double eps = 1e-4;
	double value;

	value = plow(f, xmin, xmax, ymin, ymax, xres, yres);
	printf("%f\n", value);
	assert(fabs(value - expected) < eps);
}

int
main(void)
{
	test(sin, 1, 8, -1, 1, 30, 15, 0.5911);
	test(f1, 0, 10, 0, 2, 25, 25, 20);
	test(f1, 0, 10, 0, 5, 5, 5, 30);
	test(f1, 0, 10, 0, 4, 5, 5, 32);
	test(f2, -5, 5, -10, 10, 50, 50, 18.72);
	test(f2, -5, 5, -20, 20, 500, 500, 20.1648);
	test(f3, 0, 10, 0, 120, 10, 10, 348);
	test(f3, 0, 10, 0, 120, 100, 100, 335.88);
	test(f3, 0, 10, 0, 120, 500, 500, 333.6768);
	test(f4, -3.14, 3.14, -5.0, 5.0, 50, 50, 0.60288);
	test(f4, -3.14, 3.14, -5.0, 5.0, 1500, 1500, 0.020850);
	test(f5, 0.0, 10.0, -1.0, 1.0, 250, 50, 0.7808);
	test(f5, 0.0, 10.0, -1.0, 1.0, 1000, 1000, 0.59628);

	return 0;
}
