/*

--- Day 12: Hill Climbing Algorithm ---
You try contacting the Elves using your handheld device, but the river you're following must be too low to get a decent signal.

You ask the device for a heightmap of the surrounding area (your puzzle input). The heightmap shows the local area from above broken into a grid; the elevation of each square of the grid is given by a single lowercase letter, where a is the lowest elevation, b is the next-lowest, and so on up to the highest elevation, z.

Also included on the heightmap are marks for your current position (S) and the location that should get the best signal (E). Your current position (S) has elevation a, and the location that should get the best signal (E) has elevation z.

You'd like to reach E, but to save energy, you should do it in as few steps as possible. During each step, you can move exactly one square up, down, left, or right. To avoid needing to get out your climbing gear, the elevation of the destination square can be at most one higher than the elevation of your current square; that is, if your current elevation is m, you could step to elevation n, but not to elevation o. (This also means that the elevation of the destination square can be much lower than the elevation of your current square.)

For example:

Sabqponm
abcryxxl
accszExk
acctuvwj
abdefghi
Here, you start in the top-left corner; your goal is near the middle. You could start by moving down or right, but eventually you'll need to head toward the e at the bottom. From there, you can spiral around to the goal:

v..v<<<<
>v.vv<<^
.>vv>E^^
..v>>>^^
..>>>>>^
In the above diagram, the symbols indicate whether the path exits each square moving up (^), down (v), left (<), or right (>). The location that should get the best signal is still E, and . marks unvisited squares.

This path reaches the goal in 31 steps, the fewest possible.

What is the fewest steps required to move from your current position to the location that should get the best signal?

--- Part Two ---
As you walk up the hill, you suspect that the Elves will want to turn this into a hiking trail. The beginning isn't very scenic, though; perhaps you can find a better starting point.

To maximize exercise while hiking, the trail should start as low as possible: elevation a. The goal is still the square marked E. However, the trail should still be direct, taking the fewest steps to reach its goal. So, you'll need to find the shortest path from any square at elevation a to the square marked E.

Again consider the example from above:

Sabqponm
abcryxxl
accszExk
acctuvwj
abdefghi
Now, there are six choices for starting position (five marked a, plus the square marked S that counts as being at elevation a). If you start at the bottom-left square, you can reach the goal most quickly:

...v<<<<
...vv<<^
...v>E^^
.>v>>>^^
>^>>>>>^
This path reaches the goal in only 29 steps, the fewest possible.

What is the fewest steps required to move starting from any square with elevation a to the location that should get the best signal?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int width;
	int height;
	int size;
	int sx, sy;
	char *pix;
	char *aux;
} Map;

#define auxset(m, x, y, v) (m)->aux[(y) * m->width + (x)] = (v)
#define auxget(m, x, y) (m)->aux[(y) * m->width + (x)]

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

	free(m->pix);
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
	return m->pix[i];
}

void
mapset(Map *m, int x, int y, int c)
{
	int i;

	i = (m->width * y) + x;
	if (x < 0 || y < 0 || x >= m->width || y >= m->height)
		return;
	m->pix[i] = c;
}

int
mapfind(Map *m, int c, int *xp, int *yp)
{
	int x, y;

	for (y = 0; y < m->height; y++) {
		for (x = 0; x < m->width; x++) {
			if (mapget(m, x, y) == c) {
				*xp = x;
				*yp = y;
				return 1;
			}
		}
	}
	return 0;
}

Map *
readmap(const char *name)
{
	FILE *fp;
	char buf[1024];
	int len;
	Map *m;

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
		else if (len != m->width) {
			errno = EINVAL;
			goto error;
		}

		m->height += 1;
		m->size = m->width * m->height;
		m->pix = xrealloc(m->pix, m->size);
		memcpy(m->pix + m->size - m->width, buf, len);
	}
	m->aux = xcalloc(1, m->size);

	mapfind(m, 'S', &m->sx, &m->sy);

	if (0) {
	error:
		mapfree(m);
		m = NULL;
	}

	if (fp)
		fclose(fp);

	return m;
}

int
minpath(Map *m, int target, int invert)
{
	static const struct dir {
		int d, dx, dy;
	} dir[4] = {
		{ '>', 1, 0 },
		{ '<', -1, 0 },
		{ '^', 0, -1 },
		{ 'v', 0, 1 }
	};

	struct queue {
		int x, y, depth;
	};

	struct queue *queue;
	int queuelen;
	int depth;
	int x, y;
	int nx, ny;
	int h, curh;
	int ret;
	size_t i;

	ret = -1;
	memset(m->aux, 0, m->size);

	queue = xcalloc(sizeof(*queue), m->size);
	queue[0] = (struct queue){ m->sx, m->sy, 0 };
	queuelen = 1;

	auxset(m, m->sx, m->sy, '.');
	while (queuelen--) {
		x = queue[0].x;
		y = queue[0].y;
		depth = queue[0].depth;

		memmove(queue, queue + 1, queuelen * sizeof(*queue));

		curh = mapget(m, x, y);
		if (curh == target) {
			ret = depth;
			break;
		}

		if (curh == 'S')
			curh = 'a';

		for (i = 0; i < nelem(dir); i++) {
			nx = x + dir[i].dx;
			ny = y + dir[i].dy;
			h = mapget(m, nx, ny);
			if (h == 'E')
				h = 'z';

			if (h == -1)
				continue;

			if (!invert) {
				if (h - curh > 1)
					continue;
			} else if (h - curh < -1)
				continue;

			if (auxget(m, nx, ny) != 0)
				continue;

			auxset(m, nx, ny, '.');
			queue[queuelen++] = (struct queue){ nx, ny, depth + 1 };
		}
	}

	free(queue);
	return ret;
}

int
part1(Map *m)
{
	return minpath(m, 'E', 0);
}

int
part2(Map *m)
{
	mapset(m, m->sx, m->sy, 'a');
	mapfind(m, 'E', &m->sx, &m->sy);
	mapset(m, m->sx, m->sy, 'z');
	return minpath(m, 'a', 1);
}

int
main()
{
	Map *m;

	m = readmap("12.txt");
	if (!m) {
		printf("Failed to read map: %s\n", strerror(errno));
		return 1;
	}

	printf("%d\n", part1(m));
	printf("%d\n", part2(m));

	mapfree(m);
	return 0;
}
