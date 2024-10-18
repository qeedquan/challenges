/*

A Cullen Number is any number that is contained in the sequence generated using the formula:

C(n) = (n*2^n)+1.

Your Task:
Write a program or function that receives an input and outputs a truthy/falsy value based on whether the input is a Cullen Number.

Input:
A non-negative integer between 0 and 10^9 (inclusive).

Output:
A truthy/falsy value that indicates whether the input is a Cullen Number.

Test Cases:
Input:    Output:
1   --->  truthy
3   --->  truthy
5   --->  falsy
9   --->  truthy
12  --->  falsy
25  --->  truthy

Scoring:
This is code-golf, so the lowest score in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A002064
uvlong
cullen(uvlong n)
{
	return (n * (1ULL << n)) + 1;
}

bool
isnum(uvlong n, uvlong (*f)(uvlong))
{
	uvlong i, m;

	i = 0;
	do {
		m = f(i);
		i = i + 1;
	} while (m < n);

	return m == n;
}

int
main(void)
{
	assert(isnum(1, cullen) == true);
	assert(isnum(3, cullen) == true);
	assert(isnum(5, cullen) == false);
	assert(isnum(9, cullen) == true);
	assert(isnum(12, cullen) == false);
	assert(isnum(25, cullen) == true);

	return 0;
}
