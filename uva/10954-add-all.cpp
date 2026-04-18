/*

Add All
Input: standard input
Output: standard output

Yup!! The problem name reflects your task; just add a set of numbers. But you may feel yourselves condescended, to write a C/C++ program just to add a set of numbers. Such a problem will simply question your erudition. So, let’s add some flavor of ingenuity to it.
Addition operation requires cost now, and the cost is the summation of those two to be added. So, to add 1 and 10, you need a cost of 11. If you want to add 1, 2 and 3. There are several ways –
1 + 2 = 3, cost = 3
3 + 3 = 6, cost = 6
Total = 9
1 + 3 = 4, cost = 4
2 + 4 = 6, cost = 6
Total = 10
2 + 3 = 5, cost = 5
1 + 5 = 6, cost = 6
Total = 11
I hope you have understood already your mission, to add a set of integers so that the cost is minimal.
Input
Each test case will start with a positive number, N (2 ≤ N ≤ 5000) followed by N positive integers (all are less than 100000). Input is terminated by a case where the value of N is zero. This case should not be processed.
Output
For each case print the minimum total cost of addition in a single line.

Sample Input
3
1 2 3
4
1 2 3 4

Sample Output
9
19

*/

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int add_all(const vector<int> &nums)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto x : nums)
		pq.push(x);

	auto cost = 0;
	while (pq.size() > 1)
	{
		auto total = pq.top();
		pq.pop();
		
		total += pq.top();
		pq.pop();
		
		cost += total;
		pq.push(total);
	}
	return cost;
}

int main()
{
	assert(add_all({ 1, 2, 3 }) == 9);
	assert(add_all({ 1, 2, 3, 4 }) == 19);

	return 0;
}
