/*

You are tasked with planning a flying route for a local airplane delivery company. You need to route an airplane from point A to point B. You just can't start at A, point the airplane at B, and go, however, as the prevailing winds will blow you off course. Instead you need to figure out which direction you should point the airplane so that it will fly directly to B, taking the wind into account.

input

7 floating-point numbers, encoding A_x, A_y, B_x, B_y, S, W_x, W_y. These are the coordinates of your start and destination, the airspeed of your airplane, and the strength of the wind along the x and y axes (the direction the wind blows to, not from).

output

You should print the angle in degrees (rotating counterclockwise from the positive x axis) that the plane should point to reach B in a straight line. Print GROUNDED if the wind is so strong as to make the trip impossible.

You may round to the nearest degree, and do so with any method you would like (up/down/nearest/...).

examples

inputs

0 0 10 0 100 0 -50
0 0 10 0 50 -55 0
3.3 9.1 -2.7 1.1 95.0 8.8 1.7
outputs

30
GROUNDED
229
Shortest code wins.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define rad2deg(x) ((x)*180 / M_PI)

/*

@DCharness


$X = crosswind component, $T = tailwind component. We're grounded if the tailwind is actually a headwind (i.e., negative) and stronger than our airspeed.
Otherwise, $C is the wind correction angle that we subtract from our course $c to get our heading.
We need to turn far enough to balance the crosswind with the cross-track component of our velocity.

*/

double
navigate(double Ax, double Ay, double Bx, double By, double S, double Wx, double Wy)
{
	double A, C, R, T, X, c;

	c = atan2(By - Ay, Bx - Ax);
	A = atan2(Wy, Wx);
	R = hypot(Wx, Wy);
	X = R * sin(A - c);
	T = R * cos(A - c);
	C = asin(X / S);
	if (-T > (S * cos(C)))
		return -1;
	return fmod(360 + rad2deg(c - C), 360);
}

void
test(double Ax, double Ay, double Bx, double By, double S, double Wx, double Wy, double r)
{
	double v;

	v = navigate(Ax, Ay, Bx, By, S, Wx, Wy);
	printf("%f\n", v);
	assert(fabs(v - r) < 1);
}

int
main(void)
{
	test(0, 0, 10, 0, 100, 0, -50, 30);
	test(0, 0, 10, 0, 50, -55, 0, -1);
	test(3.3, 9.1, -2.7, 1.1, 95.0, 8.8, 1.7, 229);

	return 0;
}
