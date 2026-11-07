/*

Definition
The cardinal sine function, commonly denoted as sinc(x), is defined as below in mathematics:

sinc(x) = sin(x) / x

In digital signal processing and information theory, this function is defined slightly differently (stretched in the x-direction by a factor of 1 / pi) and called the "normalized cardinal sine" instead but this is outside the scope of this Kata (source: Wikipedia).

Origins
In the mid 19th century, a man by the name of Philip M. Woodward noted in his paper "Information theory and inverse probability in telecommunication" that the expression sin(x) / x occurred in Fourier analysis and its applications with such frequency that it probably should merit a notation of its own (source: Wikipedia). After all, one can save a lot of time by writing all occurrences of sin(x) / x as simply sinc(x) and the resulting working out would also look much cleaner.

Preloaded
Preloaded is a class ComplexNumber which is used to represent a complex number in this Kata. Its class constructor can receive two arguments, $x/x and $y/y, where x is the real component of the complex number and y is the imaginary component. The first argument is required while the second argument is optional; if not provided, $y/y will default to 0. For example:

$z = new ComplexNumber(3, 4); // 3 + 4i
$w = new ComplexNumber(5); // 5 (+ 0i)
Its real and imaginary components are protected (and readonly in C#) properties which means that you cannot directly access / assign to them outside of the class itself; an attempt to do so will throw an error/exception. To extract the imaginary and real components of a ComplexNumber, use the functions Im()/Im and Re()/Re respectively which have also been preloaded for you (C#: ComplexNumber.Im and ComplexNumber.Re):

$z = new ComplexNumber(3, 4); // 3 + 4i
echo Im($z) . "\r\n"; // prints 4
echo Re($z) . "\r\n"; // prints 3
Task
Implement the (unnormalized) cardinal sine function as described above (JavaScript: Math.sinc, PHP: sinc(), C#: Complex.Sinc). Sounds easy, right? You're probably thinking of the following code:

function sinc($x) {
  return sin($x) / $x;
}
However, there's a caveat - your function should work for all complex numbers on top of the usual real numbers (e.g. integers and floats) and should type-check its argument(s) as well. Below is the precise specification that your function should follow:

Specification
Your function should accept exactly 1 required argument $z/z which could be a real or complex number (or invalid). In C# this means that z can be any of: int, float, double, ComplexNumber.

Input Validation
You may not assume that all input passed into your function is valid. If $z/z is not a real or complex number, your function must throw: InvalidArgumentException in PHP, anything in JavaScript. You may assume that all valid $z/z passed into your function are finite.

Return Type
Regardless of whether the valid $z/z passed in is a real (integer/float/Number/double) or complex number, you must always return an instance of ComplexNumber.

Edge Cases
While the expression sin(x) / x is undefined for x = 0 due to an attempt at division by zero, the cardinal sine function is defined such that sinc(0) = 1 which makes it holomorphic on the complex plane and an entire function. Therefore, when a real or complex number representing the quantity 0 is passed into your function, your function should return an instance of ComplexNumber that represents the real number 1.

Getting Stuck?
No problem - in that case, you may want to attempt and complete this Kata first which will hopefully provide you with a useful hint as to how to tackle this Kata.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex
sinc(double complex z)
{
	if (z == 0)
		return 1;
	return csin(z) / z;
}

void
test(double complex z, double complex r)
{
	static const double eps = 1e-12;

	double complex v;

	v = sinc(z);
	printf("%f + %fi\n", creal(v), cimag(v));
	assert(fabs(creal(v) - creal(r)) < eps);
	assert(fabs(cimag(v) - cimag(r)) < eps);
}

int
main()
{
	test(1, 0.841470984807897);
	test(-2.5, 0.239388857641583);
	test(CMPLX(3, 4), CMPLX(-3.860241556730304, -3.858615677027573));
	return 0;
}
