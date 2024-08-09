/*

Credit goes where credit is due:
https://chat.stackexchange.com/transcript/message/29818745#29818745

Given two digits, x, and y, calculate the shortest number of horizontal or vertical jumps to get from x to y on a standard numpad, e.g.

789
456
123
00
You can safely assume that all inputs will be 0-9, and you do not have to handle invalid inputs. The input may be the same number twice, which has a distance of 0.

IO can be in any reasonable format, and standard loopholes are forbidden. Shortest answer in bytes wins!

Sample IO:
1, 4: 1
1, 8: 3
3, 7: 4
8, 2: 2
6, 1: 3
0, 9: 4
4, 4: 0
0, 4: 2

*/

#include <assert.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Point;

int
min(int a, int b)
{
	return (a < b) ? a : b;
}

int
manhattan(Point p, Point q)
{
	return abs(p.x - q.x) + abs(p.y - q.y);
}

int
jumps(int x, int y)
{
	static const Point numpad[11] = {
	    {0, 0},
	    {0, 1},
	    {1, 1},
	    {2, 1},
	    {0, 2},
	    {1, 2},
	    {2, 2},
	    {0, 3},
	    {1, 3},
	    {2, 3},
	    {1, 0},
	};

	int d;

	if (x < 0 || x > 9 || y < 0 || y > 9)
		return -1;

	d = manhattan(numpad[x], numpad[y]);
	if (x == 0)
		d = min(d, manhattan(numpad[10], numpad[y]));
	if (y == 0)
		d = min(d, manhattan(numpad[x], numpad[10]));
	return d;
}

int
main(void)
{
	assert(jumps(1, 4) == 1);
	assert(jumps(1, 8) == 3);
	assert(jumps(3, 7) == 4);
	assert(jumps(8, 2) == 2);
	assert(jumps(6, 1) == 3);
	assert(jumps(0, 9) == 4);
	assert(jumps(4, 4) == 0);
	assert(jumps(0, 4) == 2);
	assert(jumps(0, 0) == 0);

	return 0;
}
