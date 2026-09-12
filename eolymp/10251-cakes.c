/*

Vitaliy wants to buy exactly n cakes. He has two purchasing options:

Buy 1 cake for 1 coin.

Buy k+1 cakes for k coins.

Determine the minimum number of coins Vitaliy needs to spend to purchase exactly n cakes.

Input
The input consists of a single line containing two integers n and k (1≤n,k≤10^18),
where n is the number of cakes to be purchased and k is the number of coins required for the second type of purchase.

Output
Output a single integer representing the minimum number of coins needed to buy exactly n cakes.

Examples

Input #1
5 2

Answer #1
4

Input #2
1 1

Answer #2
1

Note
In the first example, Vitaliy can buy 3 cakes for 2 coins and then buy 1 cake twice for 1 coin each. This results in a total of 2+1+1=4 coins.

In the second example, Vitaliy can simply buy 1 cake for 1 coin.

Scoring
Solutions that correctly handle the constraints 1≤n,k≤10^5 will earn 20% of the total points.

*/

#include <assert.h>

int
solve(int n, int k)
{
	int x, y;

	x = n / (k + 1);
	y = n - (x * (k + 1));
	return (x * k) + y;
}

int
main()
{
	assert(solve(5, 2) == 4);
	assert(solve(1, 1) == 1);

	return 0;
}
