/*

At a birthday party, a huge festive cake was served to three friends.
The first friend could eat the entire cake by themselves in t1 hours, the second in t2 hours, and the third in t3 hours.

How much time will it take the three friends to eat the whole cake together?

Input
The only line contains three non-negative integers t1, t2, and t3, each not exceeding 10000.

Output
Print the time in hours it takes for the three friends to eat the cake together. Round the result to two decimal places.

Examples
Input #1
3 3 3

Answer #1
1.00

*/

#include <stdio.h>

double
solve(int t1, int t2, int t3)
{
	return 1.0 / ((1.0 / t1) + (1.0 / t2) + (1.0 / t3));
}

int
main()
{
	printf("%f\n", solve(3, 3, 3));
	return 0;
}
