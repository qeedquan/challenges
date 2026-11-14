/*

Given a square matrix (i.e. an array of subarrays), find the sum of values from the first value of the first array, the second value of the second array, the third value of the third array, and so on...

Examples
array = [[1, 2],
         [3, 4]]

diagonal sum: 1 + 4 = 5

array = [[5, 9, 1, 0],
         [8, 7, 2, 3],
         [1, 4, 1, 9],
         [2, 3, 8, 2]]

diagonal sum: 5 + 7 + 1 + 2 = 15

*/

#include <cassert>
#include <vector>

using namespace std;

int diagonal_sum(const vector<vector<int> > matrix)
{
	auto sum = 0;
	for (size_t i = 0; i < matrix.size(); i++)
		sum += matrix[i][i];
	return sum;
}

int main()
{
	assert(diagonal_sum({ { 1, 2 }, { 3, 4 } }) == 5);
	assert(diagonal_sum({ { 5, 9, 1, 0 }, { 8, 7, 2, 3 }, { 1, 4, 1, 9 }, { 2, 3, 8, 2 } }) == 15);
	return 0;
}
