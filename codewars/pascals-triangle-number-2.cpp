/*

Here you will create the classic [Pascal's triangle](https://en.wikipedia.org/wiki/Pascal%27s_triangle).
Your function will be passed the depth of the triangle and you code has to return the corresponding pascal triangle up to that depth.

The triangle should be returned as a nested array.

for example:

PascalsTriangle.pascal(5); // should return [[1], [1,1], [1,2,1], [1,3,3,1], [1,4,6,4,1]]

To build the triangle, start with a single 1 at the top, for each number in the next row you just take the two numbers above it and add them together (except for the edges, which are all 1), e.g.:

              [1]
            [1   1]
          [1   2   1]
        [1   3   3   1]

*/

#include <cassert>
#include <vector>

using namespace std;

vector<vector<int>> pascal(size_t depth)
{
	vector<vector<int>> triangle;
	triangle.resize(depth);
	for (size_t i = 0; i < depth; i++)
	{
		triangle[i].resize(i + 1);
		triangle[i][0] = triangle[i][i] = 1;
		for (size_t j = 1; j < i; j++)
			triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
	}
	return triangle;
}

int main()
{
	vector<vector<int>> triangle_1 = { { 1 } };
	vector<vector<int>> triangle_2 = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 }, { 1, 4, 6, 4, 1 } };

	assert(pascal(1) == triangle_1);
	assert(pascal(5) == triangle_2);

	return 0;
}
