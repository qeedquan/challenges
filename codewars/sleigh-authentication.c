/*

Christmas is coming and many people dreamed of having a ride with Santa's sleigh. But, of course, only Santa himself is allowed to use this wonderful transportation. And in order to make sure, that only he can board the sleigh, there's an authentication mechanism.

Your task is to implement the `authenticate()` method of the sleigh, which takes the name of the person, who wants to board the sleigh and a secret password. If, and only if, the name equals "Santa Claus" and the password is "Ho Ho Ho!" *(yes, even Santa has a secret password with uppercase and lowercase letters and special characters :D)*, the return value must be `true`. Otherwise it should return `false`.

Examples:

sleigh.authenticate("Santa Claus", "Ho Ho Ho!") # must return True
sleigh.authenticate("Santa', 'Ho Ho Ho!") # must return False
sleigh.authenticate("Santa Claus", "Ho Ho!") # must return False
sleigh.authenticate("jhoffner", "CodeWars") # Nope, even Jak

*/

#include <assert.h>
#include <string.h>

bool
authenticate(const char *name, const char *secret)
{
	return !strcmp(name, "Santa Claus") && !strcmp(secret, "Ho Ho Ho!");
}

int
main()
{
	assert(authenticate("Santa Claus", "Ho Ho Ho!") == true);
	assert(authenticate("Santa", "Ho Ho Ho!") == false);
	assert(authenticate("Santa Claus", "Ho Ho!") == false);
	assert(authenticate("jhoffner", "CodeWars") == false);

	return 0;
}
