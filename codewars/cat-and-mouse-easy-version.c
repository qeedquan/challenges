/*

You will be given a string (x) featuring a cat 'C' and a mouse 'm'. The rest of the string will be made up of '.'.

You need to find out if the cat can catch the mouse from it's current position. The cat can jump over three characters. So:

C.....m returns 'Escaped!' <-- more than three characters between

C...m returns 'Caught!' <-- as there are three characters between the two, the cat can jump.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
catmouse(const char *s)
{
	const char *c, *m;

	m = strchr(s, 'm');
	c = strchr(s, 'C');
	if (!m || !c)
		return NULL;
	if (m > c && m - c > 4)
		return "Escaped!";
	return "Caught!";
}

int
main()
{
	assert(!strcmp(catmouse("C.....m"), "Escaped!"));
	assert(!strcmp(catmouse("C....m"), "Escaped!"));
	assert(!strcmp(catmouse("C.....m"), "Escaped!"));
	assert(!strcmp(catmouse("C.......m"), "Escaped!"));
	assert(!strcmp(catmouse("C.....m"), "Escaped!"));

	assert(!strcmp(catmouse("C...m"), "Caught!"));
	assert(!strcmp(catmouse("C...m"), "Caught!"));
	assert(!strcmp(catmouse("C..m"), "Caught!"));
	assert(!strcmp(catmouse("C.m"), "Caught!"));
	assert(!strcmp(catmouse("C...m"), "Caught!"));

	return 0;
}
