/*

Given a positive integer n, print all permutations of the integers from 1 to n in lexicographical order.

Input
One positive integer n where 1≤n≤8 is given.

Output
Print all permutations of the integers from 1 to n in lexicographical order. Print each permutation on a separate line.

Examples
Input #1
3

Answer #1
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/

#include <algorithm>
#include <print>

using namespace std;

void solve(int n)
{
	int p[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	if (n < 1 || n > 8)
		return;
	
	do
	{
		for (auto i = 0; i < n - 1; i++)
			print("{} ", p[i]);
		println("{}", p[n - 1]);
	} while (next_permutation(p, p + n));

	println();
}

int main()
{
	solve(3);
	return 0;
}
