/*

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
valids(const char *s)
{
	int lo, hi;
	size_t i;

	lo = hi = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '(':
			lo += 1;
			hi += 1;
			break;
		case ')':
			lo = max(lo - 1, 0);
			hi -= 1;
			break;
		default:
			lo = max(lo - 1, 0);
			hi += 1;
			break;
		}
		if (hi < 0)
			return false;
	}
	return lo == 0;
}

int
main(void)
{
	assert(valids("()") == true);
	assert(valids("(*)") == true);
	assert(valids("(*))") == true);

	return 0;
}
