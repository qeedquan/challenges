/*

The program receives a natural number m as input, which represents a weight in grams.
Your task is to output the whole number of kilograms that this weight corresponds to.

Input
A natural number m, m≤10^12.

Output
The number of complete kilograms in the given weight.

Examples

Input #1
1234

Answer #1
1

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	return n / 1000;
}

int
main()
{
	assert(solve(1234) == 1);

	return 0;
}
