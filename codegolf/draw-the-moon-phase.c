/*

Challenge
Given the phase of the moon, draw it using ASCII art.

Your program must handle new moon, waxing crescent, first quarter, waxing gibbous, full moon, waning gibbous, last quarter, and waning crescent. Your input will be an integer.

0 -> new moon
1 -> waxing crescent
2 -> first quarter
3 -> waxing gibbous
4 -> full moon
5 -> waning gibbous
6 -> last quarter
7 -> waning crescent
The ASCII art is all placed on a 16x8 grid (because character dimension ratios). You can replace . with any character and # with any other non-whitespace character.

The output for new moon should be:

................
................
................
................
................
................
................
................
For waxing crescent:

..........######
............####
.............###
.............###
.............###
.............###
............####
..........######
For first quarter:

........########
........########
........########
........########
........########
........########
........########
........########
For waxing gibbous:

......##########
....############
...#############
...#############
...#############
...#############
....############
......##########
And for full moon:

################
################
################
################
################
################
################
################
The waning crescent is just the waxing crescent with each line reversed, as with the waning gibbous and the waxing gibbous, and the first and last quarter.

Rules
Standard Loopholes Apply
You may choose to output waxing/waning in the opposite direction if you want, though it should make no difference (the graphics shown in this question are for the northern hemisphere)
Your output must be exactly as specified. Your newlines can be any reasonable line separator, and you may have a trailing newline if you would like.

*/

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
clear(void)
{
	printf("\033c");
}

void
moonphase(unsigned n)
{
	static const uint64_t phases[][2] = {
	    {0x0000000000000000, 0x0000000000000000},
	    {0xE000E000F000FC00, 0xFC00F000E000E000},
	    {0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00},
	    {0xFFF8FFF8FFF0FFC0, 0xFFC0FFF0FFF8FFF8},
	    {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF},
	    {~0xE000E000F000FC00, ~0xFC00F000E000E000},
	    {~0xFF00FF00FF00FF00, ~0xFF00FF00FF00FF00},
	    {~0xFFF8FFF8FFF0FFC0, ~0xFFC0FFF0FFF8FFF8},
	};

	uint64_t b, p, i;
	uint64_t x, y;

	if (n >= nelem(phases))
		return;

	printf("phase=%u\n", n);
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 16; x++) {
			i = (y * 16) + x;
			p = i / 64;
			b = i & 63;
			if (phases[n][p] & (UINT64_C(1) << b))
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	struct timespec tp = {
	    .tv_sec = 1,
	};
	unsigned i;

	i = 0;
	for (;;) {
		clear();
		moonphase(i);
		i = (i + 1) & 7;
		thrd_sleep(&tp, NULL);
	}

	return 0;
}
