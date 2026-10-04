/*

Alice and Bob are playing the game SanguoSha 1VS1.
If Alice takes a card or use a card (it may be slash, missed, peach, duel, sabotage or theft and so on) or discard
(sometimes she does not need to throw any card) we will write down an uppercase A, if Bob does this, of course, we will write down the letter B.
Tell me the length of the longest operation combo performed by either player.

Input
There are several test cases, each test case contains only a string composed of uppercase A and B.
The input will finish with the end of file. The length of the string is no more than 1000.

Output
For each case, output an integer indicating the length.

Examples
Input #1
AAABBAAAAA
AABBBBAA
AAAAAAAA

Answer #1
5
4
8

*/

#include <cassert>
#include <algorithm>

using namespace std;

size_t solve(const char *s)
{
	size_t r = 0;
	for (size_t i = 0; s[i]; i++)
	{
		auto j = i + 1;
		while (s[j] && s[j] == s[i])
			j++;
		r = max(r, j - i);
	}
	return r;
}

int main()
{
	assert(solve("AAABBAAAAA") == 5);
	assert(solve("AABBBBAA") == 4);
	assert(solve("AAAAAAAA") == 8);

	return 0;
}
