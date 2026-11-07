/*

There is alarm at Summer Computer School!
The minimum is lost.
Your task is to find it.

Input
The first line contains an integer n (1≤n≤1000).
The second line contains n integers, each does not exceed 10^5 in absolute value.

Output
Print the smallest of the given n integers.

Examples

Input #1
1
2

Answer #1
2

Input #2
4
5 8 -4 6

Answer #2
-4

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int solve(const vector<int> &numbers)
{
	if (numbers.empty())
		return 0;
	return *min_element(numbers.begin(), numbers.end());
}

int main()
{
	assert(solve({ 2 }) == 2);
	assert(solve({ 5, 8, -4, 6 }) == -4);
	return 0;
}
