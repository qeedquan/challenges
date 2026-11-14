/*

The fifteen puzzle is peculiar in that only half the possible states of arrangement are solvable. If you flip the 14 and 15 tiles, there is no way you can slide the blocks so that they are flipped back.

Your task is to build a program that accepts a list of integers in the format of your choice (containing exactly one instance of each of the numbers from 0 to 15, with 0 being the blank space) representing the state of an arrangement of tiles in a 4x4 grid, and outputs a single boolean value determining whether the grid is solvable or not.

The shortest code to do this in any language wins.

*/

#include <assert.h>
#include <math.h>

/*

https://stackoverflow.com/questions/34570344/check-if-15-puzzle-is-solvable
https://math.stackexchange.com/questions/2714774/rigorous-proof-to-show-that-the-15-puzzle-problem-is-unsolvable

@user307169
In short, a puzzle configuration is not solvable if and only if it's an odd number of swaps away from the solved state,
like the one in your image is (14 and 15 swapped = 1 swap).
I used this fact a few years ago to quickly generate random configurations for a 15-puzzle app I used to have in the App Store.

Reference: https://kconrad.math.uconn.edu/blurbs/grouptheory/15puzzle.pdf

*/

bool
solvable(int puzzle[16])
{
	int parity;
	int width;
	int size;
	int blankrow;
	int row;
	int i, j;

	parity = 0;
	blankrow = 0;
	row = 0;
	size = 16;
	width = sqrt(size);
	for (i = 0; i < size; i++) {
		// advance to next row
		if (!(i % width))
			row += 1;

		// blank tile
		if (puzzle[i] == 0) {
			blankrow = row;
			continue;
		}
		for (j = i + 1; j < size; j++) {
			if (puzzle[i] > puzzle[j] && puzzle[j] != 0)
				parity += 1;
		}
	}

	// even grid
	if (width % 2 == 0) {
		// blank on odd row; counting from bottom
		if (!(blankrow % 2))
			return (parity % 2) == 0;
		// blank on even row; counting from bottom
		return (parity % 2) != 0;
	}

	// odd grid
	return (parity % 2) == 0;
}

int
main()
{
	int puzzle1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 11, 13, 14, 15, 12 };
	int puzzle2[] = { 1, 2, 3, 4, 8, 7, 6, 5, 9, 10, 11, 0, 12, 15, 14, 13 };
	int puzzle3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 0 };

	assert(solvable(puzzle1) == true);
	assert(solvable(puzzle2) == true);
	assert(solvable(puzzle3) == false);

	return 0;
}
