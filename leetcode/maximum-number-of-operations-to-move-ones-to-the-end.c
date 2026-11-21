/*

You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'.
For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.

Example 1:

Input: s = "1001101"

Output: 4

Explanation:

We can perform the following operations:

Choose index i = 0. The resulting string is s = "0011101".
Choose index i = 4. The resulting string is s = "0011011".
Choose index i = 3. The resulting string is s = "0010111".
Choose index i = 2. The resulting string is s = "0001111".

Example 2:

Input: s = "00111"

Output: 0

Constraints:

1 <= s.length <= 10^5
s[i] is either '0' or '1'.

Hint 1
It is optimal to perform the operation on the lowest index possible each time.

Hint 2
Traverse the string from left to right and perform the operation every time it is possible.

*/

#include <assert.h>
#include <stdio.h>

size_t
maxops(const char *s)
{
	size_t c, i, r;

	for (c = r = i = 0; s[i]; i++) {
		if (s[i] == '1')
			c += 1;
		else if (!s[i + 1] || s[i + 1] == '1')
			r += c;
	}
	return r;
}

int
main()
{
	assert(maxops("1001101") == 4);
	assert(maxops("00111") == 0);

	return 0;
}
