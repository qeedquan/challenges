/*

Given n points (1 dimensional) and q segments, you have to find the number of points that lie in each of the segments. A point pi will lie in a segment A B if A ≤ pi ≤ B.

For example if the points are 1, 4, 6, 8, 10. And the segment is 0 to 5. Then there are 2 points that lie in the segment.

Input
Input starts with an integer T (≤ 5), denoting the number of test cases.

Each case starts with a line containing two integers n (1 ≤ n ≤ 10^5) and q (1 ≤ q ≤ 50000). The next line contains n space separated integers denoting the points in ascending order. All the integers are distinct and each of them range in [0, 108].

Each of the next q lines contains two integers Ak Bk (0 ≤ Ak ≤ Bk ≤ 10^8) denoting a segment.

Output
For each case, print the case number in a single line. Then for each segment, print the number of points that lie in that segment.

Sample
Input	Output
1
5 3
1 4 6 8 10
0 5
6 10
7 100000

Case 1:
2
3
2

Notes
Dataset is huge, use faster I/O methods.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

size_t solve(const vector<int> &points, size_t left, size_t right)
{
	auto upper = upper_bound(points.begin(), points.end(), right);
	auto lower = lower_bound(points.begin(), points.end(), left);
	return upper - lower;
}

int main()
{
	assert(solve({ 1, 4, 6, 8, 10 }, 0, 5) == 2);
	assert(solve({ 1, 4, 6, 8, 10 }, 6, 10) == 3);
	assert(solve({ 1, 4, 6, 8, 10 }, 7, 100000) == 2);

	return 0;
}
