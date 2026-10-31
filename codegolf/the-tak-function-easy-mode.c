/*

The TAK function is defined as follows for integers x, y, z:

t(x, y, z) = y if x <= y
             t(t(x-1, y, z), t(y-1, z, x), t(z-1, x, y))

It can be proved that it always terminates and evaluates to the simple function below:

t(x, y, z) = y   if x <= y
             z   if x > y and y <= z
             x   otherwise

Your job is to implement the function. (As per the standard rules, it is OK to implement the simplified version, or anything else that evaluates to the same value for all inputs.)

You may assume that the three input values are nonnegative integers.

Standard code-golf rules apply. The shortest code in bytes wins.

For a harder challenge, check out "The TAK function".

Test cases
(x, y, z) -> output

(10, 20, 100) -> 20
(20, 20, 100) -> 20
(20, 10, 100) -> 100
(20, 10, 10) -> 10
(20, 10, 0) -> 20

*/

#include <assert.h>

int
tak(int x, int y, int z)
{
	if (x <= y)
		return y;
	if (y <= z)
		return z;
	return x;
}

int
main(void)
{
	assert(tak(10, 20, 100) == 20);
	assert(tak(20, 20, 100) == 20);
	assert(tak(20, 10, 100) == 100);
	assert(tak(20, 10, 10) == 10);
	assert(tak(20, 10, 0) == 20);

	return 0;
}
