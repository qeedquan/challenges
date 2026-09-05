/*

You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:

Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.

Remove all characters that are not an English letter, except the first '#'.

Truncate the result to a maximum of 100 characters.

Return the tag after performing the actions on caption.

Example 1:

Input: caption = "Leetcode daily streak achieved"

Output: "#leetcodeDailyStreakAchieved"

Explanation:

The first letter for all words except "leetcode" should be capitalized.

Example 2:

Input: caption = "can I Go There"

Output: "#canIGoThere"

Explanation:

The first letter for all words except "can" should be capitalized.

Example 3:

Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Explanation:

Since the first word has length 101, we need to truncate the last two letters from the word.

Constraints:

1 <= caption.length <= 150
caption consists only of English letters and ' '.

Hint 1
Simulate as described

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
tag(const char *caption, char *result)
{
	static const size_t limit = 100;

	size_t index;
	size_t length;

	result[0] = '#';
	length = 1;
	for (index = 0; caption[index]; index++) {
		if (caption[index] == ' ')
			continue;

		if (index == 0 || caption[index - 1] == ' ')
			result[length++] = toupper(caption[index]);
		else
			result[length++] = tolower(caption[index]);

		if (length >= limit)
			break;
	}

	if (length >= 1)
		result[1] = tolower(result[1]);

	result[length] = '\0';
	return result;
}

void
test(const char *caption, const char *expected)
{
	char result[128];

	tag(caption, result);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("Leetcode daily streak achieved", "#leetcodeDailyStreakAchieved");
	test("can I Go There", "#canIGoThere");
	test("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh", "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");

	return 0;
}
