/*

You are given a 0-indexed array of string words and two integers left and right.

A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.

Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

Example 1:

Input: words = ["are","amy","u"], left = 0, right = 2
Output: 2
Explanation:
- "are" is a vowel string because it starts with 'a' and ends with 'e'.
- "amy" is not a vowel string because it does not end with a vowel.
- "u" is a vowel string because it starts with 'u' and ends with 'u'.
The number of vowel strings in the mentioned range is 2.
Example 2:

Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
Output: 3
Explanation:
- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
- "mu" is not a vowel string because it does not start with a vowel.
- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
The number of vowel strings in the mentioned range is 3.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 10
words[i] consists of only lowercase English letters.
0 <= left <= right < words.length

Hint 1
consider iterating over all strings from left to right and use an if condition to check if the first character and last character are vowels.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

size_t
vowelstrings(const char **words, size_t left, size_t right)
{
	const char *word;
	size_t length;
	size_t index;
	size_t count;

	count = 0;
	for (index = left; index <= right; index++) {
		word = words[index];
		length = strlen(word);
		if (isvowel(word[0]) && isvowel(word[length - 1]))
			count += 1;
	}
	return count;
}

int
main()
{
	const char *words1[] = { "are", "amy", "u" };
	const char *words2[] = { "hey", "aeo", "mu", "ooo", "artro" };

	assert(vowelstrings(words1, 0, 2) == 2);
	assert(vowelstrings(words2, 1, 4) == 3);

	return 0;
}
