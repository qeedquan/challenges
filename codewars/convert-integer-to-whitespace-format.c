/*

Story
Hereinafter, [space] refers to " ", [tab] refers to "\t", and [LF] refers to "\n" for illustrative purposes. This does not mean that you can use these placeholders in your solution.

In esoteric language called Whitespace, numbers are represented in the following format:

first character represents the sign: [space] for plus, [tab] for minus;
characters after that and until [LF] are the binary representation of the integer: [space] for 0, [tab] for 1.
characters after that are the binary representation of the absolute value of the number, with [space] for 0, [tab] for 1, the rightmost bit is the least significand bit, and no leading zero bits.
the binary representation is immediately followed by [LF].
Notes
Valid Whitespace number must always have at least two characters: a sign and the terminator. In case there are only two characters, the number is equal to zero.
For the purposes of this kata, zero must always be represented as [space][LF].
In Whitespace, only space, tabulation and linefeed are meaningful characters. All other characters are ignored. However, for the purposes of this simple kata, please do not add any other characters in the output.
In this kata, input will always be a valid negative or positive integer.
For your convenience, in this kata we will use unbleach() function when evaluating your results. This function replaces whitespace characters with [space], [tab], and [LF] to make fail messages more obvious. You can see how it works in Example Test Cases.
Examples
1 in Whitespace is " \t\n".
0 in Whitespace is " \n".
-1 in Whitespace is "\t\t\n".
2 in Whitespace is " \t \n".
-3 in Whitespace is "\t\t\t\n".

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbit.h>

void
print(const char *s)
{
	for (; *s; s++) {
		switch (*s) {
		case '\t':
			printf("\\t");
			break;
		case '\n':
			printf("\\n");
			break;
		case ' ':
			printf("\\s");
			break;
		default:
			printf("%c", *s);
			break;
		}
	}
	printf("\n");
}

char *
wsn(int n, char *b)
{
	char *p;
	int i, w;
	unsigned u;

	p = b;
	p += sprintf(p, "%c", (n >= 0) ? ' ' : '\t');
	u = abs(n);
	w = stdc_bit_width(u);
	for (i = w - 1; i >= 0; i--) {
		if (u & (1 << i))
			*p++ = '\t';
		else
			*p++ = ' ';
	}
	sprintf(p, "\n");
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	wsn(n, b);
	print(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(2, " \t \n");
	test(1, " \t\n");
	test(0, " \n");
	test(-1, "\t\t\n");
	test(-3, "\t\t\t\n");
	return 0;
}
