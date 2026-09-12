/*

Inspired by this question which was further inspired by this one, write a program which takes two integers and adds them in a unique way, by performing an OR operation on the segments used to display them in a 7-segment display. For reference, the digits are represented in the following way:

 _        _   _         _    _   _    _    _
| |   |   _|  _|  |_|  |_   |_    |  |_|  |_|
|_|   |  |_   _|    |   _|  |_|   |  |_|   _|

Note that the 1 uses the two segments on the right, not the left. There are two special characters that can be produced this way which are not numbers. See the addition table below:

  | 0 1 2 3 4 5 6 7 8 9
--+--------------------
0 | 0 0 8 8 8 8 8 0 8 8
1 | 0 1 a 3 4 9 8 7 8 9
2 | 8 a 2 a 8 8 8 a 8 8
3 | 8 3 a 3 9 9 8 3 8 9
4 | 8 4 8 9 4 9 8 Q 8 9
5 | 8 9 8 9 9 5 6 9 8 9
6 | 8 8 8 8 8 6 6 8 8 8
7 | 0 7 a 3 Q 9 8 7 8 9
8 | 8 8 8 8 8 8 8 8 8 8
9 | 8 9 8 9 9 9 8 9 8 9

Useful observations:

Any digit plus itself equals itself
8 plus any digit equals 8
2 plus 1, 3, or 7 equals the letter 'a' (must be lower-case)
4 plus 7 equals either 'q' or 'Q', your choice
Numbers should be right-aligned, so the digits should be added from right to left. If one number has more digits than the other, the extra digits at the beginning should be unchanged. There are no leading 0's, unless the number is exactly 0.
All numbers will be 0 or greater. You don't need to handle a '-' sign. (Mainly because there's no good fit for the sum of a '-' and a '1' or '7'.)
Your program should accept 2 integers in any format you choose, and output a string containing their "sum" when calculated in this manner. This is code-golf, so your program should be as small as possible.

Examples:
Input: 12345, 123. Output: 12389
Input: 88888, 42. Output: 88888
Input: 0, 23. Output: 28
Input: 120, 240. Output: a80
Input: 270, 42. Output: 2Q8 (or 2q8)
Input: 1234567890, 1234567890. Output: 1234567890

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
length(const char *s, size_t *l)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
			return 0;
	}
	*l = i;
	return 1;
}

char *
ledadd(const char *s, const char *t, char *b)
{
	static const char lut[10][10] = {
	    {'0', '0', '8', '8', '8', '8', '8', '0', '8', '8'},
	    {'0', '1', 'a', '3', '4', '9', '8', '7', '8', '9'},
	    {'8', 'a', '2', 'a', '8', '8', '8', 'a', '8', '8'},
	    {'8', '3', 'a', '3', '9', '9', '8', '3', '8', '9'},
	    {'8', '4', '8', '9', '4', '9', '8', 'Q', '8', '9'},
	    {'8', '9', '8', '9', '9', '5', '6', '9', '8', '9'},
	    {'8', '8', '8', '8', '8', '6', '6', '8', '8', '8'},
	    {'0', '7', 'a', '3', 'Q', '9', '8', '7', '8', '9'},
	    {'8', '8', '8', '8', '8', '8', '8', '8', '8', '8'},
	    {'8', '9', '8', '9', '9', '9', '8', '9', '8', '9'},
	};

	size_t i, l, n, m;
	char *p;

	if (!length(s, &n) || !length(t, &m))
		return NULL;

	l = min(n, m);
	p = b;
	for (i = n; i < m; i++)
		*p++ = *t++;
	for (i = m; i < n; i++)
		*p++ = *s++;
	for (i = 0; i < l; i++)
		*p++ = lut[*s++ - '0'][*t++ - '0'];
	*p = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	ledadd(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("12345", "123", "12389");
	test("88888", "42", "88888");
	test("0", "23", "28");
	test("120", "240", "a80");
	test("270", "42", "2Q8");
	test("1234567890", "1234567890", "1234567890");

	return 0;
}
