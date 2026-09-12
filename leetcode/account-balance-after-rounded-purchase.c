/*

Initially, you have a bank account balance of 100 dollars.

You are given an integer purchaseAmount representing the amount you will spend on a purchase in dollars, in other words, its price.

When making the purchase, first the purchaseAmount is rounded to the nearest multiple of 10.
Let us call this value roundedAmount. Then, roundedAmount dollars are removed from your bank account.

Return an integer denoting your final bank account balance after this purchase.

Notes:

0 is considered to be a multiple of 10 in this problem.
When rounding, 5 is rounded upward (5 is rounded to 10, 15 is rounded to 20, 25 to 30, and so on).


Example 1:

Input: purchaseAmount = 9

Output: 90

Explanation:

The nearest multiple of 10 to 9 is 10. So your account balance becomes 100 - 10 = 90.

Example 2:

Input: purchaseAmount = 15

Output: 80

Explanation:

The nearest multiple of 10 to 15 is 20. So your account balance becomes 100 - 20 = 80.

Example 3:

Input: purchaseAmount = 10

Output: 90

Explanation:

10 is a multiple of 10 itself. So your account balance becomes 100 - 10 = 90.

Constraints:

0 <= purchaseAmount <= 100

Hint 1
To determine the nearest multiple of 10, we can brute force the rounded amount since there are at most 100 options.
In case of multiple nearest multiples, choose the largest.

Hint 2
Another solution is observing that the rounded amount is floor((purchaseAmount + 5) / 10) * 10.
Using this formula, we can calculate the account balance without having to brute force the rounded amount.

*/

#include <assert.h>

int
balance(int purchase)
{
	return 100 - (((purchase + 5) / 10) * 10);
}

int
main()
{
	assert(balance(9) == 90);
	assert(balance(15) == 80);
	assert(balance(10) == 90);

	return 0;
}
