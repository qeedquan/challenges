/*

Write code to compute the median of 5 positive 32 bit integers. Your code must be branchless.

A branch, jump or transfer is an instruction in a computer program that can cause a computer to begin executing a different instruction sequence and thus deviate from its default behavior of executing instructions in order.

This essentially means no if statements or jumps in your code or anything that would translate to an if statement or jump at the cpu level.

You can assume a modern x86 processor when determining if your code will be branchless.

Here is a previous related challenge about the median of three numbers.

You can use any programming language of your choosing.

Examples:

[4, 5, 5, 6, 3] 5
[9, 3, 9, 8, 2] 8
[8, 6, 2, 9, 1] 6
[7, 1, 7, 2, 5] 5
[5, 5, 9, 3, 9] 5
[1, 2, 7, 1, 8] 2
[2, 4, 7, 6, 7] 6
[3, 1, 3, 6, 2] 3
[5, 4, 6, 8, 3] 5
[1, 3, 9, 1, 4] 3

EDIT

While and for loops will require branching as will most sorting algorithms. Radix sort is implementable without if statement/conditionals.

The median for three numbers is a+b+c−min(a,b,c)−max(a,b,c) for example.

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
cmp(int *a, int *b)
{
	int x, y;

	x = min(*a, *b);
	y = max(*a, *b);
	*a = x;
	*b = y;
}

int
median5(int a, int b, int c, int d, int e)
{
	cmp(&a, &b);
	cmp(&d, &e);
	cmp(&a, &d);
	cmp(&b, &e);
	cmp(&b, &c);
	cmp(&c, &d);
	cmp(&b, &c);
	return c;
}

int
main()
{
	assert(median5(4, 5, 5, 6, 3) == 5);
	assert(median5(9, 3, 9, 8, 2) == 8);
	assert(median5(8, 6, 2, 9, 1) == 6);
	assert(median5(7, 1, 7, 2, 5) == 5);
	assert(median5(5, 5, 9, 3, 9) == 5);
	assert(median5(1, 2, 7, 1, 8) == 2);
	assert(median5(2, 4, 7, 6, 7) == 6);
	assert(median5(3, 1, 3, 6, 2) == 3);
	assert(median5(5, 4, 6, 8, 3) == 5);
	assert(median5(1, 3, 9, 1, 4) == 3);

	return 0;
}
