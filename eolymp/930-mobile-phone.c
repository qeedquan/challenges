/*

A mobile phone number is given. Determine which digits are absent in this number.

Input
The mobile phone number is provided in a single line.

Output
In the first line, output the number of digits that are absent from the number. In the second line, output the absent digits in ascending order, separated by spaces.

Examples
Input #1
0631562976

Answer #1
2
4 8

Input #24
+380 63 4423122

Answer #24
3
5 7 9

*/

#include <stdio.h>
#include <string.h>
#include <stdbit.h>
#include <ctype.h>

void
solve(const char *phone)
{
	size_t count[10];
	unsigned missing;
	int symbol;

	memset(count, 0, sizeof(count));
	for (missing = 0x3ff; *phone; phone++) {
		if (!isdigit(*phone))
			continue;

		symbol = *phone - '0';
		count[symbol] += 1;
		missing &= ~(1U << symbol);
	}

	printf("%d\n", stdc_count_ones(missing));
	for (symbol = 0; symbol <= 9; symbol++) {
		if (!count[symbol])
			printf("%d ", symbol);
	}
	printf("\n");
}

int
main()
{
	solve("0631562976");
	solve("+380 63 4423122");
	solve("0123456789");

	return 0;
}
