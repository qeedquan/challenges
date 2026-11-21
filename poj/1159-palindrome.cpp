/*

Description

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome.

As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome.

Input

Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.

Output

Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.

Sample Input

5
Ab3bd

Sample Output

2

Source

IOI 2000

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int inserts(const string &s)
{
	auto n = s.length();
	auto dp = vector<vector<int>>(n + 2, vector<int>(n + 2));
	for (size_t i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
		dp[i][i + 1] = (s[i] == s[i + 1]) ? 0 : 1;
	}

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 0; i + j < n; j++)
		{
			if (s[j] == s[i + j])
				dp[j][i + j] = dp[j + 1][i + j - 1];
			else
				dp[j][i + j] = min(dp[j + 1][i + j], dp[j][i + j - 1]) + 1;
		}
	}
	return dp[0][n - 1];
}

int main()
{
	assert(inserts("Ab3bd") == 2);

	return 0;
}
