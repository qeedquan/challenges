/*

You are given a 0-indexed integer array nums and an integer k.

Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.

The set bits in an integer are the 1's present when it is written in binary.

    For example, the binary representation of 21 is 10101, which has 3 set bits.

Example 1:

Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are:
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.

Example 2:

Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 10^5
    0 <= k <= 10

Hint 1
Iterate through the indices i in the range [0, n - 1], for each index i count the number of bits in its binary representation. If it is k, add nums[i] to the result.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://iamkate.com/code/hakmem-item-175/
int
next_popcount(int number)
{
	int lowest_bit;
	int left_bits;
	int changed_bits;
	int right_bits;

	lowest_bit = number & -number;
	left_bits = number + lowest_bit;
	changed_bits = number ^ left_bits;
	right_bits = (changed_bits / lowest_bit) >> 2;
	return left_bits | right_bits;
}

int
ksetbits(int *numbers, int size, int bits)
{
	int result;
	int index;

	result = 0;
	index = (1 << bits) - 1;
	while (index < size) {
		result += numbers[index];
		if (index == 0)
			break;
		index = next_popcount(index);
	}
	return result;
}

int
main()
{
	int numbers_1[] = { 5, 10, 1, 5, 2 };
	int numbers_2[] = { 4, 3, 2, 1 };

	assert(ksetbits(numbers_1, nelem(numbers_1), 1) == 13);
	assert(ksetbits(numbers_2, nelem(numbers_2), 2) == 1);

	return 0;
}
