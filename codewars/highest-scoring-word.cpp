/*

Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

For example, the score of abad is 8 (1 + 2 + 1 + 4).

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.

*/

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

string highest_scoring_word(const string &input)
{
	string result = "";
	string word = "";
	auto highscore = 0;
	auto score = 0;
	for (auto symbol : input)
	{
		if (isspace(symbol))
		{
			if (score > highscore)
			{
				result = word;
				highscore = score;
			}
			word = "";
			score = 0;
		}
		else if ('a' <= symbol && symbol <= 'z')
		{
			word += symbol;
			score += symbol - 'a' + 1;
		}
	}

	if (score > highscore)
		result = word;

	return result;
}

int main()
{
	assert(highest_scoring_word("man i need a taxi up to ubud") == "taxi");
	assert(highest_scoring_word("what time are we climbing up the volcano") == "volcano");
	assert(highest_scoring_word("take me to semynak") == "semynak");
	assert(highest_scoring_word("massage yes massage yes massage") == "massage");
	assert(highest_scoring_word("take two bintang and a dance please") == "bintang");
	assert(highest_scoring_word("aa b") == "aa");

	return 0;
}
