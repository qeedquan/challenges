/*

Company abc have been badly hit by recession and is taking a lot of cost cutting measures.
Some of these measures include giving up office space, going open source, reducing incentives, cutting on luxuries and issuing pink slips.
They have got three (3) employees working in the accounts department and are going to lay-off two (2) of them.
After a series of meetings, they have decided to dislodge the person who gets the most salary and the one who gets the least.
This is usually the general trend during crisis like this.
bou will be given the salaries of these 3 employees working in the accounts department.
bou have to find out the salary of the person who survives.

Input
The first line of input is an integer T (T < 20) that indicates the number of test cases. Each case
consists of a line with 3 distinct positive integers. These 3 integers represent the salaries of the three
employees. All these integers will be in the range [1000, 10000].

Output
For each case, output the case number followed by the salary of the person who survives.

Sample Input
3
1000 2000 3000
3000 2500 1500
1500 1200 1800

Sample Output
Case 1: 2000
Case 2: 2500
Case 3: 1500

*/

#include <assert.h>

int
salary(int a, int b, int c)
{
	if ((a > b && a < c) || (a > c && a < b))
		return a;
	if ((b < a && b > c) || (b < c && b > a))
		return b;
	return c;
}

int
main(void)
{
	assert(salary(1000, 2000, 3000) == 2000);
	assert(salary(3000, 2500, 1500) == 2500);
	assert(salary(1500, 1200, 1800) == 1500);

	return 0;
}
