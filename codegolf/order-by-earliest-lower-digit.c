/*

Given two strings of digits, determine which string, if any, has the earliest digit which is lower than the other string's digit at the same index.

Do note that this differs from alphabetization, as shown in the following examples:

Examples
Given inputs 12345000 and 1233999999, the second string would have the earliest lower digit.

12345000
1233999999
^          same value
 ^         same value
  ^        same value
   ^       second is lower
    ^^^^^^ irrelevant
Given strings 99 and 998, neither has the earliest lowest digit, since 99 equals 99, and the 8 has no digit to compare against.

99
998
^   same value
 ^  same value
  ^ irrelevant
Additional specification
Input/output can be taken/given in any reasonable format.
You can output any three consistent values to represent choosing the first input, the second input, or neither. (similar to decision-problem)
Alternatively, you may use the standard output method of three-way comparison of your language of choice (if one exists)
You may assume that there will be no leading 0s in input.
This is code-golf, so shortest code in bytes wins.

Test cases
Output is in the form < for first input, > for second input, and = for equal.

 999   999 =
 115   116 <
 116   115 >
 870   789 >
  33  3333 =
3333    33 =
  20  2100 <
  19  1200 >
2100    20 >
1200    19 <
1234  1234 =
4321  5432 <
5678  5432 >
  99   998 =
12345000  1233999999 >

*/

#include <assert.h>
#include <stdio.h>

int
cmp(const char *s, const char *t)
{
	size_t i;

	for (i = 0; s[i] && t[i]; i++) {
		if (s[i] < t[i])
			return '<';
		if (s[i] > t[i])
			return '>';
	}
	return '=';
}

int
main(void)
{
	assert(cmp("999", "999") == '=');
	assert(cmp("115", "116") == '<');
	assert(cmp("116", "115") == '>');
	assert(cmp("870", "789") == '>');
	assert(cmp("33", "3333") == '=');
	assert(cmp("20", "2100") == '<');
	assert(cmp("19", "1200") == '>');
	assert(cmp("2100", "20") == '>');
	assert(cmp("1200", "19") == '<');
	assert(cmp("1234", "1234") == '=');
	assert(cmp("4321", "5432") == '<');
	assert(cmp("5678", "5432") == '>');
	assert(cmp("99", "998") == '=');
	assert(cmp("12345000", "1233999999") == '>');

	return 0;
}
