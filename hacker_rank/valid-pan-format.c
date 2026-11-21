/*

The equivalent of SSN in India is a PAN number, which is unique to each of its citizens. In any of the country's official documents, the PAN number is listed as follows

<char><char><char><char><char><digit><digit><digit><digit><char>

Your task is to figure out if the PAN number is valid or not. A valid PAN number will have all its letters in uppercase and digits in the same order as listed above.


Input Format

First line contains N. N lines follow, each having a PAN number.

Constraints

1 <= N <= 10
Each char is an uppercase letter, i.e., ['A', 'Z'].
Each digit lies between 0 and 9, i.e., [0, 9].
The length of the PAN number is always 10, i.e. length(PAN) = 10,
Every character in PAN is either char or digit satisfying the above constraints.

Output Format

For every PAN number listed, print YES if it is valid and NO if it isn't.

Sample Input

3
ABCDS1234Y
ABAB12345Y
avCDS1234Y

Sample Output

YES
NO
NO

The first PAN number is valid since the first 5 characters are letters, the next 4 are digits and the last character is an alphabet. All letters in input is in uppercase.
The second PAN number is invalid as the fifth character is a digit as opposed to an letter.
The third PAN number contains lowercase characters. Hence invalid

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
ispan(const char *s)
{
	static const char fmt[] = "cccccddddc";

	size_t i;

	for (i = 0; fmt[i]; i++) {
		switch (fmt[i]) {
		case 'c':
			if (!('A' <= s[i] && s[i] <= 'Z'))
				return "NO";
			break;

		case 'd':
			if (!('0' <= s[i] && s[i] <= '9'))
				return "NO";
			break;
		}
	}
	return (!s[i]) ? "YES" : "NO";
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(ispan(s), r));
}

int
main()
{
	test("ABCDS1234Y", "YES");
	test("ABAB12345Y", "NO");
	test("avCDS1234Y", "NO");
	return 0;
}
