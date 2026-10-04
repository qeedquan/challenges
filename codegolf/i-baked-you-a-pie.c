/*

There is an asdfmovie video about a pie flavoured pie. Someone also made an edited version with more pies, so I created this challenge.

The input is a positive integer.

The code should first out the following string:

I baked you a pie!
Oh boy, what flavour?
Then, the next line should be PIE  (input number of times) + flavour..

Next, print a blank line.

After that, ASCII-art pies should be drawn.

Here is what a size-1 pie looks like.

 _________
/         \
-----------
 \       /
  -------
Size-2 pie:

 _____________
/             \
---------------
 \           /
  -----------
Size-3 pie:

 _________________
/                 \
-------------------
 \               /
  ---------------
Each pie starting from size-2 should be four characters longer on each line than the pie one smaller.

The program should draw (input number + 1) pies, seperated by newlines, with increasing sizes (1 at the top, 2 directly below it, etc).

The pies should be centred.

Examples:

Input 1

I baked you a pie!
Oh boy, what flavour?
PIE flavour.

   _________
  /         \
  -----------
   \       /
    -------
 _____________
/             \
---------------
 \           /
  -----------
Input 2

I baked you a pie!
Oh boy, what flavour?
PIE PIE flavour.

     _________
    /         \
    -----------
     \       /
      -------
   _____________
  /             \
  ---------------
   \           /
    -----------
 _________________
/                 \
-------------------
 \               /
  ---------------
Input 3

I baked you a pie!
Oh boy, what flavour?
PIE PIE PIE flavour.

       _________
      /         \
      -----------
       \       /
        -------
     _____________
    /             \
    ---------------
     \           /
      -----------
   _________________
  /                 \
  -------------------
   \               /
    ---------------
 _____________________
/                     \
-----------------------
 \                   /
  -------------------
This is code-golf, so use any language, shortest code wins.

Bytes are counted based on the UTF-8 encoding. Only characters decodable in UTF-8 are allowed.

*/

#include <stdio.h>
#include <stdarg.h>

void
out(const char *fmt, ...)
{
	va_list ap;
	size_t i;
	const char *s;
	int j, n;

	va_start(ap, fmt);
	for (i = 0; fmt[i]; i++) {
		switch (fmt[i]) {
		case '$':
			n = va_arg(ap, int);
			for (j = 0; j < n; j++)
				printf(" ");
			break;

		case '%':
			s = va_arg(ap, const char *);
			n = va_arg(ap, int);
			for (j = 0; j < n; j++)
				printf("%s", s);
			break;

		default:
			putchar(fmt[i]);
			break;
		}
	}
	va_end(ap);
	printf("\n");
}

void
pies(int n)
{
	int i, p, w;

	if (n < 1)
		return;

	out("I baked you a pie!");
	out("Oh boy, what flavour?");
	out("%flavour.", "PIE ", n);

	for (i = 1; i <= n + 1; i++) {
		w = (4 * i) + 5;
		p = 2 * (n + 1 - i);

		out("");
		out("$ %", p, "_", w);
		out("$/%\\", p, " ", w);
		out("$%", p, "-", w + 2);
		out("$ \\%/", p, " ", w - 2);
		out("$  %", p, "-", w - 2);
		out("");
	}
}

int
main(void)
{
	pies(1);
	pies(2);
	pies(3);
	return 0;
}
