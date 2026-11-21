/*

The length of a cryptocurrency code is k bits. How many bytes are needed to store this code in a computer's RAM?

Input
A natural number k that does not exceed 10^12.

Output
Provide the number of bytes required.

Examples

Input #1
27

Answer #1
4

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	return ceil(n / 8.0);
}

int
main()
{
	assert(solve(27) == 4);

	return 0;
}
