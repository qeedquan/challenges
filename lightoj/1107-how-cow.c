/*

Mr Kopa Samsu is a farmer. He has a land of rectangular shape. But there are cows that disturb him a lot. The cows use to enter his land and ruin his crops. Now Mr Kopa Samsu has become smarter. He has a GPS system that will help him to know the position of the cows. So, you can think his land as a 2D grid, and cows can be treated as points. Now you are given the information of his land and cows. You have to tell him whether a cow is inside his land or not.

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

The first line of each case contains four integers x1 y1 x2 y2, where (x1, y1) is the lower left coordinate of his land and (x2, y2) is the upper right coordinate of his land. You can assume that the sides of the land are axis parallel. The next line contains an integer M (1 ≤ M ≤ 100) denoting the number of cows. Each of the next M lines contains two integers each denoting x y - the position of a cow. You can safely assume that no cow will lie on the boundary of the rectangle. All the coordinates will lie in the range [0, 10000].

Output
For each case you have to print the case number in a line first. Then for each cow, you have to print Yes or No depending whether the cow is inside the land or not.

Sample
Input	Output
1
1 2 8 10
7
0 0
5 6
1 0
7 9
3 5
10 10
1 11

Case 1:
No
Yes
No
Yes
Yes
No
No

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int x1, int y1, int x2, int y2, int p[][2], size_t n)
{
	size_t i;
	int x, y;

	for (i = 0; i < n; i++) {
		x = p[i][0];
		y = p[i][1];
		if (x > x1 && x < x2 && y > y1 && y < y2)
			puts("Yes");
		else
			puts("No");
	}
}

int
main()
{
	int p[][2] = {
		{ 0, 0 },
		{ 5, 6 },
		{ 1, 0 },
		{ 7, 9 },
		{ 3, 5 },
		{ 10, 10 },
		{ 1, 11 },
	};

	solve(1, 2, 8, 10, p, nelem(p));
	return 0;
}
