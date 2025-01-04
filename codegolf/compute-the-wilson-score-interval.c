/*

The Wilson score interval is a confidence interval of the probability of success, based on the proportion of successes in a set of Bernoulli trials (a Bernoulli trial is a trial in which exactly two outcomes are possible: success or failure). The interval is given by the following formula:

1/(n + z^2) * (n_s + 0.5*z^2 +- z*sqrt(1/n*n_s*n_f + 0.25*z^2))

The two values given by the formula are the upper and lower bounds of the interval. nS and nF are the number of successes and failures, respectively, and n is the total number of trials (equivalent to nS + nF). z is a parameter dependent on the level of confidence desired. For the purposes of this challenge, z = 1.96 will be used (corresponding to a 95% confidence interval)1.

Given non-negative integers nS and nF, output the bounds of the Wilson score interval.

Rules
The outputs must be as accurate as possible to the true values, within the limits of your language's floating-point implementation, ignoring any potential issues due to floating-point arithmetic inaccuracies. If your language is capable of arbitrary-precision arithmetic, it must be at least as precise as IEEE 754 double-precision arithmetic.
The inputs will be within the representable range for your language's native integer type, and the outputs will be within the representable range for your language's native floating-point type.
n will always be positive.
The order of the outputs does not matter.
Test Cases
Format: n_s, n_f => lower, upper

0, 1 => 0.0, 0.7934567085261071
1, 0 => 0.20654329147389294, 1.0
1, 1 => 0.09452865480086611, 0.905471345199134
1, 10 => 0.016231752262825982, 0.3773646254862038
10, 1 => 0.6226353745137962, 0.9837682477371741
10, 90 => 0.05522854161313612, 0.1743673043676654
90, 10 => 0.8256326956323345, 0.9447714583868639
25, 75 => 0.17545094003724265, 0.3430464637007583
75, 25 => 0.6569535362992417, 0.8245490599627573
50, 50 => 0.40382982859014716, 0.5961701714098528
0, 100 => 0.0, 0.03699480747600191
100, 0 => 0.9630051925239981, 1.0
The z value is the 1-α/2th quantile of the standard normal distribution, where α is the significance level. If you want a 95% confidence interval, your significance level is α=0.05, and the z value is 1.96.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
wilsonscore(double s, double f, double r[2])
{
	double a, b, c, d;
	double n, z;

	n = s + f;
	z = 1.96;

	a = s;
	b = 0.5 * z * z;
	c = z * sqrt(((s * f) / n) + (0.25 * z * z));
	d = n + (z * z);

	r[0] = (a + b - c) / d;
	r[1] = (a + b + c) / d;
}

void
test(double s, double f, double r0, double r1)
{
	static const double eps = 1e-8;

	double w[2];

	wilsonscore(s, f, w);
	printf("%f %f\n", w[0], w[1]);
	assert(fabs(w[0] - r0) < eps);
	assert(fabs(w[1] - r1) < eps);
}

int
main(void)
{
	test(0, 1, 0.0, 0.7934567085261071);
	test(1, 0, 0.20654329147389294, 1.0);
	test(1, 1, 0.09452865480086611, 0.905471345199134);
	test(1, 10, 0.016231752262825982, 0.3773646254862038);
	test(10, 1, 0.6226353745137962, 0.9837682477371741);
	test(10, 90, 0.05522854161313612, 0.1743673043676654);
	test(90, 10, 0.8256326956323345, 0.9447714583868639);
	test(25, 75, 0.17545094003724265, 0.3430464637007583);
	test(75, 25, 0.6569535362992417, 0.8245490599627573);
	test(50, 50, 0.40382982859014716, 0.5961701714098528);
	test(0, 100, 0.0, 0.03699480747600191);
	test(100, 0, 0.9630051925239981, 1.0);

	return 0;
}
