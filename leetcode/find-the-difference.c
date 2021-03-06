/*

Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

*/

#include <stdio.h>

int
diffchar(const char *s, const char *t)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; s[i]; i++)
		v ^= s[i];
	for (i = 0; t[i]; i++)
		v ^= t[i];
	return v;
}

int
main(void)
{
	printf("%c\n", diffchar("abcd", "abcde"));
	printf("%c\n", diffchar("ezbinda", "debian"));
	return 0;
}
