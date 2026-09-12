/*

Three real numbers x, y, and z are given. Using auxiliary functions for calculating the minimum and maximum of two elements, determine min(max(x,y),max(y,z),x+y+z).

Input
The only line contains three real numbers x, y, and z separated by spaces. The values do not exceed 100 in absolute value.

Output
Print the answer rounded to two decimal places.

Examples

Input #1
1.05 2.25 2.15

Answer #1
2.25

*/

#include <cassert>
#include <algorithm>

using namespace std;

double solve(double x, double y, double z)
{
	return min(max(x, y), min(max(y, z), x + y + z));
}

int main()
{
	assert(solve(1.05, 2.25, 2.15) == 2.25);

	return 0;
}
