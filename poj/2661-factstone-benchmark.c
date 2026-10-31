/*

Description

Amtel has announced that it will release a 128-bit computer chip by 2010, a 256-bit computer by 2020, and so on, continuing its strategy of doubling the word-size every ten years. (Amtel released a 64-bit computer in 2000, a 32-bit computer in 1990, a 16-bit computer in 1980, an 8-bit computer in 1970, and a 4-bit computer, its first, in 1960.)
Amtel will use a new benchmark - the Factstone - to advertise the vastly improved capacity of its new chips. The Factstone rating is defined to be the largest integer n such that n! can be represented as an unsigned integer in a computer word.
Given a year 1960 <= y <= 2160, what will be the Factstone rating of Amtel's most recently released chip?

Input

There are several test cases. For each test case, there is one line of input containing y. A line containing 0 follows the last test case.

Output

For each test case, output a line giving the Factstone rating.

Sample Input

1960
1981
0

Sample Output

3
8

Source

Waterloo local 2005.09.24

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
factstone(int y)
{
	double s, t;
	int c;

	c = 1;
	t = pow(2, 2 + ((y - 1960) / 10.0));
	for (s = 0; s < t; s += log2(c))
		c++;
	return c - 1;
}

int
main(void)
{
	assert(factstone(1960) == 3);
	assert(factstone(1981) == 8);

	return 0;
}
