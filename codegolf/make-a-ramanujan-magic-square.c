/*

Background
As you maybe know Ramanujan made this magic square by 4x4
https://i.ytimg.com/vi/pWutwQkqV3g/hqdefault.jpg

This works like all magic squares.
But the special thing in this square is that his birthdate is hidden in the first row, the 22nd Dec 1887.

Challenge
Can you make one for your birthdate?

Input
The User will give Input in this format: DD/MM/yyYY.
The input can't be a list of 3 numbers([DD,MM,yyYY]).

Here is the formula to make a square for your birthdate
https://i.sstatic.net/KT9od.png

Output
The output should be a "unnormal" or special square, in your languages equivalent for a list.
Note: These are not really magic squares, because as Abigail mentioned tin some dates there are duplicate numbers, but every row, column and diagonal there will e the same number of sum

Test cases:
In: 20/08/2000
Out:
[20, 8, 20, 0]
[1, 19, 5, 23]
[6, 22, 2, 18]
[21, -1, 21, 7]

In: 10/01/2020
Out:
[10, 1, 20, 20]
[21, 19, -2, 13]
[-1, 12, 22, 18]
[21, 19, 11, 0]

In: 10/05/2020
Out:
[10, 5, 20, 20]
[21, 19, 2, 13]
[3, 12, 22, 18]
[21, 19, 11, 4]

In: 00/00/0000
Out:
[0, 0, 0, 0]
[1, -1, -3, 3]
[-2, 2, 2, -2]
[1, -1, 1, -1]

Rules
This is code-golf, so the shortest code wins

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef int mat4[4][4];

int
rmsb(mat4 m, const char *s)
{
	int D, M, y, Y;

	if (sscanf(s, "%02d/%02d/%02d%02d", &D, &M, &y, &Y) != 4)
		return -1;

	m[0][0] = D;
	m[0][1] = M;
	m[0][2] = y;
	m[0][3] = Y;

	m[1][0] = Y + 1;
	m[1][1] = y - 1;
	m[1][2] = M - 3;
	m[1][3] = D + 3;

	m[2][0] = M - 2;
	m[2][1] = D + 2;
	m[2][2] = Y + 2;
	m[2][3] = y - 2;

	m[3][0] = y + 1;
	m[3][1] = Y - 1;
	m[3][2] = D + 1;
	m[3][3] = M - 1;

	return 0;
}

void
test(const char *s, mat4 r)
{
	mat4 m;

	assert(rmsb(m, s) >= 0);
	assert(!memcmp(r, m, sizeof(m)));
}

int
main()
{
	mat4 m1 = {
	    {20, 8, 20, 0},
	    {1, 19, 5, 23},
	    {6, 22, 2, 18},
	    {21, -1, 21, 7},
	};

	mat4 m2 = {
	    {10, 1, 20, 20},
	    {21, 19, -2, 13},
	    {-1, 12, 22, 18},
	    {21, 19, 11, 0},
	};

	mat4 m3 = {
	    {10, 5, 20, 20},
	    {21, 19, 2, 13},
	    {3, 12, 22, 18},
	    {21, 19, 11, 4},
	};

	mat4 m4 = {
	    {0, 0, 0, 0},
	    {1, -1, -3, 3},
	    {-2, 2, 2, -2},
	    {1, -1, 1, -1},
	};

	test("20/08/2000", m1);
	test("10/01/2020", m2);
	test("10/05/2020", m3);
	test("00/00/0000", m4);

	return 0;
}
