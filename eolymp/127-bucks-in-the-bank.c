/*

Marley gave Scrooge 1 dollar on his first birthday, and Scrooge deposited this money in the bank.
Each following year, Marley doubled the amount of the previous gift and added a number of dollars equal to Scrooge's age.
Scrooge continued to deposit all the money in the bank.
On which birthday, denoted as N, will the total amount in the bank reach at least S dollars?

Input
A single integer S, where 1≤S≤2^40.

Output
Print the required value of N.

Examples

Input #1
15

Answer #1
3

*/

#include <assert.h>
#include <stdio.h>

int
solve(int n)
{
	int d, s, r;

	r = d = 1;
	for (s = 1; s < n; s += d) {
		r += 1;
		d = (2 * d) + r;
	}
	return r;
}

int
main()
{
	assert(solve(15) == 3);
	assert(solve(1000) == 9);
	assert(solve(5000) == 11);

	return 0;
}
