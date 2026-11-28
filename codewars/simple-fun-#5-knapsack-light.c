/*

Task
You found two items in a treasure chest! The first item weighs weight1 and is worth value1, and the second item weighs weight2 and is worth value2. What is the total maximum value of the items you can take with you, assuming that your max weight capacity is maxW/max_w and you can't come back for the items later?

Example
For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4 and maxW = 8, the output should be

knapsacklight(value1, weight1, value2, weight2, maxW) === 10 (or equivalent for PHP)

You can only carry the first item.

For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4 and maxW = 9, the output should be

knapsacklight(value1, weight1, value2, weight2, maxW) === 16 (or equivalent for PHP)

You're strong enough to take both of the items with you.

For value1 = 10, weight1 = 10, value2 = 6, weight2 = 10 and maxW = 9, the output should be

knapsacklight(value1, weight1, value2, weight2, maxW) === 0 (or equivalent for PHP)

Unfortunately, you're not strong enough to take any one :(

Input/Output
[input] integer value1

Constraints: 2 ≤ value1 ≤ 50.

[input] integer weight1

Constraints: 2 ≤ weight1 ≤ 30.

[input] integer value2

Constraints: 2 ≤ value2 ≤ 50.

[input] integer weight2

Constraints: 2 ≤ weight2 ≤ 30.

[input] integer maxW/max_w

Constraints: 1 ≤ maxW ≤ 50.

[output] an integer

*/

#include <assert.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
knapsacklight(int value1, int weight1, int value2, int weight2, int maxweight)
{
	int sum;

	if (value1 < value2) {
		swap(&value1, &value2);
		swap(&weight1, &weight2);
	}

	sum = 0;
	if (maxweight >= weight1) {
		sum += value1;
		maxweight -= weight1;
	}
	if (maxweight >= weight2)
		sum += value2;

	return sum;
}

int
main()
{
	assert(knapsacklight(10, 5, 6, 4, 8) == 10);
	assert(knapsacklight(10, 10, 6, 10, 9) == 0);
	assert(knapsacklight(10, 5, 6, 4, 9) == 16);
	assert(knapsacklight(10, 2, 11, 3, 1) == 0);
	assert(knapsacklight(15, 2, 20, 3, 2) == 15);
	assert(knapsacklight(2, 5, 3, 4, 5) == 3);
	assert(knapsacklight(4, 3, 3, 4, 4) == 4);
	assert(knapsacklight(3, 5, 3, 8, 10) == 3);

	return 0;
}
