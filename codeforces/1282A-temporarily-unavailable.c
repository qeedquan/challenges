/*

Polycarp lives on the coordinate axis Ox and travels from the point x=a to x=b. It moves uniformly rectilinearly at a speed of one unit of distance per minute.

On the axis Ox at the point x=c the base station of the mobile operator is placed. It is known that the radius of its coverage is r. Thus, if Polycarp is at a distance less than or equal to r from the point x=c, then he is in the network coverage area, otherwise — no. The base station can be located both on the route of Polycarp and outside it.

Print the time in minutes during which Polycarp will not be in the coverage area of the network, with a rectilinear uniform movement from x=a to x=b. His speed — one unit of distance per minute.

Input
The first line contains a positive integer t (1≤t≤1000) — the number of test cases. In the following lines are written t test cases.

The description of each test case is one line, which contains four integers a, b, c and r (−10^8≤a,b,c≤10^8, 0≤r≤10^8) — the coordinates of the starting and ending points of the path, the base station, and its coverage radius, respectively.

Any of the numbers a, b and c can be equal (either any pair or all three numbers). The base station can be located both on the route of Polycarp and outside it.

Output
Print t numbers — answers to given test cases in the order they are written in the test. Each answer is an integer — the number of minutes during which Polycarp will be unavailable during his movement.

Example

input
9
1 10 7 1
3 3 3 0
8 2 10 4
8 2 10 100
-10 20 -17 2
-3 2 2 0
-3 1 2 0
2 3 2 3
-1 3 -2 2

output
7
0
4
0
30
5
4
0
3

Note
The following picture illustrates the first test case.

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
unavailable(int a, int b, int c, int r)
{
	if (a > b)
		swap(&a, &b);
	return b - a - max(min(b, c + r) - max(a, c - r), 0);
}

int
main(void)
{
	assert(unavailable(1, 10, 7, 1) == 7);
	assert(unavailable(3, 3, 3, 0) == 0);
	assert(unavailable(8, 2, 10, 4) == 4);
	assert(unavailable(8, 2, 10, 100) == 0);
	assert(unavailable(-10, 20, -17, 2) == 30);
	assert(unavailable(-3, 2, 2, 0) == 5);
	assert(unavailable(-3, 1, 2, 0) == 4);
	assert(unavailable(2, 3, 2, 3) == 0);
	assert(unavailable(-1, 3, -2, 2) == 3);

	return 0;
}
