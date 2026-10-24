#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(const char *t1, const char *t2)
{
	int sh, sm;
	int eh, em;
	int ah, am;
	int bh, bm;

	if (sscanf(t1, "%d:%d %d:%d", &sh, &sm, &eh, &em) != 4)
		return NULL;

	if (sscanf(t2, "%d:%d %d:%d", &ah, &am, &bh, &bm) != 4)
		return NULL;

	sh = (sh * 60) + sm;
	eh = (eh * 60) + em;
	ah = (ah * 60) + am;
	bh = (bh * 60) + bm;

	if (eh < ah || sh > bh)
		return "Hits Meeting";
	return "Mrs Meeting";
}

void
test(const char *t1, const char *t2, const char *r)
{
	const char *p;

	p = solve(t1, t2);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("17:47 22:40", "06:18 17:04", "Hits Meeting");
	test("10:44 17:05", "01:11 01:27", "Hits Meeting");
	test("03:36 19:02", "14:33 15:24", "Mrs Meeting");

	return 0;
}
