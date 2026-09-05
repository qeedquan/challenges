/*

If you've done any work or research onto cellular automata, you may have heard of Langton's Ant. It starts with a grid similar to that of Conway's Game of Life where a grid cell can be black or white, however this time we have an 'ant' on it. This little metaphorical ant will follow these four rules at every 'step':

If the current square is white, turn the ant 90' clockwise

If the current square is black, turn the ant 90' anticlockwise

Flip the colour of the current square

Move forward (from the ant's perspective) one cell

With the following starting conditions:

All cells start white

The ant starts pointing north

However, being r/DailyProgrammer, we don't do things the easy way. Why only have 2 colours, black or white? Why not as many colours as you want, where you choose whether ant turns left or right at each colour? Today's challenge is to create an emulator for such a modifiable ant.

If you have more than 2 colours, of course, there is no way to just 'flip' the colour. Whenever the ant lands on a square, it is to change the colour of the current square to the next possible colour, going back to the first one at the end - eg. red, green, blue, red, green, blue, etc. In these cases, at the start of the simulation, all of the cells will start with the first colour/character.

Input Description
You will be given one line of text consisting of the characters 'L' and 'R', such as:

LRLRR
This means that there are 5 possible colours (or characters, if you're drawing the grid ASCII style - choose the colours or characters yourself!) for this ant.

In this case, I could choose 5 colours to correspond to the LRLRR:

White, turn left (anticlockwise)

Black, turn right (clockwise)

Red, turn left (anticlockwise)

Green, turn right (clockwise)

Blue, turn right (clockwise)

You could also choose characters, eg. ' ', '#', '%', '*', '@' instead of colours if you're ASCII-ing the grid. You will then be given another line of text with a number N on it - this is the number of 'steps' to simulate.

Output Description
You have some flexibility here. The bare minimum would be to output the current grid ASCII style. You could also draw the grid to an image file, in which case you would have to choose colours rather than ASCII characters. I know there are some people who do these sorts of challenges with C/C++ curses or even more complex systems.

Notes
More info on Langton's Ant with multiple colours.
https://en.wikipedia.org/wiki/Langton%27s_ant#Extension_to_multiple_colors

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ported from @skeeto solution

typedef unsigned char uchar;
typedef unsigned long long uvlong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const uchar COLORS[][3] = {
	{ 0, 0, 0 },
	{ 255, 255, 255 },
	{ 0, 0, 255 },
	{ 0, 127, 0 },
	{ 255, 0, 0 },
	{ 0, 191, 191 },
	{ 191, 0, 191 },
	{ 191, 191, 0 },
	{ 63, 63, 63 }
};

const struct direction {
	int x, y;
} DIRECTIONS[] = {
	{ 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 }
};

typedef struct Cell Cell;
typedef struct Langton Langton;

struct Cell {
	const uchar *rgb;
	int delta;
	Cell *next;
};

struct Langton {
	Cell **cells;
	int size;
	int antx;
	int anty;
	int antd;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

void
langton_init(Langton *state, Cell *init, int size)
{
	int i;

	state->size = size;
	state->cells = xcalloc(size, size * sizeof(*state->cells));
	for (i = 0; i < state->size * state->size; i++)
		state->cells[i] = init;
	state->antx = state->anty = state->size / 2;
	state->antd = 0;
}

void
langton_step(Langton *state)
{
	struct direction direction;
	int i;

	i = state->anty * state->size + state->antx;
	state->antd = (state->antd + state->cells[i]->delta + 4) % 4;
	direction = DIRECTIONS[state->antd];
	state->antx = (state->antx + direction.x + state->size) % state->size;
	state->anty = (state->anty + direction.y + state->size) % state->size;
	state->cells[i] = state->cells[i]->next;
}

void
langton_print(Langton *state)
{
	int i;

	printf("P6\n%d %d\n255\n", state->size, state->size);
	for (i = 0; i < state->size * state->size; i++) {
		putchar(state->cells[i]->rgb[0]);
		putchar(state->cells[i]->rgb[1]);
		putchar(state->cells[i]->rgb[2]);
	}
}

Cell *
parse_rules(FILE *fp, uvlong *steps)
{
	Cell *head;
	Cell *curr;
	Cell *prev;
	uvlong i;
	int c;

	prev = NULL;
	curr = xcalloc(1, sizeof(*curr));
	head = curr;

	head->rgb = COLORS[0];
	head->delta = 1;

	i = 0;
	for (;;) {
		c = fgetc(fp);
		if (c == EOF || isspace(c))
			break;

		curr->rgb = COLORS[i];
		curr->delta = (c == 'L') ? -1 : 1;
		curr->next = xcalloc(1, sizeof(*curr->next));
		prev = curr;
		curr = curr->next;
		i = (i + 1) % nelem(COLORS);
	}
	if (prev) {
		free(prev->next);
		prev->next = head;
	}

	if (fscanf(fp, "%llu", steps) != 1)
		*steps = 0;

	return head;
}

int
main(int argc, char *argv[])
{
	Langton langton;
	Cell *colors;
	uvlong steps;
	int size;

	size = 1024;
	if (argc >= 2)
		size = atoi(argv[1]);
	if (size < 1 || size >= 32767) {
		printf("invalid size\n");
		return 1;
	}

	colors = parse_rules(stdin, &steps);
	langton_init(&langton, colors, size);
	for (; steps > 0; steps--)
		langton_step(&langton);
	langton_print(&langton);

	return 0;
}
