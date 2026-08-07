/*

The 52 week challenge is a way to save money. For example, Week 1, you save $1.00. Week 2 you save $2.00, and it continues through the year, adding one more dollar to each week’s savings goal. By Week 52, you’ll set aside $52.00, which will bring the year’s total savings to $1,378! Of course, you can decide how much money you start saving and how many weeks.

Given an amount for Week 1 and the number of weeks the challenge should run for, return the total amount saved at the end of the challenge.

Week 2 will have as twice the amount of Week 1, Week 3 will have thrice the amount of Week 1, etc.

Examples
1 and 52 weeks: 1378

5 and 6 weeks: 105

.25 and 100 weeks: 1262.5

10 and 1 week: 10

7 and 0 weeks: 0

0 and 30 weeks: 0

0 and 0 weeks: 0

*/

#include <assert.h>

double
savings(double x, int w)
{
	return x * w * (w + 1) / 2;
}

int
main(void)
{
	assert(savings(1, 52) == 1378);
	assert(savings(5, 6) == 105);
	assert(savings(.25, 100) == 1262.5);
	assert(savings(10, 1) == 10);
	assert(savings(7, 0) == 0);
	assert(savings(0, 30) == 0);
	assert(savings(0, 0) == 0);

	return 0;
}
