/*

Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching.
We need to add one more ')' at the end of the string to be "(())))" which is balanced.

Example 2:
Input: s = "())"
Output: 0
Explanation: The string is already balanced.

Example 3:
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

Constraints:

1 <= s.length <= 10^5
s consists of '(' and ')' only.

*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

size_t insertions(const string &input)
{
	vector<int> stack;
	size_t count = 0;
	for (size_t index = 0; index < input.size(); index++)
	{
		switch (input[index])
		{
		case '(':
			stack.push_back(input[index]);
			break;

		case ')':
			if (stack.size() > 0)
				stack.pop_back();
			else
				count += 1;

			if (index + 1 < input.size() && input[index + 1] == ')')
				index += 1;
			else
				count += 1;
			break;
		}
	}

	return count + (2 * stack.size());
}

int main()
{
	assert(insertions("(()))") == 1);
	assert(insertions("())") == 0);
	assert(insertions("))())(") == 3);
	assert(insertions("((((((") == 12);
	assert(insertions(")))))))") == 5);

	return 0;
}
