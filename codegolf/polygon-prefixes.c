/*

Polygons are named after the number of sides that they have. A pentagon has 5 sides, an octagon has 8 sides. But how are they named? What's the name for a 248-sided polygon?

All polygons are suffixed with -gon. There are specific prefixes for each polygon depending on the number of sides. Here are the prefixes for the lower numbers:

3 - tri
4 - tetra
5 - penta
6 - hexa
7 - hepta
8 - octa
9 - nona
10 - deca
11 - undeca
12 - dodeca
13 - triskaideca
14 - tetradeca
15 - pentadeca
16 - hexadeca
17 - heptadeca
18 - octadeca
19 - nonadeca
20 - icosa
Polygons with 21 to 99 sides have a different system. Take the prefix for the tens digit (found on the left column), the ones digit (right column below), and then stick a "kai" between them to get (tens)kai(ones)gon.

10 - deca        | 1 - hena
20 - icosi       | 2 - di
30 - triaconta   | 3 - tri
40 - tetraconta  | 4 - tetra
50 - pentaconta  | 5 - penta
60 - hexaconta   | 6 - hexa
70 - heptaconta  | 7 - hepta
80 - octaconta   | 8 - octa
90 - nonaconta   | 9 - nona
The 3-digit sided polygons are named in a similar fashion. A 100-sided polygon is called a hectogon. Take the hundreds digit, find it on the column for ones digits, then stick a "hecta" to its right. Now number off the tens and ones like above: (hundreds)hecta(tens)kai(ones)gon. If the hundreds place digit is a 1, don't put the prefix behind "hecta"; if the ones place is 0, then omit the (ones) section.

So, given an integer (3 <= n <= 999), return the name of an n-sided polygon. n-gon is not a valid answer :P

As with all code golf, shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
append(char **p, int n)
{
	static const char *prefix[] = {
	    "",
	    "hena",
	    "di",
	    "tri",
	    "tetra",
	    "penta",
	    "hexa",
	    "hepta",
	    "octa",
	    "nona",
	    "un",
	    "do",
	    "triskai",
	    "deca",
	    "icosi",
	    "tria",
	    "conta",
	    "kai",
	    "icosa",
	    "hecto",
	    "hecta",
	    "gon",
	};

	*p += sprintf(*p, "%s", prefix[n]);
}

// ported from @baby-rabbit solution
char *
polygon(int n, char *b)
{
	char *p;
	int t;

	p = b;
	if (n < 10) {
		// ones
		append(&p, n);
	} else if (n < 20) {
		n -= 10;
		append(&p, n + (n && n < 4) * 9);
		append(&p, 13);
	} else if (n == 20) {
		// icosa
		append(&p, 18);
	} else if (n == 100) {
		// hecto
		append(&p, 19);
	} else {
		t = n / 100;
		// hundreds
		append(&p, t > 1 ? t : 0);
		// hecta
		append(&p, t ? 20 : 0);
		n %= 100;
		t = n / 10;
		// tens
		append(&p, t + (t && t < 4) * 12);
		// conta
		append(&p, t > 2 ? 16 : 0);
		n %= 10;
		// kai
		append(&p, n ? 17 : 0);
		// ones
		append(&p, n);
	}
	// gon
	append(&p, 21);
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	polygon(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(3, "trigon");
	test(4, "tetragon");
	test(5, "pentagon");
	test(6, "hexagon");
	test(7, "heptagon");
	test(8, "octagon");
	test(9, "nonagon");
	test(10, "decagon");
	test(11, "undecagon");
	test(12, "dodecagon");
	test(13, "triskaidecagon");
	test(14, "tetradecagon");
	test(15, "pentadecagon");
	test(16, "hexadecagon");
	test(17, "heptadecagon");
	test(18, "octadecagon");
	test(19, "nonadecagon");
	test(20, "icosagon");
	test(21, "icosikaihenagon");
	test(22, "icosikaidigon");
	test(23, "icosikaitrigon");
	test(99, "nonacontakainonagon");
	test(100, "hectogon");
	test(101, "hectakaihenagon");
	test(102, "hectakaidigon");
	test(103, "hectakaitrigon");
	test(104, "hectakaitetragon");
	test(105, "hectakaipentagon");
	test(106, "hectakaihexagon");
	test(107, "hectakaiheptagon");
	test(108, "hectakaioctagon");
	test(109, "hectakainonagon");
	test(110, "hectadecagon");
	test(111, "hectadecakaihenagon");
	test(997, "nonahectanonacontakaiheptagon");
	test(998, "nonahectanonacontakaioctagon");
	test(999, "nonahectanonacontakainonagon");

	return 0;
}
