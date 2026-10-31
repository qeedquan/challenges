/*

There are buckets buckets of liquid, where exactly one of the buckets is poisonous. To figure out which one is poisonous, you feed some number of (poor) pigs the liquid to see whether they will die or not.
Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

Choose some live pigs to feed.
For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.
Wait for minutesToDie minutes. You may not feed any other pigs during this time.
After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
Repeat this process until you run out of time.
Given buckets, minutesToDie, and minutesToTest, return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.

Example 1:

Input: buckets = 1000, minutesToDie = 15, minutesToTest = 60
Output: 5
Example 2:

Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2
Example 3:

Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
Constraints:

1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100

*/

#include <assert.h>
#include <math.h>

int
poorpigs(int buckets, int minutes_to_die, int minutes_to_test)
{
	int state;

	state = (minutes_to_test / minutes_to_die) + 1;
	return ceil(log(buckets) / log(state));
}

int
main(void)
{
	assert(poorpigs(1000, 15, 60) == 5);
	assert(poorpigs(4, 15, 15) == 2);
	assert(poorpigs(4, 15, 30) == 2);

	return 0;
}
