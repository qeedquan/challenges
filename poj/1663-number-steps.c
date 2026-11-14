/*

Description

Starting from point (0,0) on a plane, we have written all non-negative integers 0,1,2, ... as shown in the figure. For example, 1, 2, and 3 has been written at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.

http://poj.org/images/1663_1.jpg

You are to write a program that reads the coordinates of a point (x, y), and writes the number (if any) that has been written at that point. (x, y) coordinates in the input are in the range 0...5000.

Input

The first line of the input is N, the number of test cases for this problem. In each of the N following lines, there is x, and y representing the coordinates (x, y) of a point.

Output

For each point in the input, write the number written at that point or write No Number if there is none.
Sample Input

3
4 2
6 6
3 4

Sample Output

6
12
No Number

Source

Tehran 2000

*/

#include <assert.h>

int
number(int x, int y)
{
	if (x == y || x - y == 2)
		return (x + y) - (x & 1);
	return -1;
}

int
main(void)
{
	assert(number(4, 2) == 6);
	assert(number(6, 6) == 12);
	assert(number(3, 4) == -1);
	assert(number(7, 5) == 11);
	assert(number(0, 0) == 0);
	assert(number(5, 5) == 9);
	assert(number(2, 2) == 4);

	return 0;
}
