/*

A two-dimensional array of size n×m is given. Read the elements of the array, then print them.

Input
The first line contains two integers n and m (n,m≤100) — the number of rows and columns in the array.
The next n lines each contain m integers, the elements of the array.
All numbers have an absolute value not exceeding 100.

Output
Print n rows, each containing m integers — the elements of the array.

Examples
Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

Answer #1
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

*/

#include <print>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

int main()
{
	Matrix matrix = {
		{ 1, 3, 2, 4, 5 },
		{ 4, 2, 7, 6, 5 },
		{ 9, 2, 3, 5, 1 },
		{ 7, 8, 1, 7, 2 },
	};

	println("{}", matrix);

	return 0;
}
