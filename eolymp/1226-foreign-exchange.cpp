/*

Your non-profit organization coordinates a student exchange program and needs your help.

The exchange program works as follows: each participant specifies their current place of residence and the place to which they would like to move.
The program is considered successful if a suitable exchange partner can be found for every student.
In other words, if a student wants to move from A to B, there must exist another student who wants to move from B to A.

Such a check is easy to perform when there are only 10 participants, but what should be done if there are 100001?

Input
The first line contains the number of test cases t.
The first line of each test case contains the number of students n (1≤n≤100001).
This is followed by n lines describing the exchange data.

Each of these lines contains information about one student: two integers representing the student's current place of residence and the desired destination.
Locations are given as non-negative integers not exceeding 10^9.
The current and desired locations are different for every student.

Output
For each test case, print "YES" on a separate line if the exchange program can be carried out successfully, and "NO" otherwise.

Examples

Input #1
2
6
1 2
100 200
1 2
2 1
200 100
2 1
4
1 2
15 16
17 18
19 20

Answer #1
YES
NO

*/

#include <cassert>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct Location
{
	int from;
	int to;
};

string solve(const vector<Location> &locations)
{
	multiset<pair<int, int> > set;
	for (auto location : locations)
	{
		auto a = location.from;
		auto b = location.to;
		auto it = set.find({ b, a });
		if (it == set.end())
			set.insert({ a, b });
		else
			set.erase(it);
	}
	if (set.size() > 0)
		return "NO";
	return "YES";
}

int main()
{
	assert(solve({ { 1, 2 }, { 100, 200 }, { 1, 2 }, { 2, 1 }, { 200, 100 }, { 2, 1 } }) == "YES");
	assert(solve({ { 1, 2 }, { 15, 16 }, { 17, 18 }, { 19, 20 } }) == "NO");

	return 0;
}
