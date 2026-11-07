/*

You are given two positive integers a and b. In one move you can increase a by 1 (replace a with a+1). Your task is to find the minimum number of moves you need to do in order to make a divisible by b.
It is possible, that you have to make 0 moves, as a is already divisible by b. You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤10^4) — the number of test cases. Then t test cases follow.

The only line of the test case contains two integers a and b (1≤a,b≤10^9).

Output
For each test case print the answer — the minimum number of moves you need to do in order to make a divisible by b.

Example

input
5
10 4
13 9
100 13
123 456
92 46

output
2
5
4
333
0

*/

#include <assert.h>

int
stepdiv(int a, int b)
{
	if (b == 0 || (a % b) == 0)
		return 0;
	return (((a / b) + 1) * b) - a;
}

int
main(void)
{
	assert(stepdiv(10, 4) == 2);
	assert(stepdiv(13, 9) == 5);
	assert(stepdiv(100, 13) == 4);
	assert(stepdiv(123, 456) == 333);
	assert(stepdiv(92, 46) == 0);

	return 0;
}
