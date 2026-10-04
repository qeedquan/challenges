/*

Let m[i,j] be a two dimensional array of size n×n. Let m[i,j] = i + j. Indexation starts from 1 (m[1,1] is a left upper corner of the matrix). Print the array.

Input
One positive integer n (n<50).

Output
Print the two dimensional array. Each number must be printed in 2 positions.

Examples
Input #1
6

Answer #1
 2  3  4  5  6  7 
 3  4  5  6  7  8 
 4  5  6  7  8  9 
 5  6  7  8  9 10 
 6  7  8  9 10 11 
 7  8  9 10 11 12 

*/

#include <print>

using namespace std;

void solve(int n)
{
	for (auto i = 1; i <= n; i++)
	{
		for (auto j = 1; j <= n; j++)
			print("{:2} ", i + j);
		println();
	}
}

int main()
{
	solve(6);

	return 0;
}
