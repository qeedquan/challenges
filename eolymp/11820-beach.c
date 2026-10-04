/*

Kostya laid out a blanket on the beach with a length of A units to relax comfortably under the sun.
To create shade, he brought two large umbrellas.
Each umbrella provides a shadow of length B units.

The umbrellas can be positioned in any way — adjacent, overlapping, or even such that part of the shadow extends beyond the edges of the blanket.
Kostya wants to position them so that the least possible part of the blanket remains under the open sun.

Determine the minimum length of the blanket that will remain uncovered by shadow.

Input
The first line contains two integers A and B (1≤A,B≤100) — the length of the blanket and the length of the shadow from one umbrella.

Output
Output one number — the minimum length of the blanket that will remain open after the best placement of the umbrellas.

Examples

Input #0
12 4

Answer #0
4

Input #1
20 15

Answer #1
0

Input #2
20 30

Answer #2
0

Note
Explanation for example 1:

We have a blanket with a length of 12 and two umbrellas, each providing a shadow of length 4.
For example, one umbrella can be placed on the left edge of the blanket, the other on the right.
A total of 8 units will be covered by shade, leaving 4 units in the sun. The answer is 4.

Explanation for example 2:

The combined shadow length from the two umbrellas is sufficient to completely cover the blanket. No part of it remains in the sun, so the answer is 0.

Explanation for example 3:

Each umbrella provides a shadow greater than the entire blanket.
Only one umbrella can be used to cover the whole surface.
In this case, the blanket will be completely in the shade — the answer is 0.

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve(int a, int b)
{
	return max(a - (2 * b), 0);
}

int
main()
{
	assert(solve(12, 4) == 4);
	assert(solve(20, 15) == 0);
	assert(solve(20, 30) == 0);

	return 0;
}
