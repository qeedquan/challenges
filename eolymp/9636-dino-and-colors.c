/*

Dino accidentally painted a red strip of length a on the school wall with red paint.
Before the end of the break, he must hide it; otherwise, if the teacher sees it, he will be very angry.

Dino remembered that he has two cans of white paint, each enough to paint a white stripe of length b.
He wants to use these paints to completely hide the red strip by painting over it with white,
or at least paint over as much as possible, so that the length of the visible red strip is minimized.

Help Dino achieve this.

Input
Two integers a and b (1≤a,b≤10^9).

Output
Print the minimum possible length of the remaining red strip.

Examples

Input #1
10 5

Answer #1
0

Input #2
6 2

Answer #2
2

*/

#include <assert.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int
solve(int a, int b)
{
	return max(a - (2 * b), 0);
}

int
main()
{
	assert(solve(10, 5) == 0);
	assert(solve(6, 2) == 2);

	return 0;
}
