/*

Write a simple regex to validate a username. Allowed characters are:

- lowercase letters,
- numbers,
- underscore

Length should be between 4 and 16 characters (both included).

*/

#include <assert.h>
#include <regex.h>

int
validate(const char *s)
{
	regex_t re;
	regmatch_t m;
	int r;

	if (regcomp(&re, "^[a-z0-9_]{4,16}$", REG_EXTENDED) != 0)
		return -1;

	r = regexec(&re, s, 1, &m, 0);
	regfree(&re);
	return r == 0;
}

int
main()
{
	assert(validate("regex") == 1);
	assert(validate("a") == 0);
	assert(validate("Hass") == 0);
	assert(validate("Hasd_12assssssasasasasasaasasasasas") == 0);
	assert(validate("") == 0);
	assert(validate("____") == 1);
	assert(validate("012") == 0);
	assert(validate("p1pp1") == 1);
	assert(validate("asd43 34") == 0);
	assert(validate("asd43_34") == 1);

	return 0;
}
