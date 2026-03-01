/*

You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.

Example 1:

Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.

Example 2:

Input: s = "2-5g-3-J", k = 2
Output: "2-5G-3J"
Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.


Constraints:

    1 <= s.length <= 10^5
    s consists of English letters, digits, and dashes '-'.
    1 <= k <= 10^4

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void
rev(char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n / 2; i++)
		swap(&s[i], &s[n - i - 1]);
}

void
license(const char *s, size_t k, char *b)
{
	size_t i, j, n;

	n = strlen(s);
	j = 0;
	for (i = n; i > 0; i--) {
		if (s[i - 1] == '-')
			continue;

		if (j % (k + 1) == k)
			b[j++] = '-';

		b[j++] = toupper(s[i - 1]);
	}
	b[j] = '\0';

	rev(b, j);
}

void
test(const char *s, size_t k, char *r)
{
	char b[32];

	license(s, k, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("5F3Z-2e-9-w", 4, "5F3Z-2E9W");
	test("2-5g-3-J", 2, "2-5G-3J");

	return 0;
}
