/*

Input
Two integers:

A non-negative integer W in the range 0 to 2^64-1, specifying the weave.
A positive integer S in the range 1 to 255, specifying the side length.
These can be taken in whichever order suits you.

Output
An S by S ASCII representation of the requested weave (S newline separated strings of S characters with an optional trailing newline). The weave is defined by the weave number W as follows:

Convert W to binary and split into 8 bytes. The first (most significant) byte defines the top row, from left (most significant bit) to right. The next byte defines the next row, and so on for 8 rows. The weave number defines an 8 by 8 square which should be tiled over the required area starting from the top left. That is, its top left corner should correspond to the top left corner of the area to be covered.

Every 0 should be displayed as a | and every 1 should be displayed as a -

Examples
Input: 0 8

Ouput:

||||||||
||||||||
||||||||
||||||||
||||||||
||||||||
||||||||
||||||||
Input: 3703872701923249305 8

Output:

||--||--
|--||--|
--||--||
-||--||-
||--||--
|--||--|
--||--||
-||--||-
Input: 3732582711467756595 10

Output:

||--||--||
--||--||--
--||--||--
||--||--||
||--||--||
--||--||--
--||--||--
||--||--||
||--||--||
--||--||--
Input: 16141147355100479488 3

Output:

---
|||
---

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
weave(uvlong w, uvlong s)
{
	uvlong b, x, y;

	printf("w=%llu s=%llu\n", w, s);
	for (y = 0; y < s; y++) {
		for (x = 0; x < s; x++) {
			b = 63 - (((y & 7) << 3) + (x & 7));
			if (w & (1ULL << b))
				printf("-");
			else
				printf("|");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	weave(0, 8);
	weave(3703872701923249305ULL, 8);
	weave(3732582711467756595ULL, 10);
	weave(16141147355100479488ULL, 3);

	return 0;
}
