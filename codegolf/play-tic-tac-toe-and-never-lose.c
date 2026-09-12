/*

(There exists some challenges that require to use the best strategy, but here we don't. Even if you are able to win, you are allowed to make a tie)

Challenge
Write a program which plays the game tic-tac-toe. It must not lose (therefore, it should end the game either with a tie or by winning).

Allowed I/O methods
Input may be the current board. You can assume that all previous moves of the 2nd player were played by your engine.
Input may be the first player's moves, and your function stores which moves happened in the past. In this case the function is called multiple times, once for each move; or the function/program prompt input for multiple times.
You are allowed to take an extra input saying if you are the first player, or write two (possibly related) functions to solve the first-player problem and the second-player one. If your program need use the input method 2 (multiple call), you can decide what is passed in the first call.
Output may be the board after your turn.
Output may be your move.
A move may be represented as a pair of numbers (can be 0-indexing or 1-indexing), a number in range 0~8, or a number in range 1~9.
The board may be represented as a 3×3 array, or an array of length 9. Even if the language have 0-indexing array, you can use 1-indexing.
The cells on the grid may use any 3 different values to indicate X, O and empty.

Winning criteria
Shortest code in each language win.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef int Board[9];

/*

@Samuel Waller

This brilliant AI will always force a tie, and sometimes win if you let it. The grid is numbered in a spiral, like so:

1 2 3
8 9 4
7 6 5
and the computer always goes first. For the first move, input "10". This is a little redundant because it always goes in the same place, but it's already built into the algorithm so ¯\_(ツ)_/¯

By going in the middle first, the game is essentially converted into 1 dimension, with the only way to win being 3 in a row along the sides. The divides all of these remaining 8 squares into pairs, and always goes in the other square in the pair. For example, if you go in square 1, it goes in square 2. If you go in square 2, it goes in square 1. The nice thing about this system is that it will never make an illegal move, as well as never losing.

This was actually from a magic trick invented by Martin Gardner, where you can predict the outcome of a game of tic-tac-toe. Every game ends the exact same, including rotation, or the computer wins. It "never loses".

This is definitely my favorite solution to a code golf that I ever have found, and probably ever will find.

*/

int
ai(int position)
{
	return position + ((position & 1) << 1) - 1;
}

void
reset(Board board)
{
	static const Board setup = {1, 2, 3, 8, 9, 4, 7, 6, 5};

	memcpy(board, setup, sizeof(setup));
}

bool
move(Board board, int position, int move)
{
	int i;

	for (i = 0; i < 9; i++) {
		if (board[i] == position) {
			board[i] = move;
			return true;
		}
	}
	return false;
}

void
show(Board board)
{
	int i, x, y;

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			i = (y * 3) + x;
			if (isalpha(board[i]))
				printf("%c ", board[i]);
			else
				printf("%d ", board[i]);
		}
		printf("\n");
	}
	printf("\n");
}

const char *
score(Board board)
{
	static const int positions[][3] = {
	    {0, 1, 2},
	    {3, 4, 5},
	    {6, 7, 8},
	    {0, 3, 6},
	    {1, 4, 7},
	    {2, 5, 8},
	    {0, 4, 8},
	    {2, 4, 6},
	};

	int draw, crosses, noughts;
	size_t i, x, y;

	for (y = 0; y < nelem(positions); y++) {
		crosses = noughts = 0;
		for (x = 0; x < 3; x++) {
			i = positions[y][x];
			crosses += (board[i] == 'X');
			noughts += (board[i] == 'O');
		}
		if (crosses == 3)
			return "Computer Won!";
		if (noughts == 3)
			return "Player Won!";
	}

	draw = 0;
	for (i = 0; i < 9; i++) {
		if (isalpha(board[i]))
			draw++;
	}
	return (draw == 9) ? "Draw!" : NULL;
}

void
play()
{
	const char *outcome;
	Board board;
	int position;
	char line[128];

	reset(board);
	move(board, ai(10), 'X');
	for (;;) {
		show(board);
		printf("Enter your move: ");

		if (!fgets(line, sizeof(line), stdin))
			break;

		if (sscanf(line, "%d", &position) != 1)
			position = -1;

		if (!move(board, position, 'O')) {
			printf("Invalid move!\n\n");
			continue;
		}

		move(board, ai(position), 'X');

		outcome = score(board);
		if (outcome) {
			show(board);
			printf("%s\n", outcome);
			break;
		}
	}
	printf("\n");
}

int
main()
{
	play();
	return 0;
}
