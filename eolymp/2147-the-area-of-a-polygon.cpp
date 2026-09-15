/*

Determine the area of the given polygon.

Input
The first line contains one integer N (3≤N≤100000).
Each of the next N lines contains a pair of integers, which are the coordinates of each vertex of a simple polygon given in either clockwise or counterclockwise order.
All coordinates are integers with absolute values not exceeding 10000.

Output
Output a single number: the area of the given polygon, accurate to 1 decimal place.

Examples

Input #1
3
1 0
0 1
1 1

Answer #1
0.5

*/

#include <cassert>
#include <vector>

using namespace std;

struct Point
{
	double x, y;
};

double solve(const vector<Point> &vertices)
{
	auto length = vertices.size();
	if (length < 3)
		return 0;

	auto value = 0.0;
	for (auto i = 0u; i < length - 1; i++)
		value += (vertices[i + 1].x + vertices[i].x) * (vertices[i].y - vertices[i + 1].y);

	value += (vertices[0].x + vertices[length - 1].x) * (vertices[length - 1].y - vertices[0].y);

	return value * 0.5;
}

int main()
{
	assert(solve({ { 1, 0 }, { 0, 1 }, { 1, 1 } }) == 0.5);

	return 0;
}
