/*

There is a given sequence of integers a1, a2, ..., an, where every number is from 1 to 3 inclusively. You have to replace the minimum number of numbers in it so that all the numbers in the sequence are equal to each other.

Input
The first line contains an integer n (1 ≤ n ≤ 10^6). The second line contains a sequence of integers a1, a2, ..., an (1 ≤ ai ≤ 3).

Output
Print the minimum number of replacements needed to be performed to make all the numbers in the sequence equal.

Examples

input
9
1 3 2 2 2 1 1 2 3

output
5

Note
In the example all the numbers equal to 1 and 3 should be replaced by 2.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
replacements(int *nums, size_t len)
{
	int one, two, three;
	size_t i;

	one = two = three = 0;
	for (i = 0; i < len; i++) {
		one += (nums[i] == 1);
		two += (nums[i] == 2);
		three += (nums[i] == 3);
	}
	return abs(max(one, max(two, three)) - (one + two + three));
}

int
main(void)
{
	int nums1[] = {1, 3, 2, 2, 2, 1, 1, 2, 3};

	assert(replacements(nums1, nelem(nums1)) == 5);

	return 0;
}
