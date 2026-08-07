/*

You are given a 3×3 square matrix where each cell is any digit between 0 and 9 except 7. Your task is to figure out the minimum number of digits that must be replaced with 7's so that the sums of the digits in each row and each column are the same.

NB: There is no constraint whatsoever on the diagonals, so we end up with a semi-magical square.

Examples
Here is a matrix where three digits need to be turned into 7's so that all sums are 20:

8 6 6    7 6 7
1 5 8 -> 7 5 8
6 9 5    6 9 5

In this one, only one digit needs to be replaced with a 7 so that all sums are 13:

9 2 2    9 2 2
0 9 4 -> 0 9 4
4 2 9    4 2 7

And for this one, our only option is to replace all digits with 7's:

0 6 8    7 7 7
3 6 1 -> 7 7 7
8 4 0    7 7 7

So the expected outputs for the above examples are 3, 1 and 9 respectively.

Rules
Because the size of the matrix is fixed, you may take input as a flattened array or 9 distinct arguments.
Because we're dealing with digits exclusively, you may also take a string of 9 characters.
The input matrix may already fulfill the sum constraints, in which case the expected answer is 0.
This is code-golf.
Test cases
[[9,4,3],[3,4,9],[4,8,4]] -> 0
[[5,1,3],[3,1,5],[1,2,1]] -> 1
[[3,9,6],[8,5,5],[8,4,0]] -> 2
[[5,3,5],[1,9,5],[3,3,3]] -> 2
[[8,3,0],[8,0,8],[0,8,4]] -> 3
[[1,5,2],[5,9,5],[6,5,3]] -> 4
[[3,0,8],[1,8,0],[1,3,8]] -> 4
[[3,3,0],[5,1,9],[9,9,5]] -> 5
[[2,4,5],[5,3,4],[4,4,8]] -> 6
[[3,0,3],[8,3,5],[8,3,4]] -> 9

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
same(int a[3][3])
{
	int s[6];

	s[0] = a[0][0] + a[0][1] + a[0][2];
	s[1] = a[1][0] + a[1][1] + a[1][2];
	s[2] = a[2][0] + a[2][1] + a[2][2];
	s[3] = a[0][0] + a[1][0] + a[2][0];
	s[4] = a[0][1] + a[1][1] + a[2][1];
	s[5] = a[0][2] + a[1][2] + a[2][2];
	return s[0] == s[1] && s[1] == s[2] && s[3] == s[4] && s[4] == s[5];
}

int
sevens(int a[3][3])
{
	int m[3][3];
	int i, j;
	int c, r;

	r = 10;
	for (i = 0; i < 512; i++) {
		memcpy(m, a, sizeof(m));
		for (c = j = 0; j < 9; j++) {
			if (i & (1 << j)) {
				m[j / 3][j % 3] = 7;
				c++;
			}
		}
		if (same(m))
			r = min(r, c);
	}
	return r;
}

int
main(void)
{
	int a1[3][3] = {
	    {8, 6, 6},
	    {1, 5, 8},
	    {6, 9, 5},
	};
	int a2[3][3] = {
	    {9, 2, 2},
	    {0, 9, 4},
	    {4, 2, 9},
	};
	int a3[3][3] = {
	    {0, 6, 8},
	    {3, 6, 1},
	    {8, 4, 0},
	};
	int a4[3][3] = {
	    {9, 4, 3},
	    {3, 4, 9},
	    {4, 8, 4},
	};
	int a5[3][3] = {
	    {5, 1, 3},
	    {3, 1, 5},
	    {1, 2, 1},
	};
	int a6[3][3] = {
	    {3, 9, 6},
	    {8, 5, 5},
	    {8, 4, 0},
	};
	int a7[3][3] = {
	    {5, 3, 5},
	    {1, 9, 5},
	    {3, 3, 3},
	};
	int a8[3][3] = {
	    {8, 3, 0},
	    {8, 0, 8},
	    {0, 8, 4},
	};
	int a9[3][3] = {
	    {1, 5, 2},
	    {5, 9, 5},
	    {6, 5, 3},
	};
	int a10[3][3] = {
	    {3, 0, 8},
	    {1, 8, 0},
	    {1, 3, 8},
	};
	int a11[3][3] = {
	    {3, 3, 0},
	    {5, 1, 9},
	    {9, 9, 5},
	};
	int a12[3][3] = {
	    {2, 4, 5},
	    {5, 3, 4},
	    {4, 4, 8},
	};
	int a13[3][3] = {
	    {3, 0, 3},
	    {8, 3, 5},
	    {8, 3, 4},
	};

	assert(sevens(a1) == 3);
	assert(sevens(a2) == 1);
	assert(sevens(a3) == 9);
	assert(sevens(a4) == 0);
	assert(sevens(a5) == 1);
	assert(sevens(a6) == 2);
	assert(sevens(a7) == 2);
	assert(sevens(a8) == 3);
	assert(sevens(a9) == 4);
	assert(sevens(a10) == 4);
	assert(sevens(a11) == 5);
	assert(sevens(a12) == 6);
	assert(sevens(a13) == 9);

	return 0;
}
