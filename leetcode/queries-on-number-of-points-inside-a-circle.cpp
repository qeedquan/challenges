/*

You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

Return an array answer, where answer[j] is the answer to the jth query.

Example 1:

Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.

Example 2:

Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
Explanation: The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.

Constraints:

1 <= points.length <= 500
points[i].length == 2
0 <= x[i], y[i] <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= x[j], y[j] <= 500
1 <= r[j] <= 500
All coordinates are integers.

Follow up: Could you find the answer for each query in better complexity than O(n)?

Hint 1
For a point to be inside a circle, the euclidean distance between it and the circle's center needs to be less than or equal to the radius.

Hint 2
Brute force for each circle and iterate overall points and find those inside it.

*/

#include <cassert>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool in_circle(const vector<int> &point, const vector<int> &circle)
{
	auto dx = abs(point[0] - circle[0]);
	auto dy = abs(point[1] - circle[1]);
	auto r = circle[2];
	if (dx > r || dy > r)
		return false;
	if (dx + dy <= r)
		return true;
	return (dx * dx) + (dy * dy) <= (r * r);
}

vector<int> count_points(const vector<vector<int> > &points, const vector<vector<int> > &queries)
{
	vector<int> result;
	for (auto &query : queries)
	{
		auto count = 0;
		for (auto &point : points)
		{
			if (in_circle(point, query))
				count += 1;
		}
		result.push_back(count);
	}
	return result;
}

void test(const vector<vector<int> > &points, const vector<vector<int> > &queries)
{
	auto result = count_points(points, queries);
	for (auto value : result)
		cout << value << " ";
	cout << endl;
}

int main()
{
	vector<vector<int> > points_1 = { { 1, 3 }, { 3, 3 }, { 5, 3 }, { 2, 2 } };
	vector<vector<int> > points_2 = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 } };

	vector<vector<int> > queries_1 = { { 2, 3, 1 }, { 4, 3, 1 }, { 1, 1, 2 } };
	vector<vector<int> > queries_2 = { { 1, 2, 2 }, { 2, 2, 2 }, { 4, 3, 2 }, { 4, 3, 3 } };

	test(points_1, queries_1);
	test(points_2, queries_2);

	return 0;
}
