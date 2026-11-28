/*

Description

Given n, a positive integer, how many positive integers less than n are relatively prime to n? Two integers a and b are relatively prime if there are no integers x > 1, y > 0, z > 0 such that a = xy and b = xz.

Input

There are several test cases. For each test case, standard input contains a line with n <= 1,000,000,000. A line containing 0 follows the last case.

Output

For each test case there should be single line of output answering the question posed above.

Sample Input

7
12
0

Sample Output

6
4

Source

Waterloo local 2002.07.01

*/

#include <assert.h>
#include <stdio.h>

// https://oeis.org/A000010
int
totient(int n)
{
	int i, p;

	if (n < 1)
		return 0;

	p = n;
	for (i = 2; i * i <= n; i++) {
		if (!(n % i)) {
			p -= p / i;
			while (!(n % i))
				n /= i;
		}
	}
	if (n > 1)
		p -= p / n;
	return p;
}

int
main(void)
{
	assert(totient(7) == 6);
	assert(totient(12) == 4);
	return 0;
}
