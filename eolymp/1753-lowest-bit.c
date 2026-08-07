/*

Given a positive integer A (1≤A≤100), output the lowest set bit of A.

For example, given A=26, write A in binary as 11010. The lowest set bit of A is 10 in binary (which equals 2 in decimal), so the output should be 2.

Another example: for A=88, write A in binary as 1011000. The lowest set bit of A is 1000 in binary (which equals 8 in decimal), so the output should be 8.

Input
Each line of input contains a single integer A (1≤A≤100). A line containing 0 indicates the end of input, and this line is not part of the input data.

Output
For each A in the input, output a single line containing only its lowest set bit (in decimal).

Examples

Input #1
26
88
0

Answer #1
2
8

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

typedef unsigned int uint;

uint
solve(uint n)
{
	return 1U << stdc_trailing_zeros(n);
}

int
main()
{
	assert(solve(26) == 2);
	assert(solve(88) == 8);

	return 0;
}
