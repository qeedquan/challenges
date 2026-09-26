/*

If you're like me (and/or use Windows), You should have found this issue quite disturbing.

You plug in a hard drive (2TB for my occasion), and realize it doesn't show as 2TB, but a bit smaller size which is clearly not 2TB.

Over some research, I found it was because of Microsoft's mistake. Mistyping Binary prefix as Decimal prefixes. (i.e. They typed 1TiB as 1TB)

So, I would like to see a Binary prefix to Decimal prefix program. Since this is a big problem (and some computers are literally toasters), You have to make your program as short as possible.

conversion chart I found

I/O
You will be given the size (positive real number, will not exceed 2ˆ16 when converted), and the unit (4 of them, KiB, MiB, GiB and TiB, each corresponds to 1024ˆ1, 1024ˆ2, 1024ˆ3 and 1024ˆ4 bytes)

You have to output the (decimal representation of) the size (rounded half-up to integer value), and the corresponding unit.

Examples
678 MiB => 711 MB
1.8 TiB => 2 TB
Tip: Google has a unit converter

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
tib2tb(const char *s, char *b)
{
	static const struct Unit {
		char iec[4];
		char si[4];
		double scale;
	} tab[] = {
	    {"KiB", "KB", 1.024},
	    {"MiB", "MB", 1.048576},
	    {"GiB", "GB", 1.073741824},
	    {"TiB", "TB", 1.099511627776},
	};

	const struct Unit *p;
	double v;
	char t[4];
	size_t i;

	if (sscanf(s, "%lf %3s", &v, t) != 2)
		return NULL;

	for (i = 0; i < nelem(tab); i++) {
		p = tab + i;
		if (!strcmp(t, p->iec))
			break;
	}
	if (i == nelem(tab))
		return NULL;

	v = round(v * p->scale);
	sprintf(b, "%.0lf %s", v, p->si);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	assert(tib2tb(s, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("678 MiB", "711 MB");
	test("1.8 TiB", "2 TB");
	test("34 GiB", "37 GB");
	test("3 KiB", "3 KB");

	return 0;
}
