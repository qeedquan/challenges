/*

Description

Given a prime P, 2 <= P < 2^31, an integer B, 2 <= B < P, and an integer N, 1 <= N < P, compute the discrete logarithm of N, base B, modulo P.
That is, find an integer L such that

B^L == N (mod P)

Input

Read several lines of input, each containing P,B,N separated by a space.

Output

For each line print the logarithm on a separate line. If there are several, print the smallest; if there is none, print "no solution".

Sample Input

5 2 1
5 2 2
5 2 3
5 2 4
5 3 1
5 3 2
5 3 3
5 3 4
5 4 1
5 4 2
5 4 3
5 4 4
12345701 2 1111111
1111111121 65537 1111111111

Sample Output

0
1
3
2
0
3
1
2
0
no solution
no solution
1
9584351
462803587

Hint

The solution to this problem requires a well known result in number theory that is probably expected of you for Putnam but not ACM competitions. It is Fermat's theorem that states
   B^(P-1) == 1 (mod P)

for any prime P and some other (fairly rare) numbers known as base-B pseudoprimes. A rarer subset of the base-B pseudoprimes, known as Carmichael numbers, are pseudoprimes for every base between 2 and P-1. A corollary to Fermat's theorem is that for any m
   B^(-m) == B^(P-1-m) (mod P) .

Source

Waterloo Local 2002.01.26

*/

#include <cassert>
#include <cstdio>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

typedef long long vlong;

// https://cp-algorithms.com/algebra/discrete-log.html
vlong discrete_log(vlong m, vlong a, vlong b)
{
	unordered_map<vlong, vlong> vals;
	vlong k, c, g;
	vlong n, an, i;
	vlong p, q, x;

	k = 1;
	c = 0;

	a %= m;
	b %= m;
	while ((g = gcd(a, m)) > 1)
	{
		if (b == k)
			return c;
		if (b % g)
			return -1;

		b /= g;
		m /= g;
		c++;
		k = (k * a / g) % m;
	}

	n = sqrt(m) + 1;
	an = 1;
	for (i = 0; i < n; i++)
		an = (an * a) % m;

	x = b;
	for (q = 0; q <= n; q++)
	{
		vals[x] = q;
		x = (x * a) % m;
	}

	x = k;
	for (p = 1; p <= n; p++)
	{
		x = (x * an) % m;
		if (vals.count(x))
			return (n * p) - vals[x] + c;
	}

	return -1;
}

int main()
{
	assert(discrete_log(5, 2, 1) == 0);
	assert(discrete_log(5, 2, 2) == 1);
	assert(discrete_log(5, 2, 3) == 3);
	assert(discrete_log(5, 2, 4) == 2);
	assert(discrete_log(5, 3, 1) == 0);
	assert(discrete_log(5, 3, 2) == 3);
	assert(discrete_log(5, 3, 3) == 1);
	assert(discrete_log(5, 3, 4) == 2);
	assert(discrete_log(5, 4, 1) == 0);
	assert(discrete_log(5, 4, 2) == -1);
	assert(discrete_log(5, 4, 3) == -1);
	assert(discrete_log(5, 4, 4) == 1);
	assert(discrete_log(12345701, 2, 1111111) == 9584351);
	assert(discrete_log(1111111121, 65537, 1111111111) == 462803587);

	return 0;
}
