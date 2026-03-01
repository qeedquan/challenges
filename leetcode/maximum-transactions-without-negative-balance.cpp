/*

You are given an integer array transactions, where transactions[i] represents the amount of the ith transaction:

    A positive value means money is received.
    A negative value means money is sent.

The account starts with a balance of 0, and the balance must never become negative. Transactions must be considered in the given order, but you are allowed to skip some transactions.

Return an integer denoting the maximum number of transactions that can be performed without the balance ever going negative.

 

Example 1:

Input: transactions = [2,-5,3,-1,-2]

Output: 4

Explanation:

One optimal sequence is [2, 3, -1, -2], balance: 0 → 2 → 5 → 4 → 2.

Example 2:

Input: transactions = [-1,-2,-3]

Output: 0

Explanation:

All transactions are negative. Including any would make the balance negative.

Example 3:

Input: transactions = [3,-2,3,-2,1,-1]

Output: 6

Explanation:

All transactions can be taken in order, balance: 0 → 3 → 1 → 4 → 2 → 3 → 2.



Constraints:

    1 <= transactions.length <= 10^5
    -10^9 <= transactions[i] <= 10^9

*/

#include <cassert>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long vlong;

vlong max_transactions(const vector<vlong> &transactions)
{
	priority_queue<vlong, vector<vlong>, greater<vlong> > minheap;
	vlong current = 0;
	for (const auto &value : transactions)
	{
		minheap.emplace(value);
		current += value;
		if (current < 0)
		{
			current -= minheap.top();
			minheap.pop();
		}
	}
	return minheap.size();
}

int main()
{
	assert(max_transactions({ 2, -5, 3, -1, -2 }) == 4);
	assert(max_transactions({ -1, -2, -3 }) == 0);
	assert(max_transactions({ 3, -2, 3, -2, 1, -1 }) == 6);

	return 0;
}
