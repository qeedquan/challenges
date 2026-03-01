/*

You are given a binary string binary. A subsequence of binary is considered good if it is not empty and has no leading zeros (with the exception of "0").

Find the number of unique good subsequences of binary.

For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1".
Note that subsequences "00", "01", and "001" are not good because they have leading zeros.
Return the number of unique good subsequences of binary. Since the answer may be very large, return it modulo 10^9 + 7.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: binary = "001"
Output: 2
Explanation: The good subsequences of binary are ["0", "0", "1"].
The unique good subsequences are "0" and "1".

Example 2:

Input: binary = "11"
Output: 2
Explanation: The good subsequences of binary are ["1", "1", "11"].
The unique good subsequences are "1" and "11".

Example 3:

Input: binary = "101"
Output: 5
Explanation: The good subsequences of binary are ["1", "0", "1", "10", "11", "101"].
The unique good subsequences are "0", "1", "10", "11", and "101".

Constraints:

1 <= binary.length <= 10^5
binary consists of only '0's and '1's.

Hint 1
The number of unique good subsequences is equal to the number of unique decimal values there are for all possible subsequences.

Hint 2
Find the answer at each index based on the previous indexes' answers.

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(const char *s)
{
	static const vlong mod = 1000000007;

	vlong r0, r1, zo;

	for (zo = r0 = r1 = 0; *s; s++) {
		if (*s == '1')
			r1 = (r0 + r1 + 1) % mod;
		else {
			r0 = (r0 + r1) % mod;
			zo = 1;
		}
	}
	return (r0 + r1 + zo) % mod;
}

int
main()
{
	assert(solve("001") == 2);
	assert(solve("11") == 2);
	assert(solve("101") == 5);

	return 0;
}
