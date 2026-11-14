/*

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.


Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
dbs(const char **s, size_t n, char *b)
{
	size_t i;

	for (i = 0; i < n; i++)
		b[i] = (s[i][i] == '0') ? '1' : '0';
	b[i] = '\0';
	return b;
}

void
test(const char **s, size_t n)
{
	char b[128];
	size_t i;

	dbs(s, n, b);
	printf("%s\n", b);
	for (i = 0; i < n; i++)
		assert(strcmp(b, s[i]) != 0);
}

int
main(void)
{
	const char *s1[] = {"01", "10"};
	const char *s2[] = {"00", "01"};
	const char *s3[] = {"111", "011", "001"};
	const char *s4[] = {"010", "011", "100"};
	const char *s5[] = {"0101", "0000", "1000", "1111"};

	test(s1, nelem(s1));
	test(s2, nelem(s2));
	test(s3, nelem(s3));
	test(s4, nelem(s4));
	test(s5, nelem(s5));

	return 0;
}
