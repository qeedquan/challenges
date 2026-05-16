#include <stdio.h>
#include <string.h>

enum {
	SIZE = 32,
};

typedef char Map[SIZE][SIZE];

void
init(Map map)
{
	memset(map, '.', SIZE * SIZE);
}

void
set(Map map, int x, int y)
{
	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
		return;
	map[SIZE - y - 1][x] = 'X';
}

void
draw(Map map)
{
	int x, y;

	for (y = 0; y < SIZE; y++) {
		for (x = 0; x < SIZE; x++)
			printf("%c", map[y][x]);
		printf("\n");
	}
}

void
solve(int x, int y, const char *cmd)
{
	Map map;

	init(map);
	for (; *cmd; cmd++) {
		switch (*cmd) {
		case 'E':
			set(map, x, y - 1);
			x += 1;
			break;
		case 'N':
			set(map, x, y);
			y += 1;
			break;
		case 'W':
			set(map, x - 1, y);
			x -= 1;
			break;
		case 'S':
			set(map, x - 1, y - 1);
			y -= 1;
			break;
		}
	}
	draw(map);
}

int
main()
{
	solve(2, 1, "EENNWNENWWWSSSES");

	return 0;
}
