/*

Imagine simple math problem. You have a number, say it's 1000. And you want to find the next multiple of 32 that follows 1000. You automatically make some simple calculations and get the result. Typical algorithm looks like this:

int number = 1000, result;
result = (1 + (number/32)) * 32; // integer division
It's kind of easy and obvious, right? And now the challenge. Make this calculation without using *, / and loops.

Rules:

Don't use *, / and loops.
Assume that input number is already stored in variable n, store result in the variable r (already declared).
The shortest code wins.
Sample input: (already stored in n)

1000
Sample output: (value of r)

1024
Sample input:

31
Sample output:

32
Sample input:

32
Sample output:

64
It is assumed that n is a positive number.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long ulong;

ulong
multiple32_1(ulong n)
{
	return (1 + (n / 32)) * 32;
}

ulong
multiple32_2(ulong n)
{
	return (n | 31) + 1;
}

int
main(void)
{
	ulong i;

	for (i = 0; i <= 10000000; i++)
		assert(multiple32_1(i) == multiple32_2(i));

	return 0;
}
