/*

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

size_t longest_valid_parentheses(const string &input)
{
	vector<size_t> stack;
	size_t max_length = 0;
	size_t last_error = 0;
	for (size_t index = 0; index < input.size(); index++)
	{
		switch (input[index])
		{
		case '(':
			stack.push_back(index);
			break;

		case ')':
			if (stack.size() == 0)
			{
				last_error = index;
				continue;
			}
			stack.pop_back();

			size_t length;
			if (stack.size() == 0)
				length = index - last_error;
			else
				length = index - stack.back();

			max_length = max(max_length, length);
			break;
		}
	}
	return max_length;
}

int main()
{
	assert(longest_valid_parentheses("(()") == 2);
	assert(longest_valid_parentheses(")()())") == 4);
	assert(longest_valid_parentheses("") == 0);

	return 0;
}
