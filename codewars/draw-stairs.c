/*

Given a number n, draw stairs using the letter "I", n tall and n wide, with the tallest in the top left.

For example n = 3 result in:

"I\n I\n  I"

or printed:


I
 I
  I

Another example, a 7-step stairs should be drawn like this:


I
 I
  I
   I
    I
     I
      I

*/

#include <stdio.h>

void
stairs(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			printf(" ");
		printf("I\n");
	}
}

int
main()
{
	stairs(3);
	stairs(7);

	return 0;
}
