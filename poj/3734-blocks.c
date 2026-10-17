/*

Description

Panda has received an assignment of painting a line of blocks. Since Panda is such an intelligent boy, he starts to think of a math problem of painting. Suppose there are N blocks in a line and each block can be paint red, blue, green or yellow. For some myterious reasons, Panda want both the number of red blocks and green blocks to be even numbers. Under such conditions, Panda wants to know the number of different ways to paint these blocks.

Input

The first line of the input contains an integer T(1≤T≤100), the number of test cases. Each of the next T lines contains an integer N(1≤N≤10^9) indicating the number of blocks.

Output

For each test cases, output the number of ways to paint the blocks in a single line. Since the answer may be quite large, you have to module it by 10007.

Sample Input

2
1
2

Sample Output

2
6

Source

PKU Campus 2009 (POJ Monthly Contest – 2009.05.17), Simon

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://oeis.org/A063376
uvlong
blocks(uvlong n)
{
	static const uvlong mod = 10007ULL;
	uvlong a, b;

	if (n == 0)
		return 1;

	n--;
	a = 1ULL << n;
	b = 1ULL << (n << 1);
	return (a + b) % mod;
}

int
main(void)
{
	assert(blocks(1) == 2);
	assert(blocks(2) == 6);

	return 0;
}
