/*

What is the rank of a playing card? The function takes a string like '2c' or 'Kh' and returns a value based on rank of the card. The first character corresponds to the rank of the card and the second character corresponds to the suit of the card. Cards 2-9 should return the corresponding number. T returns 10, J => 11, Q => 12, K => 13 and A => 14. Otherwise the rank should be returned as 0.

For example:

rank('2c') == 2;
rank('Tc') == 10;
rank('As') == 14;
rank('1c') == 0; // There is no card '1'

Suits can be disregarded.

*/

#include <assert.h>
#include <string.h>

int
rank(const char *s)
{
	static const char map[] = "23456789TJQKA";
	char *p;

	p = strchr(map, s[0]);
	if (!p)
		return 0;
	return p - map + 2;
}

int
main()
{
	assert(rank("2c") == 2);
	assert(rank("Tc") == 10);
	assert(rank("As") == 14);
	assert(rank("1c") == 0);
	assert(rank("2s") == 2);
	assert(rank("7h") == 7);
	assert(rank("Jc") == 11);
	assert(rank("Ad") == 14);
	assert(rank("1d") == 0);

	return 0;
}
