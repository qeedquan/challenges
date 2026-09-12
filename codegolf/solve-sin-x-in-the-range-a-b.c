/*

Challenge
Given a number, x where -1 ≤ x ≤ 1, and the integers a and b, where b > a, solve the equation sin(θ) = x for θ, giving all solutions in the range a° ≤ θ ≤ b°.

Rules
x will have a maximum of three decimal places of precision. The output, θ, must also be to three decimal places, no more, no less.

Your output may be as a list or separated output.

You may use built-in trig functions.

You may not use radians for a and b.

You will never be given invalid input.

Output may be in any order.

Examples
x, a, b => outputs
0.500, 0, 360 => 30.000, 150.000
-0.200, 56, 243 => 191.537
0.000, -1080, 1080 => 0.000, 180.000, 360.000, 540.000, 720.000, 900.000, 1080.000, -1080.000 -900.000, -720.000, -540.000, -360.000, -180.000

Winning
Shortest code in bytes wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)

void
solve(double x, int a, int b)
{
	static const double step = 1e-3;
	static const double eps = 1e-6;

	double t, y;

	printf("%.3f %d %d\n", x, a, b);
	for (t = a; t <= b; t += step) {
		y = sin(deg2rad(t));
		if (fabs(x - y) < eps)
			printf("%.3f\n", t);
	}
	printf("\n");
}

int
main(void)
{
	solve(0.5, 0, 360);
	solve(-0.2, 56, 243);
	solve(0, -1080, 1080);

	return 0;
}
