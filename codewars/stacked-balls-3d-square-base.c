/*

Background
I have stacked some cannon balls in a square pyramid.

Like this,

https://i.imgur.com/6d5Kpva.png

Kata Task
Given the number of layers of my stack, what is the total height?

Return the height as multiple of the ball diameter.

Example
The image above shows a stack of 4 layers.

Notes
layers >= 0
approximate answers (within 0.001) are good enoughq

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
stackheight(double layers)
{
	if (layers < 1)
		return 0;
	return 1 + (layers - 1) * M_SQRT1_2;
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
	test(2, 1.7071);
	return 0;
}
