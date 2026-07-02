/*

Task
Take in 3 inputs. The length of the wall, the height of the wall and the coverage of the paint. Output how many tins of paint are required.

Output
Since there's no way to purchase 1/3 tin of paint, you'll need to round the amount of paint tins up to the nearest integer.

Assumptions/Stipulations
Only 1 coat of paint is required
Round up in terms of paint tins required

Test Cases
Length: 20 meters | Height: 7 meters | Coverage: 12 meters = 12 tins of paint

Input	Output
1/1/10	1
5/5/10	3
2/3/8	1
5/8/8	5
45/5/18	13
20/7/12	12
1/1/1	1
200/10/14	143

*/

#include <assert.h>

int
tins(int l, int h, int c)
{
	if (c == 0)
		return 0;
	return ((l * h) + c - 1) / c;
}

int
main(void)
{
	assert(tins(1, 1, 10) == 1);
	assert(tins(5, 5, 10) == 3);
	assert(tins(2, 3, 8) == 1);
	assert(tins(5, 8, 8) == 5);
	assert(tins(45, 5, 18) == 13);
	assert(tins(20, 7, 12) == 12);
	assert(tins(1, 1, 1) == 1);
	assert(tins(200, 10, 14) == 143);

	return 0;
}
