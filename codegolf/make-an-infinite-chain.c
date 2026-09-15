/*

Lets define a class of functions. These functions will map from the positive integers to the positive integers and must satisfy the following requirements:

The function must be Bijective, meaning that every value maps to and is mapped to by exactly one value.

You must be able to get from any positive integer to any other positive integer by repeated applications of the function or its inverse.

Now, write some code that will perform any one function in this class on its input.

This is a code-golf question so answers will be scored in bytes, with less bytes being better.

*/

#include <stdio.h>
#include <math.h>

// @Dennis: lambda n:n-(-1)**n*2 or 1
int
f(int x)
{
	int r;

	r = x - (2 * pow(-1, x));
	return (r) ? r : 1;
}

int
main(void)
{
	int i;

	for (i = 1; i <= 20; i++)
		printf("%d -> %d\n", i, f(i));

	return 0;
}
