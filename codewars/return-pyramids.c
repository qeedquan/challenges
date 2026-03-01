/*

The task is very simple.

You must to return pyramids. Given a number n you print a pyramid with n floors

For example , given a n=4 you must to print this pyramid:

   /\
  /  \
 /    \
/______\

Other example, given a n=6 you must to print this pyramid:

     /\
    /  \
   /    \
  /      \
 /        \
/__________\

Another example, given a n=10, you must to print this pyramid:

         /\
        /  \
       /    \
      /      \
     /        \
    /          \
   /            \
  /              \
 /                \
/__________________\

Note: an extra line feed character is needed at the end of the string. Case n=0 should so return "\n".

*/

#include <stdio.h>
#include <stdarg.h>

void
linef(const char *fmt, ...)
{
	int i, n;
	va_list ap;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case ' ':
		case '_':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(*fmt);
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	putchar('\n');
	va_end(ap);
}

void
pyramid(int n)
{
	int i;

	for (i = 0; i < n - 1; i++)
		linef(" / \\", n - i - 1, i * 2);
	linef("/_\\", (n * 2) - 2);
	linef("");
}

int
main()
{
	pyramid(4);
	pyramid(6);
	pyramid(10);

	return 0;
}
