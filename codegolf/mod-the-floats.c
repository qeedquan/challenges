/*

3D-modeling software mainly uses UV Mapping to map textures onto a 3D object. The valid values for both U and V are usually located in an inclusive [0..1] range.

Challenge
You bought a new 3D-modeling software which is super-easy to use. However there is one issue with it: it adds or subtracts a random integer number from UV values.
Your task is to create a program or a function that modifies an input value to get a float value in an inclusive [0..1] range.

The resulting float should have the same fractional part as the original, and be as close to the original as possible. Because both 0 and 1 are in the output range, any integers 0 or less should change to 0, and any integers 1 or greater should change to 1.

An example algorithm in JavaScript:

function modFloat(input) {
    while (input < 0 || input > 1) {
        if (input < 0) input += 1;
        if (input > 1) input -= 1;
    }
    return input;
}

Rules
Input is a single integer or float value. Any reasonable format is allowed as long as it is specified in your answer.
The output should be a decimal representation of a float value.
The output precision should be at least same decimal places as input.
Trailing zeros are allowed.
Be sure your code correctly chooses which of 0 or 1 to output for integer inputs.
Test cases
Input       | Output
------------+---------
         -4 | 0
         -1 | 0
          0 | 0
          1 | 1
          2 | 1
     1.0001 | 0.000100
 678.123456 | 0.123456
-678.123456 | 0.876544
        4.5 | 0.5
This is code-golf, so the shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
modflt(double x)
{
	while (x < 0)
		x++;
	while (x > 1)
		x--;
	return x;
}

void
test(double x, double r)
{
	double p;

	p = modflt(x);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(-4, 0);
	test(-1, 0);
	test(0, 0);
	test(1, 1);
	test(2, 1);
	test(1.0001, 0.000100);
	test(678.123456, 0.123456);
	test(-678.123456, 0.876544);
	test(4.5, 0.5);

	return 0;
}
