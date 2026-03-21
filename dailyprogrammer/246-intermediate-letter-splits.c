/*

This problem is a simplified version of Text Segmentation in Natural Language Processing.

Description

Given a positive integer, return all the ways that the integer can be represented by letters using the mapping:

1 -> A

2 -> B

3 -> C

...

25 -> Y

26 -> Z

For example, the integer 1234 can be represented by the words :

ABCD -> [1,2,3,4]

AWD -> [1,23,4]

LCD -> [12,3,4]

Input description

A positive integer:

Output description

All possible ways the number can be represented once per line.

Examples

Example 1:

1234

ABCD
AWD
LCD
Example 2:

1234567899876543210

LCDEFGHIIHGFEDCBJ
AWDEFGHIIHGFEDCBJ
ABCDEFGHIIHGFEDCBJ
Example 3:

10520

jet
Bonus

We can use our beloved enable1.txt (or other if you prefer that) to find real words or even sentences.

Example 1

1321205

ACUTE
MUTE
Example 2

1252020518

LETTER
ABETTER
Example 3

85121215231518124

HELLOWORLD
Bonus Input

81161625815129412519419122516181571811313518
Finally

Thanks to u/wizao and u/smls for the idea and bonus idea

Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas

*/

#include <stdio.h>

void
i2l(const char *in, char *out, int n)
{
	int c;

	if (in[0] == '\0') {
		out[n] = '\0';
		puts(out);
		return;
	}

	if (in[0] == '0')
		return;

	c = in[0] - '0';
	out[n] = c - 1 + 'A';
	i2l(in + 1, out, n + 1);
	if (in[1]) {
		c = (in[0] - '0') * 10 + (in[1] - '0');
		if (1 <= c && c <= 26) {
			out[n] = c - 1 + 'A';
			i2l(in + 2, out, n + 1);
		}
	}
}

void
test(const char *in)
{
	char out[128];

	printf("%s\n\n", in);
	i2l(in, out, 0);
	printf("\n");
}

int
main()
{
	test("1234");
	test("1234567899876543210");
	test("10520");
	test("1321205");
	test("1252020518");
	test("85121215231518124");
	test("81161625815129412519419122516181571811313518");

	return 0;
}
