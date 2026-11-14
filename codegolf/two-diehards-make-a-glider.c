/*

In Conway's Game of Life, there is an infinite square grid of cells, each of which is alive or dead. The pattern changes each "generation". A dead cell with exactly 3 live neighbors (orthogonal or diagonal) becomes a live cell. A live cell only lives to the next generation if it has 2 or 3 live neighbors. These simple rules lead to very complex behaviors. The most well-known pattern is the glider, a pattern that moves diagonally one cell every 4 generations and looks like this:

https://upload.wikimedia.org/wikipedia/commons/9/96/Animated_glider_emblem.gif

The Challenge
Your task is to create two patterns which will eventually result in an empty board when by themselves (a.k.a. a diehard), but when combined in a certain non-bordering and non-overlapping arrangement, eventually spawn a single glider and nothing else.

Rules and Scoring
Each of the lone diehards must fit all live cells within a 100x100 cell box and may not contain more than 100 live cells.
The combination glider synthesizer must contain both diehards such that their bounding boxes surrounding all live cells are separated by at least one dead cell.
It does not matter which direction the single glider is facing
Your score is the sum of the number of generations it takes to reach an empty board from the initial states for the diehards, plus the number of generations it takes to reach a state where there is exactly one glider and nothing else (i.e. there are exactly 5 live cells on the board in a glider pattern) for the combined glider synthesizer. Highest score wins.

*/

#include <stdio.h>

/*

Ported from @user1502040 solution

Pattern 1 is a self-destructing glider + loaf combination where the glider and loaf are spaced as far apart as possible.

Pattern 2 is the result of searching for random disappearing patterns which can be placed next to pattern 1 to destroy the loaf, giving a valid solution to the puzzle. I generated a large number and took the one with the best score.

I'm sure its possible to do better by adding an independent diehard to the far corner of pattern 2 (or even pattern 1), but I'm done for now

*/

void
pat1()
{
	int x, y;

	x = 100, y = 94;
	printf("%d %d\n", x, y);
	puts("97b2o$96bo2bo$97bobo$98bo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$3o$2bo$bo!");
}

void
pat2()
{
	int x, y;

	x = 11, y = 2;
	printf("%d %d\n", x, y);
	puts("o5b2obo$3bo$2b2o2bo2b2o!");
}

void
pat1p2()
{
	int x, y;

	x = 112, y = 94;
	printf("%d %d\n", x, y);
	puts("97b2o$96bo2bo$97bobo$98bo2bo5b2obo$104bo$103b2o2bo2b2o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$3o$2bo$bo!");
}

int
main()
{
	pat1();
	pat2();
	pat1p2();
	return 0;
}
