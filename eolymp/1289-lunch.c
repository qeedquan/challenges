/*

Vlad wants to take a couple of fruits for lunch. He has a different bananas, b different apples, and c different pears.
In how many ways can he choose 2 different fruits from the available ones?

Input
Three non-negative integers a, b, and c are given in a single line. All integers do not exceed 10^6.

Output
Print the number of ways to choose 2 different fruits for lunch.

Examples

Input #1
3 4 2

Answer #1
26

*/

#include <assert.h>

int
solve(int a, int b, int c)
{
	return (a * b) + (a * c) + (b * c);
}

int
main()
{
	assert(solve(3, 4, 2) == 26);

	return 0;
}
