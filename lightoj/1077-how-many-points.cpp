/*

Given two points A and B on the X-Y plane, output the number of the lattice points on the segment AB.

Note that A and B are also lattice points. Those who are confused with the definition of lattice points, lattice points are those points which have both x and y integer co-ordinates.

For example, for A (3, 3) and B (-1, -1) the output is 5. The points are: (-1, -1), (0, 0), (1, 1), (2, 2) and (3, 3).

Input
Input starts with an integer T (≤ 125), denoting the number of test cases.

Each case contains four integers, Ax, Ay, Bx and By. Each of them will fit into a 32 bit signed integers.

Output
For each test case, print the case number and the number of lattice points between AB.

Sample
Input	Output
2
3 3 -1 -1
0 0 5 2

Case 1: 5
Case 2: 2

*/

#include <cassert>
#include <cstdlib>
#include <numeric>

using namespace std;

struct Point {
	int x, y;
};

// https://math.stackexchange.com/questions/628117/how-to-count-lattice-points-on-a-line
int solve(Point a, Point b)
{
	return gcd(abs(a.x - b.x), abs(a.y - b.y)) + 1;
}

int main()
{
	assert(solve({ 3, 3 }, { -1, -1 }) == 5);
	assert(solve({ 0, 0 }, { 5, 2 }) == 2);

	return 0;
}
