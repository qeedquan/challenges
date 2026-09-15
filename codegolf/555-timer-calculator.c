/*

The Challenge
In honour of getting 555 Rep, here's a little challenge to work out the frequency of a 555 Timer. The frequency can be worked out using

f = 1.44/((R1 + 2(R2))C1)
Implement this in the shortest code possible!

Test Cases
(Assume positive float input, r1/2 will be in ohms, c1 will always be in uF, output can be rounded int or float in hz)

R1 (ohms), R2 (ohms), C1 (uF) -> Freq (HZ, rounded)
1.0,1.0,1.0 -> 480000Hz
1000.0, 1000.0, 10.2 -> 47hz
569.6, 123.7, 0.5 -> 3525hz

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
freq(double r1, double r2, double c1)
{
	return 144e4 / (c1 * (r1 + (2 * r2)));
}

void
test(double r1, double r2, double c1, double r)
{
	double f;

	f = freq(r1, r2, c1);
	printf("%.3f\n", f);
	assert(fabs(f - r) < 1e-1);
}

int
main()
{
	test(1.0, 1.0, 1.0, 480000);
	test(1000.0, 1000.0, 10.2, 47);
	test(569.6, 123.7, 0.5, 3525);
	return 0;
}
