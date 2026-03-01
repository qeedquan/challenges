/*

This is a problem that involves adding numbers to items in a list. In a list you will have to add the item's remainder when divided by a given divisor to each item.

For example if the item is 40 and the divisor is 3 you would have to add 1 since 40 minus the closest multiple of 3 which is 39 is 1. So the 40 in the list will become 41. You would have to return the modified list in this problem.

For this problem you will receive a divisor called div as well as simple list of whole numbers called nums. Good luck and happy coding.

Examples
nums = [2, 7, 5, 9, 100, 34, 32, 0], div = 3
  ==>  [4, 8, 7, 9, 101, 35, 34, 0]

nums = [1000, 999, 998, 997], div = 5
   ==> [1000, 1003, 1001, 999]

nums = [], div = 2
   ==> []

Note: random tests check lists containing up to 10000 elements.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int *nums, size_t len, int div)
{
	size_t i;

	if (!div)
		return -1;

	for (i = 0; i < len; i++)
		nums[i] = nums[i] + (nums[i] % div);
	return 0;
}

void
test(int *nums, size_t len, int div, int *res)
{
	solve(nums, len, div);
	assert(!memcmp(nums, res, len * sizeof(*res)));
}

int
main()
{
	int nums1[] = { 2, 7, 5, 9, 100, 34, 32, 0 };
	int nums2[] = { 1000, 999, 998, 997 };

	int res1[] = { 4, 8, 7, 9, 101, 35, 34, 0 };
	int res2[] = { 1000, 1003, 1001, 999 };

	test(nums1, nelem(nums1), 3, res1);
	test(nums2, nelem(nums2), 5, res2);
	test(nums2, 0, 2, res2);

	return 0;
}
