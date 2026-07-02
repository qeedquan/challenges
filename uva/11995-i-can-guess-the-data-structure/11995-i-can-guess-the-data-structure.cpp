#include <cassert>
#include <array>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string solve(vector<array<int, 2> > commands)
{
	queue<int> queue;
	stack<int> stack;
	priority_queue<int> priority_queue;

	bool is_stack = true;
	bool is_queue = true;
	bool is_priority_queue = true;
	for (auto command : commands)
	{
		auto [op, x] = command;
		switch (op)
		{
		case 1:
			if (is_stack)
				stack.push(x);
			if (is_queue)
				queue.push(x);
			if (is_priority_queue)
				priority_queue.push(x);
			break;

		case 2:
			if (is_stack)
			{
				if (stack.empty() || stack.top() != x)
					is_stack = false;
				else
					stack.pop();
			}

			if (is_queue)
			{
				if (queue.empty() || queue.front() != x)
					is_queue = false;
				else
					queue.pop();
			}

			if (is_priority_queue)
			{
				if (priority_queue.empty() || priority_queue.top() != x)
					is_priority_queue = false;
				else
					priority_queue.pop();
			}
			break;
		}
	}

	if (is_stack == true && is_queue == false && is_priority_queue == false)
		return "stack";
	if (is_stack == false && is_queue == true && is_priority_queue == false)
		return "queue";
	if (is_stack == false && is_queue == false && is_priority_queue == true)
		return "priority queue";
	if (is_stack == false && is_queue == false && is_priority_queue == false)
		return "impossible";
	return "not sure";
}

int main()
{
	assert(solve({ { 1, 1 }, { 1, 2 }, { 1, 3 }, { 2, 1 }, { 2, 2 }, { 2, 3 } }) == "queue");
	assert(solve({ { 1, 1 }, { 1, 2 }, { 1, 3 }, { 2, 3 }, { 2, 2 }, { 2, 1 } }) == "not sure");
	assert(solve({ { 1, 1 }, { 2, 2 } }) == "impossible");
	assert(solve({ { 1, 2 }, { 1, 1 }, { 2, 1 }, { 2, 2 } }) == "stack");
	assert(solve({ { 1, 2 }, { 1, 5 }, { 1, 1 }, { 1, 3 }, { 2, 5 }, { 1, 4 }, { 2, 4 } }) == "priority queue");

	return 0;
}
