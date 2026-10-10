/*

Challenge
Generate two 16×16 grids, each initially filled with "@" symbols and spaces.
Each cell in the grids should be independently filled with an "@" or a space, with each character having an equal probability (50%) of being chosen for each cell.
This ensures that both grids start off identically, with all possible configurations of each grid having the same probability of occurrence, corresponding to a uniform distribution across all possible grid states.

After generating these identical grids, modify a single, randomly selected cell in the second grid by either adding or removing an "@" symbol.
This modification guarantees that the second grid differs from the first grid in exactly one position.
The selection of this cell must be uniformly random from among the 256 cells, ensuring that each cell has an equal chance (1/256) of being chosen for modification.

Input

None

Output

Both grids side by side, separated by a vertical bar "|", to visually compare them and spot the single difference. e.g. row 3, col 10.

@ @ @ @   @ @ @@|@ @ @ @   @ @ @@
 @@@ @@   @    @| @@@ @@   @    @
 @ @@@@@@ @   @ | @ @@@@@@@@   @
  @  @  @@ @@ @ |  @  @  @@ @@ @
@@@  @@ @@  @  @|@@@  @@ @@  @  @
  @ @   @ @@  @@|  @ @   @ @@  @@
@ @ @@ @  @@ @@@|@ @ @@ @  @@ @@@
@ @       @@    |@ @       @@
    @ @@   @@@ @|    @ @@   @@@ @
 @@ @    @@ @@  | @@ @    @@ @@
@    @@@@   @ @@|@    @@@@   @ @@
@@ @@ @@  @@@ @@|@@ @@ @@  @@@ @@
 @@@ @ @@    @ @| @@@ @ @@    @ @
   @ @  @  @ @  |   @ @  @  @ @
@@@@ @@@@@ @  @@|@@@@ @@@@@ @  @@
 @  @@@ @@@@ @@@| @  @@@ @@@@ @@@

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum {
	W = 16,
	H = 16,
};

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

void
gen(char A[H][W], char B[H][W])
{
	static const char sym[] = " @";

	int x, y;

	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++)
			A[y][x] = sym[randn(2) - 1];
	}
	memcpy(B, A, W * H);

	x = randn(W) - 1;
	y = randn(H) - 1;
	A[y][x] = (A[y][x] == sym[0]) ? sym[1] : sym[0];
}

void
draw(char A[H][W], char B[H][W])
{
	int x, y;

	for (y = 0; y < H; y++) {
		for (x = 0; x < W; x++)
			printf("%c", A[y][x]);
		printf("|");
		for (x = 0; x < W; x++)
			printf("%c", B[y][x]);
		printf("\n");
	}
}

void
spots()
{
	char A[H][W], B[H][W];

	gen(A, B);
	draw(A, B);
}

int
main()
{
	srand(time(NULL));
	spots();
	return 0;
}
