/*

Many formulas in math involve nested radicals (square root signs inside other square roots signs). Your task here is to draw these using ascii art.

Specs
You will be given two integers, the number inside the radical, and the number of radicals. I think the best way to explain what you have to do is with an example. Here is the output for 2, 4:

        ____________________
\      /       _______________
 \    /  \    /     __________
  \  /    \  /  \  /   _____
   \/      \/    \/  \/ 2
Here are some things to note:

The height of each radical increases by one
The length of the _'s are always 5 times the height
There is a space after the last / and before the next inner radical starts
The number inside will never be greater than 4 digits
If the number of radicals is 0, just output the number
Putting extra spaces to pad it into a rectangle is up to you
This is code-golf, so shortest code in bytes wins!
Test Cases
2, 4:
        ____________________
\      /       _______________
 \    /  \    /     __________
  \  /    \  /  \  /   _____
   \/      \/    \/  \/ 2

23, 0:
23

4, 1:
  _____
\/ 4

1234, 3:
      _______________
\    /     __________
 \  /  \  /   _____
  \/    \/  \/ 1234

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
radical(int n, int x)
{
	int i, j;

	printf("%d, %d\n", n, x);
	for (i = x; i >= 0; i--) {
		for (j = x - i - 1; j >= 0; j--) {
			repeat(" ", j);
			printf("\\");
			repeat("  ", i);
			printf("/ ");
			repeat(" ", j);
		}
		repeat("  ", i);
		if (i == 0)
			printf("%d", n);
		else
			repeat("_____", i);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	radical(2, 4);
	radical(23, 0);
	radical(4, 1);
	radical(1234, 3);

	return 0;
}
