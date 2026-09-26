/*

The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

*/

#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

size_t power(const string &str)
{
	auto cnt = 0u;
	auto len = str.length();
	for (auto i = 0u; i < len; )
	{
		auto j = i;
		while (j < len && str[i] == str[j])
			j++;

		cnt = max(cnt, j - i);
		i = j;
	}

	return cnt;
}

int main()
{
	assert(power("leetcode") == 2);
	assert(power("abbcccddddeeeeedcba") == 5);

	return 0;
}
