/*

Find the number of digits in a nonnegative integer n.

Input
One nonnegative integer n (0≤n≤2*10^9).

Output
Print the number of digits in the number n.

Examples

Input #1
12343

Answer #1
5

*/

#include <cassert>

typedef unsigned int uint;

uint digits(uint n)
{
	uint c;
	for (c = 1; n >= 10; n /= 10)
		c++;
	return c;
}

int main()
{
	assert(digits(12343) == 5);

	return 0;
}
