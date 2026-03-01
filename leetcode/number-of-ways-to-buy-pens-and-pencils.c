/*

You are given an integer total indicating the amount of money you have.
You are also given two integers cost1 and cost2 indicating the price of a pen and pencil respectively.
You can spend part or all of your money to buy multiple quantities (or none) of each kind of writing utensil.

Return the number of distinct ways you can buy some number of pens and pencils.

Example 1:

Input: total = 20, cost1 = 10, cost2 = 5
Output: 9
Explanation: The price of a pen is 10 and the price of a pencil is 5.
- If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
- If you buy 1 pen, you can buy 0, 1, or 2 pencils.
- If you buy 2 pens, you cannot buy any pencils.
The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.

Example 2:

Input: total = 5, cost1 = 10, cost2 = 10
Output: 1
Explanation: The price of both pens and pencils are 10, which cost more than total, so you cannot buy any writing utensils. Therefore, there is only 1 way: buy 0 pens and 0 pencils.

Constraints:

1 <= total, cost1, cost2 <= 10^6

*/

#include <assert.h>

typedef long long vlong;

vlong
ways(vlong total, vlong cost1, vlong cost2)
{
	vlong count, maxpen;
	vlong i;

	if (total <= 0 || cost1 <= 0 || cost2 <= 0)
		return -1;

	maxpen = total / cost1;
	count = 0;
	for (i = 0; i <= maxpen; i++)
		count += ((total - (i * cost1)) / cost2) + 1;
	return count;
}

int
main(void)
{
	assert(ways(20, 10, 5) == 9);
	assert(ways(5, 10, 10) == 1);

	return 0;
}
