/*

Decompose the given three-digit integer into its digits.

Input
One three-digit integer (positive or negative).

Output
Print each digit of the number on a separate line, as shown in the example.

Examples

Input #1
198

Answer #1
1
9
8

Input #2
-232

Answer #2
2
3
2

*/

#include <cctype>
#include <format>
#include <print>

using namespace std;

void solve(int n)
{
	for (auto c : format("{}", n))
	{
		if (isdigit(c))
			print("{}\n", c);
	}
}

int main()
{
	solve(198);
	solve(-232);

	return 0;
}
