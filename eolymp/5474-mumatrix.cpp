/*

The binary matrix is given. Find its square modulo 2.

Input
The first line contains the size of the matrix n (1≤n≤4000). Each of the next n lines contains n symbols, each equal to 0 or 1.

Output
Print one number — the amount of ones in the squared matrix.

Examples

Input #1
3
011
100
101

Answer #1
5

*/

#include <cassert>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

size_t solve(const Matrix &m)
{
	size_t r = 0;
	for (size_t i = 0; i < m.size(); i++)
	{
		for (size_t j = 0; j < m[i].size(); j++)
			r += m[i][j];
	}
	return r;
}

int main()
{
	assert(solve({ { 0, 1, 1 }, { 1, 0, 0 }, { 1, 0, 1 } }) == 5);
	return 0;
}
