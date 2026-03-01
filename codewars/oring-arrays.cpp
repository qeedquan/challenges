/*

It started as a discussion with a friend, who didn't fully grasp some way of setting defaults, but I thought the idea was cool enough for a beginner kata: binary OR each matching element of two given arrays (or lists, if you do it in Python; vectors in c++) of integers and give the resulting ORed array [starts to sound like a tonguetwister, doesn't it?].

If one array is shorter than the other, use the optional third parameter (defaulted to 0) to OR the unmatched elements.

For example:

orArrays([1,2,3],[1,2,3]) === [1,2,3]
orArrays([1,2,3],[4,5,6]) === [5,7,7]
orArrays([1,2,3],[1,2]) === [1,2,3]
orArrays([1,2],[1,2,3]) === [1,2,3]
orArrays([1,2,3],[1,2,3],3) === [1,2,3]

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ors(const vector<int> &&a, const vector<int> &&b, int c = 0)
{
	vector<int> r;
	auto n = max(a.size(), b.size());
	for (size_t i = 0; i < n; i++)
	{
		if (i >= a.size())
			r.push_back(b[i] | c);
		else if (i >= b.size())
			r.push_back(a[i] | c);
		else
			r.push_back(a[i] | b[i]);
	}
	return r;
}

int main()
{
	vector<int> r1 = { 1, 2, 3 };
	vector<int> r2 = { 5, 7, 7 };
	vector<int> r3 = { 1, 2, 3 };
	vector<int> r4 = { 1, 2, 3 };
	vector<int> r5 = { 1, 2, 3 };

	assert(ors({ 1, 2, 3 }, { 1, 2, 3 }) == r1);
	assert(ors({ 1, 2, 3 }, { 4, 5, 6 }) == r2);
	assert(ors({ 1, 2, 3 }, { 1, 2 }) == r3);
	assert(ors({ 1, 2 }, { 1, 2, 3 }) == r4);
	assert(ors({ 1, 2, 3 }, { 1, 2, 3 }, 3) == r5);

	return 0;
}
