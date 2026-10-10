/*

Note: This is inspired by this question by @Willbeing where task was to count the number of perfect plates of a certain length, but it's slightly different.

We call a perfect licence plate that plate whose text satisfies the following conditions:

It consists of characters, which can either be uppercase letters([A-Z]) or digits([0-9])
Summing the positions of its letters in the English alphabet, 1-indexed (i.e: A=1,B=2,...,Z=26) gives an integer n
Getting each chunk of digits, summing them and then multiplying all the results gives the same result, n
n is a perfect square (e.g: 49 (72), 16 (42))
A nearly perfect licence plate meets the conditions for a perfect licence plate, except that n is not a perfect square.

Input
A string representing the text of the licence plate, taken as input in any standard form, except for hardcoding.

Output
If the given string represents a nearly perfect licence plate, return a truthy value (e.g: True / 1), otherwise return a falsy value (e.g: False / 0). Any standard form of output is accepted while taking note that this loopholes are strictly forbidden.

Examples
licence plate -> output


A1B2C3 -> 1

A + B + C = 1 + 2 + 3 = 6
1 * 2 * 3 = 6
6 is not a perfect square, 6 = 6 => nearly perfect plate

01G61 -> 1

(0 + 1) * (6 + 1) = 7
G = 7
7 is not a perfect square, 7 = 7 => nearly perfect plate

11BB2 -> 0

(1 + 1) * 2 = 4
B + B = 2 + 2 = 4
4 = 4, but 4 is the square of 2 => perfect license plate (not what we want)

67FF1 -> 0

(6 + 7) * 1 = 13
F + F = 6 + 6 = 12
12 != 13 => not perfect at all!

Scoring

This is code-golf, so the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

bool
npl(const char *s)
{
	unsigned x, y, z, f;
	size_t i;

	x = y = f = 0;
	for (i = 0; s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			x += s[i] - 'A' + 1;
		} else if ('0' <= s[i] && s[i] <= '9') {
			for (z = s[i] - '0'; isdigit(s[i + 1]); i++)
				z += s[i + 1] - '0';

			y = (f) ? (y * z) : z;
			f = 1;
		} else
			return false;
	}

	if (x != y)
		return false;

	z = sqrt(x);
	return x != (z * z);
}

int
main(void)
{
	assert(npl("A1B2C3") == true);
	assert(npl("01G61") == true);
	assert(npl("11BB2") == false);
	assert(npl("67FF1") == false);
	assert(npl("A") == false);

	return 0;
}
