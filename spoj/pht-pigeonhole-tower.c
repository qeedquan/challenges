/*

Pigeon SSNA want to build a tower with some wood walls. Let's describe the tower they want to make:

A Tower can consist of different number of level.
If a tower contain L levels then 1st level must contain L holes, 2nd level L-1, 3rd level L-2 ….. L level contain 1 hole.
Each room contain 3 wood walls.
See the picture below:

Now pigeon SSNA has n wood walls. What is maximum number of level he can made.

Input
Input starts with an integer T (≤ 100000), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 1012)

Output
For each case of input you have to print the case number and expected answer.

Example
Input:
2
15
24

Output:
Case 1: 3
Case 2: 4

*/

#include <assert.h>
#include <math.h>

int
solve(int n)
{
	if (n < 3)
		return 0;
	return sqrt(n + 1) - 1;
}

int
main()
{
	assert(solve(15) == 3);
	assert(solve(24) == 4);

	return 0;
}
