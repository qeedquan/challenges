/*

In this Kata, you will be given a number in form of a string and an integer k and your task is to insert k commas into the string and determine which of the partitions is the largest.

For example:
solve('1234',1) = 234 because ('1','234') or ('12','34') or ('123','4').
solve('1234',2) = 34 because ('1','2','34') or ('1','23','4') or ('12','3','4').
solve('1234',3) = 4
solve('2020',1) = 202

More examples in test cases. Good luck!

*/

#include <cassert>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int solve(const string &s, int k)
{
	if (s == "" || k < 1)
		return 0;

	int l = s.size();
	int n = max(l - k, 1);
	int r = INT_MIN;
	for (int i = 0; i < l - n + 1; i++)
	{
		auto t = s.substr(i, n);
		r = max(r, stoi(t));
	}
	return r;
}

int main()
{
	assert(solve("1234", 1) == 234);
	assert(solve("1234", 2) == 34);
	assert(solve("1234", 3) == 4);
	assert(solve("2020", 1) == 202);

	return 0;
}
