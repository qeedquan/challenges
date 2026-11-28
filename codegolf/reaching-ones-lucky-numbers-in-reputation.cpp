/*

A new code-golfer, Joe, just registered to the site. He has 1 reputation but determined to reach all his lucky numbers in reputation exactly. Joe believes in higher powers which will help him to achieve his goal with minimal amount of (his or others) actions. As a new user he also believes that negative reputation is possible.

You should write a program or function which helps Joe to compute how many action should he expect.

Details
The actions can change the reputation by the following amounts (all actions are available at every step regardless of stackexchange rules):

answer accepted:     +15
answer voted up:     +10
question voted up:    +5
accepts answer:       +2
votes down an answer: −1
question voted down:  −2
Other special reputation changes are disregarded.

Lucky numbers can be negative and can be reached in any order.
Your solution has to solve any example test case under a minute on my computer (I will only test close cases. I have a below-average PC.).
Input
Joe's lucky numbers as a list of integers in a common form of your language.
Output
The number of minimum actions needed as a single integer.
Output could be printed to stdout or returned as an integer.

Examples
Input => Output (Example reputation states)

1                     => 0  (1)
3 2 1                 => 2  (1 -> 3 -> 2)
2 10 50               => 7  (1 -> 3 -> 2 -> 12 -> 10 -> 25 -> 40 -> 50)
10 11 15              => 3  (1 -> 11 -> 10 -> 15)
42 -5                 => 7  (1 -> -1 -> -3 -> -5 -> 10 -> 25 -> 40 -> 42)
-10                   => 6  (1 -> -1 -> -3 -> -5 -> -7 -> -9 -> -10)
15 -65                => 39
7 2015 25 99          => 142
-99 576 42 1111 12345 => 885
This is code-golf so the shortest entry wins.

*/

#include <cassert>
#include <vector>
#include <string>

using namespace std;

int distance(int start, int end)
{
	static const int lookup[] = { 0, 2, 1, 2, 2, 1, 3, 2, 2, 2, 1, 3, 2, 2, 2 };
	if (start > end)
		return (start - end + 1) / 2;
	return (end - start) / 15 + lookup[(end - start) % 15];
}

// Ported from @Fors solution
int walk(int current, const vector<int> &points)
{
	int min = 0;
	for (size_t i = 0; i < points.size(); i++)
	{
		vector<int> new_points = points;
		new_points.erase(new_points.begin() + i);

		int dist = distance(current, points[i]) + walk(points[i], new_points);
		min = (min && min < dist) ? min : dist;
	}
	return min;
}

int main()
{
	vector<int> points_1 = { 1 };
	vector<int> points_2 = { 3, 2, 1 };
	vector<int> points_3 = { 2, 10, 50 };
	vector<int> points_4 = { 10, 11, 15 };
	vector<int> points_5 = { 42, -5 };
	vector<int> points_6 = { -10 };
	vector<int> points_7 = { 15, -65 };
	vector<int> points_8 = { 7, 2015, 25, 99 };
	vector<int> points_9 = { -99, 576, 42, 1111, 12345 };

	assert(walk(1, points_1) == 0);
	assert(walk(1, points_2) == 2);
	assert(walk(1, points_3) == 7);
	assert(walk(1, points_4) == 3);
	assert(walk(1, points_5) == 7);
	assert(walk(1, points_6) == 6);
	assert(walk(1, points_7) == 39);
	assert(walk(1, points_8) == 142);
	assert(walk(1, points_9) == 885);
	assert(walk(1, points_9) == 885);

	return 0;
}
