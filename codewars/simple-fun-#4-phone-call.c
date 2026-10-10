/*

Task
Some phone usage rate may be described as follows:

first minute of a call costs min1 cents,

each minute from the 2nd up to 10th (inclusive) costs min2_10 cents

each minute after 10th costs min11 cents.

You have s cents on your account before the call. What is the duration of the longest call (in minutes rounded down to the nearest integer) you can have?

Example
For min1 = 3, min2_10 = 1, min11 = 2 and s = 20, the output should be

phoneCall(min1, min2_10, min11, s) === 14

Here's why:

the first minute costs 3 cents, which leaves you with 20 - 3 = 17 cents;

the total cost of minutes 2 through 10 is 1 * 9 = 9, so you can talk 9 more minutes and still have 17 - 9 = 8 cents;

each next minute costs 2 cents, which means that you can talk 8 / 2 = 4 more minutes.

Thus, the longest call you can make is 1 + 9 + 4 = 14 minutes long.

Input/Output
[input] integer min1

Constraints: 1 ≤ min1 ≤ 10

[input] integer min2_10

Constraints: 1 ≤ min2_10 ≤ 10

[input] integer min11

Constraints: 1 ≤ min11 ≤ 10

[input] integer s

Constraints: 2 ≤ s ≤ 100

[output] an integer

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
phonecall(int m1, int m2_10, int m11, int s)
{
	int n, r;

	if (m1 < 1 || m2_10 < 1 || m11 < 1 || s < 1)
		return -1;

	r = 0;
	if (s >= m1) {
		r += 1;
		s -= m1;
	}
	if (s >= m2_10) {
		n = min(s / m2_10, 9);
		r += n;
		s -= n * m2_10;
	}
	if (r >= 10)
		r += s / m11;
	return r;
}

int
main()
{
	assert(phonecall(3, 1, 2, 20) == 14);
	assert(phonecall(2, 2, 1, 2) == 1);
	assert(phonecall(10, 1, 2, 22) == 11);
	assert(phonecall(2, 2, 1, 24) == 14);
	assert(phonecall(1, 2, 1, 6) == 3);
	return 0;
}
