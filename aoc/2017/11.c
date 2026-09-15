/*

--- Day 11: Hex Ed ---
Crossing the bridge, you've barely reached the other side of the stream when a program comes up to you, clearly in distress. "It's my child process," she says, "he's gotten lost in an infinite grid!"

Fortunately for her, you have plenty of experience with infinite grids.

Unfortunately for you, it's a hex grid.

The hexagons ("hexes") in this grid are aligned such that adjacent hexes can be found to the north, northeast, southeast, south, southwest, and northwest:

  \ n  /
nw +--+ ne
  /    \
-+      +-
  \    /
sw +--+ se
  / s  \
You have the path the child process took. Starting where he started, you need to determine the fewest number of steps required to reach him. (A "step" means to move from the hex you are in to any adjacent hex.)

For example:

ne,ne,ne is 3 steps away.
ne,ne,sw,sw is 0 steps away (back where you started).
ne,ne,s,s is 2 steps away (se,se).
se,sw,se,sw,sw is 3 steps away (s,s,sw).

--- Part Two ---
How many steps away is the furthest he ever got from his starting position?

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
distance(int x, int y)
{
	x = abs(x);
	y = abs(y);
	if (x > y)
		return x;
	return (abs(x - y) / 2) + min(x, y);
}

int
move(FILE *fp, int *x, int *y)
{
	size_t i;
	char d[4];
	int c;

	if (feof(fp))
		return 0;

	i = 0;
	for (;;) {
		c = fgetc(fp);
		if (c == EOF || c == ',')
			break;
		if (isspace(c))
			continue;
		if (i + 1 < sizeof(d))
			d[i++] = c;
	}
	d[i] = '\0';

	if (!strcmp(d, "s")) {
		*y -= 2;
	} else if (!strcmp(d, "n")) {
		*y += 2;
	} else if (!strcmp(d, "se")) {
		*x += 1;
		*y -= 1;
	} else if (!strcmp(d, "sw")) {
		*x -= 1;
		*y -= 1;
	} else if (!strcmp(d, "nw")) {
		*x -= 1;
		*y += 1;
	} else if (!strcmp(d, "ne")) {
		*x += 1;
		*y += 1;
	}
	return 1;
}

int
solve(const char *name)
{
	FILE *fp;
	int x, y;
	int d, m;

	fp = fopen(name, "r");
	if (!fp)
		return -errno;

	x = y = m = 0;
	while (move(fp, &x, &y)) {
		d = distance(x, y);
		m = max(m, d);
	}

	printf("%d\n", d);
	printf("%d\n", m);

	fclose(fp);
	return 0;
}

int
main()
{
	solve("11.txt");
	return 0;
}
