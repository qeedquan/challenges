/*

There is a section of choral singing at school.
The start of the section always happens in the same way: by the signal of the leader, all n participants stand in a circle and each m-th person sings a scale for chanting.

The leader of the section noticed that all the members are not always able to stretch their vocal cords.
Given n and m, help him to determine whether or not all the choir participants will take part in the warm-up again.

Input
The input consists of several cases. Each case contains two positive integers n and m (1≤n,m≤10^3).

Output
For each test case, print YES if everyone has a chance to sing, otherwise print NO.

Examples
Input #1
4 1
6 3

Answer #1
YES
NO

*/

#include <cassert>
#include <string>
#include <numeric>

using namespace std;

string solve(int n, int m)
{
	return (gcd(n, m) == 1) ? "YES" : "NO";
}

int main()
{
	assert(solve(4, 1) == "YES");
	assert(solve(6, 3) == "NO");

	return 0;
}
