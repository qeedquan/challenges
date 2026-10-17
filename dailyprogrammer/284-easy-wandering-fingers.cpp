/*

Description
Software like Swype and SwiftKey lets smartphone users enter text by dragging their finger over the on-screen keyboard, rather than tapping on each letter.

Example image of Swype

You'll be given a string of characters representing the letters the user has dragged their finger over.

For example, if the user wants "rest", the string of input characters might be "resdft" or "resert".

Input
Given the following input strings, find all possible output words 5 characters or longer.

qwertyuytresdftyuioknn

gijakjthoijerjidsdfnokg

Output
Your program should find all possible words (5+ characters) that can be derived from the strings supplied.

Use http://norvig.com/ngrams/enable1.txt as your search dictionary.

The order of the output words doesn't matter.

queen question

gaeing garring gathering gating geeing gieing going goring

Notes/Hints
Assumptions about the input strings:

QWERTY keyboard

Lowercase a-z only, no whitespace or punctuation

The first and last characters of the input string will always match the first and last characters of the desired output word

Don't assume users take the most efficient path between letters

Every letter of the output word will appear in the input string

Bonus
Double letters in the output word might appear only once in the input string, e.g. "polkjuy" could yield "polly".

Make your program handle this possibility.

Credit
This challenge was submitted by u/fj2010, thank you for this! If you have any challenge ideas please share them in r/dailyprogrammer_ideas and there's a chance we'll use them.

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// Ported from @lordtnt solution

using namespace std;

class Dict
{
public:
	bool load(const string &);
	vector<string> match_words(const string, size_t);

private:
	vector<string> &group(const string &);
	static size_t lcss(const string &, const string &);

private:
	vector<string> data[256][256];
};

int main()
{
	Dict dict;
	if (!dict.load("enable1.txt"))
	{
		cerr << "No dict!\n";
		return 1;
	}

	const string input[] = { "qwertyuytresdftyuioknn", "gijakjthoijerjidsdfnokg" };
	for (auto &s : input)
	{
		for (auto &w : dict.match_words(s, 5))
			cout << w << " ";
		cout << "\n\n";
	}
}

bool Dict::load(const string &fname)
{
	ifstream fin(fname);
	if (!fin)
		return false;
	string w;
	while (fin >> w)
		group(w).push_back(w);
	fin.close();
	return true;
}

vector<string> Dict::match_words(const string s, size_t minlen)
{
	vector<string> words;
	for (auto &w : group(s))
	{
		if (w.size() >= minlen && lcss(w, s) == w.size())
			words.push_back(w);
	}
	return words;
}

vector<string> &Dict::group(const string &s)
{
	return data[s.front() & 0xff][s.back() & 0xff];
}

size_t Dict::lcss(const string &w, const string &s)
{
	auto n = w.size();
	auto m = s.size();
	vector<vector<int> > p(n + 1, vector<int>(m + 1));
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			if (w[i - 1] == s[j - 1])
				p[i][j] = max(p[i - 1][j - 1], p[i - 1][j]) + 1;
			else
				p[i][j] = max(p[i - 1][j], p[i][j - 1]);
		}
	}
	return p[n][m];
}
