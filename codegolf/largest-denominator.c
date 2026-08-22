/*

The number 1 can be written as sum of fractions of the form 1/p (where p>1). There are different ways to write it. You will be given an integer k which denotes the number of fractions to be used to get the sum as 1. You need to find the largest possible value of p among all possible ways. See sample input for clarity

Input Format:

The first line contains number of test cases t. Then t lines follow each having a single integer k.

Output:

You need to print the largest value of p modulo 10^9 + 7.

Constraints:

1<=t<=10^5
2<=k<=10^6
Sample Input --------------- Sample Output

2                        2
2                        6
3
Explanation There is only one way to write '1' as sum of two fractions. 1/2 + 1/2. hence the largest value is 2. In the second test case, the only possible ways as sum of three fractions are:

1/3, 1/3, 1/3
1/6, 1/2, 1/3
1/4, 1/4, 1/2
Among these the second representation has the largest denominator which is '6' and hence the answer.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

// https://oeis.org/A007018
vlong
denom(vlong k)
{
	vlong i, m, x;

	if (k < 1)
		return 0;

	m = 1000000007;
	x = 1;
	for (i = 2; i <= k; i++)
		x = (x * (x + 1)) % m;
	return x;
}

int
main()
{
	assert(denom(2) == 2);
	assert(denom(3) == 6);
	assert(denom(4) == 42);
	assert(denom(5) == 1806);
	assert(denom(6) == 3263442);
	return 0;
}
