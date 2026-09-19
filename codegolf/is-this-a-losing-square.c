/*

There is a game called Get Home that is played on the a chess board. In this game there is a single piece that is moved by both players in turns. There are some rules to how the piece can be moved. On a turn a player must make one of the following moves for positive n.

n spaces up

n spaces to the left

n spaces up and to the left (a diagonal)

The player who moves the piece into the top left corner of the board wins the game.

Now we will define the concept of a losing square. In this video (from where I got the idea) a losing square is defined as a square on which, any player starting their turn will be forced to make a move allowing their opponent to force a win. The simplest example of a losing square would be the square at (1,2). A piece at (1,2) can move to any of the following places.

https://i.stack.imgur.com/M00pY.png

All of which have a direct path to victory for the next player.

It also follows that any square that has a one move path to a losing square allows the player starting on that square to force a win. This means that any square that is not one move away from a losing square is also a losing square.

This brings us to this rather neat definition of a losing square:

A losing square is a square from which no move can arrive on another losing square and (0,0) is a losing square.

Task
Given the coordinates of a square on an arbitrarily sized chess board determine if it is a losing square. Output two values one for losing squares and one for others.

This is code-golf so answers will be scored in bytes with less bytes being better.

Test Cases
Here are all the losing squares on a regular 8 by 8 chess board (marked with 0).

0 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 0
1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1

Here is an image of a 100 by 100 board with losing squares marked in black (each square is 2 pixels by 2 pixels).

https://i.stack.imgur.com/9o8MP.png

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@notjagan

Based on the formula for cold positions in Wythoff's game and making some modifications in order to produce an explicit formula.

*/

int
outcome(int r, int c)
{
	int v;

	v = abs(r - c) * (3 + sqrt(5)) / 2;
	return v != max(r, c);
}

int
main(void)
{
	static const int sq[8][8] = {
	    {0, 1, 1, 1, 1, 1, 1, 1},
	    {1, 1, 0, 1, 1, 1, 1, 1},
	    {1, 0, 1, 1, 1, 1, 1, 1},
	    {1, 1, 1, 1, 1, 0, 1, 1},
	    {1, 1, 1, 1, 1, 1, 1, 0},
	    {1, 1, 1, 0, 1, 1, 1, 1},
	    {1, 1, 1, 1, 1, 1, 1, 1},
	    {1, 1, 1, 1, 0, 1, 1, 1},
	};

	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			assert(outcome(i, j) == sq[i][j]);
	}

	return 0;
}
