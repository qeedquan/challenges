/*

Hello people. Sorry for submitting this early, but I have exams this week and the next so I'll have to submit these challenges a little bit early - I'm sure that's not an issue though! Welcome to June, and it's time for a run of similarly themed challenges - all of them will be based on ASCII data. Not too dissimilar to this challenge from a while ago.

This first challenge is based on a game (the mathematical variety - not quite as fun!) called Conway's Game of Life. This is called a cellular automaton. This means it is based on a 'playing field' of sorts, made up of lots of little cells or spaces. For Conway's game of life, the grid is square - but other shapes like hexagonal ones could potentially exist too. Each cell can have a value - in this case, on or off - and for each 'iteration' or loop of the game, the value of each cell will change depending on the other cells around it. This might sound confusing at first, but looks easier when you break it down a bit.

A cell's "neighbours" are the 8 cells around it.

If a cell is 'off' but exactly 3 of its neighbours are on, that cell will also turn on - like reproduction.

If a cell is 'on' but less than two of its neighbours are on, it will die out - like underpopulation.

If a cell is 'on' but more than three of its neighbours are on, it will die out - like overcrowding.

Fairly simple, right? This might sound boring, but it can generate fairly complex patterns - this one, for example, is called the Gosper Glider Gun and is designed in such a way that it generates little patterns that fly away from it. There are other examples of such patterns, like ones which grow indefinitely.

Your challenge is, given an initial 'state' of 'on' and 'off' cells, and a number, simulate that many steps of the Game of Life.

Formal Inputs and Outputs
Input Description
You will be given a number N, and then two more numbers X and Y. After that you will be given a textual ASCII grid of 'on' and 'off' states that is X cells wide and Y cells tall. On the grid, a period or full-stop . will represent 'off', and a hash sign # will represent 'on'.

The grid that you are using must 'wrap around'. That means, if something goes off the bottom of the playing field, then it will wrap around to the top, like this: http://upload.wikimedia.org/wikipedia/en/d/d1/Long_gun.gif See how those cells act like the top and bottom, and the left and right of the field are joined up? In other words, the neighbours of a cell can look like this - where the lines coming out are the neighbours:

#-...-  ......  ../|\.
|\.../  ......  ......
......  |/...\  ......
......  #-...-  ......
......  |\.../  ..\|/.
|/...\  ......  ..-#-.
Output Description
Using that starting state, simulate N iterations of Conway's Game of Life. Print the final state in the same format as above - . is off and # is on.

Sample Inputs & Output
Sample Input
7 10 10
..........
..........
..#.......
...#......
.###......
..........
..........
..........
..........
..........
Sample Output
..........
..........
..........
..........
...#......
....##....
...##.....
..........
..........
..........
Challenge
Challenge Input
32 17 17
.................
.................
....###...###....
.................
..#....#.#....#..
..#....#.#....#..
..#....#.#....#..
....###...###....
.................
....###...###....
..#....#.#....#..
..#....#.#....#..
..#....#.#....#..
.................
....###...###....
.................
.................
(just for laughs, see how the output changes when you change N. Cool, eh?)

Notes
To test your program, use one of the many online simulation programs. There are plenty written in JavaScript you can get at with a Google search (or Bing, if you'd prefer. I wouldn't.)

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <ncursesw/ncurses.h>

// ported from @skeeto solution

typedef struct {
	int width;
	int height;
	char *front;
	char *back;
} GOL;

const cchar_t blocks[] = {
	{ .chars = { 0x0020 } },
	{ .chars = { 0x2584 } },
	{ .chars = { 0x2580 } },
	{ .chars = { 0x2588 } },
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

void
golinit(GOL *g)
{
	int i;

	setlocale(LC_ALL, "");
	initscr();
	curs_set(0);
	timeout(0);
	erase();
	getmaxyx(stdscr, g->height, g->width);
	g->height *= 2;
	g->front = xcalloc(g->width, g->height);
	g->back = xcalloc(g->width, g->height);
	for (i = 0; i < g->width * g->height; i++)
		g->front[i] = rand() % 2;
}

void
golfree(GOL *g)
{
	free(g->front);
	free(g->back);
	endwin();
}

int
goli(GOL *g, int x, int y)
{
	return ((y + g->height) % g->height) * g->width + ((x + g->width) % g->width);
}

void
goldraw(GOL *g)
{
	char top, bot;
	int x, y;

	for (y = 0; y < g->height; y += 2) {
		move(y / 2, 0);
		for (x = 0; x < g->width; x++) {
			top = g->front[goli(g, x, y + 0)];
			bot = g->front[goli(g, x, y + 1)];
			add_wch(blocks + (top * 2 + bot));
		}
	}
	refresh();
}

void
golstep(GOL *g)
{
	int x, y;
	int xx, yy;
	int sum;
	char self;
	char *front;
	char *back;

	for (y = 0; y < g->height; y++) {
		for (x = 0; x < g->width; x++) {
			self = g->front[goli(g, x, y)];
			sum = -self;
			for (yy = -1; yy <= 1; yy++) {
				for (xx = -1; xx <= 1; xx++) {
					sum += g->front[goli(g, x + xx, y + yy)];
				}
			}
			if (self == 0 && sum == 3) {
				self = 1;
			} else if (self == 1 && (sum < 2 || sum > 3)) {
				self = 0;
			}
			g->back[goli(g, x, y)] = self;
		}
	}

	front = g->back;
	back = g->front;
	g->front = front;
	g->back = back;
}

int
main()
{
	static const struct timespec delay = {
		.tv_nsec = 150000000,
	};

	GOL g[1];
	int c;

	srand(time(NULL));
	golinit(g);
	for (;;) {
		c = getch();
		if (c == 'q' || c == 27)
			break;

		goldraw(g);
		nanosleep(&delay, NULL);
		golstep(g);
	}
	golfree(g);

	return 0;
}
