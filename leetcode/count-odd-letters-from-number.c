/*

You are given an integer n. Your task is to:

Convert each digit of n into its corresponding lowercase English word:

0 → "zero"
1 → "one"
2 → "two"
3 → "three"
4 → "four"
5 → "five"
6 → "six"
7 → "seven"
8 → "eight"
9 → "nine"
Concatenate these words in the same order as the digits appear in n to form a string s.

Count how many distinct characters in s appear an odd number of times.

For example, if n = 123:

The digits are 1, 2, 3
Converting to words: "one", "two", "three"
Concatenated string s = "onetwothree"
Character frequencies:
'o' appears 2 times (even)
'n' appears 1 time (odd)
'e' appears 3 times (odd)
't' appears 2 times (even)
'w' appears 1 time (odd)
'h' appears 1 time (odd)
'r' appears 1 time (odd)
Distinct characters with odd frequency: 'n', 'e', 'w', 'h', 'r' = 5 characters

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

typedef unsigned long ulong;

#define bit(x) (1UL << (x))

ulong
oddletters(ulong value)
{
	static const char *numbers[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};

	const char *string;
	ulong result;

	for (result = 0; value > 0; value /= 10) {
		string = numbers[value % 10];
		for (; *string; string++)
			result ^= bit(*string - 'a');
	}
	return stdc_count_ones(result);
}

int
main()
{
	assert(oddletters(123) == 5);

	return 0;
}
