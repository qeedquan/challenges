/*

Introduction
This is how a chessboard looks like.

https://i.stack.imgur.com/YxP53.gif

You can see that a1 is a dark square. However, b1 is a light square.

The Task
The challenge is, given dark, light or both, output all the dark, light or all squares with a separator (like a whitespace or a newline). The order of all the squares does not matter.

Test cases
Input: dark
Output: a1 a3 a5 a7 b2 b4 b6 b8
        c1 c3 c5 c7 d2 d4 d6 d8
        e1 e3 e5 e7 f2 f4 f6 f8
        g1 g3 g5 g7 h2 h4 h6 h8

Input: light
Output: a2 a4 a6 a8 b1 b3 b5 b7
        c2 c4 c6 c8 d1 d3 d5 d7
        e2 e4 e6 e8 f1 f3 f5 f7
        g2 g4 g6 g8 h1 h3 h5 h7

Input: both
Output: a1 a2 a3 a4 a5 a6 a7 a8
        b1 b2 b3 b4 b5 b6 b7 b8
        c1 c2 c3 c4 c5 c6 c7 c8
        d1 d2 d3 d4 d5 d6 d7 d8
        e1 e2 e3 e4 e5 e6 e7 e8
        f1 f2 f3 f4 f5 f6 f7 f8
        g1 g2 g3 g4 g5 g6 g7 g8
        h1 h2 h3 h4 h5 h6 h7 h8
Note: I have prettified the output but this is not necessary.

This is code-golf, so the submission with the least amount of bytes wins!

*/

#include <stdio.h>
#include <string.h>

void
output(const char *s)
{
	char b[3];
	int i, n;
	int c, t;

	if (!strcmp(s, "dark"))
		t = 0;
	else if (!strcmp(s, "light"))
		t = 1;
	else if (!strcmp(s, "both"))
		t = 2;
	else
		return;

	printf("%s\n", s);
	b[2] = '\0';
	for (i = n = 0; i < 64; i++) {
		b[0] = 'a' + (i / 8);
		b[1] = '1' + (i & 7);

		c = ((i / 8) ^ (i & 7)) & 1;
		if (c != t && t != 2)
			continue;

		printf("%s", b);
		if ((n & 7) != 7)
			printf(" ");
		else
			printf("\n");
		n++;
	}
	printf("\n");
}

int
main(void)
{
	output("dark");
	output("light");
	output("both");

	return 0;
}
