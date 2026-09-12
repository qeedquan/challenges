/*

You are given an integer n. Using bitwise operations, replace the rightmost 1 bit in the binary representation of n with 0.

Input
One integer n (1≤n≤10^8).

Output
Print the modified integer.

Examples

Input #1
1
Answer #1
0

Input #2
18

Answer #2
16

Input #3
196

Answer #3
192

*/

#include <cassert>

typedef unsigned int uint;

uint clearlsb(uint n)
{
	if (n == 0)
		return 0;
	return n & (n - 1);
}

int main()
{
	assert(clearlsb(1) == 0);
	assert(clearlsb(18) == 16);
	assert(clearlsb(196) == 192);

	return 0;
}
