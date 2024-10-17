/*

https://i.stack.imgur.com/cfNEC.pngGiven one of the following inputs:

Sweet Onion Chicken Teriyaki
Oven Roasted Chicken
Turkey Breast
Italian BMT
Tuna
Black Forest Ham
Meatball Marinara

output a number from 1-7 (or 0-6) representing the day of the week that you get that deal, starting with Monday as the lowest number. Input can be all lowercase or uppercase if preferred (i.e "italian bmt"). No internet allowed.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
dow(int n)
{
	static const char *tab[] = {
	    "Sweet Onion Chicken Teriyaki",
	    "Oven Roasted Chicken",
	    "Turkey Breast",
	    "Italian BMT",
	    "Tuna",
	    "Black Forest Ham",
	    "Meatball Marinara",
	};

	if (n < 0 || n > 6)
		return NULL;
	return tab[n];
}

int
main(void)
{
	assert(!strcmp(dow(0), "Sweet Onion Chicken Teriyaki"));
	assert(!strcmp(dow(5), "Black Forest Ham"));
	assert(!strcmp(dow(6), "Meatball Marinara"));

	return 0;
}
