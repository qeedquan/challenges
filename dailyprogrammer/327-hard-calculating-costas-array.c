/*

Description
Costas arrays are special permutation matrices. A permutation matrix contains 0s and 1s such that each row and each column contains only a single 1. The identity matrix is a trivial example of a permutation matrix:

1 0 0
0 1 0
0 0 1
The special property of Costas arrays are that the [displacement vector](https://en.wikipedia.org/wiki/Displacement_(vector)) (distance) between any pair of ones in the matrix is not repeated for another pair of ones. This means that the identity matrix is not a valid Costas array because each closest pair of 1s is the same distance apart.

Costas arrays are named after John P. Costas, who first wrote about them in a 1965 technical report.

Costas arrays have a number of applications. This property was originally defined to make the permutation matrix an optimal scheme for setting frequencies in a multiple-tone sonar waveform because it means that unless the receiver is locked on the signal in both frequency and time, no more than one tone will be where it is expected. This property also makes Costas arrays ideal for one of the techniques in sophisticated communications and radar waveforms.

Furthermore, Costas arrays are an active area of research in computer graphics.

Costas arrays have an order N which describes the length of one of their sides; they are squares.

Today's challenge is to calculate the number of distinct Costas arrays given an order.

Input Description
You'll be given a number N, one integer per line, telling you the order of the Costas array. Example:

3
5

Output Description
Your program should emit the number of distinct Costas arrays for that order. From our example:

3 -> 4
5 -> 40

Challenge Input
6
7
13

Challenge Output
6 -> 116
7 -> 200
13 -> 12828

Orders 13-18 should test the efficiency of your solution pretty well.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// ported from @gabyjunior solution
typedef struct Cell Cell;

struct Cell {
	int x;
	Cell *last;
	Cell *next;
};

void
set_cell(Cell *cell, int x, Cell *last, Cell *next)
{
	cell->x = x;
	cell->last = last;
	cell->next = next;
}

void
unlink_cell(Cell *cell)
{
	cell->next->last = cell->last;
	cell->last->next = cell->next;
}

void
relink_cell(Cell *cell)
{
	cell->last->next = cell;
	cell->next->last = cell;
}

int
costas(int order, int x_factor, Cell *header, int *choices, int *indices, int *used, int y, int index)
{
	Cell *cell;
	int y_prev;
	int solutions;

	if (y >= order)
		return 1;

	solutions = 0;
	for (cell = header->next; cell < header; cell = cell->next) {
		for (y_prev = y - 1; y_prev >= 0; y_prev--) {
			indices[index + y_prev] = ((y - y_prev) * x_factor) + cell->x - choices[y_prev] + order - 1;
			if (used[indices[index + y_prev]])
				break;
			used[indices[index + y_prev]] = 1;
		}
		if (y_prev < 0) {
			unlink_cell(cell);
			choices[y] = cell->x;
			solutions += costas(order, x_factor, header, choices, indices, used, y + 1, index + y);
			relink_cell(cell);
		}
		for (y_prev++; y_prev < y; y_prev++)
			used[indices[index + y_prev]] = 0;
	}
	return solutions;
}

// http://oeis.org/A008404
int
gen(int order)
{
	Cell *cells;
	Cell *cell;
	Cell *cell_half;
	Cell *header;
	int *choices;
	int *indices;
	int *used;
	int x_factor;
	int x;
	int solutions;

	if (order < 1)
		return 0;

	x_factor = (order * 2) - 1;
	choices = calloc(order, sizeof(*choices));
	cells = calloc(order + 1, sizeof(*cells));
	indices = calloc(order * (order + 1) / 2, sizeof(*indices));
	used = calloc(order * x_factor, sizeof(*used));
	if (!choices || !cells || !indices || !used)
		goto error;

	header = cells + order;
	cell_half = cells + (order / 2);

	set_cell(cells, 0, header, cells + 1);
	for (cell = cells + 1, x = 1; cell < header; cell++, x++)
		set_cell(cell, x, cell - 1, cell + 1);
	set_cell(header, order, header - 1, cells);

	if (order % 2 == 0) {
		solutions = 0;
	} else {
		unlink_cell(cell_half);
		choices[0] = cell_half->x;
		solutions = costas(order, x_factor, header, choices, indices, used, 1, 1);
		relink_cell(cell_half);
	}
	for (cell = header->next; cell < cell_half; cell = cell->next) {
		unlink_cell(cell);
		choices[0] = cell->x;
		solutions += costas(order, x_factor, header, choices, indices, used, 1, 1) * 2;
		relink_cell(cell);
	}

	if (0) {
	error:
		solutions = -errno;
	}

	free(used);
	free(indices);
	free(cells);
	free(choices);
	return solutions;
}

int
main()
{
	int tab[] = { 1, 2, 4, 12, 40, 116, 200, 444, 760, 2160, 4368, 7852, 12828 };
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(gen(i + 1) == tab[i]);

	return 0;
}
