/*

Let x be a variable initially equal to 0. Simulate the next operations with this variable:

add  a: add value a to x;

subtract  a: subtract value a from x;

multiply  a: multiply x by a;

Input
Each line contains operation and value. Process all given operations. The value of the variable x after each operation does not exceed 10^9 by absolute value.

Output
Print the resulting value of x.

Examples

Input #1
add 2
subtract 5
subtract 1
multiply -3

Answer #1
12

Input #2
subtract 5
multiply -5
add 5

Answer #2
30

*/

#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int solve(const vector<string> &operations)
{
	auto result = 0;
	for (auto operation : operations)
	{
		char command[16];
		int value;
		if (sscanf(operation.c_str(), "%15s %d", command, &value) != 2)
			continue;

		if (!strcmp(command, "add"))
			result += value;
		else if (!strcmp(command, "subtract"))
			result -= value;
		else if (!strcmp(command, "multiply"))
			result *= value;
	}
	return result;
}

int main()
{
	vector<string> operations_1 = {
		"add 2",
		"subtract 5",
		"subtract 1",
		"multiply -3",
	};

	vector<string> operations_2 = {
		"subtract 5",
		"multiply -5",
		"add 5",
	};

	assert(solve(operations_1) == 12);
	assert(solve(operations_2) == 30);

	return 0;
}
