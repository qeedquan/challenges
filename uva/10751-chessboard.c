/*

A king wishes to go for a walk of a square chessboard with the following conditions:
• Each two consequent cells of the path must be adjacent, i.e., share an edge or a corner (thus, a
cell may have up to eight adjacent cells).
• Each cell must be visited exactly once; the first and the last cells of the path must coincide (thus,
the first cell of the path will be actually visited twice).
• The path must have no self intersections (we may think of a path as a closed polyline with vertices
at cells’ centers).
Your task is to find the maximal possible length of a king’s path (here we mean the length of the
polyline, not the number of king’s moves).

Input
The first line of the input contains the number of the test cases, which is at most 20. The descriptions
of the test cases follow. Each test case description consists of an integer N (1 ≤ N ≤ 300), denoting
the size of the chessboard. The test cases are separated by blank lines.

Output
For each test case in the input, output a line containing the length of the king’s tour with at least three
digits after the decimal point. Print a blank line between test cases. The cells have side 1.

Sample Input
3
1
2
3

Sample Output
0.000
4.000
9.414

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))

double
solve(int n)
{
	if (n < 2)
		return 0;
	return ((4 * n) - 4) + (M_SQRT2 * sqr(n - 2));
}

int
main()
{
	printf("%f\n", solve(1));
	printf("%f\n", solve(2));
	printf("%f\n", solve(3));

	return 0;
}
