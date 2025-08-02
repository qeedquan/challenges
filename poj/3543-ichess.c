/*

Description

The Jury of NEERC’07 quarterfinals is proud to present you a new game — chess patience. This patience is played not with cards, but with black and white square tiles. The goal of the game is to place these tiles on a flat surface so that they form a square colored in a chess-like pattern. The square should be totally filled and be of the maximal possible size. There may remain some spare tiles, if they do not fit into the resulting square.

To make this game more popular, a computer version of this patience named iChess was developed. The rules are the same with the exception that the player is given the number of tiles, not the actual tiles. Also, the result of the patience is not the actual layout, but the side length (measured in tiles) of the maximal square with the required layout.

Your task is to write a program which can play iChess patience.

Input

The input file contains two integer numbers b and w — the number of black and white tiles respectively (0 ≤ b, w ≤ 10 000).

Output

The first line of the input file must contain a single integer number s — the side length of the maximum possible square made of at most b black and w white tiles.

If no square can be formed with the given tiles, output a single word “Impossible”.

Sample Input

#1	12 15
#2	0 0

Sample Output

#1	5
#2	Impossible

Source

Northeastern Europe 2007, Northern Subregion

*/

#include <assert.h>
#include <limits.h>

int
sidelen(unsigned b, unsigned w)
{
	unsigned i, x, y;

	for (i = 1; i < INT_MAX; i++) {
		x = ((i * i) - (i & 1)) / 2;
		y = ((i * i) + (i & 1)) / 2;
		if (!((b >= x && w >= y) || (b >= y && w >= x))) {
			if (--i > 0)
				return i;

			break;
		}
	}
	return -1;
}

int
main(void)
{
	assert(sidelen(12, 15) == 5);
	assert(sidelen(0, 0) == -1);

	return 0;
}
