/*

Bob is an honors pupil. He enjoys every five that he sees in a number.
Every morning, he goes by bus and counts the number of fives in his bus ticket.
According to the ancient omen (valid from the 2nd class), he knows that this day he will receive as many fives as there are in his ticket.
Given today's Bob's ticket number, determine how many fives he will get today.

Input
Bob's ticket number n (0≤n≤9999).

Output
Print the number of fives that Bob will get.

Examples

Input #1
3533

Answer #1
1

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	uvlong r;

	for (r = 0; n; n /= 10)
		r += ((n % 10) == 5);
	return r;
}

int
main()
{
	assert(solve(3533) == 1);

	return 0;
}
