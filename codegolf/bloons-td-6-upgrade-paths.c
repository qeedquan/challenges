/*

Background
The monkeys need help organizing their defense and have asked you, Benjamin the code monkey, to create a program that will list all tower upgrade options. Each tower has three unique upgrade "paths", each having a tier represented by a number between 0 and 5 inclusive, 0 meaning no upgrade. Up to two paths may be chosen for upgrading, that is contain an upgrade tier 1 or greater. Additionally, only one path can can contain a tier 3 or greater.

Task
Output in some reasonable format all valid upgrade path triples in any order (the triples themselves are ordered). Triples can be represented in any reasonable way, such as 025 or 0-2-5. The triples must be distinguishable from each other in some way, so a flat list of numbers without triple delimiters is not allowed.

Here is an example list of all 64 possible triples, as they appear in-game for your insta-monkey collection:

5-2-0
5-0-2
5-1-0
5-0-1
5-0-0
2-5-0
0-5-2
1-5-0
0-5-1
0-5-0
2-0-5
0-2-5
1-0-5
0-1-5
0-0-5
4-2-0
4-0-2
4-1-0
4-0-1
4-0-0
2-4-0
0-4-2
1-4-0
0-4-1
0-4-0
2-0-4
0-2-4
1-0-4
0-1-4
0-0-4
3-2-0
3-0-2
3-1-0
3-0-1
3-0-0
2-3-0
0-3-2
1-3-0
0-3-1
0-3-0
2-0-3
0-2-3
1-0-3
0-1-3
0-0-3
2-2-0
2-0-2
2-1-0
2-0-1
2-0-0
0-2-2
1-2-0
0-2-1
0-2-0
1-0-2
0-1-2
0-0-2
1-1-0
1-0-1
1-0-0
0-1-1
0-1-0
0-0-1
0-0-0

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve()
{
	static const char *solution[] = {
	    "5-2-0",
	    "5-0-2",
	    "5-1-0",
	    "5-0-1",
	    "5-0-0",
	    "2-5-0",
	    "0-5-2",
	    "1-5-0",
	    "0-5-1",
	    "0-5-0",
	    "2-0-5",
	    "0-2-5",
	    "1-0-5",
	    "0-1-5",
	    "0-0-5",
	    "4-2-0",
	    "4-0-2",
	    "4-1-0",
	    "4-0-1",
	    "4-0-0",
	    "2-4-0",
	    "0-4-2",
	    "1-4-0",
	    "0-4-1",
	    "0-4-0",
	    "2-0-4",
	    "0-2-4",
	    "1-0-4",
	    "0-1-4",
	    "0-0-4",
	    "3-2-0",
	    "3-0-2",
	    "3-1-0",
	    "3-0-1",
	    "3-0-0",
	    "2-3-0",
	    "0-3-2",
	    "1-3-0",
	    "0-3-1",
	    "0-3-0",
	    "2-0-3",
	    "0-2-3",
	    "1-0-3",
	    "0-1-3",
	    "0-0-3",
	    "2-2-0",
	    "2-0-2",
	    "2-1-0",
	    "2-0-1",
	    "2-0-0",
	    "0-2-2",
	    "1-2-0",
	    "0-2-1",
	    "0-2-0",
	    "1-0-2",
	    "0-1-2",
	    "0-0-2",
	    "1-1-0",
	    "1-0-1",
	    "1-0-0",
	    "0-1-1",
	    "0-1-0",
	    "0-0-1",
	    "0-0-0",
	};

	size_t i;

	for (i = 0; i < nelem(solution); i++)
		printf("%s\n", solution[i]);
}

int
main()
{
	solve();
	return 0;
}
