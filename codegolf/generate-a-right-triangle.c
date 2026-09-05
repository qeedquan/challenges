/*

In this challenge, you must take two numbers (separated by a space) as input and output an ASCII right triangle, made up of xs.

The first number will be the width and height of the triangle you should output. The second number will be which corner the right angle will be in. The corners are numbered 1 to 4, starting in the top left and going in English reading order:

1    2



3    4
For example (inputs and their respective triangle outputs):

INPUT | 3 1 | 3 2 | 3 3 | 3 4
------+-----+-----+-----+----
 OUT- | xxx | xxx | x   |   x
 PUT  | xx  |  xx | xx  |  xx
      | x   |   x | xxx | xxx
Your program's output must match these examples exactly for their respective inputs.

The input will always be valid: the first number will be an integer ≥1, and the second number will be 1, 2, 3, or 4.

This is code-golf; shortest code (in character count) wins.

*/

#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
sign(Point a, Point b, Point c)
{
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool
inside(Point p, Point a, Point b, Point c)
{
	bool b1, b2, b3;

	b1 = sign(p, a, b) < 0;
	b2 = sign(p, b, c) < 0;
	b3 = sign(p, c, a) < 0;
	return b1 == b2 && b2 == b3;
}

int
right(int s, int c)
{
	Point v[][3] = {
	    {{1, 1}, {s, 1}, {1, s}},
	    {{1, 1}, {s, 1}, {s, s}},
	    {{1, 1}, {s, s}, {1, s}},
	    {{s, 1}, {s, s}, {1, s}},
	};

	Point p, *t;

	if (!(1 <= c && c <= 4))
		return -1;

	printf("%d %d\n", s, c);
	t = v[c - 1];
	for (p.y = 1; p.y <= s; p.y++) {
		for (p.x = 1; p.x <= s; p.x++) {
			if (inside(p, t[0], t[1], t[2]))
				printf("x");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

int
main(void)
{
	right(3, 1);
	right(3, 2);
	right(3, 3);
	right(3, 4);

	return 0;
}
