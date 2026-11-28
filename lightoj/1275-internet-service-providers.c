/*

A group of N Internet Service Provider companies (ISPs) use a private communication channel that has a maximum capacity of C traffic units per second. Each company transfers T traffic units per second through the channel and gets a profit that is directly proportional to the factor T(C - T * N). The problem is to compute the smallest value of T that maximizes the total profit the N ISPs can get from using the channel. Notice that N, C, T, and the optimal T are integer numbers.

Input
Input starts with an integer T (≤ 20), denoting the number of test cases.

Each case starts with a line containing two integers N and C (0 ≤ N, C ≤ 109).

Output
For each case, print the case number and the minimum possible value of T that maximizes the total profit. The result should be an integer.

Sample
Input	Output
6
1 0
0 1
4 3
2 8
3 27
25 1000000000

Case 1: 0
Case 2: 0
Case 3: 0
Case 4: 2
Case 5: 4
Case 6: 20000000

*/

#include <assert.h>

typedef long long vlong;

/*

Profit = T(C - T*N)
       = T*C - T^2*N
       = -T^2*N + T*C

Maximize the quadratic equation

*/

vlong
solve(vlong n, vlong c)
{
	vlong t1, t2;
	vlong f1, f2;

	if (n == 0)
		return 0;

	t1 = c / (2 * n);
	t2 = c / (2 * n) + 1;

	f1 = t1 * (c - t1 * n);
	f2 = t2 * (c - t2 * n);
	if (f1 >= f2)
		return t1;
	return t2;
}

int
main()
{
	assert(solve(1, 0) == 0);
	assert(solve(0, 1) == 0);
	assert(solve(4, 3) == 0);
	assert(solve(2, 8) == 2);
	assert(solve(3, 27) == 4);
	assert(solve(25, 1000000000) == 20000000);

	return 0;
}
