/*

Task
A person is moving along a straight line. Initially he is at point A. He goes to point B from A with speed equal to 1 meter per second. Immediately after reaching B he turns around and heads to A from B with the same speed. After reaching point A he turns around once again and heads to B. etc.

We need an algorithm that identifies the location of the person at any given moment in time(argument t).

It's guaranteed that A and B are two different points.

Input/Output
[input] integer a

Coordinate of point A (in meters).

1 ≤ a ≤ 10^9.

[input] integer b

Coordinate of point B (in meters).

1 ≤ b ≤ 10^9,

b ≠ a.

[input] integer t

A positive integer representing time (in seconds).

3 ≤ t ≤ 10^9.

[output] an integer

Coordinate of the person t seconds after he left A.

Example
For a = 2, b = 4 and t = 3, the output should be 3.


t-->From A to B  0  1  2
                    3     <--B back to A
                 A  |  B
  line --> .--.--.--.--.--.--.--.--.
           0  1  2  3  4  5  6  7  8
For a = 1, b = 10 and t = 8, the output should be 9.


t-->From A to B   0  1  2  3  4  5  6  7  8
                  A                       |  B
      line --> .--.--.--.--.--.--.--.--.--.--.--.
               0  1  2  3  4  5  6  7  8  9 10 11

*/

#include <assert.h>
#include <stdlib.h>

int
tofrom(int a, int b, int t)
{
	int d, p, r;

	d = abs(a - b);
	if (d == 0)
		return 0;

	p = t / d;
	r = t % d;
	if (!(p & 1))
		return (a > b) ? a - r : a + r;
	return (b > a) ? b - r : b + r;
}

int
main()
{
	assert(tofrom(2, 4, 3) == 3);
	assert(tofrom(1, 10, 8) == 9);
	assert(tofrom(10, 4, 8) == 6);
	assert(tofrom(2, 4, 5) == 3);
	assert(tofrom(42, 150, 548) == 142);
	assert(tofrom(94, 81, 65) == 81);

	return 0;
}
