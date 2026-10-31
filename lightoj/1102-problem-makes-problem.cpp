/*

As I am fond of creating easier problems, recently I discovered a new problem. Actually, the problem is 'how can you make n by adding k non-negative integers?' I think a small example will make things clear. Suppose n=4 and k=3. There are 15 solutions. They are:

#	Combination	#	Combination	#	Combination
1	0 0 4	6	1 0 3	11	2 1 1
2	0 1 3	7	1 1 2	12	2 2 0
3	0 2 2	8	1 2 1	13	3 0 1
4	0 3 1	9	1 3 0	14	3 1 0
5	0 4 0	10	2 0 2	15	4 0 0
As I have already told you that I like to make problems easier, you don't have to find the actual result. You should report the result modulo 1000,000,007.

Input
Input starts with an integer T (≤ 25000), denoting the number of test cases.

Each case contains two integer n (0 ≤ n ≤ 10^6) and k (1 ≤ k ≤ 10^6).

Output
For each case, print the case number and the result modulo 1000000007 (10^9 + 7, it's a prime).

Sample
Input	Output
4
4 3
3 5
1000 3
1000 5

Case 1: 15
Case 2: 35
Case 3: 501501
Case 4: 84793457

*/

#include <cassert>
#include <cstdio>
#include <vector>

typedef long long vlong;

#define MOD 1000000007

using namespace std;

vlong modexp(vlong b, vlong p)
{
	vlong r = 1;
	while (p)
	{
		if (p & 1)
			r = (r * b) % MOD;
		b = (b * b) % MOD;
		p >>= 1;
	}
	return r;
}

vector<vlong> factorials(size_t n)
{
	vector<vlong> f;

	f.resize(n + 1);
	f[0] = 1;
	for (size_t i = 1; i <= n; i++)
		f[i] = (f[i - 1] * i) % MOD;
	return f;
}

vlong solve(const vector<vlong> &f, vlong n, vlong k)
{
	if (n < 0 || k < 1)
		return 0;

	vlong r = f[n + k - 1];
	vlong p = (f[n] * f[k - 1]) % MOD;
	r *= modexp(p, MOD - 2);
	return r % MOD;
}

int main()
{
	auto f = factorials(10000000);
	assert(solve(f, 4, 3) == 15);
	assert(solve(f, 3, 5) == 35);
	assert(solve(f, 1000, 3) == 501501);
	assert(solve(f, 1000, 5) == 84793457);

	return 0;
}
