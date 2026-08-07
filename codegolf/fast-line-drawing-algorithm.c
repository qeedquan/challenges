/*

The task is to find a way to draw a horizontal line in an array of 16-bit integers.

We're assuming a 256x192 pixel array with 16 pixels per word. A line is a contiguous run of set (1) bits. Lines can start in the middle of any word, overlap any other words, and end in any word; they may also start and end in the same word. They may not wrap on to the next line. Hint: the middle words are easy - just write 0xffff, but the edges will be tricky, as will handling the case for the start and end in the same word. A function/procedure/routine must take an x0 and x1 coordinate indicating the horizontal start and stop points, as well as a y coordinate.

I exclude myself from this because I designed a nearly identical algorithm myself for an embedded processor but I'm curious how others would go about it. Bonus points for using relatively fast operations (for example, a 64 bit multiply or floating point operation wouldn't be fast on an embedded machine but a simple bit shift would be.)

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned short word;

/*

ported from @Keith Randall solution

This code assumes that both x0 and x1 are inclusive endpoints, and that words are little endian (i.e. the (0,0) pixel can be set with array[0][0]|=1).

*/

void
line(word *array, int x0, int x1, int y)
{
	word *start, *end;
	word *line, *p;
	word start_mask, end_mask;

	line = array + (y << 4);
	start = line + (x0 >> 4);
	end = line + (x1 >> 4);
	start_mask = 0xffff << (x0 & 15);
	end_mask = 0xffff >> (15 - (x1 & 15));

	if (start == end) {
		*start |= start_mask & end_mask;
	} else {
		*start |= start_mask;
		*end |= end_mask;
		for (p = start + 1; p < end; p++)
			*p = 0xffff;
	}
}

int
main()
{
	word array[32];
	size_t i;

	memset(array, 0, sizeof(array));
	line(array, 2, 11, 0);
	line(array, 30, 32, 0);

	for (i = 0; i < nelem(array); i++)
		printf("%#x ", array[i]);
	printf("\n");

	return 0;
}
