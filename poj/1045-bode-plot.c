/*

Description

Consider the AC circuit below. We will assume that the circuit is in steady-state. Thus, the voltage at nodes 1 and 2 are given by v1 = VS coswt and v2 = VRcos (wt + q ) where VS is the voltage of the source, w is the frequency (in radians per second), and t is time. VR is the magnitude of the voltage drop across the resistor, and q is its phase.

http://poj.org/images/1045/bode.jpg

You are to write a program to determine VR for different values of w. You will need two laws of electricity to solve this problem. The first is Ohm's Law, which states v2 = iR where i is the current in the circuit, oriented clockwise. The second is i = C d/dt (v1-v2) which relates the current to the voltage on either side of the capacitor. "d/dt"indicates the derivative with respect to t.

Input

The input will consist of one or more lines. The first line contains three real numbers and a non-negative integer. The real numbers are VS, R, and C, in that order. The integer, n, is the number of test cases. The following n lines of the input will have one real number per line. Each of these numbers is the angular frequency, w.

Output

For each angular frequency in the input you are to output its corresponding VR on a single line. Each VR value output should be rounded to three digits after the decimal point.

Sample Input

1.0 1.0 1.0 9
0.01
0.031623
0.1
0.31623
1.0
3.1623
10.0
31.623
100.0

Sample Output

0.010
0.032
0.100
0.302
0.707
0.953
0.995
1.000
1.000

Source

Greater New York 2001

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

Given
v1 = Vs*cos(w*t)
v2 = Vr*cos(w*t + q)
i = C * d/dt(v1 - v2)

Plug in v1 and v2

i = C * d/dt(Vs*cos(w*t) - Vr*cos(w*t + q))

Use ohm's law

iR = R*C * d/dt(Vs*cos(w*t) - Vr*cos(w*t + q))

iR = C*R*w * (Vr*sin(w*t + q) - Vs*sin(w*t))

Since we want to solve for Vr we can use the following relation:

Vr*cos(w*t + q) = C*R*w * (Vr*sin(w*t + q) - Vs*sin(w*t))

Solving for Vr gives
Vr = C*R*w*Vs / sqrt(1 + (R*C*w)^2)

*/

double
Vr(double Vs, double R, double C, double w)
{
	return (Vs * R * C * w) / sqrt(1 + pow(R * C * w, 2));
}

void
test(double Vs, double R, double C, double w, double r)
{
	double p;

	p = Vr(Vs, R, C, w);
	printf("%.3f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	double Vs, R, C;

	Vs = 1;
	R = 1;
	C = 1;
	test(Vs, R, C, 0.01, 0.010);
	test(Vs, R, C, 0.031623, 0.032);
	test(Vs, R, C, 0.1, 0.100);
	test(Vs, R, C, 0.31623, 0.302);
	test(Vs, R, C, 1.0, 0.707);
	test(Vs, R, C, 3.1623, 0.953);
	test(Vs, R, C, 10.0, 0.995);
	test(Vs, R, C, 31.623, 1.000);
	test(Vs, R, C, 100.0, 1.000);

	return 0;
}
