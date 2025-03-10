/*

Background
I have stacked some pool balls in a triangle.

Like this,

https://imgur.com/RuDkTCH

Kata Task
Given the number of layers of my stack, what is the total height?

Return the height as multiple of the ball diameter.

Example
The image above shows a stack of 5 layers.

Notes
layers >= 0
approximate answers (within 0.001) are good enough

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define SQRT3 1.732050807568877293527446341505872366942805253810380628055806

double
stackheight2d(double layers)
{
	if (layers < 1)
		return 0;
	return (layers - 1) * (SQRT3 / 2) + 1;
}

void
test(double layers, double expected)
{
	double height;

	height = stackheight2d(layers);
	printf("%.3f\n", height);
	assert(fabs(height - expected) < 1e-3);
}

int
main()
{
	test(1, 1);
	test(2, 1.866);

	return 0;
}
