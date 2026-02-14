/*

Given a string whose length is divisible by 4, make a triangle as demonstrate below.

If the string is abcdefghijkl, then the triangle would be:

   a
  b l
 c   k
defghij
If the string is iamastringwithalengthdivisiblebyfour, then the triangle would be:

         i
        a r
       m   u
      a     o
     s       f
    t         y
   r           b
  i             e
 n               l
gwithalengthdivisib
If the string is thisrepresentationisnotatriangle, then the triangle would be:

        t
       h e
      i   l
     s     g
    r       n
   e         a
  p           i
 r             r
esentationisnotat

Notes
The string will only consist of characters from a to z.
Leading/Trailing whitespaces and newlines are allowed as long as the shape is not broken.
A list of strings as output is allowed.
This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void
output(const char *fmt, ...)
{
	size_t i, j, n;
	char *p, *q;
	va_list ap;

	va_start(ap, fmt);
	for (i = 0; fmt[i]; i++) {
		switch (fmt[i]) {
		case 'c':
			putchar(va_arg(ap, int));
			break;
		case 'p':
			n = va_arg(ap, size_t);
			for (j = 0; j < n; j++)
				putchar(' ');
			break;
		case 's':
			p = va_arg(ap, char *);
			q = va_arg(ap, char *);
			do {
				putchar(*p++);
			} while (p != q);
			break;
		}
	}
	va_end(ap);
	putchar('\n');
}

void
foldtriangle(const char *s)
{
	size_t i, l, n;

	n = strlen(s);
	if (n == 0 || (n & 3))
		return;

	l = n / 4;
	output("pc", l, s[0]);
	for (i = 1; i < l; i++)
		output("pcpc", l - i, s[i], (2 * i) - 1, s[(4 * l) - i]);
	output("s", s + l, s + (3 * l) + 1);
}

int
main(void)
{
	foldtriangle("abcdefghijkl");
	foldtriangle("iamastringwithalengthdivisiblebyfour");
	foldtriangle("thisrepresentationisnotatriangle");

	return 0;
}
