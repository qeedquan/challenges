/*

Funny Dots
You will get two integers n (width) and m (height) and your task is to draw the following pattern. Each line is seperated with a newline (\n)

Both integers are equal or greater than 1; no need to check for invalid parameters.

Examples

                                            +---+---+---+
             +---+                          | o | o | o |
dot(1, 1) => | o |            dot(3, 2) =>  +---+---+---+
             +---+                          | o | o | o |
                                            +---+---+---+

Serie: ASCII Fun
ASCII Fun #1: X-Shape
ASCII Fun #2: Funny Dots
ASCII Fun #3: Puzzle Tiles
ASCII Fun #4: Build a pyramid

*/

#include <stdio.h>

void
output(const char *s, int n, const char *t)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
	puts(t);
}

void
dot(int n, int m)
{
	int i;

	printf("n=%d m=%d\n", n, m);
	for (i = 0; i <= 2 * m; i++) {
		if (i & 1)
			output("| o ", n, "|");
		else
			output("+---", n, "+");
	}
	puts("");
}

int
main()
{
	dot(1, 1);
	dot(3, 2);
	return 0;
}
