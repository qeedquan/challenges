/*

**Problem Description:**

A snail is crawling along a rubber band that has an initial length of x units. The snail moves at a constant speed of y units
per minute. As the snail crawls from the left end of the rubber band to the right end, the rubber band increases in length from the right
side every minute, adding z units to its length.

The question is: Will the snail be able to reach the right end of the rubber band within 1 year?

**Parameters:**

- x: Initial length of the rubber band (in units), where 0.01 ≤ x ≤ 1,000,000.
- y: Speed of the snail (in units per minute), where 0.01 ≤ y ≤ 1,000,000.
- z: Amount by which the rubber band increases in length every minute (in units), where 0.01 ≤ z ≤ 1,000,000.

**Examples:**

1. **Example 1:**

- Initial length of the rubber band: x = 10 units
- Speed of the snail: y = 2 units/minute
- Increase rate of the rubber band: z = 1 unit/minute
- **Outcome:** True (The snail will reach the end in 10 minutes.)

2. **Example 2:**

- Initial length of the rubber band: x = 100 units
- Speed of the snail: y = 1 unit/minute
- Increase rate of the rubber band: z = 2 units/minute
- **Outcome:** False (The snail will never reach the end.)

3. **Example 3:**

- Initial length of the rubber band: x = 100,000 units
- Speed of the snail: y = 0.1 units/minute
- Increase rate of the rubber band: z = 0.05 units/minute
- **Outcome:** False (The snail will not be able to reach the end within one year.)q

*/

#include <assert.h>

bool
reachend(double length, double speed, double length_increases)
{
	return (speed - length_increases) > (length / 525600);
}

int
main()
{
	assert(reachend(10, 2, 1) == true);
	assert(reachend(100, 10, 5) == true);
	assert(reachend(50, 5, 1) == true);
	assert(reachend(1000, 100, 10) == true);
	assert(reachend(1, 0.1, 0.01) == true);

	assert(reachend(100, 1, 2) == false);
	assert(reachend(100000, 0.1, 0.05) == false);
	assert(reachend(100, 0.5, 1) == false);
	assert(reachend(1000, 1, 2) == false);
	assert(reachend(500, 5, 10) == false);
	assert(reachend(10000, 0.1, 1) == false);
	assert(reachend(65523.45, 656330.6, 832119.73) == false);

	return 0;
}
