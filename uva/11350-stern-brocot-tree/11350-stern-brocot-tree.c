#include <assert.h>
#include <stdio.h>

typedef long long vlong;

typedef struct {
	vlong n, d;
} Rat;

Rat
walk(const char *s)
{
	Rat l, r, c;

	l = (Rat){ 0, 1 };
	r = (Rat){ 1, 0 };
	c = (Rat){ 1, 1 };
	for (; *s; s++) {
		switch (*s) {
		case 'R':
			l = c;
			c = (Rat){ c.n + r.n, c.d + r.d };
			break;
		case 'L':
			r = c;
			c = (Rat){ c.n + l.n, c.d + l.d };
			break;
		}
	}
	return c;
}

void
test(const char *s, Rat r)
{
	Rat p;

	p = walk(s);
	printf("%lld/%lld\n", p.n, p.d);
	assert(p.n == r.n);
	assert(p.d == r.d);
}

int
main()
{
	test("RL", (Rat){ 3, 2 });
	test("RLR", (Rat){ 5, 3 });
	test("RRL", (Rat){ 5, 2 });

	return 0;
}
