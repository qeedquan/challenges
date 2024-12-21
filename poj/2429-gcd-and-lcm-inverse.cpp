/*

Description

Given two positive integers a and b, we can easily calculate the greatest common divisor (GCD) and the least common multiple (LCM) of a and b. But what about the inverse? That is: given GCD and LCM, finding a and b.
Input

The input contains multiple test cases, each of which contains two positive integers, the GCD and the LCM. You can assume that these two numbers are both less than 2^63.
Output

For each test case, output a and b in ascending order. If there are multiple solutions, output the pair with smallest a + b.
Sample Input

3 60
Sample Output

12 15
Source

POJ Achilles

*/

#include <cassert>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <numeric>

using namespace std;

typedef tuple<long, long> long2;

/*

https://shanzi.gitbooks.io/algorithm-notes/content/problem_solutions/gcd_and_lcm_inverse.html
Assume the two origin number is a and b, then we have gcd(a,b) divides lcm(a,b), but gcd(a,b) does not divide lcm(a,b)/gcd(a,b). In fact we have lcm(a,b)=(a*b)/gcd(a,b). Let m=gcd(a,b), then there must have

lcm(a,b) = (a*b)/m = (mx*my)/m = xy*m
While x and y are divisor of a and b and they are relatively-prime with each other. So we first get x*y=lcm(a,b)/gcd(a,b) to get the multiplication of x and y, then we start from sqrt(floor(x*y)) to iterately find for x and thus we get y.
We stop iteration when the first time we find a pair x and y that are relatively-prime. Then we return mx and my.

*/

long2 glinv(long m, long n)
{
	if (m < 1 || n < 1)
		return long2();

	n /= m;
	long x = 1;
	long i = sqrt(n);
	for (; i >= 1; i--)
	{
		if (!(n % i) && gcd(i, n / i) == 1)
		{
			x = i;
			break;
		}
	}
	return long2(x * m, (n / x) * m);
}

int main()
{
	auto r1 = glinv(3, 60);
	auto r2 = glinv(6, 48);
	auto r3 = glinv(15, 90);

	assert(get<0>(r1) == 12 && get<1>(r1) == 15);
	assert(get<0>(r2) == 6 && get<1>(r2) == 48);
	assert(get<0>(r3) == 30 && get<1>(r3) == 45);

	return 0;
}
