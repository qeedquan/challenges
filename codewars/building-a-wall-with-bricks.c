/*

Scenario
A construction master applies specific rules when creating walls. But the construction master cannot calculate the exact number of bricks to be spent on the walls.

For this reason, you are expected to write a method that calculates the number of bricks that need to be spent for the wall whose width and height are clear.

Rules

Only 3 kinds of bricks can be used. Large Brick(60 cm), Medium Brick(40 cm) and Small Brick(20cm)
The height of all bricks is 5 cm and wall height is always 5 cm and multiples.
The Wall width is always 60 cm and multiples.
The lowest row should be composed of only large bricks.
After that, the first brick from the right of the next row must be the middle brick, the first brick from the left is the small brick.
Finally, The first brick from the right of the next row must be the small brick, the first brick from the left is the medium brick.
The first row after the series is completed again consists of large bricks and the cycle continues.
The number of bricks used should return to the following format. "21L6M6S"
If number of medium and small bricks is 0, then answer should be the following format. "21L"

Example Wall
https://farm8.staticflickr.com/7890/46919699451_0f8c097540.jpg

Wall height is 45 cm and wall width is 180 cm. There are 21 large bricks. (Yellow bricks) There are 6 medium bricks. (Green bricks) There are 6 small bricks. (Pink bricks)

So answer is "21L6M6S"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
bricks(int w, int h, char *b)
{
	int c[3];
	int r;
	int i;

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	r = h / 5;
	for (i = 0; i < r; i++) {
		if ((i + 1) % 3 != 1) {
			c[2] += 1;
			c[1] += 1;
			c[0] += (w / 60) - 1;
		} else
			c[0] += w / 60;
	}

	b += sprintf(b, "%dL", c[0]);
	if (c[1])
		b += sprintf(b, "%dM", c[1]);
	if (c[2])
		b += sprintf(b, "%dS", c[2]);
}

void
test(int w, int h, const char *r)
{
	char b[64];

	bricks(w, h, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(180, 45, "21L6M6S");
	test(60, 5, "1L");
	test(540, 5, "9L");
	test(60, 10, "1L1M1S");
	test(300, 95, "83L12M12S");
	test(1860, 210, "1274L28M28S");
	test(6600, 330, "7216L44M44S");

	return 0;
}
