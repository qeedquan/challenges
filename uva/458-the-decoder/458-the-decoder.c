#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
decode(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = s[i] - 7;
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5", "*CDC is the trademark of the Control Data Corporation.");
	test("1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5", "*IBM is a trademark of the International Business Machine Corporation.");
	test("1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5", "*DEC is the trademark of the Digital Equipment Corporation.");

	return 0;
}
