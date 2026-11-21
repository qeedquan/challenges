/*

Petryk and Marichka are playing a game with a rectangular chocolate bar of size a×b.
They take turns breaking off exactly one piece of chocolate and eating it.
The player who cannot make a move loses the game. Marichka always goes first because Petryk is a gentleman.

Your task is to determine the outcome of the game given the dimensions of the chocolate bar.
Output 1 if Petryk will have to buy the next chocolate bar, meaning Marichka wins.
Output 0 if Marichka loses.

Input
The input consists of a single line with two natural numbers a and b, separated by a space. Each number does not exceed 1000.

Output
Print the result of the game.

Examples

Input #1
4 5

Answer #1
0

*/

#include <assert.h>

int
solve(int a, int b)
{
	return (a * b) & 1;
}

int
main()
{
	assert(solve(4, 5) == 0);

	return 0;
}
