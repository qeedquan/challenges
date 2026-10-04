/*

Based on a scenario similar to the previous task, your goal is to determine how much money Petryk has remaining.

Input
You will receive two natural numbers, m and n, provided on a single line and separated by a space.

Output
Print the amount of money Petryk has left after his enthusiastic pie purchase.

Examples

Input #1
27 10

Answer #1
7

*/

#include <cassert>

int solve(int m, int n)
{
	if (n == 0)
		return 0;
	return m % n;
}

int main()
{
	assert(solve(27, 10) == 7);

	return 0;
}
