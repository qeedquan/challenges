/*

There is a strange counter. At the first second, it displays the number 3.
Each second, the number displayed by decrements by 1 until it reaches 1.
In next second, the timer resets to 2xinitial_number and continues counting down.
The diagram below shows the counter values for each time t in the first three cycles:

https://s3.amazonaws.com/hr-challenge-images/22185/1469447349-bae87a5071-strange1.png

Find and print the value displayed by the counter at time t.

Function Description

Complete the strangeCounter function in the editor below.

strangeCounter has the following parameter(s):

int t: an integer
Returns

int: the value displayed at time
Input Format

A single integer, the value of t.

Constraints
1 <= t <= 10^12

Subtask
1 <= t <= 10^5 for 60% of maximum score.

Sample Input

4
Sample Output

6
Explanation

Time t=4 marks the beginning of the second cycle.
It is double the number displayed at the beginning of the first cycle: 2x3 = 6.
This is shown in the diagram in the problem statement.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

long
strange_counter(long t)
{
	long p, x, y;
	double v;

	if (t < 1)
		return 0;

	v = log2((t + 3) / 3.0);
	x = floor(v);
	y = ceil(v);
	if (x == y)
		return 1;

	p = 3 * ((1 << y) - 1);
	return p - t + 1;
}

int
main()
{
	assert(strange_counter(1) == 3);
	assert(strange_counter(2) == 2);
	assert(strange_counter(3) == 1);
	assert(strange_counter(4) == 6);
	assert(strange_counter(5) == 5);
	assert(strange_counter(6) == 4);
	assert(strange_counter(7) == 3);
	assert(strange_counter(8) == 2);
	assert(strange_counter(9) == 1);
	assert(strange_counter(10) == 12);
	assert(strange_counter(11) == 11);
	assert(strange_counter(12) == 10);
	assert(strange_counter(13) == 9);
	assert(strange_counter(14) == 8);
	assert(strange_counter(15) == 7);
	assert(strange_counter(16) == 6);
	assert(strange_counter(17) == 5);
	assert(strange_counter(18) == 4);
	assert(strange_counter(19) == 3);
	assert(strange_counter(20) == 2);
	assert(strange_counter(21) == 1);

	return 0;
}
