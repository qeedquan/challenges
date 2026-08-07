/*

Consider the following algorithm:

Enter n.

Print n.

If n=1, then STOP.

If n is odd, then n=3⋅n+1.

Else, n=n/2.

Return to step 2.

Given the input 22, the following sequence of numbers will be printed:

22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
It is conjectured that the above algorithm will terminate (when a 1 is printed) for any positive integer n.
Despite the simplicity of the algorithm, it is unknown whether this conjecture is true.
However, it has been verified for all integers n such that 0<n<1,000,000 (and, in fact, for many more numbers as well).

For a given n, the number of values printed in its sequence (including the 1) is called the cycle length of n. In the example above, the cycle length for 22 is 16.

For any two integers i and j, find the maximum cycle length for all numbers between i and j inclusive.

Input
The input consists of a series of pairs of integers i and j, one pair per line.
All integers will satisfy 0<i<1,000,000 and 0<j<1,000,000.
You may assume that no operation will cause overflow of a 32-bit integer.

Output
For each pair of integers i and j, print i and j in the same order as in the input, followed by the maximum cycle length for numbers between i and j inclusive.
For each test case, print three numbers on one line, separated by single spaces.

Examples
Input #1
1 10
100 200
201 210
900 1000

Answer #1
1 10 20
100 200 125
201 210 89
900 1000 174

*/

#include <cassert>
#include <algorithm>

using namespace std;

int cycle(int n)
{
	int r = 1;
	for (; n > 1; r++)
	{
		if (n & 1)
			n = (n * 3) + 1;
		else
			n = n / 2;
	}
	return r;
}

int solve(int a, int b)
{
	if (a > b)
		swap(a, b);

	int r = 0;
	for (int i = a; i <= b; i++)
		r = max(r, cycle(i));
	return r;
}

int main()
{
	assert(solve(1, 10) == 20);
	assert(solve(100, 200) == 125);
	assert(solve(201, 210) == 89);
	assert(solve(900, 1000) == 174);

	return 0;
}
