/*

You are given an integer n.

We write the integers from 1 to n in a sequence from left to right. Then, alternately apply the following two operations until only one integer remains, starting with operation 1:

Operation 1: Starting from the left, delete every second number.
Operation 2: Starting from the right, delete every second number.
Return the last remaining integer.

Example 1:

Input: n = 8

Output: 3

Explanation:

Write [1, 2, 3, 4, 5, 6, 7, 8] in a sequence.
Starting from the left, we delete every second number: [1, 2, 3, 4, 5, 6, 7, 8]. The remaining integers are [1, 3, 5, 7].
Starting from the right, we delete every second number: [1, 3, 5, 7]. The remaining integers are [3, 7].
Starting from the left, we delete every second number: [3, 7]. The remaining integer is [3].
Example 2:

Input: n = 5

Output: 1

Explanation:

Write [1, 2, 3, 4, 5] in a sequence.
Starting from the left, we delete every second number: [1, 2, 3, 4, 5]. The remaining integers are [1, 3, 5].
Starting from the right, we delete every second number: [1, 3, 5]. The remaining integers are [1, 5].
Starting from the left, we delete every second number: [1, 5]. The remaining integer is [1].
Example 3:

Input: n = 1

Output: 1

Explanation:

Write [1] in a sequence.
The last remaining integer is 1.

Constraints:

1 <= n <= 10^15

Hint 1
Use divide and conquer.

Hint 2
Maintain the start value, remaining length, and current direction using recursion.

Hint 3
Track the current direction (left or right) and update the start value based on the parity of the remaining length.

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A090569
int64_t
lastinteger(int64_t n)
{
	static const int64_t mask = 0xAAAAAAAAAAAAA;

	if (n < 1)
		return 0;
	return ((n - 1) & mask) + 1;
}

int
main()
{
	static const int64_t tab[] = {
		1, 1, 3, 3, 1, 1, 3, 3, 9, 9, 11, 11, 9, 9, 11, 11, 1, 1, 3, 3, 1, 1,
		3, 3, 9, 9, 11, 11, 9, 9, 11, 11, 33, 33, 35, 35, 33, 33, 35, 35, 41,
		41, 43, 43, 41, 41, 43, 43, 33, 33, 35, 35, 33, 33, 35, 35, 41, 41, 43,
		43, 41, 41, 43, 43, 1, 1, 3, 3, 1, 1, 3, 3, 9, 9, 11, 11, 9, 9, 11, 11,
		1, 1
	};

	size_t i;

	assert(lastinteger(8) == 3);
	assert(lastinteger(5) == 1);
	assert(lastinteger(1) == 1);

	for (i = 0; i < nelem(tab); i++)
		assert(lastinteger(i + 1) == tab[i]);

	return 0;
}
