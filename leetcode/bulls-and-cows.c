/*

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"

Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

Constraints:

1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
hint(const char *s, const char *g, char *b)
{
	int c1[10], c2[10];
	int d1, d2;
	size_t x, y;
	size_t i;

	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	for (i = x = y = 0; s[i]; i++) {
		d1 = s[i] - '0';
		d2 = g[i] - '0';
		if (d1 == d2)
			x += 1;
		else {
			c1[d1] += 1;
			c2[d2] += 1;
		}
	}

	for (i = 0; i < 10; i++)
		y += min(c1[i], c2[i]);

	sprintf(b, "%zuA%zuB", x, y);
}

void
test(const char *s, const char *g, const char *r)
{
	char b[64];

	hint(s, g, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1807", "7810", "1A3B");
	test("1123", "0111", "1A1B");

	return 0;
}
