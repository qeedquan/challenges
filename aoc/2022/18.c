/*

--- Day 18: Boiling Boulders ---
You and the elephants finally reach fresh air. You've emerged near the base of a large volcano that seems to be actively erupting! Fortunately, the lava seems to be flowing away from you and toward the ocean.

Bits of lava are still being ejected toward you, so you're sheltering in the cavern exit a little longer. Outside the cave, you can see the lava landing in a pond and hear it loudly hissing as it solidifies.

Depending on the specific compounds in the lava and speed at which it cools, it might be forming obsidian! The cooling rate should be based on the surface area of the lava droplets, so you take a quick scan of a droplet as it flies past you (your puzzle input).

Because of how quickly the lava is moving, the scan isn't very good; its resolution is quite low and, as a result, it approximates the shape of the lava droplet with 1x1x1 cubes on a 3D grid, each given as its x,y,z position.

To approximate the surface area, count the number of sides of each cube that are not immediately connected to another cube. So, if your scan were only two adjacent cubes like 1,1,1 and 2,1,1, each cube would have a single side covered and five sides exposed, a total surface area of 10 sides.

Here's a larger example:

2,2,2
1,2,2
3,2,2
2,1,2
2,3,2
2,2,1
2,2,3
2,2,4
2,2,6
1,2,5
3,2,5
2,1,5
2,3,5
In the above example, after counting up all the sides that aren't connected to another cube, the total surface area is 64.

What is the surface area of your scanned lava droplet?

--- Part Two ---
Something seems off about your calculation. The cooling rate depends on exterior surface area, but your calculation also included the surface area of air pockets trapped in the lava droplet.

Instead, consider only cube sides that could be reached by the water and steam as the lava droplet tumbles into the pond. The steam will expand to reach as much as possible, completely displacing any air on the outside of the lava droplet but never expanding diagonally.

In the larger example above, exactly one cube of air is trapped within the lava droplet (at 2,2,5), so the exterior surface area of the lava droplet is 58.

What is the exterior surface area of your scanned lava droplet?

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define SIZE 25

static const struct {
	int x, y, z;
} DIRS[6] = {
	{ 1, 0, 0 },
	{ -1, 0, 0 },
	{ 0, -1, 0 },
	{ 0, 1, 0 },
	{ 0, 0, -1 },
	{ 0, 0, 1 },
};

bool
outside(int x, int y, int z)
{
	return x < 0 || y < 0 || z < 0 || x >= SIZE || y >= SIZE || z >= SIZE;
}

int
load(const char *name, char space[SIZE][SIZE][SIZE])
{
	FILE *fp;
	char buf[128];
	int x, y, z;
	int ret;

	ret = 0;
	fp = fopen(name, "r");
	if (!fp)
		goto error;

	memset(space, 0, SIZE * SIZE * SIZE);
	while (fgets(buf, sizeof(buf), fp)) {
		if (sscanf(buf, "%d,%d,%d", &x, &y, &z) != 3)
			continue;

		if (outside(x, y, z)) {
			errno = ENOMEM;
			goto error;
		}

		space[x][y][z] = 1;
	}

	if (0) {
	error:
		ret = -errno;
	}

	if (fp)
		fclose(fp);

	return ret;
}

void
flood(char space[SIZE][SIZE][SIZE], int x, int y, int z)
{
	int cx, cy, cz;
	size_t i;

	if (space[x][y][z])
		return;

	space[x][y][z] = 2;
	for (i = 0; i < nelem(DIRS); i++) {
		cx = x + DIRS[i].x;
		cy = y + DIRS[i].y;
		cz = z + DIRS[i].z;
		if (!outside(cx, cy, cz))
			flood(space, cx, cy, cz);
	}
}

int
part1(char space[SIZE][SIZE][SIZE])
{
	int cx, cy, cz;
	int x, y, z;
	int area;
	size_t i;

	area = 0;
	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			for (z = 0; z < SIZE; z++) {
				if (!space[x][y][z])
					continue;

				for (i = 0; i < nelem(DIRS); i++) {
					cx = x + DIRS[i].x;
					cy = y + DIRS[i].y;
					cz = z + DIRS[i].z;

					if (outside(cx, cy, cz) || !space[cx][cy][cz])
						area++;
				}
			}
		}
	}
	return area;
}

int
part2(char space[SIZE][SIZE][SIZE])
{
	int trapped_area;
	int cx, cy, cz;
	int x, y, z;
	size_t i;

	trapped_area = 0;
	flood(space, 0, 0, 0);
	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			for (z = 0; z < SIZE; z++) {
				if (!space[x][y][z])
					continue;

				for (i = 0; i < nelem(DIRS); i++) {
					cx = x + DIRS[i].x;
					cy = y + DIRS[i].y;
					cz = z + DIRS[i].z;

					if (!outside(cx, cy, cz) && !space[cx][cy][cz])
						trapped_area++;
				}
			}
		}
	}
	return trapped_area;
}

int
main()
{
	char space[SIZE][SIZE][SIZE];
	int area, trapped_area;

	if (load("18.txt", space) < 0) {
		printf("Failed to load file: %s\n", strerror(errno));
		return 1;
	}

	area = part1(space);
	trapped_area = part2(space);
	printf("%d\n", area);
	printf("%d\n", area - trapped_area);

	return 0;
}
