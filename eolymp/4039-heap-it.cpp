/*

In this problem you must create a Heap data structure to store the integers, where the following operations are defined:

Insert(x) - add to Heap the value x;

Extract - extract from the Heap the maximum element (and delete it).

Input
The first line contains the number of commands n (1≤n≤10^5), then a sequence of n operations, each in a separate line.

Each command has the following format: "0 number" or "1", which means respectively the operations Insert (number) and Extract.
The inserted numbers range from 1 to 10 
7 inclusive.

It is guaranteed that when the Extract command is executed, there is at least one element in the structure.

Output
For each extraction command, print the number obtained by executing the Extract command.

Examples
Input #1
7
0 100
0 10
1
0 5
0 30
0 50
1

Answer #1
100
50

*/

#include <print>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int> > List;

void solve(const List &commands)
{
	priority_queue<int> queue;
	for (auto command : commands)
	{
		if (command.size() < 1)
			continue;

		if (command[0] == 0 && command.size() >= 2)
			queue.push(command[1]);
		else if (command[0] == 1)
		{
			println("{}", queue.top());
			queue.pop();
		}
	}
}

int main()
{
	solve({
		{ 0, 100 },
		{ 0, 10 },
		{ 1 },
		{ 0, 5 },
		{ 0, 30 },
		{ 0, 50 },
		{ 1 },
	});

	return 0;
}
