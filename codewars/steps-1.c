/*

Consider the process of stepping from integer x to integer y along integer points of the straight line. The length of
each step must be non-negative, and must be either one bigger, or equal to, or one smaller than, the length of the
previous step. The length of the first and last steps must be 1.

Create a function that computes the minimum number of steps needed to go from x to y. It should handle 0 <= x <= y < 2^31.

Source: Problem 6.6.8 from Skiena & Revilla, "Programming Challenges".

Examples:

x = 45, y = 48: Clearly the steps are 46,47,48, so the result is 3.

x = 45, y = 49: We can take one 2-step: 46,48,49, so the result is still 3.

x = 45, y = 50: Still one 2-step: 46,48,49,50, so the result is 4.

x = 45, y = 51: Two 2-steps: 46,48,50,51, so the result remains 4.

And so on.

Having the function consider the different possibilities in this way is not practical for large values. What
characterizes these optimal sequences of steps? The example tests might help.

*/

#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

long
step(double x, double y)
{
	double z, w;

	z = (y > x) ? 1 : 0;
	w = 4 * (y - x) - z;
	return sqrt(fmax(w, 0));
}

int
main()
{
	assert(0 == step(0, 0));
	assert(0 == step(45, 45));
	assert(1 == step(45, 46));
	assert(2 == step(45, 47));
	assert(3 == step(45, 48));
	assert(3 == step(45, 49));
	assert(4 == step(45, 50));
	assert(4 == step(45, 51));
	assert(5 == step(45, 52));
	assert(5 == step(45, 53));
	assert(5 == step(45, 54));
	assert(6 == step(45, 55));
	assert(6 == step(45, 56));
	assert(6 == step(45, 57));
	assert(7 == step(45, 58));
	assert(8 == step(45, 62));
	assert(9 == step(45, 66));
	assert(10 == step(45, 71));
	assert(92681 == step(1, INT32_MAX));

	return 0;
}
