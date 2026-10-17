/*

Find the largest digit in a four-digit integer.

Input
A single four-digit integer n.

Output
Output the largest digit of n.

Examples

Input #1
2134

Answer #1
4

Input #8
2662

Answer #8
6

*/

#include <cassert>
#include <algorithm>

using namespace std;

int highest_digit(int n)
{
	auto r = 0;
	do
	{
		r = max(r, n % 10);
		n /= 10;
	} while (n);
	return r;
}

int main()
{
	assert(highest_digit(2134) == 4);
	assert(highest_digit(2662) == 6);

	return 0;
}
