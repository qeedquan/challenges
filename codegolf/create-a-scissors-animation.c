/*

Try to create a simple ASCII art scissors animation!

Challenge

All inputs will be integers -31 through 31.

The output will be an animation (To be outputted somewhere, as long as the previous frame is replaced. GIFs are allowed.), separated by (approximately) 1 quarter of a second.

If the input (n) is positive:

The animation should start with 8<, AKA open scissors.
The next frame is 8=. This shows the scissors "cutting".
A dash (cut mark) is added behind the scissors, and the animation repeats until there are n dashes.
If the input is negative:

The scissors start open and facing towards the left (Like this: >8), with n spaces in front of it.
The scissors close and remain facing towards the left (=8).
The scissors re-open, as space is removed, and a dash is added behind the scissors.
If the input is zero:

Output just the scissors opening and closing, for 10 frames. They can be facing either direction, as long as it is consistent.
This is code-golf, so the shortest submission in bytes wins. (Even if your entry clearly won't win because of some sort of newfangled "golfing language", we'd still like to see it.)

Error messages are allowed, as long as the error message itself does not interfere with the animation.

Example Input and Output Pairs:
(I separated the frames for clarity, but there should be approximately .25 seconds between each frame)

Input: 1
Output:
8<
8=
-8<

Input: 2
Output:
8<
8=
-8<
-8=
--8<

Input: 5
Output:
8<
8=
-8<
-8=
--8<
--8=
---8<
---8=
----8<
----8=
-----8<

Input: 0
Output:
8<
8=
8<
8=
8<
8=
8<
8=
8<
8=

Input: -2
Output:
  >8
  =8
 >8-
 =8-
>8--

Input: -3
Output:
   >8
   =8
  >8-
  =8-
 >8--
 =8--
>8---
Enjoy!

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <threads.h>

void
linef(const char *fmt, ...)
{
	struct timespec t = {
		.tv_nsec = 250000000,
	};

	va_list ap;
	int i, n;

	printf("\033c");
	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case ' ':
		case '-':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(*fmt);
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	va_end(ap);
	printf("\n");
	thrd_sleep(&t, NULL);
}

void
minus(int n)
{
	int i;

	n = -n;
	for (i = n; i >= 0; i--) {
		linef(" >8-", i, n - i);
		if (i)
			linef(" =8-", i, n - i);
	}
}

void
zero()
{
	int i;

	for (i = 0; i < 5; i++) {
		linef("8<");
		linef("8=");
	}
}

void
plus(int n)
{
	int i;

	for (i = 0; i <= n; i++) {
		linef("-8<", i);
		if (i + 1 <= n)
			linef("-8=", i);
	}
}

void
scissors(int n)
{
	if (n < 0)
		minus(n);
	else if (n == 0)
		zero();
	else
		plus(n);
}

void
usage()
{
	fprintf(stderr, "usage: <n>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	scissors(atoi(argv[1]));
	return 0;
}
