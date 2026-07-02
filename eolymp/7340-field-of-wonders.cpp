/*

Petryk and Marichka enjoy playing the game "Field of Wonders."
In this game, Marichka writes down a word using uppercase English letters, and Petryk attempts to guess it.
Each time Petryk guesses a letter correctly, it is revealed in all positions where it appears in the word.
What is the minimum number of guesses Petryk needs to identify the entire word?

Input
A word composed of uppercase English letters (≤100 characters).

Output
The minimum number of guesses required to reveal the entire word.

Examples

Input #1
GOOGLE

Answer #1
4

*/

#include <cassert>
#include <cstdio>
#include <string>

using namespace std;

size_t solve(const string &input)
{
	bool set[256] = {};
	size_t count = 0;
	for (auto character : input)
	{
		int symbol = character & 0xff;
		if (!set[symbol])
		{
			count += 1;
			set[symbol] = true;
		}
	}
	return count;
}

int main()
{
	assert(solve("GOOGLE") == 4);

	return 0;
}
