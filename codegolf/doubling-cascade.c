/*

First, a mathematical interlude, short, and worth your while:

If 0 < a < 4, the logistic function f(x) = ax(1-x) maps the interval [0,1] inside itself. This means that one can play the iteration game; for instance, if a=2, the initial value 0.3 becomes 0.42, then 0.4872, etc.

As the parameter a increases, the quadratic function f becomes more complicated in the following sense:

0 < a < 1 all initial values iterate toward 0.
1 < a < 3 0 becomes repelling, but there is a new fixed point (a-1)/a that attracts all iterations.
3 < a < 1+sqrt(6) the new fixed point becomes repelling, but a cycle of 2 attracting points appears.
3.44949... < a < 3.54409... the 2-cycle becomes repelling, but a cycle of 4 attracting points appears.
etc.
Feigenbaum noticed that the lengths of these parameter intervals decrease at a rate that gets closer and closer to 4.6692..., the Feigenbaum constant. The wonderful discovery is that this period 2 bifurcation sequence is a general phenomenon shared by any function that (like the quadratic parabola) is increasing, then decreasing. This was one of the first reports on the universality of chaos.

Now for the challenge! Write the shortest possible code that computes the Feigenbaum constant to an accuracy of your choice. The point here is not to cheat the system by encoding a number that you googled, but to actually have the computer find the value. For reference, here is the constant to 30 digits:

4.669201609102990671853203821578

*/

#include <stdio.h>

/*

https://en.wikipedia.org/wiki/Feigenbaum_constants
https://code.activestate.com/recipes/577464-feigenbaum-constant-calculation/
http://keithbriggs.info/documents/how-to-calc.pdf
https://oeis.org/A006890

*/

double
feigenbaum()
{
	static const int I = 13;
	static const int J = 10;

	double a1, a2, d1;
	double x, y;
	double a, d;
	int i, j, k;

	a1 = 1;
	a2 = 0;
	d1 = 3.2;
	for (i = 2; i < I; i++) {
		a = a1 + (a1 - a2) / d1;
		for (j = 0; j < J; j++) {
			x = y = 0;
			for (k = 0; k < (1 << i); k++) {
				y = 1 - (2 * y * x);
				x = a - (x * x);
			}
			a -= x / y;
		}
		d = (a1 - a2) / (a - a1);
		d1 = d;
		a2 = a1;
		a1 = a;
	}
	return d;
}

int
main()
{
	printf("%f\n", feigenbaum());
	return 0;
}
