/*

Your work is to recreate this piece of art:

                        _____
                       |
                       |
                       |
                       |
                  _____|
                 |
                 |
                 |
                 |
            _____|
           |
           |
           |
           |
      _____|
     |
     |
     |
     |
_____|

The answer must recreate this and print this as a result. All languages allowed, no direct printing of art, ofc, some level of manipulation is required. The answer with the least bytes wins.

Closes on Thursday 6:30 AM UTC or so.

The original thing was shown to me by my friend who did this with Java, he refused to show me the source code and now I'll dazzle him with the brilliance of other languages possibly. :D

You cannot use any alternative character (makes it easier?).

*/

#include <stdio.h>

void
staircase(void)
{
	const char *s;
	int c, i, n;

	c = 0;
	for (i = 20; i >= 0; i--) {
		n = ((i / 5) * 6) + 5;
		s = (i % 5) ? "" : "_____";

		printf("%*s", n, s);
		if (c)
			putchar(c);
		putchar('\n');

		c = '|';
	}
}

int
main(void)
{
	staircase();
	return 0;
}
