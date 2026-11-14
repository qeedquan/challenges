/*

You must write a program that outputs the n-th largest value in a fixed-size array of integers.
To simplify the task, n=3, and each array will always contain 10 decimal integer values.

Input
The first line contains a single integer p (1≤p≤1000), the number of data sets.
Each data set consists of a single line containing the data set number, followed by a space, then 10 space-separated decimal integers,
each in the range from 1 to 1000 inclusive.

Output
For each data set, output one line containing the data set number, a space, and the 3-rd largest value among the corresponding 10 integers.

Examples

Input #1
4
1 1 2 3 4 5 6 7 8 9 1000
2 338 304 619 95 343 496 489 116 98 127
3 931 240 986 894 826 640 965 833 136 138
4 940 955 364 188 133 254 501 122 768 408

Answer #1
1 8
2 489
3 931
4 768

*/

#include <cassert>
#include <queue>
#include <print>
#include <vector>

using namespace std;

void solve(int set, const vector<int> &numbers)
{
	priority_queue<int> queue;
	for (auto number : numbers)
		queue.push(number);

	if (queue.size() < 3)
		return;

	queue.pop();
	queue.pop();
	
	println("{} {}", set, queue.top());
}

int main()
{
	solve(1, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1000 });
	solve(2, { 338, 304, 619, 95, 343, 496, 489, 116, 98, 127 });
	solve(3, { 931, 240, 986, 894, 826, 640, 965, 833, 136, 138 });
	solve(4, { 940, 955, 364, 188, 133, 254, 501, 122, 768, 408 });

	return 0;
}
