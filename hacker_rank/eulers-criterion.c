/*

Your friend gives you an equation A≡X^2 (mod M) and asks you to find an integer solution for X.

However, you know your friend's mischievous nature and suspect that there is no solution to such an equation. Thus, you first want to find out whether there is a solution to it.

You may find this link helpful: http://mathworld.wolfram.com/EulersCriterion.html

Input Format

The first line contains the number of cases, T. T lines follow, each containing two integers A and M separated by a single space.

Constraints

0 < T <= 10^5
2 <= M < 10^9, M is prime
0 <= A < M

Output Format

Output T lines, each containing one word: YES, if a solution exists and NO otherwise.

Sample Input

2
5 7
4 7

Sample Output

NO
YES

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
modbin(vlong a, vlong e, vlong m)
{
	vlong r, x;

	if (e == 0)
		return 1;

	if (e == 1)
		return a % m;

	r = modbin(a, e / 2, m);
	if (!(e & 1))
		return (r * r) % m;

	x = (r * r) % m;
	x *= (a % m);
	x %= m;
	return x;
}

bool
solvable(vlong a, vlong m)
{
	if (a == 0 || a == 2)
		return true;
	return modbin(a, ((m - 1) / 2), m) == 1;
}

int
main()
{
	assert(solvable(5, 7) == false);
	assert(solvable(4, 7) == true);
	return 0;
}
