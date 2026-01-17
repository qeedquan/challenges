/*

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

ssize_t longest_palindrome_subseq(const string &s)
{
	ssize_t n = s.size();
	if (n == 0)
		return 0;

	vector<vector<ssize_t> > p(n, vector<ssize_t>(n, 0));
	for (auto i = n - 1; i >= 0; i--)
	{
		for (auto j = i; j < n; j++)
		{
			if (i == j)
			{
				p[i][j] = 1;
				continue;
			}

			if (s[i] == s[j])
				p[i][j] = p[i + 1][j - 1] + 2;
			else
				p[i][j] = max(p[i + 1][j], p[i][j - 1]);
		}
	}
	return p[0][n - 1];
}

int main()
{
	assert(longest_palindrome_subseq("bbbab") == 4);
	assert(longest_palindrome_subseq("cbbd") == 2);

	return 0;
}
