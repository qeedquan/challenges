/*

NOTE: Some terminology used in this challenge is fake.

For two integers n and k both greater than or equal to 2 with n > k, n is semidivisible by k if and only if n/k = r/10 for some integer r.
However, n may not be divisible by k. Put more simply, the base 10 representation of n/k has exactly one digit after the decimal place.
For example, 6 is semidivisible by 4 because 6/4=15/10, but 8 is not semidivisible by 4 because 8 % 4 == 0.

Your task is to write a program which takes in two integers as input, in any convenient format, and outputs a truthy (respectively falsy) value if the first input is semidivisible by the second, and a falsey (respectively truthy) value otherwise.
Standard loopholes are forbidden. You may assume that n > k and that both n and k are at least 2.

Test cases:

[8, 4] -> falsey
[8, 5] -> truthy
[9, 5] -> truthy
[7, 3] -> falsey
This question is code-golf therefore shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
semidivisible(unsigned n, unsigned k)
{
	return !((n * 10) % k) && (n % k);
}

int
main(void)
{
	assert(semidivisible(8, 4) == false);
	assert(semidivisible(8, 5) == true);
	assert(semidivisible(9, 5) == true);
	assert(semidivisible(7, 3) == false);
	assert(semidivisible(19001, 10000) == false);

	return 0;
}
