/*

(Taken from https://en.wikipedia.org/wiki/File:Tangential_quadrilateral.svg) Tangential quadrilateral

A tangential quadrilateral (see example above) is a quadrilateral in which a circle can be inscribed.

Your task is to find the possible value of d given a, b, and c.

Specs
a, b, c will all be positive integers.
If no possible value of d exists, output 0.

Scoring
This is code-golf. Shortest solution in bytes wins.

Testcases
a b c d
3 4 4 3
1 2 3 2
1 5 3 0

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://en.wikipedia.org/wiki/Pitot_theorem
// The Pitot theorem in geometry states that in a tangential quadrilateral the two pairs of opposite sides have the same total length
int
pitot(int a, int b, int c)
{
	return max(a + c - b, 0);
}

int
main(void)
{
	assert(pitot(3, 4, 4) == 3);
	assert(pitot(1, 2, 3) == 2);
	assert(pitot(1, 5, 3) == 0);

	return 0;
}
