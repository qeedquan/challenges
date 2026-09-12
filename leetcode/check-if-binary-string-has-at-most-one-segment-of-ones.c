/*

Given a binary string s without leading zeros, return true if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is either '0' or '1'.
s[0] is '1'.

Hint 1
It's guaranteed to have at least one segment

Hint 2
The string size is small so you can count all segments of ones with no that have no adjacent ones.

*/

#include <assert.h>
#include <stdio.h>

bool
check(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] == '1')
		i++;
	while (s[i] == '0')
		i++;
	return s[i] == '\0';
}

int
main()
{
	assert(check("1001") == false);
	assert(check("110") == true);

	return 0;
}
