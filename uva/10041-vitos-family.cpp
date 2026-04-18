/*

The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all
of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a
house close to them.
Vito wants to minimize the total distance to all of them and has blackmailed you to write a program
that solves his problem.

Input
The input consists of several test cases. The first line contains the number of test cases.
For each test case you will be given the integer number of relatives r (0 < r < 500) and the
street numbers (also integers) s1, s2, . . . , si, . . . , sr where they live (0 < si < 30000 ). Note that several
relatives could live in the same street number.

Output
For each test case your program must write the minimal sum of distances from the optimal Vito’s house
to each one of his relatives. The distance between two street numbers si and sj is dij = |si − sj |.

Sample Input
2
2 2 4
3 2 4 6

Sample Output
2
4

*/

#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int distance(vector<int> &&streets)
{
	auto size = streets.size();
	if (size == 0)
		return 0;

	sort(streets.begin(), streets.end());

	auto median = streets[size / 2];
	auto result = 0;
	for (auto value : streets)
		result += abs(median - value);
	return result;
}

int main()
{
	assert(distance({ 2, 4 }) == 2);
	assert(distance({ 2, 4, 6 }) == 4);

	return 0;
}
