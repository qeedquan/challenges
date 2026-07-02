/*

Find the value of x^n.

Input
Two positive integers x and n.

Output
Print the value of x^n. It is guaranteed that the result will not exceed 10^18.

Examples

Input #1
2 10

Answer #1
1024

*/

#include <cassert>
#include <cmath>

int solve(int x, int n)
{
	return pow(x, n);
}

int main()
{
	assert(solve(2, 10) == 1024);

	return 0;
}
