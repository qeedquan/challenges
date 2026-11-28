/*

A non-negative integer is called evil if it has an even number of ones in its binary representation.
Similarly, a non-negative integer is called odious if it has an odd number of ones in its binary representation.
Let us write down evil and odious numbers in ascending order.

Let E(n) be the n-th evil number in this list. Similarly, let O(n) be the n-th odious number.

Write a program to calculate the sum of n-th evil and odious numbers E(n)+O(n) given their index n.

Input
The input file contains a single integer, n (1≤n≤1000000).

Output
The output file should contain a single integer, the sum E(n)+O(n).

Examples
Input #1
1

Answer #1
1

*/

#include <assert.h>

int
solve(int n)
{
	return (4 * n) - 3;
}

int
main()
{
	assert(solve(1) == 1);

	return 0;
}
