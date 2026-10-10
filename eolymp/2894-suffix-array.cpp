/*

Given a string, construct its suffix array. The suffix array is an array of all suffixes of the string sorted in lexicographical order.
Each suffix is represented by its starting position (an integer).

A string s is considered lexicographically smaller than string t if there exists some i such that si < ti and sj = tj for all j < i.
If no such i exists and string s is shorter than t, then s is also considered smaller.

Here, si refers to the code of the i-th character of string s.

Input
One line — an English text. The length of the text does not exceed 10^5.
The codes of all characters in the text are in the range from 32 to 127.

Output
Output n integers — the suffix array of the given string.

Examples
Input #1
99 bottles of beer.
Answer #1
14 3 11 19 2 1 15 4 16 17 9 13 8 12 5 18 10 7 6

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <print>

using namespace std;

struct Suffix
{
	int index;
	int rank[2];
};

int compare(const Suffix &a, const Suffix &b)
{
	if (a.rank[0] == b.rank[0])
		return a.rank[1] < b.rank[1];
	return a.rank[0] < b.rank[0];
}

// https://www.geeksforgeeks.org/dsa/suffix-array-set-2-a-nlognlogn-algorithm/
vector<int> build_suffix_array(const string &text)
{
	int length = text.size();

	vector<Suffix> suffix(length);
	for (int i = 0; i < length; i++)
	{
		suffix[i].index = i;
		suffix[i].rank[0] = text[i] - 'a';
		suffix[i].rank[1] = ((i + 1) < length) ? (text[i + 1] - 'a') : -1;
	}
	sort(suffix.begin(), suffix.end(), compare);

	vector<int> indices(length);
	for (int k = 4; k < (2 * length); k *= 2)
	{
		int rank = 0;
		int prev_rank = suffix[0].rank[0];

		suffix[0].rank[0] = rank;
		indices[suffix[0].index] = 0;

		for (int i = 1; i < length; i++)
		{
			if (suffix[i].rank[0] == prev_rank &&
				suffix[i].rank[1] == suffix[i - 1].rank[1])
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffix[i].rank[0];
				suffix[i].rank[0] = ++rank;
			}
			indices[suffix[i].index] = i;
		}

		for (int i = 0; i < length; i++)
		{
			int next = suffix[i].index + (k / 2);
			suffix[i].rank[1] = -1;
			if (next < length)
				suffix[i].rank[1] = suffix[indices[next]].rank[0];
		}

		sort(suffix.begin(), suffix.end(), compare);
	}

	vector<int> result(length);
	for (int i = 0; i < length; i++)
		result[i] = suffix[i].index + 1;
	return result;
}

void test(const string &text, const vector<int> &expected)
{
	auto result = build_suffix_array(text);
	println("{}", result);
	assert(result == expected);
}

int main()
{
	test("99 bottles of beer.", { 14, 3, 11, 19, 2, 1, 15, 4, 16, 17, 9, 13, 8, 12, 5, 18, 10, 7, 6 });

	return 0;
}
