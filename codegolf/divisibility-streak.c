/*

We can define the Divisibility Streak k of a number n by finding the smallest non-negative integer k such that n+k is not divisible by k+1.

Challenge
In your language of choice, write a program or function that outputs or returns the Divisibility Streak of your input.

Examples:
n=13:
13 is divisible by 1
14 is divisible by 2
15 is divisible by 3
16 is divisible by 4
17 is not divisible by 5
The Divisibilty Streak of 13 is 4

n=120:
120 is divisible by 1
121 is not divisible by 2
The Divisibilty Streak of 120 is 1

Test Cases:
n      DS
2      1
3      2
4      1
5      2
6      1
7      3
8      1
9      2
10     1
2521   10
More test cases can be found here.

Notes
Based on Project Euler Problem 601
This sequence can be found on OEIS, shifted down by 1.

Rules
You can assume the input is greater than 1.

Scoring
code-golf:The submission with the lowest score wins.

*/

#include <assert.h>
#include <limits.h>

// https://oeis.org/A055874
long
A055874(long n)
{
	long i;

	if (n < 0)
		return -1;
	if (n < 1)
		return 0;
	for (i = 1; i < LONG_MAX; i++) {
		if (n % i)
			return i - 1;
	}
	return -1;
}

long
divstreak(long n)
{
	return A055874(n - 1);
}

int
main(void)
{
	assert(divstreak(2) == 1);
	assert(divstreak(3) == 2);
	assert(divstreak(4) == 1);
	assert(divstreak(5) == 2);
	assert(divstreak(6) == 1);
	assert(divstreak(7) == 3);
	assert(divstreak(8) == 1);
	assert(divstreak(9) == 2);
	assert(divstreak(10) == 1);
	assert(divstreak(13) == 4);
	assert(divstreak(120) == 1);
	assert(divstreak(2521) == 10);

	return 0;
}
