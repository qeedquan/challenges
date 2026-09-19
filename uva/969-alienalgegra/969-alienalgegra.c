#include <assert.h>
#include <stdio.h>

int
hash(int x, int y)
{
	return (x * 13) + y;
}

int
mhash(const char *s, size_t *i)
{
	int c, r;
	int x, y;

	r = 0;
	c = s[*i];
	*i += 1;
	switch (c) {
	case 't':
		*i += 1;
		x = mhash(s, i);
		*i += 1;
		y = mhash(s, i);
		*i += 1;
		r = hash(x, y);
		break;

	case 'i':
		*i += 1;
		r = mhash(s, i);
		*i += 1;
		break;

	case 'k':
		*i += 1;
		x = mhash(s, i);
		*i += 1;
		y = mhash(s, i);
		*i += 1;
		r = hash(y, hash(x, 1));
		break;

	case '0':
		r = 1;
		break;
	}
	return r;
}

bool
equal(const char *s1, const char *s2)
{
	int h1, h2;
	size_t i1, i2;

	i1 = 0;
	i2 = 0;
	h1 = mhash(s1, &i1);
	h2 = mhash(s2, &i2);
	return h1 == h2;
}

int
main()
{
	assert(equal("t(0,t(t(0,0),0))", "i(i(k(t(0,0),i(0))))") == true);
	assert(equal("i(t(0,t(0,0)))", "k(0,t(0,0))") == false);

	return 0;
}
