/*

You are given an array of positive integers nums.

Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

Return true if Alice can win this game, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4,10]

Output: false

Explanation:

Alice cannot win by choosing either single-digit or double-digit numbers.

Example 2:

Input: nums = [1,2,3,4,5,14]

Output: true

Explanation:

Alice can win by choosing single-digit numbers which have a sum equal to 15.

Example 3:

Input: nums = [5,5,5,25]

Output: true

Explanation:

Alice can win by choosing double-digit numbers which have a sum equal to 25.

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 99

Hint 1
Alice wins if the sum of all single-digit numbers and the sum of all double-digit numbers are different.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
win(int *a, size_t n)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; i < n; i++) {
		if (x < 10)
			x += a[i];
		else
			y += a[i];
	}
	return x != y;
}

int
main()
{
	int a1[] = { 1, 2, 3, 4, 10 };
	int a2[] = { 1, 2, 3, 4, 5, 14 };
	int a3[] = { 5, 5, 5, 25 };

	assert(win(a1, nelem(a1)) == false);
	assert(win(a2, nelem(a2)) == true);
	assert(win(a3, nelem(a3)) == true);

	return 0;
}
