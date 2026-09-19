/*

In information theory and computer science, the Levenshtein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other.

(http://en.wikipedia.org/wiki/Levenshtein_distance)

Your task is to implement a function which calculates the Levenshtein distance for two arbitrary strings.

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

size_t lev(const string &s, const string &t)
{
	auto m = s.size();
	auto n = t.size();

	vector<vector<size_t> > d;
	d.resize(m + 1);
	for (size_t i = 0; i <= m; i++)
		d[i].resize(n + 1);

	for (size_t i = 1; i <= m; i++)
		d[i][0] = i;
	for (size_t j = 1; j <= n; j++)
		d[0][j] = j;

	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			if (s[i - 1] == t[j - 1])
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = min(d[i][j - 1] + 1, min(d[i - 1][j] + 1, d[i - 1][j - 1] + 1));
		}
	}
	return d[m][n];
}

int main()
{
	assert(lev("atoll", "bowl") == 3);
	assert(lev("tar", "tarp") == 1);
	assert(lev("turing", "tarpit") == 4);
	assert(lev("antidisestablishmentarianism", "bulb") == 27);
	assert(lev("kitten", "sitting") == 3);

	return 0;
}
