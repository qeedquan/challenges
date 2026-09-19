/*

Task
A cake is sliced with n straight lines. Your task is to calculate the maximum number of pieces the cake can have.

Example
For n = 0, the output should be 1.

For n = 1, the output should be 2.

For n = 2, the output should be 4.

For n = 3, the output should be 7.

See the following image to understand it:

https://cdn2.scratch.mit.edu/get_image/project/92275349_500x400.png?v=1450672809.79

Input/Output
[input] integer n

0 ≤ n ≤ 10000

[output] an integer

The maximum number of pieces the sliced cake can have.

*/

#include <assert.h>

int
cakeslice(int n)
{
	return ((n * n) + (n + 2)) / 2;
}

int
main()
{
	assert(cakeslice(0) == 1);
	assert(cakeslice(1) == 2);
	assert(cakeslice(2) == 4);
	assert(cakeslice(3) == 7);
	assert(cakeslice(10) == 56);

	return 0;
}
