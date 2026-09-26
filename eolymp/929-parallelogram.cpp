/*

Given four real numbers a, b, c, d, representing the lengths of segments.
Determine whether it is possible to form a parallelogram from these segments.

Input
A single line contains four numbers a, b, c, d separated by spaces.

Output
Print YES if it is possible to form a parallelogram, or NO otherwise.

Examples
Input #1
2 4 2 4

Answer #1
YES

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solve(int a, int b, int c, int d)
{
	vector<int> p = { a, b, c, d };
	sort(p.begin(), p.end());
	if (p[0] > 0 && p[1] > 0 && p[2] > 0 && p[3] > 0 && p[0] == p[1] && p[2] == p[3])
		return "YES";
	return "NO";
}

int main()
{
	assert(solve(2, 4, 2, 4) == "YES");

	return 0;
}
