/*

Any square is a rectangle, any rectangle is a quadrangle, and any quadrangle is composed of four sides.
But not all rectangles are squares, not all quadrangles are rectangles, and not all sets of four sides are quadrangles.
We have the length of four sides. You have to determine if they can form a square.
If not, determine if they can form a rectangle. If not, determine if they can form a quadrangle.

Input
The first line of the input contains an integer indicating the number of test cases.
For each test case, there is a line with four positive integer numbers, between 0 and 2^30.

Output
For each test case, the output should consist of a line with the text ‘square’, ‘rectangle’, ‘quadrangle’ or ‘banana’, if the sides of the corresponding case can form a square, a rectangle, a quadrangle or none, respectively.

Sample Input
4
10 8 7 6
9 1 9 1
29 29 29 29
5 12 30 7

Sample Output
quadrangle
rectangle
square
banana

*/

#include <assert.h>
#include <string.h>

const char *
shape(int a, int b, int c, int d)
{
	if (a == b && b == c && c == d)
		return "square";
	if (a == c && b == d)
		return "rectangle";
	if ((a + b + c > d) && (a + b + d > c) && (a + c + d > b) && (b + c + d > a))
		return "quadrangle";
	return "banana";
}

int
main(void)
{
	assert(!strcmp(shape(10, 8, 7, 6), "quadrangle"));
	assert(!strcmp(shape(9, 1, 9, 1), "rectangle"));
	assert(!strcmp(shape(29, 29, 29, 29), "square"));
	assert(!strcmp(shape(5, 12, 30, 7), "banana"));

	return 0;
}
