/*

Before we jump into security concepts, let us familiarize ourselves with the mathematical background required for it.

Set X is a collection of elements. Here, X = {1, 2, 3} is one such example. A collection of integers is also a set.

Given two sets, X and Y, we define a function f that maps every element in X to precisely 1 element in Y.

If X = {1, 2, 3} and Y = {a, b, c}, the function f will return:

f(1) = a, f(2) = b and f(3) = c.

Let us define a function f1(x), where x in X and xr in Y.
Here, xr is defined as the remainder of x when divided by 11.

Your task is to complete the function that takes the input x and returns xr

Constraints
1 <= x <= 1000

*/

#include <stdio.h>

int
calculate(int x)
{
	return x % 11;
}

int
main()
{
	int i;

	for (i = 1; i <= 1000; i++)
		printf("%d\n", calculate(i));
	return 0;
}
