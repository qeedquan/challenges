/*

Mom baked a large and delicious round cake for Sergei's birthday and asked him to cut it himself.
He has a knife long enough to cut completely across the cake.
However, since using such a tool always carries some risk, Sergei wants to make the minimum number of cuts so that every guest receives at least one piece.
Of course, he must also ensure that he himself gets at least one piece at the table.
Sergei does not care about the size or shape of the cake pieces — for him, the main thing is that every piece tastes just as good as the cake his mother baked.

Note that Sergei may have many guests.

Input
One number — the number of guests n (n<210000001).

Output
The minimum required number of cuts k.

Examples
Input #1
3

Answer #1
2

*/

#include <assert.h>
#include <math.h>

int
solve(int n)
{
	if (n < 0)
		return 0;
	return round(sqrt(n * 2));
}

int
main()
{
	assert(solve(3) == 2);

	return 0;
}
