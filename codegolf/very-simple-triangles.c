/*

Write a program or function that takes in a positive integer (via stdin, command line, or function arg) and prints or returns a string of that many of these small triangles tiled together, alternating which way they point:

 /\
/__\

This sole triangle is the output if the input is 1.

If the input is 2, the output is

  ____
 /\  /
/__\/

If the input is 3, the output is

  ____
 /\  /\
/__\/__\

If the input is 4, the output is

  ________
 /\  /\  /
/__\/__\/

And so on. Your program must support inputs up to 216 - 1 = 65535.

Details

The leftmost triangle always points upwards.
There may be trailing spaces but there may not be unnecessary leading spaces.
There may be an optional trailing newline.
Note that for 1 the output is two lines long but otherwise it's three. This is required.
The shortest submission in bytes wins.

*/

#include <stdio.h>
#include <stdarg.h>

void
output(const char *fmt, ...)
{
	const char *s;
	unsigned j, n;
	va_list ap;
	size_t i;

	va_start(ap, fmt);
	for (i = 0; fmt[i]; i++) {
		switch (fmt[i]) {
		case 's':
			printf("%s", va_arg(ap, const char *));
			break;

		case 'r':
			s = va_arg(ap, const char *);
			n = va_arg(ap, unsigned);
			for (j = 0; j < n; j++)
				printf("%s", s);
			break;

		default:
			printf("%c", fmt[i]);
			break;
		}
	}
	va_end(ap);
	printf("\n");
}

void
triangles(unsigned n)
{
	static const char top[] = " /\\ ";
	static const char bot[] = "/__\\";

	const char *e;
	unsigned m, k;

	m = n / 2;
	k = m + (n & 1);
	e = (m < k) ? "" : "/";

	printf("n=%u\n", n);
	if (n == 0)
		return;

	if (n > 1)
		output("  r", "_", 4 * m);
	output("r s", top, k, e);
	output("rs", bot, k, e);
	printf("\n");
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 20; i++)
		triangles(i);

	return 0;
}
