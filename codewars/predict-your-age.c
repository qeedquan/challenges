/*

My grandfather always predicted how old people would get, and right before he passed away he revealed his secret!

In honor of my grandfather's memory we will write a function using his formula!

Take a list of ages when each of your great-grandparent died.
Multiply each number by itself.
Add them all together.
Take the square root of the result.
Divide by two.
Example
predictAge(65, 60, 75, 55, 60, 63, 64, 45) === 86
Note: the result should be rounded down to the nearest integer.

Some random tests might fail due to a bug in the JavaScript implementation. Simply resubmit if that happens to you.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
predict(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i] * a[i];
	return sqrt(r) / 2;
}

int
main()
{
	int a1[] = {65, 60, 75, 55, 60, 63, 64, 45};

	assert(predict(a1, nelem(a1)) == 86);
	return 0;
}
