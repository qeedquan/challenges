/*

For the given positive integer n print the horizontal rectangular frame of size 3×n from stars, filled with spaces (as shown in the sample).

Input
One positive integer n (1<n≤100).

Output
Print the horizontal rectangular frame of size 3×n.

Examples

Input #1
5

Answer #1
*****
*   *
*****

*/

#include <print>

using namespace std;

void frame(int n)
{
	for (auto y = 0; y < 3; y++)
	{
		print("*");
		for (auto x = 0; x < n - 2; x++)
		{
			if (y != 1)
				print("*");
			else
				print(" ");
		}
		println("*");
	}
	println();
}

int main()
{
	for (auto i = 0; i <= 10; i++)
		frame(i);

	return 0;
}
