/*

In many natural languages we can find some pairs of words which could be transformed to each other by changing the order of letters. I.e. they consist of the same set of letters, for example:

cat - act take - teak ate - eat - tea

Such words are called anagrams and as we see in the third example sometimes there are more than two words.

Your task is to find out the amount of anagrams for given word by the dictionary.

Click this link with right mouse button and select "Save As" to download dictionary file

Dictionary file contains a list of english words, one per line. It was taken from Ubuntu linux distribution and stripped of words containing capital letters, apostrophes and non-english letters.

Input data will contain the number of test-cases in the first line.
Next lines will contain a single word each.
Answer should contain the number of anagrams for each word (not including the word itself).

Example:

input data:
3
bat
coal
lots

answer:
1 1 2

*/

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

typedef long long vlong;

using namespace std;

vlong solve(const string &dictionary, const string &word)
{
	ifstream file(dictionary);
	if (!file.is_open())
		return -1;

	string target = word;
	sort(target.begin(), target.end());

	vlong count = 0;
	string line;
	while (getline(file, line))
	{
		if (word == line)
			continue;

		sort(line.begin(), line.end());
		if (target == line)
			count += 1;
	}
	file.close();
	return count;
}

int main()
{
	auto dictionary = "words.txt";
	assert(solve(dictionary, "bat") == 1);
	assert(solve(dictionary, "coal") == 1);
	assert(solve(dictionary, "lots") == 2);

	return 0;
}
