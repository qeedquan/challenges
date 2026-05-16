#include <assert.h>
#include <stdio.h>
#include <string.h>

enum {
	SIZE = 32,
};

typedef char Grid[SIZE][SIZE];

void
build(const char **input, Grid grid, int column, int row, int width, int *count)
{
	int code;
	int i, j;

	code = **input;
	*input += 1;
	switch (code) {
	case 'p':
		build(input, grid, column + width / 2, row, width / 2, count);
		build(input, grid, column, row, width / 2, count);
		build(input, grid, column, row + width / 2, width / 2, count);
		build(input, grid, column + width / 2, row + width / 2, width / 2, count);
		break;

	case 'f':
		for (i = row; i < row + width; i++) {
			for (j = column; j < column + width; j++) {
				if (grid[i][j] == 0) {
					grid[i][j] = 1;
					*count += 1;
				}
			}
		}
		break;
	}
}

int
solve(const char *line1, const char *line2)
{
	Grid grid;
	int count;

	memset(grid, 0, sizeof(grid));
	count = 0;
	build(&line1, grid, 0, 0, SIZE, &count);
	build(&line2, grid, 0, 0, SIZE, &count);
	return count;
}

int
main()
{
	assert(solve("ppeeefpffeefe", "pefepeefe") == 640);
	assert(solve("peeef", "peefe") == 512);
	assert(solve("peeef", "peepefefe") == 384);

	return 0;
}
