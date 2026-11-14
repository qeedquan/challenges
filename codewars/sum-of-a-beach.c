/*

Beaches are filled with sand, water, fish, and sun.
Given a string, calculate how many times the words "Sand", "Water", "Fish", and "Sun" appear without overlapping (regardless of the case).

Examples
sumOfABeach("WAtErSlIde")                    ==>  1
sumOfABeach("GolDeNSanDyWateRyBeaChSuNN")    ==>  3
sumOfABeach("gOfIshsunesunFiSh")             ==>  4
sumOfABeach("cItYTowNcARShoW")               ==>  0

*/

#include <assert.h>
#include <stdio.h>
#include <regex.h>

int
sumofabeach(const char *s)
{
	regex_t re;
	regmatch_t m;
	int r;

	if (regcomp(&re, "(sand|water|fish|sun)", REG_EXTENDED | REG_ICASE))
		return -1;

	r = 0;
	while (regexec(&re, s, 1, &m, 0) == 0) {
		r += 1;
		s += m.rm_eo;
	}
	regfree(&re);
	return r;
}

int
main()
{
	assert(sumofabeach("WAtErSlIde") == 1);
	assert(sumofabeach("GolDeNSanDyWateRyBeaChSuNN") == 3);
	assert(sumofabeach("gOfIshsunesunFiSh") == 4);
	assert(sumofabeach("cItYTowNcARShoW") == 0);

	return 0;
}
