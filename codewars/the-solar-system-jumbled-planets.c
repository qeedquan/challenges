/*

Oh no! The celestial bodies orbiting the sun are all jumbled up!

TASK
Given the entire Solar System in the form of a list. Return a new list which has either '<', '>' or '=' depending on whether the planet is smaller than the planet on its left or not. You have to start comparing from the second item, because the first has nothing on its left.
However, there are also asteroids in the Solar System. All asteroids are smaller than all the planets. If two asteroids are found beside each other, the leftmost one will depend on the celestial being on the left of it. The one on the right will have '='.

The Solar System might be empty.

The celestial bodies stand in the order (size ascending):

Asteroid < Pluto < Mercury < Mars < Venus < Earth < Neptune < Uranus < Saturn < Jupiter

Important: the dwarf planet Pluto is also included in the Solar System

EXAMPLES
["Mars", "Asteroid", "Venus", "Jupiter", "Asteroid", "Earth", "Pluto"] -> ['<', '>', '>', '<', '>', '<']
# Asteriod is '<' Mars
# Venus is '>' any Asteroid
# Jupiter is '>' Venus
# Any Asteroid is '<' Jupiter
# Earth is '>' the Asteroid
# Finally, Pluto, being a dwarf planet, is '<' Earth

["Asteroid", "Asteroid", "Asteroid", "Earth", "Jupiter"] -> ['=', '=', '>', '>']
# Here, the Asteroid is '=' to the Asteroid on its left
# Again, it is '=' because there is another Asteroid on its left
# Earth is '>' than the Asteroid
# Finally, Jupiter, being the king of the planets, is '>' than Earth

["Mercury", "Venus", "Earth", "Mars", "Asteroid", "Jupiter", "Saturn", "Uranus", "Neptune", "Asteroid", "Pluto"] -> ['>', '>', '<', '<', '>', '<', '<', '<', '<', '>']
# Atleast here the Solar System is how it's supposed to be!
NOTES
There will never be more than one of anything except asteroids

The Solar System will never contain anything outside:

["Asteroid", "Pluto", "Mercury", "Mars", "Venus", "Earth", "Neptune", "Uranus", "Saturn", "Jupiter"]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
weight(const char *s)
{
	static const char *objs[] = {
		"Asteroid",
		"Pluto",
		"Mercury",
		"Mars",
		"Venus",
		"Earth",
		"Neptune",
		"Uranus",
		"Saturn",
		"Jupiter",
	};

	size_t i;

	for (i = 0; i < nelem(objs); i++) {
		if (!strcmp(s, objs[i]))
			return i;
	}
	return -1;
}

char *
order(const char **s, size_t n, char *b)
{
	size_t i;
	int x, y;
	char *p;

	p = b;
	for (i = 1; i < n; i++) {
		x = weight(s[i - 1]);
		y = weight(s[i]);
		if (y > x)
			*p++ = '>';
		else if (x == y)
			*p++ = '=';
		else
			*p++ = '<';
	}
	*p = '\0';

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	order(s, n, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	const char *s1[] = { "Venus", "Jupiter", "Mercury" };
	const char *s2[] = { "Earth" };
	const char *s3[] = { "Saturn", "Venus", "Mars", "Pluto", "Asteroid" };
	const char *s4[] = { "Asteroid", "Neptune", "Jupiter", "Saturn" };
	const char *s5[] = { "Venus", "Mars", "Neptune", "Uranus", "Earth", "Jupiter", "Mercury" };
	const char *s6[] = { "Pluto", "Neptune", "Mercury", "Venus", "Uranus", "Mars", "Earth", "Jupiter", "Asteroid", "Saturn", "Asteroid", "Asteroid", "Asteroid", "Asteroid" };

	test(NULL, 0, "");
	test(s1, nelem(s1), "><");
	test(s2, nelem(s2), "");
	test(s3, nelem(s3), "<<<<");
	test(s4, nelem(s4), ">><");
	test(s5, nelem(s5), "<>><><");
	test(s6, nelem(s6), "><>><>><><===");

	return 0;
}
