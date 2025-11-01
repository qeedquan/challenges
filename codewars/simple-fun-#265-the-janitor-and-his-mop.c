/*

Task
In one city it is allowed to write words on the buildings walls. The local janitor, however, doesn't approve of it at all. Every night he vandalizes the writings by erasing all occurrences of some letter. Since the janitor is quite lazy, he wants to do this with just one swipe of his mop.

Given a word, find the minimum width of the mop required to erase each of the letters.

Input/Output
[input] string word

A word consisting of only lowercase English letters.

5 ≤ word.length ≤ 50

[output] an integer array

An array of length 26. The first element is the minimum width of the mop to erase letter 'a', the second - letter 'b' etc.

Example
For word = "abacaba", the output should be:

[7, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

(26 elements altogether)

First element 7 means: from first "a" to last "a" need a width of 7.

First element 5 means: from first "b" to last "b" need a width of 5.

First element 1 means: from first "c" to last "c" need a width of 1.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
wipes(const char *input, size_t output[26])
{
	size_t index;
	size_t start[26];
	bool seen[26];
	int symbol;

	memset(output, 0, sizeof(*output) * 26);
	memset(start, 0, sizeof(start));
	memset(seen, 0, sizeof(seen));
	for (index = 0; input[index]; index++) {
		symbol = input[index] & 0xff;
		if (!('a' <= symbol && symbol <= 'z'))
			continue;
		symbol -= 'a';

		if (!seen[symbol]) {
			start[symbol] = index;
			seen[symbol] = true;
		}
		output[symbol] = index + 1;
	}

	for (index = 0; index < 26; index++)
		output[index] -= start[index];
}

void
test(const char *input, size_t expected[26])
{
	size_t output[26];

	wipes(input, output);
	assert(!memcmp(output, expected, sizeof(output)));
}

int
main()
{
	size_t expected_1[] = { 7, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	size_t expected_2[] = { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	size_t expected_3[] = { 30, 27, 0, 0, 1, 29, 1, 46, 8, 1, 41, 27, 12, 0, 5, 1, 1, 20, 17, 35, 1, 1, 1, 39, 22, 37 };
	size_t expected_4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 5, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	test("abacaba", expected_1);
	test("likemm", expected_2);
	test("rkuhsxtflzvytbtwxyarsglibmhfmmikyolfmopbtkzxezjahq", expected_3);
	test("ommnommnomm", expected_4);

	return 0;
}
