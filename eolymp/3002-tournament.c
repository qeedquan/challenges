/*

Two players are holding a darts tournament consisting of a series of n games. In each game, the participants make several throws and earn points.
The winner of an individual game is the player who scores more points than the opponent.
If both players score the same number of points, the game is considered a draw.

The winner of the tournament is the player who wins more games.

Write a program that determines the winner of the tournament.

Input
The first line contains one positive integer n (1≤n≤1000) — the number of games in the tournament.
Each of the following n lines contains two non-negative integers — the number of points scored by the first and second players, respectively.
All values do not exceed 1000.

Output
Print:

the number 1, if the winner of the tournament is the first player;

the number 2, if the winner is the second player;

the number 0, if the tournament ends in a draw.

Examples

Input #1
3
3 1
1 0
1 2

Answer #1
1

Input #2
2
1 1
0 5

Answer #2
2

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solve(int scores[][2], size_t length)
{
	size_t index;
	int player1;
	int player2;

	player1 = player2 = 0;
	for (index = 0; index < length; index++) {
		if (scores[index][0] > scores[index][1])
			player1++;
		else
			player2++;
	}
	if (player1 > player2)
		return 1;
	if (player1 < player2)
		return 2;
	return 0;
}

int
main()
{
	int scores1[][2] = {
		{ 3, 1 },
		{ 1, 0 },
		{ 1, 2 },
	};

	int scores2[][2] = {
		{ 1, 1 },
		{ 0, 5 },
	};

	assert(solve(scores1, nelem(scores1)) == 1);
	assert(solve(scores2, nelem(scores2)) == 2);

	return 0;
}
