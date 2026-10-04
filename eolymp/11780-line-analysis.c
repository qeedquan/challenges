/*

Given N lines. For each line, it is necessary to determine its type:

• purely text line – contains only Latin alphabet letters (both lowercase and uppercase);

• numeric line – contains only digits;

• mixed line – contains Latin letters, digits, and other symbols simultaneously.

Your task is to count the number of lines of each type.

Input
The first line contains an integer N (1≤N≤10^4) – the number of lines in the input data.

The next N lines contain the actual lines. The length of each line does not exceed 10^4 characters.

Output
Print three numbers separated by spaces:

• the number of purely text lines;

• the number of numeric lines;

• the number of mixed lines

Examples

Input #1
5
example
987654321
abc123
456xyz
!!

Answer #1
1 1 3

*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(const char **s, size_t n)
{
	size_t i, j, r[3];
	int c, f;

	r[0] = r[1] = r[2] = 0;
	for (i = 0; i < n; i++) {
		f = 0;
		for (j = 0; s[i][j]; j++) {
			c = s[i][j];
			if (isalpha(c))
				f |= 0x1;
			else if (isdigit(c))
				f |= 0x2;
			else
				f |= 0x4;
		}
		if (f == 0x1)
			r[0] += 1;
		else if (f == 0x2)
			r[1] += 1;
		else if (f)
			r[2] += 1;
	}
	printf("%zu %zu %zu\n", r[0], r[1], r[2]);
}

int
main()
{
	const char *s1[] = {
		"example",
		"987654321",
		"abc123",
		"456xyz",
		"!!",
	};

	solve(s1, nelem(s1));

	return 0;
}
