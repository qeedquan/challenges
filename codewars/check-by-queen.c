/*

In a game of chess, a queen is the most powerful piece on the board. She can move an unlimited number of squares in a straight line in any of 8 directions (forwards, backwards, left, right, and each of the four diagonals in between).

The diagram below shows the queen's influence from her current position - she would be able to take any piece on a square marked with an 'X'.



Image from: https://www.pinterest.com/pin/567453621770398092/

An opponent's king who can be taken by the queen is said to be in 'check', and would then need to find some way to escape this situation.

In any normal game of chess, the queen would work with her army on an 8x8 board to threaten the king in this way, and ultimately try to win the game. However, for this kata, the queen will work by herself on a 5x5 board.

The 5x5 chessboard will be represented as a 2 dimensional array, (ie: an array containing 5 other arrays, each containing 5 single character elements). Empty spaces within each sub-array will be represented by an asterix: "*", while one of these 25 elements will be represented by a "q" (queen) and a "k" (king). Both will be represented in lower case.

The 2 dimensional chessboard array would look something like this:

char b = [ [ '*', '*', '*', '*', '*' ],
              [ '*', '*', '*', '*', 'k' ],
              [ '*', '*', '*', '*', '*' ],
              [ '*', 'q', '*', '*', '*' ],
              [ '*', '*', '*', '*', '*' ] ];

Your task is to write a function which will return true if the king is in check, and false if he isn't.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bool
check(char b[5][5])
{
	int k[2], q[2];
	int dx, dy;
	int i, j;

	k[0] = k[1] = -1;
	q[0] = q[1] = -1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (b[i][j] == 'k') {
				k[0] = i;
				k[1] = j;
			} else if (b[i][j] == 'q') {
				q[0] = i;
				q[1] = j;
			}
		}
	}

	dx = k[0] - q[0];
	dy = k[1] - q[1];
	return !dx || !dy || abs(dx) == abs(dy);
}

int
main()
{
	char b1[5][5] = { { '*', 'q', '*', '*', 'k' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b2[5][5] = { { '*', '*', '*', '*', '*' }, { '*', 'k', '*', 'q', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b3[5][5] = { { 'k', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { 'q', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b4[5][5] = { { '*', '*', '*', '*', 'q' }, { '*', '*', '*', '*', 'k' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b5[5][5] = { { '*', 'k', '*', '*', '*' }, { '*', '*', 'q', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b6[5][5] = { { '*', '*', 'k', '*', '*' }, { '*', 'q', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b7[5][5] = { { '*', '*', '*', 'q', '*' }, { '*', '*', 'k', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b8[5][5] = { { '*', '*', 'q', '*', 'k' }, { '*', '*', '*', 'k', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };
	char b9[5][5] = { { '*', '*', 'q', '*', '*' }, { 'k', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' }, { '*', '*', '*', '*', '*' } };

	assert(check(b1) == true);
	assert(check(b2) == true);
	assert(check(b3) == true);
	assert(check(b4) == true);
	assert(check(b5) == true);
	assert(check(b6) == true);
	assert(check(b7) == true);
	assert(check(b8) == true);
	assert(check(b9) == false);

	return 0;
}
