/*

Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.

The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).

Example 1:

Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Example 2:

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: false

Example 3:

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: true

Constraints:

    1 <= sx, sy, tx, ty <= 10^9

*/

#include <assert.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

bool
reach(int sx, int sy, int tx, int ty)
{
	while (tx >= sx && ty >= sy) {
		if (tx < ty) {
			swap(&sx, &sy);
			swap(&tx, &ty);
		}
		if (ty > sy)
			tx %= ty;
		else
			return (tx - sx) % ty == 0;
	}
	return false;
}

int
main()
{
	assert(reach(1, 1, 3, 5) == true);
	assert(reach(1, 1, 2, 2) == false);
	assert(reach(1, 1, 1, 1) == true);

	return 0;
}
