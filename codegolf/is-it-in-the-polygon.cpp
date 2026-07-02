/*

The challenge
Given point and a path of points, say whether or not the point is in the polygon that is created by the path.

Also return true if the point is on an edge of the polygon.

Input
A list of pairs of integers.

The first 2 integers represent the point.

The remaining pairs (3rd and 4th, 5th and 6th etc.) represent the vertices of the polygon.

The edges are in the order of the input pairs.

The path is assumed to loop back to the first point of the path.

The input is assumed to be valid.

No three points in the path are collinear.

ex. 123 82 84 01 83 42

Output
A truthy/falsy value.

Test cases
Input -> Output

0 0 10 10 10 -1 -5 0 -> true

5 5 10 10 10 50 50 20 -> false

5 5 0 0 0 10 1 20 6 30 10 -40 -> true

This is code-golf. Shortest answer in bytes wins.

*/

#include <cassert>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool point_in_polygon(const Point2f point, const vector<Point2f> &polygon)
{
	return pointPolygonTest(polygon, point, false) >= 0;
}

int main()
{
	assert(point_in_polygon({0, 0}, {{10, 10}, {10, -1}, {-5, 0}}) == true);
	assert(point_in_polygon({5, 5}, {{10, 10}, {10, 50}, {50, 20}}) == false);
	assert(point_in_polygon({5, 5}, {{0, 0}, {0, 10}, {1, 20}, {6, 30}, {10, -40}}) == true);
	assert(point_in_polygon({150, 85}, {{186, 14}, {186, 44}, {175, 115}, {175, 85}}) == false);
	assert(point_in_polygon({3, 3}, {{0, 0}, {4, 0}, {4, 4}, {0, 4}}) == true);
	
	return 0;
}
