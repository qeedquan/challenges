/*

Given a string, return true if the first instance of "x" in the string is immediately followed by the string "xx".

tripleX("abraxxxas") → true
tripleX("xoxotrololololololoxxx") → false
tripleX("softX kitty, warm kitty, xxxxx") → true
tripleX("softx kitty, warm kitty, xxxxx") → false
Note :

capital X's do not count as an occurrence of "x".
if there are no "x"'s then return false

*/

#include <assert.h>
#include <string.h>

bool
triplex(const char *s)
{
	s = strchr(s, 'x');
	if (!s || s[1] != 'x' || s[2] != 'x')
		return false;
	return true;
}

int
main()
{
	assert(triplex("abraxxxas") == true);
	assert(triplex("xoxotrololololololoxxx") == false);
	assert(triplex("softX kitty, warm kitty, xxxxx") == true);
	assert(triplex("softx kitty, warm kitty, xxxxx") == false);
	return 0;
}
