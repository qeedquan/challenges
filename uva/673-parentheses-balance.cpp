/*

You are given a string consisting of parentheses () and []. A string of this type is said to be correct:
(a) if it is the empty string
(b) if A and B are correct, AB is correct,
(c) if A is correct, (A) and [A] is correct.
Write a program that takes a sequence of strings of this type and check their correctness. Your
program can assume that the maximum string length is 128.

Input
The file contains a positive integer n and a sequence of n strings of parentheses ‘()’ and ‘[]’, one string
a line.

Output
A sequence of ‘Yes’ or ‘No’ on the output file.

Sample Input
3
([])
(([()])))
([()[]()])()

Sample Output
Yes
No
Yes

*/

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
