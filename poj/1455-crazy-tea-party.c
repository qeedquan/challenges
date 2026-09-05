/*

Description

n participants of << crazy tea party >> sit around the table. Each minute one pair of neighbors can change their places.
Find the minimum time (in minutes) required for all participants to sit in reverse order (so that left neighbors would become right, and right - left).

Input

The first line is the amount of tests. Each next line contains one integer n (1 <= n <= 32767) - the amount of crazy tea participants.

Output

For each number n of participants to crazy tea party print on the standard output, on a separate line, the minimum time required for all participants to sit in reverse order.
Sample Input

3
4
5
6

Sample Output

2
4
6

Source

Southeastern Europe 2003

*/

#include <assert.h>

// https://oeis.org/A002620
unsigned
revtime(unsigned n)
{
	if (n == 0)
		return 0;
	return ((n - 1) * (n - 1)) / 4;
}

int
main(void)
{
	assert(revtime(4) == 2);
	assert(revtime(5) == 4);
	assert(revtime(6) == 6);

	return 0;
}
