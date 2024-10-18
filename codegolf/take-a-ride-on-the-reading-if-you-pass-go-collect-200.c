/*

Monopoly Board
For this code-golf challenge we will be building the board game Monopoly.

Rules:
Take no input.
Output a 11x11 board where each ASCII character forming the board is the first letter of each space of the U.S. version of the Monopoly board.
The characters must be separated by spaces.
Go should start in the bottom right.
The exact string to produce is

F K C I I B A V W M G
N                   P
T                   N
C                   C
S                   P
P                   S
V                   C
S                   P
E                   L
S                   B
J C V C O R I B C M G
Note that from bottom right to bottom left the squares are as follows:

G --> Go
M --> Mediterranean Avenue
C --> Community Chest
B --> Baltic Avenue
I --> Income Tax
...
J --> Jail

*/

#include <stdio.h>

void
board(void)
{
	puts("F K C I I B A V W M G");
	puts("N                   P");
	puts("T                   N");
	puts("C                   C");
	puts("S                   P");
	puts("P                   S");
	puts("V                   C");
	puts("S                   P");
	puts("E                   L");
	puts("S                   B");
	puts("J C V C O R I B C M G");
}

int
main(void)
{
	board();
	return 0;
}
