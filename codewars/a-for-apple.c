/*

Input: Integer n
Output: String
Example:

a(4) prints as

   A
  A A
 A A A
A     A
a(8) prints as

       A
      A A
     A   A
    A     A
   A A A A A
  A         A
 A           A
A             A
a(12) prints as

           A
          A A
         A   A
        A     A
       A       A
      A         A
     A A A A A A A
    A             A
   A               A
  A                 A
 A                   A
A                     A
Note:

Each line's length is 2n - 1
Each line should be concatenate by line break "\n"
If n is less than 4, it should return ""
If n is odd, a(n) = a(n - 1), eg a(5) == a(4); a(9) == a(8)

*/

#include <stdio.h>
#include <stdarg.h>

void
outf(const char *fmt, ...)
{
	va_list ap;
	int i, n;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case ' ':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(*fmt);
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	va_end(ap);
}

void
apple(int n)
{
	int i, j;

	printf("n=%d\n", n);

	if (n < 4)
		return;
	if (n % 2)
		n -= 1;

	outf(" A \n", n - 1, n - 1);
	for (i = 2; i <= n; i++) {
		outf(" A", n - i);
		for (j = 0; j < (2 * i) - 3; j++) {
			if (i == (n / 2) + 1 && j % 2)
				printf("A");
			else
				printf(" ");
		}
		outf("A \n", n - i);
	}
	printf("\n");
}

int
main()
{
	apple(4);
	apple(8);
	apple(12);
	return 0;
}
