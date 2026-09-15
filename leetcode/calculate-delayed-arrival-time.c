/*

You are given a positive integer arrivalTime denoting the arrival time of a train in hours, and another positive integer delayedTime denoting the amount of delay in hours.

Return the time when the train will arrive at the station.

Note that the time in this problem is in 24-hours format.

Example 1:

Input: arrivalTime = 15, delayedTime = 5
Output: 20
Explanation: Arrival time of the train was 15:00 hours. It is delayed by 5 hours. Now it will reach at 15+5 = 20 (20:00 hours).

Example 2:

Input: arrivalTime = 13, delayedTime = 11
Output: 0
Explanation: Arrival time of the train was 13:00 hours. It is delayed by 11 hours. Now it will reach at 13+11=24 (Which is denoted by 00:00 in 24 hours format so return 0).

Constraints:

    1 <= arrivaltime < 24
    1 <= delayedTime <= 24

Hint 1
Use the modulo operator to handle the case when the arrival time plus the delayed time goes beyond 24 hours.

Hint 2
If the arrival time plus the delayed time is greater than or equal to 24, you can also subtract 24 to get the time in the 24-hour format.

*/

#include <assert.h>

int
find_delayed_arrival_time(int arrival, int delayed)
{
	return (arrival + delayed) % 24;
}

int
main()
{
	assert(find_delayed_arrival_time(15, 5) == 20);
	assert(find_delayed_arrival_time(13, 11) == 0);

	return 0;
}
