/*

The coordinates of n points are given on a plane.
Print them in increasing order of their abscissa.
In the case of a tie, sort the points in decreasing order of ordinate.

Input
Each line contains the pair of numbers x,y (0≤x,y≤10^9) — the coordinates of one point.

Output
Print the points in the required order. Print the coordinates of each point on a separate line.

Examples
Input #1
3 4
1 2
5 1
3 3
3 1

Answer #1
1 2
3 4
3 3
3 1
5 1

*/

#include <print>
#include <vector>

using namespace std;

struct Point
{
	int x, y;
};

bool sort_points(const Point &a, const Point &b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

void solve(vector<Point> &&points)
{
	sort(points.begin(), points.end(), sort_points);
	for (auto &point : points)
		println("{} {}", point.x, point.y);
	println();
}

int main()
{
	solve({
		{ 3, 4 },
		{ 1, 2 },
		{ 5, 1 },
		{ 3, 3 },
		{ 3, 1 },
	});

	return 0;
}
