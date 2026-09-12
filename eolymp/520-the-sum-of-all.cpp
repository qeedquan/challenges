/*

Find the sum of all the given numbers.

Input
Contains n (1≤n≤10^5) integers. Each integer does not exceed 10^9 in absolute value.

Output
Print the sum of all the given numbers.

Examples
Input #1
2 3
   1      1

Answer #1
7

*/

#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long vlong;

vlong solve()
{
	vlong r = 0;
	vlong n;
	while (cin >> n)
		r += n;
	return r;
}

int main()
{
	cout << solve() << endl;

	return 0;
}
