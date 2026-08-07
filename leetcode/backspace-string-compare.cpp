/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

*/

#include <cassert>
#include <string>

using namespace std;

void remove_backspaces(string &input)
{
	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] == '#')
		{
			auto steps = (index > 0) ? 2 : 1;
			input.erase(index - steps + 1, steps);
			index -= steps;
		}
	}
}

bool backspace_compare(string input1, string input2)
{
	remove_backspaces(input1);
	remove_backspaces(input2);
	return input1 == input2;
}

int main()
{
	assert(backspace_compare("ab#c", "ad#c") == true);
	assert(backspace_compare("ab##", "c#d#") == true);
	assert(backspace_compare("a##c", "#a#c") == true);
	assert(backspace_compare("a#c", "b") == false);

	return 0;
}
