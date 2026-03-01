/*

When an object is moving very fast (at relativistic speeds), time begins to slow down and length begins to contract.

The Lorenz factor describes the time dilation and the length contraction by the formula

γ=1/sqrt(1-v^2/c^2)
where c is the speed of light and v is the speed of the object in question. First, write a function that calculates the Lorentz factor with the function declaration:

double lorentz_factor( double speed );
and then write two functions that determine the time dilation and length contraction that use the formulas

t′=γt
ℓ′=ℓ/γ
where t is the undilated time, and ℓ is the uncontracted length.

double time_dilation( double time, double speed );
double length_contraction( double length, double speed );

Your documentation should clearly specify the units of the parameters and the units of the return values.

Note that while the units of speed must be specified, the units of time and length need not be specified, as the calculation is simply a scalar multiple of the argument, so if the argument is in feet, the output will also be in feet, and if the argument is in seconds, the output will be in seconds.

*/

#include <stdio.h>
#include <math.h>

double
lorentz_factor(double speed)
{
	static const double c = 299792458.0;
	return 1 / sqrt(1 - (speed * speed) / (c * c));
}

double
time_dilation(double time, double speed)
{
	return lorentz_factor(speed) * time;
}

double
length_contraction(double length, double speed)
{
	return length / lorentz_factor(speed);
}

int
main(void)
{
	printf("%f\n", time_dilation(1, 1));
	printf("%f\n", length_contraction(1, 1));

	return 0;
}
