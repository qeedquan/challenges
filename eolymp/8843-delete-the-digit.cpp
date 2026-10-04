/*

Positive integer n is given. Delete the rightmost digit from it (the digit of units).

Input
One positive integer n (n>9).

Output
Print the updated number.

Examples

Input #1
512

Answer #1
51

*/

#include <cassert>

int solve(int n)
{
	return n / 10;
}

int main()
{
	assert(solve(512) == 51);

	return 0;
}
