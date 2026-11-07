/*

Bounty
One of the convincing conjectures, by Loopy Walt is,

maxlib(n) = 0, if n = 1
            2, if n = 2
            6, if n = 3
            (2n - 1)⌊n / 3⌋, if n % 3 = 0
            (2n - 1)⌊n / 3⌋ + n, if n % 3 = 2
            2n⌊n / 3⌋ + 1, otherwise
Loopy Walt's post below explains how this conjecture is derived, and contains a partial proof.

AnttiP and I will award 250 point bounty each to anyone who proves or disproves this conjecture.

I will award 50~500 point bounty for any other provable fast solution, depending on how fast it is.

Introduction
The problem is about the game of Go. I will explain the basics you need to understand the problem, but if you are already familiar with this game, the problem is basically the following sentence.

Compute the function maxlib(n) for a natural number n, whose output is the maximum number of liberties a group can have on an n×n Go board.

maxlib(n) has an OEIS sequence (A320666). The currently known values is only up to n=24.

n maxlib(n)
1 0
2 2
3 6
4 9
5 14
6 22
7 29
8 38
9 51
10 61
11 74
12 92
13 105
14 122
15 145
16 161
17 182
18 210
19 229
20 254
21 287
22 309
23 338
24 376
Go is a board game played on an n×n square grid, with two players, black and white, placing a stone alternately on an empty intersection of the grid. In this challenge we will only consider the black stones (X).

On this 4×4 board, black has 3 groups.

X X . .
X . X .
X X . X
. . X X
A group is a group of stones that are connected horizontally or vertically.

Let's denote each group with different alphabets.

A A . .
A . B .
A A . C
. . C C
Group A has 5
 liberties. Group B has 4
 liberties, and group C has 3
 liberties. Liberty is the number of empty spaces connected horizontally or vertically to a group.

. . .
. X .
. . .

. . .
X X .
. . .

. . .
X X X
. . .
There are three 3×3 boards each with a single black group. Counting the liberties, it is 4, 5, and 6, respectively.
In fact, on a 3×3 board with nothing else than 1 black group, 6 is the maximum number of liberties that group can have.

Challenge
Compute the function maxlib(n) for a natural number n, whose output is the maximum number of liberties a group can have on an n×n Go board.

Example Output up to n=6
X
1 -> 0

X .
. .
2 -> 2

. . .
X X X
. . .
3 -> 6

. . X .
. . X .
X X X .
. . . .
4 -> 9

. . . . .
. X X X X
. X . . .
. X X X .
. . . . .
5 -> 14

. X . . X .
. X . . X .
. X . . X .
. X . . X .
. X X X X .
. . . . . .
6 -> 22
You don't have to print the board positions.

Scoring
I will run your program for 30 minutes on my computer, not exclusively on a single core. The maximum n you can reach within this time is your score, starting from n=1 incrementing by 1.
Your program must reach at least n=6, and I will not run your program if this seems unlikely.

The maximum score you can get is 10000.

The OS is Linux, and here is my CPU information.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A320666
int
maxlib(int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 2;
	if (n == 3)
		return 6;
	if ((n % 3) == 0)
		return (2 * n - 1) * (n / 3);
	if ((n % 3) == 2)
		return (2 * n - 1) * (n / 3) + n;
	return (2 * n) * (n / 3) + 1;
}

int
main(void)
{
	static const int tab[] = {0, 2, 6, 9, 14, 22, 29, 38, 51, 61, 74, 92, 105, 122, 145, 161, 182, 210, 229, 254, 287, 309, 338, 376};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(maxlib(i + 1) == tab[i]);

	return 0;
}
