/*

Vova's height when wearing both heels and a hat is a cm.
When wearing only heels, Vova's height is b cm, and when wearing only a hat, Vova's height is c cm.
What is Vova's actual height without heels or a hat?

Input
You will receive a single line containing three natural numbers a, b, and c, separated by spaces. Each number is valid and does not exceed 200.

Output
Output a single number representing Vova's real height.

Examples

Input #1
165 150 155

Answer #1
140

*/

#include <cassert>

int solve(int a, int b, int c)
{
	return b + c - a;
}

int main()
{
	assert(solve(165, 150, 155) == 140);

	return 0;
}
