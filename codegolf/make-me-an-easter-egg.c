/*

No, not the ^^vv<><>BA kind of Easter eggs, real Easter eggs that we paint.

Here is an (awfully drawn) egg.

  __
 /  \
/    \
|    |
\____/
In easter, we paint them with patterns. Like these:

  __
 /--\
/----\
|----|
\____/
  __
 /%%\
/%%%%\
|%%%%|
\____/
  __
 /~~\
/~~~~\
|~~~~|
\____/
The challenge
Given a character (printable ascii) to paint the egg, print the painted egg.

Examples:

&:
  __
 /&&\
/&&&&\
|&&&&|
\____/

#:
  __
 /##\
/####\
|####|
\____/

Specs
Trailing newlines/spaces are allowed.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
egg(char p)
{
	static const char art[][7] = {
	    "  __  ",
	    " /--\\ ",
	    "/----\\",
	    "|----|",
	    "\\____/",
	};

	size_t x, y;
	char c;

	for (y = 0; y < nelem(art); y++) {
		for (x = 0; x < nelem(art[y]); x++) {
			c = art[y][x];
			if (c == '-')
				c = p;
			putchar(c);
		}
		putchar('\n');
	}
}

int
main(void)
{
	egg('&');
	egg('#');
	return 0;
}
