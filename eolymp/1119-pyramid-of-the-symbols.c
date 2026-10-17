/*

Vasya wants to print a pyramid of a given symbol with height h on the printer. Write a program to help him do this, ensuring that the program is "economically viable", i.e., it should print as few characters as possible.

Examples of pyramids are shown in the sample input and output. For clarity, spaces used for formatting are replaced by dots in the examples.

Input
The only line contains the symbol to use for printing the pyramid, followed by a space and a natural number h (h≤50), which is the height of the pyramid.

Output
Print the total number of printed characters in the first line, and the pyramid itself below.

Examples

Input #1
A 3

Answer #1
12
  A
 AAA
AAAAA

Input #2
M 9

Answer #2
117
        M
       MMM
      MMMMM
     MMMMMMM
    MMMMMMMMM
   MMMMMMMMMMM
  MMMMMMMMMMMMM
 MMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMM

*/

#include <stdio.h>

void
solve(int n, int c)
{
	int x, y, s, t;

	if (n < 1) {
		puts("0");
		return;
	}

	s = n - 1;
	t = 1;

	printf("%d\n", ((3 * n * n) - n) / 2);
	for (y = 0; y < n; y++) {
		for (x = 0; x < s; x++)
			putchar(' ');
		for (x = 0; x < t; x++)
			putchar(c);
		putchar('\n');

		s -= 1;
		t += 2;
	}
	putchar('\n');
}

int
main()
{
	solve(3, 'A');
	solve(9, 'M');

	return 0;
}
