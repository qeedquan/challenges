#include <cassert>
#include <string>
#include <stack>

using namespace std;

string balanced(const string &input)
{
	stack<int> checker;
	for (auto symbol : input)
	{
		if (symbol == '(' || symbol == '[')
			checker.push(symbol);
		else if (symbol == ')')
		{
			if (checker.empty() || checker.top() != '(')
			{
				checker.push('a');
				break;
			}
			checker.pop();
		}
		else if (symbol == ']')
		{
			if (checker.empty() || checker.top() != '[')
			{
				checker.push('a');
				break;
			}
			checker.pop();
		}
	}

	if (checker.empty())
		return "Yes";
	return "No";
}

int main()
{
	assert(balanced("([])") == "Yes");
	assert(balanced("(([()])))") == "No");
	assert(balanced("([()[]()])()") == "Yes");

	return 0;
}
