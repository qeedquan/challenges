/*

There are some packs of batteries on the Professor's table.
There are a batteries in each pack.
When the Professor took b batteries from each pack, only c batteries remained on the table.

How many packs of batteries were on the table?

Input
Three positive integers a,b,c.

Output
Print the number of packs with batteries on the table.

Examples

Input #1
6 3 15

Answer #1
5

*/

#include <assert.h>

int
solve(int a, int b, int c)
{
	int d;

	d = a - b;
	if (d == 0)
		return 0;
	return c / d;
}

int
main()
{
	assert(solve(6, 3, 15) == 5);

	return 0;
}
