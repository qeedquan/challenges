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
