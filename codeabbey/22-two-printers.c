/*

John and Mary founded J&M publishing house and bought two old printers to equip it.

Now they have their first commercial deal - to print a document consisting of N pages.

It appears that printers work at different speed. One produces a page in X seconds and other does it in Y seconds.

So now company founders are curious about minimum time they can spend on printing the whole document with two printers.

Input data contains number of test cases in the first line.
Then test-cases will follow, each in separate line.
Each testcase contains three integer values - X Y N, where N will not exceed 1,000,000,000.
Answer should contain minimum printing times for each of testcases, separated by spaces.

Example:

input data:
2
1 1 5
3 5 4

answer:
3 9

*/

#include <assert.h>
#include <stdio.h>

/*

In T seconds, the first printer can produce floor(T/X) pages,
and the second printer can produce floor(T/Y) pages.
We want to find the smallest T where:

floor(T/X) + floor(T/Y) >= N

A close estimate is:
T ~ N/(1/X + 1/Y) = (N*X*Y)/(X+Y)

Use the estimate as a base floor and keep incrementing T until we find a solution.

*/

long
solve(long x, long y, long n)
{
	long t;

	if (x < 1 || y < 1 || n < 1)
		return 0;

	t = (n * x * y) / (x + y);
	while ((t / x) + (t / y) < n)
		t += 1;
	return t;
}

int
main()
{
	assert(solve(1, 1, 5) == 3);
	assert(solve(3, 5, 4) == 9);

	return 0;
}
