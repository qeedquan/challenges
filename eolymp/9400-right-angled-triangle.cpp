/*

Create a program that outputs a right-angled triangle made of stars, where both legs have a length of n.

Input
You will receive an integer n (2≤n≤50), which specifies the length of each leg of the triangle.

Output
Display a right-angled triangle using stars, with the specified dimensions.

Examples

Input #1
3

Answer #1
*
**
***

Input #2
5

Answer #2
*
**
***
****
*****

*/

#include <print>

using namespace std;

void solve(int n)
{
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j <= i; j++)
			print("*");
		println();
	}
	println();
}

int main()
{
	solve(3);
	solve(5);

	return 0;
}
