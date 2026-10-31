/*

In Russia we have something like a tradition: we like to look for lucky tickets.

Here's what a regular ticket looks like:

https://i.sstatic.net/0bqM1m.jpg

As you can see, the ticket has a six-digit number.

A six-digit number is considered lucky if the sum of the first three digits is equal to the sum of the last three.

The number on the photo is not lucky:

038937
038 937
0 + 3 + 8 = 11
9 + 3 + 7 = 19
11 != 19
Challenge
Given the limits of a range (inclusive), return the number of lucky ticket numbers contained within it.

Parameters
Input: 2 integers: the first and last integers in the range
The inputs will be between 0 and 999999 inclusive
Output: 1 integer: how many lucky numbers are in the range
You may take the inputs and return the output in any acceptable format
Assume leading zeros for numbers less than 100000.
Examples
0, 1 => 1
100000, 200000 => 5280
123456, 654321 => 31607
0, 999999 => 55252
This is code-golf so the shortest answer in bytes in every language wins.

Update: here's the lucky one
https://i.sstatic.net/a5RK9.jpg

*/

#include <cassert>

typedef unsigned long long uvlong;

uvlong lucky(uvlong n)
{
	uvlong a = (n % 10) +
			   (n / 10) % 10 +
			   (n / 100) % 10;

	uvlong b = (n / 1000) % 10 +
			   (n / 10000) % 10 +
			   (n / 100000) % 10;

	return a == b;
}

uvlong count(uvlong m, uvlong n)
{
	uvlong c = 0;
	for (uvlong i = m; i <= n; i++)
		c += lucky(i);
	return c;
}

int main()
{
	assert(count(0, 1) == 1);
	assert(count(100000, 200000) == 5280);
	assert(count(123456, 654321) == 31607);
	assert(count(0, 999999) == 55252);

	return 0;
}
