/*

The function is not returning the correct values. Can you figure out why?

Example (Input --> Output ):

3 --> "Earth"

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
planet(unsigned id)
{
	static const char *planets[] = {
	    "Mercury",
	    "Venus",
	    "Earth",
	    "Mars",
	    "Jupiter",
	    "Saturn",
	    "Uranus",
	    "Neptune",
	};

	if (id < 1 || id > nelem(planets))
		return NULL;
	return planets[id - 1];
}

int
main()
{
	unsigned i;

	for (i = 1; i <= 8; i++)
		printf("%s\n", planet(i));
	return 0;
}
