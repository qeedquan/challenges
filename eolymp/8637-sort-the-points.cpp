/*

Given the coordinates of n points on a plane, output them in increasing order of the sum of their coordinates.
If two points have the same sum of coordinates, sort them in increasing order of the abscissa (the x-coordinate).

Input
Each line contains a pair of integers x,y (0≤x,y≤10^9) — the coordinates of a point.
The number of points does not exceed 10^5.

Output
Output the coordinates of the points in ascending order of the sum of their coordinates. Print the coordinates of each point on a separate line.

Examples
Input #1
3 4
1 2
5 1
3 3
2 1

Answer #1
1 2
2 1
3 3
5 1
3 4

Input #2
5 5
2 2
3 4
3 1
6 3
2 7
0 4

Answer #2
0 4
2 2
3 1
3 4
2 7
6 3
5 5

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
	if (a.x + a.y != b.x + b.y)
		return a.x + a.y < b.x + b.y;
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
		{ 2, 1 },
	});

	solve({
		{ 5, 5 },
		{ 2, 2 },
		{ 3, 4 },
		{ 3, 1 },
		{ 6, 3 },
		{ 2, 7 },
		{ 0, 4 },
	});

	return 0;
}
