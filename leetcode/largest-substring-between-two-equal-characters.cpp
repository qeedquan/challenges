/*

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
 

Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

ssize_t max_length_between_equal_characters(const string &input)
{
	ssize_t start[256] = {};
	ssize_t longest = -1;
	ssize_t offset = 0;
	for (auto symbol : input)
	{
		auto index = symbol & 0xff;
		if (!start[index])
			start[index] = offset + 1;
		else
			longest = max(longest, offset - start[index]);

		offset += 1;
	}
	return longest;
}

int main()
{
	assert(max_length_between_equal_characters("aa") == 0);
	assert(max_length_between_equal_characters("abca") == 2);
	assert(max_length_between_equal_characters("cbzxy") == -1);
	assert(max_length_between_equal_characters("cabbac") == 4);

	return 0;
}
