/*

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters and stars *.
The operation above can be performed on s.

*/

#include <cassert>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string remove_stars(const string &str)
{
	stack<char> stack;
	for (auto ch : str)
	{
		if (ch == '*' && stack.size() > 0)
			stack.pop();
		else
			stack.push(ch);
	}

	string ret = "";
	while (stack.size() > 0)
	{
		ret += stack.top();
		stack.pop();
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	assert(remove_stars("leet**cod*e") == "lecoe");
	assert(remove_stars("erase*****") == "");
	assert(remove_stars("kaxlo") == "kaxlo");

	return 0;
}
