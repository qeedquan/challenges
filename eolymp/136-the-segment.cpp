/*

https://static.e-olymp.com/content/4b/4bde6fe5e3c76d5cbc101c3dc47c3c1d8815682b.gif

Given a segment whose endpoints have integer coordinates, determine how many points with integer coordinates lie on this segment, including its endpoints.

Input
Four integers x1, y1, x2, y2 — the coordinates of the segment's endpoints. All coordinates satisfy ∣x1∣,∣y1∣,∣x2∣,∣y2∣≤2⋅10^9.

Output
Print the number of points with integer coordinates that lie on this segment.

Examples

Input #1
0 0 3 3

Answer #1
4

Input #2
2 1 6 3

Answer #2
3

*/

#include <cassert>
#include <cstdlib>
#include <numeric>

using namespace std;

int solve(int x1, int y1, int x2, int y2)
{
	auto dx = abs(x2 - x1);
	auto dy = abs(y2 - y1);
	return gcd(dx, dy) + 1;
}

int main()
{
	assert(solve(0, 0, 3, 3) == 4);
	assert(solve(2, 1, 6, 3) == 3);

	return 0;
}
