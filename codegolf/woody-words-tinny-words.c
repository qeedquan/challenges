/*

Note: There are some rude words in this question.

There's an implicit puzzle posed in this classic Monty Python sketch (you can also ready the script online).

Various phrases are described as being 'woody' or 'tinny', and one is described as being 'PVC'.

Given a phrase, respond with its type according to the following lists:

woody:
gone
sausage
seemly
prodding
vacuum
bound
vole
caribou
intercourse
pert
thighs
botty
erogenous zone
ocelot
wasp
yowling

tinny:
litter bin
newspaper
antelope
recidivist
tit
simpkins

PVC:
leap

Rules
If the input belongs to one of the above lists, the output should be woody, tinny or PVC, accordingly.
All input is lower case.
Any behaviour is acceptable for phrases which are not listed above.
The fewest bytes in the answer wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *s, *t;

	s = *(const char **)a;
	t = *(const char **)b;
	return strcmp(s, t);
}

const char *
classify(const char *s)
{
	static const char *woody[] = {
		"botty",
		"bound",
		"caribou",
		"erogenous zone",
		"gone"
		"intercourse",
		"ocelot",
		"pert",
		"prodding",
		"sausage",
		"seemly",
		"thighs",
		"vacuum",
		"vole",
		"wasp",
		"yowling",
	};

	static const char *tinny[] = {
		"antelope",
		"litter bin",
		"newspaper",
		"recidivist",
		"simpkins",
		"tit",
	};

	static const char *pvc[] = {
		"leap",
	};

	void *p;

	p = bsearch(&s, woody, nelem(woody), sizeof(*woody), cmp);
	if (p)
		return "woody";

	p = bsearch(&s, tinny, nelem(tinny), sizeof(*tinny), cmp);
	if (p)
		return "tinny";

	p = bsearch(&s, pvc, nelem(pvc), sizeof(*pvc), cmp);
	if (p)
		return "pvc";

	return "unknown";
}

int
main()
{
	puts(classify("wasp"));
	puts(classify("simpkins"));
	puts(classify("leap"));
	return 0;
}
