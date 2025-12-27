/*

Part 2/3 of my kata series. Part 1 ( http://www.codewars.com/kata/riemann-sums-i-left-side-rule )

The description changes little in this second part. Here we simply want to improve our approximation of the integral by using trapezoids instead of rectangles. The left/right side rules have a serious bias and the trapezoidal rules averages those approximations! The same assumptions exist but are pasted here for convenience.

f will always take a single float argument
f will always be a "nice" function, don't worry about NaN
n will always be a natural number (0, N]
b > a
and n will be chosen appropriately given the length of [a, b] (as in I will not have step sizes smaller than machine epsilon)
answers will be checked within a delta of 0.01

*/

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

typedef double (*fn)(double);

double quadratic(double x)
{
	return x * x;
}

double trapezoidal(fn f, int n, double a, double b)
{
	double h = (b - a) / n;
	double s = (f(a) + f(b)) / 2;
	for (int i = 1; i < n; i++)
		s += f(a + (i * h));
	return h * s;
}

void test(fn f, int n, double a, double b, double r)
{
	double v = trapezoidal(f, n, a, b);
	cout << v << endl;
	assert(fabs(v - r) < 1e-2);
}

int main()
{
	test(quadratic, 1, 0, 1, 0.5);
	test(quadratic, 10, 0, 1, 0.335);
	test(quadratic, 100, 0, 1, 0.33335);
	test(quadratic, 100, -1, 1, 0.6668);
	return 0;
}
