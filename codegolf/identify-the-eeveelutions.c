/*

Gah! It's a shame that Pokémon Sword and Shield won't introduce a new eeveelution. Let's mourn them with a code golf.

The objective is to, when given a type name as the input, output the name of the corresponding eeveelution.

When given Water, output Vaporeon.
When given Electric, output Jolteon.
When given Fire, output Flareon.
When given Psychic, output Espeon.
When given Dark, output Umbreon.
When given Grass, output Leafeon.
When given Ice, output Glaceon.
When given Fairy, output Sylveon.

All other input falls in don't care situation.
No other rules. Enjoy!

*/

#include <stdio.h>
#include <string.h>

const char *
identify(const char *type)
{
	if (!strcmp(type, "Water"))
		return "Vaporeon";
	if (!strcmp(type, "Electric"))
		return "Jolteon";
	if (!strcmp(type, "Fire"))
		return "Flareon";
	if (!strcmp(type, "Psychic"))
		return "Espeon";
	if (!strcmp(type, "Dark"))
		return "Umbreon";
	if (!strcmp(type, "Grass"))
		return "Leafeon";
	if (!strcmp(type, "Ice"))
		return "Glaceon";
	if (!strcmp(type, "Fairy"))
		return "Sylveon";
	return NULL;
}

int
main()
{
	puts(identify("Ice"));
	return 0;
}
