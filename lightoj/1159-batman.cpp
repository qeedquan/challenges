/*

Batman is in deep trouble. You know that superheroes are there to help you when you are in trouble. But in Gotham city there is no trouble. So, 'no trouble' is actually the trouble for our Batman.

So, Batman is trying to solve ACM problems because he wants to be a good programmer like you :). But alas! He is not that smart. But still he is trying. He found 3 strings of characters. Now he wants to find the maximum string which is contained in all the three strings as a sub sequence. He wants to find the maximum length, not the sequence.

Now, Batman claims that he is a better programmer than you. So, you are solving the same problem. Can you solve faster? You are guaranteed that Batman will need 3 hours to solve the problem. So, you have to be faster than him.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case will contain a blank line and three non-empty strings in three lines containing only alphanumeric characters. Lengths of the strings will not be greater than 50.

Output
For each case, print one line containing the case number and the length of the largest subsequence.

Sample
Input	Output
3

abcdef
cdef
dcdef

aaaa
bbbb
ccca

aaaa
aaaa
aaa

Case 1: 4
Case 2: 0
Case 3: 3

*/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

size_t lcs(const string &s1, const string &s2, const string &s3)
{
	auto n1 = s1.size();
	auto n2 = s2.size();
	auto n3 = s3.size();

	vector<vector<vector<size_t> > > dp;
	dp.resize(n1 + 1);
	for (size_t i = 0; i <= n1; i++)
	{
		dp[i].resize(n2 + 1);
		for (size_t j = 0; j <= n2; j++)
			dp[i][j].resize(n3 + 1);
	}

	for (size_t i = 0; i <= n1; i++)
	{
		for (size_t j = 0; j <= n2; j++)
		{
			for (size_t k = 0; k <= n3; k++)
			{
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 0;
				else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
			}
		}
	}
	return dp[n1][n2][n3];
}

int main()
{
	assert(lcs("abcdef", "cdef", "dcdef") == 4);
	assert(lcs("aaaa", "bbbb", "ccca") == 0);
	assert(lcs("aaaa", "aaaa", "aaa") == 3);

	return 0;
}
