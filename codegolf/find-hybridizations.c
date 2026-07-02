/*

Covalent bonding uses so-called "hybrid" orbitals to form tetrahedral, octahedral, etc. formations out of the s, p, and sometimes d orbitals. Their naming conventions are pretty much the concatenation of the component orbitals; for example, the hybridization of the s orbital and one p orbital would be the two sp orbitals, and the hybridization of the s orbital, all three p orbitals, and 2 of the 5 d orbitals would be the 6 sp3d2 orbitals. Real-life hybrid orbitals rarely go beyond this, but of course we'll do it anyway.

The Challenge
Write a program that takes in the number of orbitals needed and outputs the name of the hybrid orbital as a string such as sp3d4. Superscripts can be omitted.

The standard orbitals, ordered by the order in which they're hybridized, are as follows:

letter   # orbitals
  s           1
  p           3
  d           5
  f           7
No orbital should be used unless all lower orbitals have already been consumed. For example spd2 is not a valid orbital hybridization because there is still a p orbital that is not used.

If you go beyond the f orbital, then use the angular momentum quantum number (the zero-indexed position in this series: 0 is s, 1 is p, etc.) in parentheses. For example, 27 would be sp3d5f7(4)9(5)2. The number of orbitals for each set should continue with the pattern of "twice the angular momentum quantum number plus one".

Also, don't list the number of orbitals used in the output if that would be 1. It's sp3d, not s1p3d1.

Test Cases
1 => s
2 => sp
3 => sp2
5 => sp3d
12 => sp3d5f3
36 => sp3d5f7(4)9(5)11

Victory
The winner will be the shortest answer in bytes.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

char *
hybridizations(int n, char *b)
{
	static const char sym[] = "spdf";

	char *p;
	int i, m;

	p = b;
	*p = '\0';
	for (i = 0; n > 0; i++) {
		if (i < 4)
			p += sprintf(p, "%c", sym[i]);
		else
			p += sprintf(p, "(%d)", i);

		m = min((2 * i) + 1, n);
		if (m > 1)
			p += sprintf(p, "%d", m);

		n -= m;
	}

	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	hybridizations(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(1, "s");
	test(2, "sp");
	test(3, "sp2");
	test(5, "sp3d");
	test(12, "sp3d5f3");
	test(27, "sp3d5f7(4)9(5)2");
	test(36, "sp3d5f7(4)9(5)11");

	return 0;
}
