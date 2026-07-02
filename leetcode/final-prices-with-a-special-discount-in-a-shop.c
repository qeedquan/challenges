/*

You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop.
If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i].
Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]


Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 1000

Hint 1
Use brute force: For the ith item in the shop with a loop find the first position j satisfying the conditions and apply the discount, otherwise, the discount is 0.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
finalprices(int *prices, size_t size)
{
	size_t i, sp;
	int *stack;

	stack = calloc(size, sizeof(*stack));
	if (!stack)
		return -errno;

	sp = 0;
	for (i = 0; i < size; i++) {
		while (sp > 0 && prices[stack[sp - 1]] >= prices[i])
			prices[stack[--sp]] -= prices[i];
		stack[sp++] = i;
	}

	free(stack);
	return 0;
}

void
test(int *prices, size_t size, int *expected)
{
	assert(finalprices(prices, size) >= 0);
	assert(!memcmp(prices, expected, sizeof(*expected) * size));
}

int
main()
{
	int prices_1[] = { 8, 4, 6, 2, 3 };
	int prices_2[] = { 1, 2, 3, 4, 5 };
	int prices_3[] = { 10, 1, 1, 6 };

	int expected_1[] = { 4, 2, 4, 2, 3 };
	int expected_2[] = { 1, 2, 3, 4, 5 };
	int expected_3[] = { 9, 0, 1, 6 };

	test(prices_1, nelem(prices_1), expected_1);
	test(prices_2, nelem(prices_2), expected_2);
	test(prices_3, nelem(prices_3), expected_3);

	return 0;
}
