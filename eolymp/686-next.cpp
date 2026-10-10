/*

Implement a data structure that supports a set S of integers, with which it is allowed to perform the following operations:

add(i) – add to the set S the number i (if it already exists there, the set is not changed);

next(i) – print the minimum element of the set that is no less than i. If such an element does not exist in the structure, print -1.

Input
The set S is initially empty.
The first line contains the number of operations n (1≤n≤300 000).
The next n lines contain the operations.
Each operation has a type either "+ i" or "? i".
The operation "? i" gives the query next(i).

If the operation "+ i" is executed at the start or after another operation +, it specifies the operation add(i).
If the operation goes after the query ? with result y, then the operation add((i + y) mod 10^9) is executed.

In all queries and add operations, the parameters lie in the range from 0 to 10^9.

Output
For each query, print one number—the answer to it.

Examples
Input #1
6
+ 1
+ 3
+ 3
? 2
+ 1
? 4

Answer #1
3
4

*/

#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <print>

using namespace std;

void solve(const vector<string> &operations)
{
	set<int> set;
	char previous = 0;
	int location;
	for (auto operation : operations)
	{
		char command;
		int value;
		if (sscanf(operation.c_str(), "%c %d", &command, &value) != 2)
			continue;

		if (command == '+' && previous != '?')
			set.insert(value);
		else if (command == '+' && previous == '?')
			set.insert((value + location) % 1'000'000'000);
		else if (command == '?')
		{
				location = -1;
				auto iterator = set.lower_bound(value);
				if (iterator != set.end())
					location = *iterator;

				println("{}", location);
		}
		previous = command;
	}
}

int main()
{
	solve({
		"+ 1",
		"+ 3",
		"+ 3",
		"? 3",
		"+ 1",
		"? 4",
	});
	return 0;
}
