/*

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:

Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3


Constraints:

2 <= s.length <= 500
The string s consists of characters '0' and '1' only.

Hint 1
Precompute a prefix sum of ones ('1').

Hint 2
Iterate from left to right counting the number of zeros ('0'), then use the precomputed prefix sum for counting ones ('1'). Update the answer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxscore(const char *input)
{
	int zeros;
	int ones;
	int result;
	size_t index;
	size_t length;

	length = strlen(input);
	if (length == 0)
		return 0;

	result = 0;
	zeros = 0;
	ones = 0;
	for (index = 1; index + 1 < length; index++) {
		if (input[index] == '0')
			zeros += 1;
		else
			ones += 1;

		result = max(result, zeros - ones);
	}

	result += ones;
	if (input[0] == '0')
		result += 1;
	if (input[length - 1] == '1')
		result += 1;

	return result;
}

int
main()
{
	assert(maxscore("011101") == 5);
	assert(maxscore("00111") == 5);
	assert(maxscore("1111") == 3);

	return 0;
}
