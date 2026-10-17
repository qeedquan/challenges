/*

Tim is an obsessive soda drinker; he simply cannot get enough.
Most annoyingly, he almost never has any money, so his only obvious legal way to obtain more soda is to use the money he gets
from recycling empty soda bottles to buy new ones. In addition to the empty bottles resulting from his own consumption,
he sometimes finds empty bottles in the street.
One day, he was extra thirsty, so he drank sodas until he could no longer afford a new one.

Input
Three non-negative integers e, f, c, where e (e<1000) is the number of empty soda bottles in Tim's possession at the start of the day,
f (f<1000) is the number of empty soda bottles found during the day, and c (1<c<2000) is the number of empty bottles required to buy a new soda.

Output
How many sodas did Tim drink on his extra thirsty day?

Examples

Input #1
9 0 3

Answer #1
4

Input #2
5 5 2

Answer #2
9

*/

#include <assert.h>

int
solve(int e, int f, int c)
{
	int r, v;

	if (c == 0)
		return 0;

	r = (e + f) / c;
	e = (e + f) % c;
	e += r;
	while (e >= c) {
		v = e / c;
		e = (e % c) + v;
		r += v;
	}
	return r;
}

int
main()
{
	assert(solve(9, 0, 3) == 4);
	assert(solve(5, 5, 2) == 9);

	return 0;
}
