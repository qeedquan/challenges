/*

You need to hire a catering company out of three for lunch in a birthday party. The first caterer offers only a basic buffet which costs $15 per person. The second one has an economy buffet at $20 per person and the third one has a premium buffet at $30 per person. The third one gives a 20% discount if the number of persons to be served is greater than 60. You want to spend the maximum that fits into the budget.

The function takes two arguments denoting the budget in $ and the number of people. Return 1, 2 or 3 for the three caterers as per the above criteria. Return -1 if there are no people or the budget is lower than the cost of buffets from the first caterer.

Number of orders is always equal to number of people.

For example,


budget, people => (200, 9) will return 2.

budget, people => (300, 9) will return 3 and so on.

Goodluck :)

*/

#include <assert.h>

int
caterer(double budget, int people)
{
	int index;
	int cost[3];

	cost[0] = people * 15;
	cost[1] = people * 20;
	cost[2] = people * 30;
	if (people > 60)
		cost[2] *= 0.8;

	if (people < 1)
		return -1;

	for (index = 2; index >= 0; index--) {
		if (cost[index] <= budget)
			return index + 1;
	}
	return -1;
}

int
main()
{
	assert(caterer(200, 9) == 2);
	assert(caterer(300, 9) == 3);
	assert(caterer(150, 10) == 1);
	assert(caterer(1500, 60) == 2);
	assert(caterer(1500, 61) == 3);
	assert(caterer(100, 0) == -1);
	assert(caterer(200, 5) == 3);
	assert(caterer(1000, 45) == 2);
	assert(caterer(940, 70) == -1);

	return 0;
}
