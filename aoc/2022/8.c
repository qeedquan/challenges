/*

--- Day 8: Treetop Tree House ---
The expedition comes across a peculiar patch of tall trees all planted carefully in a grid. The Elves explain that a previous expedition planted these trees as a reforestation effort. Now, they're curious if this would be a good location for a tree house.

First, determine whether there is enough tree cover here to keep a tree house hidden. To do this, you need to count the number of trees that are visible from outside the grid when looking directly along a row or column.

The Elves have already launched a quadcopter to generate a map with the height of each tree (your puzzle input). For example:

30373
25512
65332
33549
35390
Each tree is represented as a single digit whose value is its height, where 0 is the shortest and 9 is the tallest.

A tree is visible if all of the other trees between it and an edge of the grid are shorter than it. Only consider trees in the same row or column; that is, only look up, down, left, or right from any given tree.

All of the trees around the edge of the grid are visible - since they are already on the edge, there are no trees to block the view. In this example, that only leaves the interior nine trees to consider:

The top-left 5 is visible from the left and top. (It isn't visible from the right or bottom since other trees of height 5 are in the way.)
The top-middle 5 is visible from the top and right.
The top-right 1 is not visible from any direction; for it to be visible, there would need to only be trees of height 0 between it and an edge.
The left-middle 5 is visible, but only from the right.
The center 3 is not visible from any direction; for it to be visible, there would need to be only trees of at most height 2 between it and an edge.
The right-middle 3 is visible from the right.
In the bottom row, the middle 5 is visible, but the 3 and 4 are not.
With 16 trees visible on the edge and another 5 visible in the interior, a total of 21 trees are visible in this arrangement.

Consider your map; how many trees are visible from outside the grid?

--- Part Two ---
Content with the amount of tree cover available, the Elves just need to know the best spot to build their tree house: they would like to be able to see a lot of trees.

To measure the viewing distance from a given tree, look up, down, left, and right from that tree; stop if you reach an edge or at the first tree that is the same height or taller than the tree under consideration. (If a tree is right on the edge, at least one of its viewing distances will be zero.)

The Elves don't care about distant trees taller than those found by the rules above; the proposed tree house has large eaves to keep it dry, so they wouldn't be able to see higher than the tree house anyway.

In the example above, consider the middle 5 in the second row:

30373
25512
65332
33549
35390
Looking up, its view is not blocked; it can see 1 tree (of height 3).
Looking left, its view is blocked immediately; it can see only 1 tree (of height 5, right next to it).
Looking right, its view is not blocked; it can see 2 trees.
Looking down, its view is blocked eventually; it can see 2 trees (one of height 3, then the tree of height 5 that blocks its view).
A tree's scenic score is found by multiplying together its viewing distance in each of the four directions. For this tree, this is 4 (found by multiplying 1 * 1 * 2 * 2).

However, you can do even better: consider the tree of height 5 in the middle of the fourth row:

30373
25512
65332
33549
35390
Looking up, its view is blocked at 2 trees (by another tree with a height of 5).
Looking left, its view is not blocked; it can see 2 trees.
Looking down, its view is also not blocked; it can see 1 tree.
Looking right, its view is blocked at 2 trees (by a massive tree of height 9).
This tree's scenic score is 8 (2 * 2 * 1 * 2); this is the ideal spot for the tree house.

Consider each tree on your map. What is the highest scenic score possible for any tree?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
	int width;
	int height;
	int size;
	char *buf;
	char *aux;
} Map;

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

void *
xrealloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);
	if (!ptr)
		abort();
	return ptr;
}

void
mapfree(Map *m)
{
	if (!m)
		return;

	free(m->buf);
	free(m->aux);
	free(m);
}

char
mapget(Map *m, int x, int y)
{
	int i;

	i = (m->width * y) + x;
	if (x < 0 || y < 0 || x >= m->width || y >= m->height)
		return -1;
	return m->buf[i];
}

Map *
readmap(const char *name)
{
	Map *m;
	FILE *fp;
	char buf[1024];
	int len;

	m = xcalloc(1, sizeof(*m));
	fp = fopen(name, "r");
	if (!fp)
		goto error;

	while (fgets(buf, sizeof(buf), fp)) {
		len = strlen(buf);
		if (len < 2)
			continue;

		if (buf[len - 1] == '\n')
			buf[--len] = '\0';

		if (m->width == 0)
			m->width = len;
		else if (m->width != len) {
			errno = EINVAL;
			goto error;
		}

		m->height += 1;
		m->size = m->width * m->height;
		m->buf = xrealloc(m->buf, m->size);
		memcpy(m->buf + m->size - m->width, buf, len);
	}
	m->aux = xcalloc(sizeof(*m->aux), m->size);

	if (0) {
	error:
		mapfree(m);
		m = NULL;
	}

	if (fp)
		fclose(fp);

	return m;
}

void
mark(Map *m, int px, int py, int vx, int vy, int nx, int ny)
{
	int x, y;
	int bx, by;
	int steps;
	int max;
	int c;

	x = px;
	y = py;
	for (steps = m->size; steps > 0; steps--) {
		bx = x;
		by = y;
		max = 0;
		while ((c = mapget(m, x, y)) != -1) {
			if (c > max) {
				m->aux[y * m->width + x] = 1;
				max = c;
			}
			x += vx;
			y += vy;
		}
		x = bx + nx;
		y = by + ny;
	}
}

int
visible(Map *m)
{
	int i, r;

	mark(m, 0, 0, 1, 0, 0, 1);
	mark(m, m->width - 1, 0, -1, 0, 0, 1);
	mark(m, 0, 0, 0, 1, 1, 0);
	mark(m, 0, m->height - 1, 0, -1, 1, 0);

	r = 0;
	for (i = 0; i < m->size; i++)
		r += m->aux[i];
	return r;
}

int
viewdistance(Map *m, int x, int y, int vx, int vy)
{
	int distance;
	int height;
	int value;

	distance = 0;
	height = mapget(m, x, y);
	for (;;) {
		x += vx;
		y += vy;
		value = mapget(m, x, y);
		if (value == -1)
			break;

		distance++;
		if (value >= height)
			break;
	}
	return distance;
}

int
scenic(Map *m, int x, int y)
{
	return viewdistance(m, x, y, 1, 0) *
	       viewdistance(m, x, y, -1, 0) *
	       viewdistance(m, x, y, 0, 1) *
	       viewdistance(m, x, y, 0, -1);
}

int
part1(Map *m)
{
	return visible(m);
}

int
part2(Map *m)
{
	int best;
	int score;
	int x, y;

	best = 0;
	for (x = 0; x < m->width; x++) {
		for (y = 0; y < m->height; y++) {
			score = scenic(m, x, y);
			if (score > best)
				best = score;
		}
	}
	return best;
}

int
main()
{
	Map *m;

	m = readmap("8.txt");
	if (!m) {
		printf("Failed to load map: %s\n", strerror(errno));
		return 1;
	}

	printf("%d\n", part1(m));
	printf("%d\n", part2(m));

	mapfree(m);

	return 0;
}
