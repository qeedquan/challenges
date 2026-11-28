/*

The task is simple: given a 32 bit integer, convert it to its floating point value as defined by the IEEE 754 (32-bit) standard.
To put it another way, interpret the integer as the bit-pattern of an IEEE binary32 single-precision float and output the numeric value it represents.

IEEE 754 single precision

Here is a converter for your reference.
https://www.h-schmidt.net/FloatConverter/IEEE754.html

Here is how the format looks, from Wikipedia's excellent article:
https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/Float_example.svg/885px-Float_example.svg.png

The standard is similar to scientific notation.

The sign bit determines whether the output is negative or positive. If the bit is set, the number is negative otherwise it is positive.

The exponent bit determines the exponent (base 2), it's value is offset by 127. Therefore the exponent is 2^(n-127) where n is the integer representation of the exponent bits.

The mantissa defines a floating point number in the range [1,2). The way it represents the number is like binary, the most significant bit is 12, the one to the right is 14, the next one is 18 and so on... A one by default is added to the value, implied by a non-zero exponent.

Now the final number is:

Now the final number is:
sign*2^(exponent-127)*mantissa

Test cases
1078523331 ->   3.1400001049041748046875
1076719780 ->   2.71000003814697265625
1036831949 ->   0.100000001490116119384765625
3264511895 -> -74.24919891357421875
1056964608 ->   0.5
3205496832 ->  -0.5625
0          ->   0.0
2147483648 ->  -0.0 (or 0.0)

For this challenge assume that cases like NaN and inf are not going to be the inputs, and subnormals need not be handled (except for 0.0 which works like a subnormal, with the all-zero exponent implying a leading 0 bit for the all-zero mantissa.) You may output 0 for the case where the number represented is -0.

This is code-golf, so the shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

float
int2flt(uint32_t x)
{
	float f;

	memcpy(&f, &x, sizeof(x));
	return f;
}

void
test(uint32_t x, float r)
{
	float f;

	f = int2flt(x);
	assert(fabs(f - r) < 1e-24);
}

int
main()
{
	test(1078523331, 3.1400001049041748046875);
	test(1076719780, 2.71000003814697265625);
	test(1036831949, 0.100000001490116119384765625);
	test(3264511895, -74.24919891357421875);
	test(1056964608, 0.5);
	test(3205496832, -0.5625);
	test(0, 0.0);
	test(2147483648, -0.0);

	return 0;
}
