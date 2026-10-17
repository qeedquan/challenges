/*

Your task is to output all possible ways to end a game with a tie (all rows, columns, and diagonals are completely filled and do not have 3 X's or 3 O's, and there are exactly 5 X's and 4 O's in total) in Tic-Tac-Toe (assuming X goes first):

OXO  XXO  XOX  OXX
XOX  OOX  XOX  XOO
XOX  XXO  OXO  OXX

XOX  XOX  OXX  XXO
OOX  XOO  XOO  OOX
XXO  OXX  XOX  XOX

XOX  OXX  OXO  XOO
XXO  XXO  OXX  OXX
OXO  OOX  XOX  XXO

OXO  XXO  XOX  OOX
XXO  OXX  OXX  XXO
XOX  XOO  OXO  OXX
(It does not need to be arranged in the above way.)

Rules
Output can be in any convenient format.
You may use different characters to represent X and O as long as they are distinct.
Standard loopholes are forbidden.
This is code-golf, so the shortest code in bytes wins.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
won(int board)
{
	static const int wins[] = {0x07, 0x38, 0x1C0, 0x49, 0x92, 0x124, 0x54, 0x111};

	size_t i;

	for (i = 0; i < nelem(wins); i++) {
		if ((board & wins[i]) == wins[i])
			return true;
		if ((~board & wins[i]) == wins[i])
			return true;
	}
	return false;
}

void
display(int board)
{
	int rows, cols;
	int bit;

	printf("%X\n", board);
	for (rows = 0; rows < 3; rows++) {
		for (cols = 0; cols < 3; cols++) {
			bit = (3 * rows) + cols;
			if (board & (1 << bit))
				printf("X");
			else
				printf("O");
		}
		printf("\n");
	}
	printf("\n");
}

void
search(int board, int mask, int player, bool seen[])
{
	int bit;

	if (mask == 0x1ff) {
		if (!seen[board] && !won(board)) {
			display(board);
			seen[board] = true;
		}
		return;
	}

	for (bit = 0; bit < 9; bit++) {
		if (mask & (1 << bit))
			continue;

		search(board | (player << bit), mask | (1 << bit), !player, seen);
	}
}

void
solve(void)
{
	bool seen[512];

	memset(seen, 0, sizeof(seen));
	search(0, 0, 1, seen);
}

int
main(void)
{
	solve();
	return 0;
}
