/*

This is a rather simple but interesting kata. Try to solve it using logic. The shortest solution can be fit into one line.

Task
The point is that a natural number N (1 <= N <= 10^9) is given. You need to write a function which finds the number of natural numbers not exceeding N and not divided by any of the numbers [2, 3, 5].

Example
Let's take the number 5 as an example:

1 - doesn't divide integer by 2, 3, and 5
2 - divides integer by 2
3 - divides integer by 3
4 - divides integer by 2
5 - divides integer by 5

Answer: 1

because only one number doesn't divide integer by any of 2, 3, 5

Note
Again, try to think of a formula that will shorten your solution and help you pass big tests.

Good luck :)

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
real(int n)
{
	static const int nums[] = {2, 3, 5, 6, 10, 15, 30};
	static const int sgns[] = {-1, -1, -1, 1, 1, 1, -1};

	size_t i;
	int r;

	r = n;
	for (i = 0; i < nelem(nums); i++)
		r += sgns[i] * (n / nums[i]);
	return r;
}

int
main()
{
	assert(real(5) == 1);
	assert(real(10) == 2);
	assert(real(20) == 6);
	assert(real(30) == 8);
	assert(real(40) == 10);
	assert(real(55) == 15);
	assert(real(66) == 17);
	assert(real(75) == 20);
	assert(real(100) == 26);
	return 0;
}
