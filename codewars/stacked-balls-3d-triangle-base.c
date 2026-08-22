/*

Background
I have stacked some cannon balls in a triangle-based pyramid.

Like this,

https://i.imgur.com/ut4ejG1.png

Kata Task
Given the number of layers of my stack, what is the total height?

Return the height as multiple of the ball diameter.

Example
The image above shows a stack of 3 layers.

Notes
layers >= 0
approximate answers (within 0.001) are good enough

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
stackheight(double layers)
{
	if (layers < 1)
		return 0;
	return 1 + (layers - 1) * sqrt(2.0 / 3);
}

void
test(double layers, double expected)
{
	double value;

	value = stackheight(layers);
	printf("%f\n", value);
	assert(fabs(value - expected) < 1e-3);
}

int
main()
{
	test(0, 0);
	test(1, 1);
	test(2, 1.816);
	return 0;
}
