/*

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int erase_overlaps(vector<vector<int> > &&intervals)
{
	if (intervals.empty())
		return 0;

	sort(begin(intervals), end(intervals),
		 [](const auto &a, const auto &b) {
			 return a[1] < b[1];
		 });

	auto total = 0;
	auto end = intervals[0][1];
	for (size_t i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] >= end)
			end = intervals[i][1];
		else
			total++;
	}

	return total;
}

int main()
{
	assert(erase_overlaps({ { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } }) == 1);
	assert(erase_overlaps({ { 1, 2 }, { 1, 2 }, { 1, 2 } }) == 2);
	assert(erase_overlaps({ { 1, 2 }, { 2, 3 } }) == 0);

	return 0;
}
