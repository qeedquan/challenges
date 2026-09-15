/*

Description:
In this Kata, we have to try to create a mysterious pattern.

Given a positive integer m, you can generate a Fibonacci sequence with a length of m:

1 1 2 3 5 8 13 21 34 ...

Given a positive integer n, you need to execute % operation on each element of the Fibonacci sequence:

m = 9, n = 3
Fibonacci sequence: 1 1 2 3 5 8 13 21 34
               ---> 1%3 1%3 2%3 3%3 5%3 8%3 13%3 21%3 34%3
               --->  1   1   2   0   2   2    1    0    1

Finally, make n rows string to show the pattern:

112022101
|||||||||
   o   o
oo    o o
  o oo

Please note:

Each row is separated by "\n";
You should trim the end of each row;
If there are some empty rows at the start or end of string, you should trim them too. But, if the empty row is in the middle(see the last example), you should not trim it.

Examples:
For m = 5, n = 5, the output should be:

    o
oo
  o
   o

For m = 12, n = 4, the output should be:

     o     o
oo  o oo  o
  o     o
   o     o

For m = 1, n = 1, the output should be:"o"

For: m = 6, n = 15, the output should be:

oo
  o
   o

    o


     o

*/

#include <stdio.h>

void
pattern(int m, int n)
{
	int a, b, c;
	int x, y;

	printf("m=%d n=%d\n", m, n);
	for (y = 0; y < n; y++) {
		a = b = 1;
		for (x = 0; x < m; x++) {
			if (y == a % n)
				printf("o");
			else
				printf(" ");

			c = a + b;
			a = b;
			b = c;
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	pattern(9, 3);
	pattern(5, 5);
	pattern(12, 4);
	pattern(1, 1);
	pattern(6, 15);
	return 0;
}
