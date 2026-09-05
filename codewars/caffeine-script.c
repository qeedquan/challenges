/*

Complete the function which takes a non-zero integer as its argument.

If the integer is divisible by 3, return the string "Java".

If the integer is divisible by 3 and divisible by 4, return the string "Coffee"

If one of the condition above is true and the integer is even, add "Script" to the end of the string.

If none of the condition is true, return the string "mocha_missing!"

Examples
1   -->  "mocha_missing!"
3   -->  "Java"
6   -->  "JavaScript"
12  -->  "CoffeeScript"

*/

#include <assert.h>
#include <string.h>

const char *
caffeine(unsigned n)
{
	if (!(n % 3) && !(n % 4))
		return (n % 2) ? "Coffee" : "CoffeeScript";
	if (!(n % 3))
		return (n % 2) ? "Java" : "JavaScript";
	return "mocha_missing!";
}

int
main()
{
	assert(!strcmp(caffeine(1), "mocha_missing!"));
	assert(!strcmp(caffeine(3), "Java"));
	assert(!strcmp(caffeine(6), "JavaScript"));
	assert(!strcmp(caffeine(12), "CoffeeScript"));

	return 0;
}
