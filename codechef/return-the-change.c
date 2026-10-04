/*

In Chefland, denominations less than rupees 10 have stopped and now rupees 10 is the smallest denomination.

Suppose Chef goes to buy some item with cost not a multiple of 10 then, he will be charged the cost that is the nearest multiple of 10.
If the cost is equally distant from two nearest multiples of 10, then the cost is rounded up.

For example,
35,38,40,44 are all rounded to 40.

Chef purchased an item having cost X (X <= 100) and gave a bill of rupees 100. How much amount will he get back?

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of a single integer X, the cost of the item.

Output Format
For each test case, output the amount returned to Chef.

Constraints
1 <= T <= 100
1 <= X <= 100

Sample 1:
Input
4
35
54
80
12

Output
60
50
20
90

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
change(int n)
{
	int x0, x1, x;
	int d0, d1;

	if (n < 0 || n > 100)
		return 0;

	x0 = 10 * (n / 10);
	x1 = x0 + 10;

	d0 = abs(n - x0);
	d1 = abs(n - x1);
	x = (d0 < d1) ? x0 : x1;

	return 100 - x;
}

int
main(void)
{
	assert(change(35) == 60);
	assert(change(54) == 50);
	assert(change(80) == 20);
	assert(change(12) == 90);
	assert(change(99) == 0);

	return 0;
}
