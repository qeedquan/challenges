#include <assert.h>
#include <string.h>

typedef long long vlong;

vlong
skew2dec(const char *s)
{
	vlong b, n, v;

	n = strlen(s);
	v = 0;
	for (b = 1; n > 0; n--) {
		v += (s[n - 1] - '0') * ((1LL << b) - 1);
		b += 1;
	}
	return v;
}

int
main()
{
	assert(skew2dec("10120") == 44);
	assert(skew2dec("200000000000000000000000000000") == 2147483646);
	assert(skew2dec("10") == 3);
	assert(skew2dec("1000000000000000000000000000000") == 2147483647);
	assert(skew2dec("11") == 4);
	assert(skew2dec("100") == 7);
	assert(skew2dec("11111000001110000101101102000") == 1041110737);

	return 0;
}
