/*

In an electronics supermarket, if you believe the TV advertisement, there is a discount system:
out of two purchased products, only the cost of the more expensive product is paid in full, and the other is given for free.
What is the minimum amount you need to pay to buy all three products, if the price of each is known?

Input
Three natural numbers a, b, c are the prices of the three products (1≤a,b,c≤10000).

Output
Output the minimum amount to be paid.

Examples
Input #1
8 11 6

Answer #1
17

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int a, int b, int c)
{
	return max(a, max(b, c)) + min(a, min(b, c));
}

int
main()
{
	assert(solve(8, 11, 6) == 17);

	return 0;
}
