/*

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

    For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.

Example 2:

Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"

Constraints:

    1 <= s.length <= 10^5
    s consists of lowercase English letters.
    shifts.length == s.length
    0 <= shifts[i] <= 10^9

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
shift(const char *src, int *shifts, size_t nshifts, char *dst)
{
	size_t i;
	int times;

	times = 0;
	for (i = 0; i < nshifts; i++)
		times += shifts[i];
	times %= 26;

	for (i = 0; src[i]; i++) {
		dst[i] = 'a' + ((src[i] - 'a' + times) % 26);
		times = (((times - shifts[i]) % 26) + 26) % 26;
	}
	dst[i] = '\0';

	return dst;
}

void
test(const char *src, int *shifts, size_t nshifts, const char *res)
{
	char dst[32];

	shift(src, shifts, nshifts, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	int shifts1[] = { 3, 5, 9 };
	int shifts2[] = { 1, 2, 3 };

	test("abc", shifts1, nelem(shifts1), "rpl");
	test("aaa", shifts2, nelem(shifts2), "gfd");

	return 0;
}
