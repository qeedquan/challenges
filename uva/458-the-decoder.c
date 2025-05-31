/*

Write a complete program that will correctly decode a set of characters into a valid message. Your
program should read a given file of a simple coded set of characters and print the exact message that
the characters contain. The code key for this simple coding is a one for one character substitution based
upon a single arithmetic manipulation of the printable portion of the ASCII character set.

Input and Output

For example: with the input file that contains:
1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5

your program should print the message:

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.

Your program should accept all sets of characters that use the same encoding scheme and should print the actual message of each set of characters.

Sample Input
1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5

Sample Output
*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.

*/

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
