/*

This is the inverse of Let's do some "deciph4r4ng"

In this challenge, your task is to encipher a string. Luckily, the algorithm is pretty simple: reading from left to right, each typical writing character (ASCII range 32-126) must be replaced by a number N (0-9) to indicate that it is the same as the character N+1 positions before it. The exception is when the character does not appear within the previous 10 positions in the original string. In that case, you should simply print the character again. Effectively, you should be able to reverse the operation from the original challenge.

Example
The input string "Programming" would be encoded this way:

https://i.sstatic.net/WWdbF.png


Hence, the expected output is "Prog2am0in6".

Clarifications and rules
The input string will contain ASCII characters in the range 32 - 126 exclusively. You can assume that it will never be empty.
The original string is guaranteed not to contain any digit.
Once a character has been encoded, it may in turn be referenced by a subsequent digit. For instance, "alpaca" should be encoded as "alp2c1".
References will never wrap around the string: only previous characters can be referenced.
You can write either a full program or a function, which either prints or outputs the result.
This is code golf, so the shortest answer in bytes wins.
Standard loopholes are forbidden.
Test cases
Input : abcd
Output: abcd

Input : aaaa
Output: a000

Input : banana
Output: ban111

Input : Hello World!
Output: Hel0o W2r5d!

Input : this is a test
Output: this 222a19e52

Input : golfing is good for you
Output: golfin5 3s24o0d4f3r3y3u

Input : Programming Puzzles & Code Golf
Output: Prog2am0in6 Puz0les7&1Cod74G4lf

Input : Replicants are like any other machine. They're either a benefit or a hazard.
Output: Replicants 4re3lik448ny3oth8r5mac6in8.8T64y'r371it9376a1b5n1fit7or2a1h2z17d.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
encipher(const char *input, char *output)
{
	size_t position[256];
	size_t location;
	size_t index;
	int symbol;

	memset(position, 0, sizeof(position));
	for (location = 0; input[location]; location++) {
		symbol = input[location] & 0xff;
		index = location + 1;

		if (position[symbol] && index - position[symbol] <= 10)
			output += sprintf(output, "%zu", index - position[symbol] - 1);
		else
			*output++ = symbol;

		position[symbol] = index;
	}
	*output = '\0';
}

void
test(const char *input, const char *expected)
{
	char output[128];

	encipher(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("abcd", "abcd");
	test("aaaa", "a000");
	test("banana", "ban111");
	test("Hello World!", "Hel0o W2r5d!");
	test("this is a test", "this 222a19e52");
	test("golfing is good for you", "golfin5 3s24o0d4f3r3y3u");
	test("Programming Puzzles & Code Golf", "Prog2am0in6 Puz0les7&1Cod74G4lf");
	test("Replicants are like any other machine. They're either a benefit or a hazard.", "Replicants 4re3lik448ny3oth8r5mac6in8.8T64y'r371it9376a1b5n1fit7or2a1h2z17d.");

	return 0;
}
