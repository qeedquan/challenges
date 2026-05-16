/*

A hotel has n floors. The lobby, restaurant and gym are located on the first floor.
The guestrooms are on 2-nd to n-th floors. There are m standard rooms on each floor.
If each standard room can fit 3 guests, what is the maximum number of guests that all the standard rooms can accommodate?

Input
Two positive integers n and m (n,m≤10^6).

Output
Print the maximum number of guests that all the hotel standard rooms can accommodate.

Examples

Input #1
5 10

Answer #1
120

*/

#include <assert.h>

int
solve(int n, int m)
{
	return (n - 1) * m * 3;
}

int
main()
{
	assert(solve(5, 10) == 120);

	return 0;
}
