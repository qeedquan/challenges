/*

Background

When I was younger, I was taught a method of drawing a weird "S" shape, that I (along with my classmates) found fascinating. Today, I rediscovered it, and due to its formulaic approach to drawing it, thought it could lead to an interesting challenge :P
Drawing the "S"

The S can be drawn by following these simple steps:

First, draw 2 rows of three vertical lines like so

| | |

| | |

Next, connect the top left line with the bottom middle line and the top middle with the bottom right line to produce

| | |
 \ \
| | |

Finally, draw a top and bottom on the currently drawn image so that it ends up looking like

  ^
 / \
| | |
 \ \
| | |
 \ /
  v

As you can see, this results in an "S" shape. When extended however (drawing it with more than 2 rows), it produces a very interesting pattern. Your task is reproduce this interesting pattern.

Task

Given an integer where n >= 2, output The S with n rows to be made from it. Output may be returned from a function, and input may be taken in standard methods. Trailing/leading whitespace for both the overall image, as well as each line, is fine. However, leading line spaces must be consistent so that the " isn't broken. You may output as a list of lines.
Test cases

input
output
---

2

  ^
 / \
| | |
 \ \
| | |
 \ /
  v

---

8
  ^
 / \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ /
  v

---

10

  ^
 / \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ \
| | |
 \ /
  v

This is a code-golf so shortest code wins! Good luck,

*/

#include <stdio.h>

void
schain(int n)
{
	int i;

	printf("n=%d\n", n);
	puts("  ^  ");
	puts(" / \\");
	for (i = 0; i < (2 * n) - 1; i++) {
		if (!(i & 1))
			puts("| | |");
		else
			puts(" \\ \\");
	}
	puts(" \\ /");
	puts("  v  ");
	puts("");
}

int
main(void)
{
	schain(2);
	schain(8);
	schain(10);
	return 0;
}
