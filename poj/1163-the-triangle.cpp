/*

Description

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.
Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
Output

Your program is to write to standard output. The highest sum is written as an integer.
Sample Input

5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
Sample Output

30
Source

IOI 1994

*/

#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

int maxpath(const vector<vector<int>> &triangle)
{
	auto grid = triangle;
	ssize_t len = grid.size();
	for (ssize_t i = len - 2; i >= 0; i--)
	{
		for (ssize_t j = 0; j <= i; j++)
			grid[i][j] += max(grid[i + 1][j], grid[i + 1][j + 1]);
	}
	return grid[0][0];
}

int main()
{
	assert(maxpath({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) == 30);

	return 0;
}
