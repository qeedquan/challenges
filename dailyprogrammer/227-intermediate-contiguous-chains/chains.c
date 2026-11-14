/*

Description:
If something is contiguous, it means it is connected or unbroken. For a chain, this would mean that all parts of the chain are reachable without leaving the chain. So, in this little piece of ASCII-art:

xxxxxxxx
x      x
there is only 1 contiguous chain, while in this

xxxx xxxx

x
there are 3 contiguous chains. Note that a single x, unconnected to any other, counts as one chain.

For the purposes of this problems, chains can only be contiguous if they connect horizontally of vertically, not diagonally. So this image

xx
  xx
    xx
contains three chains.

Your challenge today is to write a program that calculates the number of contiguous chains in a given input.

Formal inputs & outputs
Input:
The first line in the input will consist of two numbers separated by a space, giving the dimensions of the ASCII-field you're supposed to read. The first number gives the number of lines to read, the second the number of columns (all lines have the same number of columns).

After that follows the field itself, consisting of only x's and spaces.

Output:
Output a single number giving the number of contiguous chains.

Sample inputs & outputs
Input 1
2 8
xxxxxxxx
x      x
Output 1
1
Input 2
3 9
xxxx xxxx
    x
   xx
Output 2
3
Challenge inputs:
Input 1
4 9
xxxx xxxx
   xxx
x   x   x
xxxxxxxxx
Input 2
8 11
xx x xx x
x  x xx x
xx   xx  x
xxxxxxxxx x
         xx
xxxxxxxxxxx
 x x x x x
  x x x x
Bonus
u/Cephian was nice enough to generete a much larger 1000x1000 input which you are welcome to use if you want a little tougher performance test.

Notes
Many thanks to u/vgbm for suggesting this problem at r/dailyprogrammer_ideas! For his great contribution, u/vgbm has been awarded with a gold medal. Do you want to be as cool as u/vgbm (as if that were possible!)? Go on over to r/dailyprogrammer_ideas and suggest a problem. If it's good problem, we'll use it.

As a final note, I would just like to observe that "contiguous" is a very interesting word to spell (saying it is no picnic either...)

*/

#include <stdio.h>
#include <stdlib.h>

// Ported from @skeeto solution
typedef struct Set Set;
typedef struct State State;

struct Set {
	Set *parent;
	unsigned mark;
};

struct State {
	unsigned x;
	unsigned y;
	unsigned width;
	unsigned count;
	Set lines[][2];
};

void *
xmalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		abort();
	return ptr;
}

Set *
set_find(Set *s)
{
	while (s->parent != s)
		s = s->parent;
	return s;
}

void
set_merge(Set *a, Set *b)
{
	set_find(b)->parent = set_find(a);
}

State *
state_create(unsigned width)
{
	State *s;

	s = xmalloc(sizeof(*s) + sizeof(s->lines[0][0]) * width * 2);
	s->x = 0;
	s->y = 0;
	s->width = width;
	s->count = 0;
	for (unsigned x = 0; x < width; x++)
		s->lines[x][0].mark = s->lines[x][1].mark = 2;
	return s;
}

void
state_advance(State *state)
{
	unsigned x, y, y0, y1;
	Set *s;

	y = state->y++;
	y0 = (y + 0) % 2;
	y1 = (y + 1) % 2;
	for (x = 0; x < state->width; x++) {
		s = &state->lines[x][y0];
		if (s->mark != 2 && set_find(s)->mark == y0) {
			set_find(s)->mark = y1;
			state->count++;
		}
		s->mark = 2;
	}
	state->x = 0;
}

void
state_feed(State *state, int c)
{
	Set *cur, *up, *left;
	unsigned x, y0, y1;

	x = state->x++;
	y0 = (state->y + 0) % 2;
	y1 = (state->y + 1) % 2;
	if (c == 'x') {
		cur = &state->lines[x][y1];
		cur->mark = y1;
		cur->parent = cur;
		up = &state->lines[x][y0];
		left = (x > 0) ? &state->lines[x - 1][y1] : &(Set){ NULL, 2 };
		if (up->mark != 2)
			set_merge(cur, up);
		if (left->mark != 2)
			set_merge(cur, left);
	} else if (c == '\n') {
		state_advance(state);
	}
}

int
main(void)
{
	State *state;
	unsigned width;
	int c;

	scanf("%*u %u", &width);
	while (getchar() != '\n')
		;
	state = state_create(width);

	while ((c = getchar()) != EOF)
		state_feed(state, c);
	state_advance(state);

	printf("%d\n", state->count);
	free(state);

	return 0;
}
