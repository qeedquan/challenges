/*

Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.


Constraints:

1 <= s.length <= 10^5
s[i] is either '0' or '1'.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
triangular(uvlong n)
{
	return (n * (n + 1)) / 2;
}

uvlong
numsub(const char *s)
{
	static const uvlong mod = 1000000007ULL;

	size_t i, j;
	uvlong r;

	r = 0;
	for (i = 0; s[i]; i = j) {
		j = i;
		while (s[j] == s[i])
			j++;

		if (s[i] == '1')
			r = (r + triangular(j - i)) % mod;
	}
	return r;
}

int
main(void)
{
	assert(numsub("0110111") == 9);
	assert(numsub("101") == 2);
	assert(numsub("111111") == 21);

	return 0;
}
