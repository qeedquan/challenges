/*

In the spirit of a question on math.se: given an integer n, return the integer in position n of the sequence [1, 0, -1, 0, 1, 0, -1, 0, ...]. Assume n >= 0.

Rules:

You may only use the operations -x, x+y, x-y, x*y, x/y, and xy, whatever their representations are in the language you choose.
Your function must be called a.
Your function must run in constant time for all n.
Example:

a=lambda n:((-1)**(n*n-n)//2)+(-1)**(n*n+n)//2))//2
Non-example (uses list subscripting operation and modulo operator):

a=lambda n:[1,0,-1,0][n%4]
Non-example (uses cos operation):

from math import *;a=lambda n:int(cos(n*pi/2))
Non-example (does not run in constant time and uses if operation):

a=lambda n:-a(n-2) if n>1 else 0 if n>0 else 1
Clarifications: Both integer and float division are allowed. Your solution may return either an integer or a float (or complex number, I suppose, since some answers already used it). If your solution returns a float: your solution should, if it were to theoretically be carried out to infinite precision, give the exact answer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
f(int n)
{
	static const int tab[] = {1, 0, -1, 0};

	return (n >= 0) ? tab[n & 3] : 0;
}

int
main(void)
{
	static const int tab[] = {1, 0, -1, 0, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, -1};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(f(i) == tab[i]);

	return 0;
}
