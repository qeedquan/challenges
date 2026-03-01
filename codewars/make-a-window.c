/*

Make me a window. I'll give you a number (N). You return a window.

Rules:

The window will always be 2 x 2.

The window needs to have N number of periods across and N number of periods vertically in each pane.

Example:

N = 3

---------
|...|...|
|...|...|
|...|...|
|---+---|
|...|...|
|...|...|
|...|...|
---------
Note: there should be no trailing new line characters at the end.

*/

#include <stdio.h>
#include <stdarg.h>

void
outf(const char *fmt, ...)
{
	va_list ap;
	int c, i, n;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		c = *fmt;
		switch (c) {
		case '=':
			c = '-';
			[[fallthrough]];
		case '.':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(c);
			break;

		default:
			putchar(c);
			break;
		}
	}
	va_end(ap);
	puts("");
}

void
window(int n)
{
	int i;

	printf("n=%d\n", n);
	outf("-=-=-", n, n);
	for (i = 0; i < n; i++)
		outf("|.|.|", n, n);
	outf("|=+=|", n, n);
	for (i = 0; i < n; i++)
		outf("|.|.|", n, n);
	outf("-=-=-", n, n);
	puts("");
}

int
main()
{
	int i;

	for (i = 2; i <= 10; i++)
		window(i);
	return 0;
}
