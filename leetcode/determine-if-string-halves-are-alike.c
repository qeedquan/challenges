/*

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

Hint:
Create a function that checks if a character is a vowel, either uppercase or lowercase.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

bool
alike(const char *s)
{
	size_t i, m;
	long v;

	m = strlen(s) / 2;
	v = 0;
	for (i = 0; i < m; i++) {
		if (isvowel(s[i]))
			v++;
		if (isvowel(s[m + i]))
			v--;
	}
	return v == 0;
}

int
main(void)
{
	assert(alike("book") == true);
	assert(alike("textbook") == false);

	return 0;
}
